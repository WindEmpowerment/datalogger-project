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
	_measure->speed2 = 0;
	_measure->degree = 0;
	_measure->realPower = 0;
	_measure->apparentPower = 0;
	_measure->powerFactor = 0;
	_measure->Vrms = 0;
	_measure->Irms = 0;
	_measure->dcPower = 0;
	_measure->temp = 0;
	_measure->rpm = 0;
}

void anemos_init(void)
{
	// init TIMER1 as counter to use external clock to measure the anemo1 frequency, enable interrupt, but not enable
//	TCCR1A = 0; // no compare, normal mode = 0;
//	TCCR1B |= _BV(ICNC1) | _BV(ICES1) | _BV(CS12) | _BV(CS11) | _BV(CS10);   //ICNC1: noise canceler, ICES1: capture on rising edge, CS1[2:0] external clock on rising edge
//	TCCR1C = 0;
//	TCNT1 = 0; // clear the counter register
//	TIMSK1 = 0;		// no interrupt at init
//
//	// init TIMER3 as counter to use external clock to measure the anemo2 frequency, enable interrupt, but not enable
//	TCCR3A = 0; // no comparaison, normal mode = 0;
//	TCCR3B |= _BV(ICNC1) | _BV(ICES1) | _BV(CS12) | _BV(CS11) | _BV(CS10);   //ICNC1: noise canceler, ICES1: capture on rising edge, CS1[2:0] external clock on rising edge
//	TCCR3C = 0;
//	TCNT3 = 0; // clear the counter register
//	TIMSK3 = 0;		// no interrupt at init

	// init TIMER4 to use overflow interrupt, and 1024 prescaler
//	TCCR4A = 0; // no compare, normal mode = 0;
//	TCCR4B |= (1 << CS42) | (1 << CS40);	// CCS4[2:0] use 1024 prescaler  (1 << WGM42) |
//	TCCR4C = 0;				// no force output compare
//	TIMSK4 = 0;

}

void anemo_start_count(void)
{
	//use interrupt 4 for speed1 measurement
		logger.measureAverage.count_speed1 = 0;
		EICRB |= _BV(ISC41); // detect interrupt on INT4 on rising edge
		EIMSK |= _BV(INT4);	// enable the interrupt on INT4

	// use the timer4 to measure the frequency on TIMER1 and 3. For these timers, the input clock is use.
	// clear TIMER1 and 3 registers
	//TCNT5 = 0;
//	TCNT3 = 0;
	TCNT4 = 0;

	TCCR4B |= (1 << CS42) | (1 << CS40);	// CCS4[2:0] use 1024 prescaler  (1 << WGM42) |
	//TCCR5B |=  _BV(CS52) | _BV(CS51) | _BV(CS50); //_BV(ICNC5) | _BV(ICES5) |

//	// synchronise timers
//	GTCCR = (1 << TSM);
//	GTCCR = (1 << PSRSYNC);
//	GTCCR = 0;

	// enable TIMER1, 3 and 4 interrupt
	//TIMSK5 |= (1 << TOIE5);	// permit input clock counter, if overflow, problem
//	TIMSK3 |= (1 << TOIE3);	// permit input clock counter, if overflow, problem
	TIMSK4 |= (1 << TOIE4);	// start to count for TNCT4 time
	TCNT4_tmp = TCNT4;	// use to filter the frequency in isr

#ifdef DEBUG_SENSORS
	RTC_get_date(ptrTime);
	debug_printl("sensors", "anemo start",ptrTime->timestamp,1);
#endif

}

void anemo_read_value(Measure *_measure)
{
	//debug_printu("sensors","counter speed1",logger.measureAverage.count_speed1,1);
//	// read TIMER1 and 3 value
	//double timer1_value = (uint16_t) TCNT5;
//	uint16_t timer3_value = TCNT3;
//
//	// convert TIMER4 value in second
	double meas_period = (double) 65536/15625.0; // 15625 constant to convert from 1/fclock*1024(prescaler) in second
//
//	// convert in hertz
	logger.measureAverage.count_speed1 /= meas_period;

	//if(timer1_value>49.5) timer1_value = 0; 	// mauvais filtre 50 hertz
//	logger.measureAverage.speed2 = (double)timer3_value/meas_period;
//
//	// if(timer1_value==0)
	if(logger.measureAverage.count_speed1!=0)
	{
		logger.measureAverage.count_speed1 = (logger.measureAverage.count_speed1*logger.anemo1_factor)+logger.anemo1_offset;
		logger.measureAverage.speed1 += logger.measureAverage.count_speed1/logger.meas_max;
	}


#ifdef DEBUG_SENSORS
	RTC_get_date(ptrTime);
	debug_printl("sensors", "anemo read",ptrTime->timestamp,1);
#endif
}

ISR(TIMER4_OVF_vect)
{
	//Stop the timers 1, 3 and 0
//	TIMSK1 &= ~(1 << TOIE1);
//	TIMSK3 &= ~(1 << TOIE3);
//	TCCR5B = 0;	// stop input
	EIMSK = 0;	// disable interrupt INT4
	TCCR4B = 0;	// CCS4[2:0] use 1024 prescaler  (1 << WGM42) |
	flag_anemo_ok=1;
}

ISR(INT4_vect)
{
	if((TCNT4-TCNT4_tmp)>= 315)
	{
		logger.measureAverage.count_speed1++;
		TCNT4_tmp = TCNT4;
	}

}

void dir_value(Measure *_measure)
{
	uint32_t degree;

	degree = adc_value(0);
	degree = degree *359/847; 		/**< map the value from 0-847 to 0-359  0,423848878394 = 359/847 to map value to change by degree factor*/

	degree = (degree+logger.degree_offset)%360;

	if(degree>359) degree=359;

	_measure->degree += degree/logger.meas_max; 	/// return the wind degree's value
}

void temp_value(Measure *_measure)
{
	double temp;

	temp = adc_value(1)*5.0/1024.0;			///convert the ADC value to the voltage value
	temp = temp*(-50/1.2)+50;				/// map to degree

	_measure->temp += temp/logger.meas_max;
}

double inst_AC_voltage()
{
	double voltage =(double)adc_value(2);
	voltage = voltage*5/1024;

	return voltage;
}

double inst_AC_current()
{
	double current = (double)(adc_value(4))*5/1024;

	return current;
}

double AC_voltage_offset()
{
	double v_offset = 0;
	uint8_t i = 0;

	for(i=0;i<100;i++)
		{
		v_offset +=(double)adc_value(2);
		}
	v_offset /= 100;
	v_offset = v_offset*5/1024;

return v_offset;
}

double AC_current_offset()
{
	double i_offset = 0;
	uint8_t i = 0;

	for(i=0;i<100;i++)
		{
		i_offset +=(double)adc_value(4);
		}
	i_offset /=100;
	i_offset = i_offset*5/1024;

return i_offset;
}
