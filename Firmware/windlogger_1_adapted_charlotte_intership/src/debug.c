/**
* @file   debug.c
 * @author gilou
 * @date   20 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

#include <avr/io.h>
#include <stdlib.h>

#include "../lib/main.h"
#include "../lib/usart.h"

//#ifdef DEBUG
//		debug_print("no bug on top","<______________________|",1);
//#endif

void debug_print(char *item, char *msg, char end)
{
	USART0_print(item);
	USART0_print("	");
	USART0_print(msg);
	if(end==1) USART0_print("\r\n");
}

void debug_printd(char *state, char *msg, double value, char end)
{
	char temp_conv[20];

	USART0_print(state);
	USART0_print("	");
	USART0_print(msg);
	USART0_print("	");
	USART0_print(dtostrf(value,0,1,temp_conv));
	if(end==1)	USART0_print("\r\n");
}

void debug_printu(char *state, char *msg, unsigned int value, char end)
{
	char temp_conv[20];

	USART0_print(state);
	USART0_print("	");
	USART0_print(msg);
	USART0_print("	");
	USART0_print(itoa(value,temp_conv,10));
	if(end==1)	USART0_print("\r\n");
}

void debug_printl(char *state, char *msg, uint32_t value, char end)
{
	char temp_conv[20];

	USART0_print(state);
	USART0_print("	");
	USART0_print(msg);
	USART0_print("	");
	USART0_print(ltoa(value,temp_conv,10));
	if(end==1)	USART0_print("\r\n");
}
