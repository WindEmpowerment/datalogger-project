/**
* @file   debug.c
 * @author gilou
 * @date   20 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */


#include <stdlib.h>

#include "../lib/main.h"
#include "../lib/fct_rs232.h"

//#ifdef DEBUG
//		debug_print("no bug on top","<______________________|",1);
//#endif

void debug_print(char *item, char *msg, char end)
{
	txString(_COM1,item);
	txString(_COM1,"	");
	txString(_COM1,msg);
	if(end==1) txString(_COM1,"\r\n");
}

void debug_printd(char *state, char *msg, double value, char end)
{
	char temp_conv[20];

	txString(_COM1,state);
	txString(_COM1,"	");
	txString(_COM1,msg);
	txString(_COM1,"	");
	txString(_COM1,dtostrf(value,0,1,temp_conv));
	if(end==1)	txString(_COM1,"\r\n");
}

void debug_printu(char *state, char *msg, unsigned int value, char end)
{
	char temp_conv[20];

	txString(_COM1,state);
	txString(_COM1,"	");
	txString(_COM1,msg);
	txString(_COM1,"	");
	txString(_COM1,itoa(value,temp_conv,10));
	if(end==1)	txString(_COM1,"\r\n");
}

void debug_printl(char *state, char *msg, uint32_t value, char end)
{
	char temp_conv[20];

	txString(_COM1,state);
	txString(_COM1,"	");
	txString(_COM1,msg);
	txString(_COM1,"	");
	txString(_COM1,ltoa(value,temp_conv,10));
	if(end==1)	txString(_COM1,"\r\n");
}

