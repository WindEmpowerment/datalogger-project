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
#include "../lib/fsm.h"
#include "../lib/debug.h"

void init_FSM() // added : init of logger's coefficients
{
	// initialisation timer1 : 256 prescaler, compare mode  512, change state every 10ms
	OCR3A = 0x0271;	//here 0x0271 = 625		enable copare interrupt each 10 ms
	TIMSK3 |= _BV(OCIE3A);		//Enable compare A interrupt
	TCCR3A = 0x00;				// reset conf
	TCCR3B |= _BV(WGM32) | _BV(CS32); 				// Set WGM1[3:0]=4 to OCRA compare mode and CS1[2:0]= 101, 256 prescaler
	logger.inPinVane = 6;
	logger.inPinanemo = 4;

}

ISR(TIMER3_COMPA_vect)
{
	flag_next_state = 1;	/**< at each interrupt measure's, set the flag! */
	logger.to_cent++;		/// @todo do this 100 time to avec second but can be done with the rtc
}

