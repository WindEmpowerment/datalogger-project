/**
 * @file   sensors.c
 * @author gilou
 * @date   30 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

#include <avr/interrupt.h>
#include "../lib/main.h"
#include "../lib/sensors.h"
#include "../lib/adc.h"
#include "../lib/debug.h"
#ifdef DEBUG_SENSORS

	#include "../lib/pcf8563.h"
	#include "../lib/usart.h"
#endif


void measure_clear(Measure *_measure)
{
	_measure->count_speed1 = 0;
	_measure->speed1 = 0;
	_measure->degree = 0;

}

//void anemos_init(void)
//{
//	// init TIMER1 as counter to use external clock to measure the anemo1 frequency, enable interrupt, but not enable
//	TCCR1A = 0; // no compare, normal mode = 0;
//	TCCR1B |= _BV(ICNC1) | _BV(ICES1) | _BV(CS12) | _BV(CS11) | _BV(CS10);   //ICNC1: noise canceler, ICES1: capture on rising edge, CS1[2:0] external clock on rising edge
//	TCCR1C = 0;
//	TCNT1 = 0; // clear the counter register
//	TIMSK1 = 0;		// no interrupt at init
//
//}

void anemo_start_count(void)
{
	//use interrupt 4 for speed1 measurement
		logger.measureAverage.count_speed1 = 0;
		EICRA |= _BV(ISC01); // detect interrupt on INT4 on rising edge
		EIMSK |= _BV(INT0);	// enable the interrupt on INT4

	// use the timer4 to measure the frequency on TIMER1 and 3. For these timers, the input clock is use.
	// clear TIMER1 and 3 registers
	//TCNT5 = 0;
	//TCNT3 = 0;
    TCNT0 = 0;
	TCCR0B |= (1 << CS02) | (1 << CS00);	// CCS4[2:0] use 1024 prescaler  (1 << WGM42) |
	//TCCR5B |=  _BV(CS52) | _BV(CS51) | _BV(CS50); //_BV(ICNC5) | _BV(ICES5) |

//	// synchronise timers
//	GTCCR = (1 << TSM);
//	GTCCR = (1 << PSRSYNC);
//	GTCCR = 0;

	// enable TIMER1, 3 and 4 interrupt
	//TIMSK5 |= (1 << TOIE5);	// permit input clock counter, if overflow, problem
//	TIMSK3 |= (1 << TOIE3);	// permit input clock counter, if overflow, problem
	TIMSK0 |= (1 << TOIE0);	// start to count for TNCT4 time
	TCNT0_tmp = TCNT0;	// use to filter the frequency in isr

#ifdef DEBUG_SENSORS
	RTC_get_date(ptrTime);
	debug_printl("sensors", "anemo start",ptrTime->timestamp,1);
#endif

}

void anemo_read_value(Measure *_measure)
{
		double speed;

			speed = adc_value(logger.inPinanemo);		// map the value from 0-847 to 0-359  0,423848878394 = 359/847 to map value to change by degree factor
			speed = speed * 77.1667 / 1058.75;
			_measure->speed1 = speed   ;
			_measure->speed1 += speed/logger.meas_max; 	/// return the wind speed's value

#ifdef DEBUG_SENSORS
	RTC_get_date(ptrTime);
	debug_printl("sensors", "anemo read",ptrTime->timestamp,1);
#endif

}


ISR(TIMER0_OVF_vect)
{
	//Stop the timers 1, 3 and 0
//	TIMSK1 &= ~(1 << TOIE1); 
//	TIMSK3 &= ~(1 << TOIE3);
//	TCCR5B = 0;	// stop input
	EIMSK = 0;	// disable interrupt INT0
	TCCR0B = 0;	// CCS4[2:0] use 1024 prescaler  (1 << WGM42) |
	flag_anemo_ok = 1;
}

ISR(INT0_vect)
{
	if((TCNT0-TCNT0_tmp)>= 315)
	{
		logger.measureAverage.count_speed1++;
		TCNT0_tmp = TCNT0;
	}

}

void dir_value(Measure *_measure)
{
	uint32_t degree;

	degree = adc_value(logger.inPinVane);
	degree = degree *359./1694; 		// map the value from 0-847 to 0-359  0,423848878394 = 359/847 to map value to change by degree factor

	degree = (degree+logger.degree_offset)%360;

	if(degree>359) degree=359;

	_measure->degree = degree * 359/356 - 38;
	_measure->degree += degree/logger.meas_max; 	/// return the wind degree's value
}

