/**
 * @file   time.c
 * @author gilou
 * @date   20 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../lib/main.h"
#include "../lib/usart.h"

void init_FSM()
{
	TCCR0=0x06;
	TIMSK|=_BV(TOIE0);

	// initialisation timer1 : 356 prescaler, compare mode  512, change state every 32.76ms
//	OCR1A = 0x00FF;				//Compare A register to 512
//	TIMSK |= _BV(OCIE1A);		//Enable compare A
//	TCCR1A = 0x00;				//
//	TCCR1B |= _BV(WGM12) | _BV(CS12); 				// Set WGM1[3:0]=4 to OCRA compare mode and CS1[2:0]= 101, 256 prescaler
}

ISR(TIMER0_OVF_vect){
	flag_next_state = 1;	/**< at each interrupt measure's, set the flag! */
	ptrLogger->to_cent++;
}


//ISR(TIMER1_COMPA_vect)
//{
//	USART0_print('a');
//	flag_next_state = 1;	/**< at each interrupt measure's, set the flag! */
//	ptrLogger->to_cent++;
//
//}

