/**
 * @file   usart.c
 * @author gilou
 * @date   15 juil. 2016
 * @brief  uart lib for the atmega 328p.
 *
 * Look the chapter called:
 * 24. USART - Universal Synchronous Asynchronous Receiver Transceiver
 * in the ATmega328/P datasheet (p225)
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "../lib/main.h"

void USART0_init()
{
	UBRR0 = usart0_baudrate; // set baud rate
	UCSR0A = _BV(U2X0); // for the baud rate setting
	UCSR0B = _BV(RXCIE0) | _BV(RXEN0) |_BV(TXEN0); //enable receiver and transmitter
	UCSR0C = _BV(UPM01) | _BV(UPM00) | _BV(UCSZ01) | _BV(UCSZ00);	// Set frame format : 8data 2stop bit
}

void USART0_set(char character)
{
   /* Wait for empty transmit buffer */
   while ( !( UCSR0A & (1<<UDRE0)) )
	  ;
   /* Put data into buffer, sends the data */
   UDR0 = character;
}


void USART0_print(char *string)
{
	uint8_t i = 0;

		while(*(string+i)!='\0')
		{
			USART0_set(*(string+i));			//Sending of characters on the fly contained in adresses of data (adresses incremented by i)
			i++;								//while the data doesn't contain '\0'
		}
}

ISR(USART0_RX_vect)							//under interrupt routine while receiving
{
	data_udr0 = UDR0;						//recuperation of the data register UDR0 in the global variable data_udr0
	flag_USART0_read = 1;					//reception flag set to 1 for the interruption
}

unsigned char get_Arg(char string[])
{
	uint8_t temp_unit;  	//temporary variable receiving the integer value of the character "unit" from the sting pointer
	uint8_t temp_diz_unit; 	//temporary variable receiving the integer value of the character "dizaine" (tens) from the string pointer

	temp_unit = (uint8_t) (*(string+1) - '0');		// the pointer s_nombre+1 points the units of the number which needs to be converted
	temp_diz_unit = (uint8_t) (*string - '0');		//  the pointer s_nombre points the tens of the number which needs to be converted

	return 10*temp_diz_unit + temp_unit;			// return the converted number
}

void USART0_print_conf(){

	char conv_string[10];

	USART0_print("Configuration :\r\n");
	USART0_print("Logger :\r\n");
	USART0_print("$00=");USART0_print(itoa(logger.meas_conf,conv_string,10));USART0_print("	0: not measure,1: 1s average,2:1min average,3:10min average.\r\n");
	USART0_print("Time :\r\n");
	USART0_print("$11=");USART0_print(itoa(ptrTime->secs,conv_string,10));USART0_print("	seconds\r\n");
	USART0_print("$12=");USART0_print(itoa(ptrTime->mins,conv_string,10));USART0_print("	minutes\r\n");
	USART0_print("$13=");USART0_print(itoa(ptrTime->hours,conv_string,10));USART0_print("	hours\r\n");
	USART0_print("$14=");USART0_print(ptrTime->weekday);USART0_print("	0:su,1:mo,...,6:sa\r\n");
	USART0_print("$15=");USART0_print(itoa(ptrTime->day,conv_string,10));USART0_print("	month day\r\n");
	USART0_print("$16=");USART0_print(itoa(ptrTime->month,conv_string,10));USART0_print("	year month\r\n");
	USART0_print("$17=");USART0_print(itoa(ptrTime->year,conv_string,10));USART0_print("	year (16 - 99)\r\n");

}

void build_filename(){

	char temp_conv[20];				/**converting register*/

	 	strcpy(logger.forme_filename,dtostrf(ptrTime->month,0,0,temp_conv));		/**copy la valeur month de la structure Time, qui est convertie en chaine de caractére, dans le registre forme_filename de la structure Logger*/
	 	strcat(logger.forme_filename,"_") ;											/**concatener la chaine de caractére de forme_filename avec "_"*/
	 	strcat(logger.forme_filename, dtostrf(ptrTime->year,0,0,temp_conv)) ;		/**copier la valeur year de la structure Time, qui est convertie en chaine de caractére, dans le registre forme_filename de la structure Logger*/
	 	strcat(logger.forme_filename,".csv") ;										/**concatener la chaine de caractére de forme_filename avec ".csv"*/

}



