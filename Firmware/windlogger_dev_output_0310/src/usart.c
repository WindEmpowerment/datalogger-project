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
#include <string.h>

#include "../lib/main.h"
#include "../lib/fct_rs232.h"

//void USART0_init()
//{
//	UBRR0L = (uint8_t)usart0_baudrate; // set baud rate
//	UBRR0H = (uint8_t)(usart0_baudrate>>8);
//
//	UCSR0A = _BV(U2X); // for the baud rate setting
//
//	UCSR0B = _BV(RXCIE) | _BV(RXEN0) |_BV(TXEN0); //enable receiver and transmitter
//
//	UCSR0C = _BV(UPM01) | _BV(UPM00) |_BV(USBS0)| _BV(UCSZ01) | _BV(UCSZ00);	// Set frame format : 8data 2stop bit
//}

//void USART0_set(char character)
//{
//   /* Wait for empty transmit buffer */
//   while ( !( UCSR0A & (1<<UDRE0)) )
//	  ;
//   /* Put data into buffer, sends the data */
//   UDR0 = character;
//}


//void USART0_print(char *string)
//{
//	uint8_t i = 0;
//
//		while(*(string+i)!='\0')
//		{
//			USART0_set(*(string+i));			//envoi de caractère à la volée contenu dans les adresses de data (adresses incrémentée par i)
//			i++;								//tant que la data ne contient pas '\0'
//		}
//}
//
//ISR(USART0_RX_vect)							//sous routine d'interruption lors d'une reception
//{
//	data_udr0 = UDR0;						//récupération du registre de donnée UDR0 dans la variable globale data_udr0
//	flag_USART0_read = 1;					//mise à 1 du drapeau de reception pour interruption
//}

unsigned char get_Arg(char string[])
{
	uint8_t temp_unit;  	//variable temporaire recevant la valeur entière du caractère "unité" du pointeur string
	uint8_t temp_diz_unit; 	//variable temporaire recevant la valeur entière du caractère "dizaine" du pointeur string

	temp_unit = (uint8_t) (*(string+1) - '0');		// le pointeur s_nombre+1 pointe l'unité du nombre à convertir
	temp_diz_unit = (uint8_t) (*string - '0');		// le pointeur s_nombre pointe la dizaine du nombre à convertir

	return 10*temp_diz_unit + temp_unit;			// renvoi le nombre converti
}

void USART0_print_conf(){

	char conv_string[10];

	txString(_COM1,"Configuration :\r\n");
	txString(_COM1,"Logger :\r\n");
	txString(_COM1,"$00=");txString(_COM1,itoa(ptrLogger->meas_conf,conv_string,10));txString(_COM1,"\r\n");
	txString(_COM1,"$01=");txString(_COM1,itoa(ptrLogger->output_enable,conv_string,10));txString(_COM1," 1: UART0 Only, 2: 1+SD card, 3: 1+GPRS\r\n");
	txString(_COM1,"Time :\r\n");
	txString(_COM1,"$11=");txString(_COM1,itoa(ptrTime->secs,conv_string,10));txString(_COM1," seconds\r\n");
	txString(_COM1,"$12=");txString(_COM1,itoa(ptrTime->mins,conv_string,10));txString(_COM1," minutes\r\n");
	txString(_COM1,"$13=");txString(_COM1,itoa(ptrTime->hours,conv_string,10));txString(_COM1," hours\r\n");
	txString(_COM1,"$14=");txString(_COM1,ptrTime->weekday);txString(_COM1," 0:su,1:mo,...,6:sa\r\n");
	txString(_COM1,"$15=");txString(_COM1,itoa(ptrTime->day,conv_string,10));txString(_COM1," month day\r\n");
	txString(_COM1,"$16=");txString(_COM1,itoa(ptrTime->month,conv_string,10));txString(_COM1," year month\r\n");
	txString(_COM1,"$17=");txString(_COM1,itoa(ptrTime->year,conv_string,10));txString(_COM1," year (16 - 99)\r\n");
	txString(_COM1,"Sensors :\r\n");
	txString(_COM1,"$20=");txString(_COM1,dtostrf(ptrLogger->anemo1_factor,0,3,conv_string));txString(_COM1," anemo1 factor\r\n");
	txString(_COM1,"$21=");txString(_COM1,dtostrf(ptrLogger->anemo1_offset,0,3,conv_string));txString(_COM1," anemo1 offset\r\n");
	txString(_COM1,"AC wattmeter\r\n");
	txString(_COM1,"$30=");txString(_COM1,dtostrf(ptrLogger->ac_voltage_offset,0,3,conv_string));txString(_COM1," ac voltage offset, normally 2.500, send X to update\r\n");
	txString(_COM1,"$31=");txString(_COM1,dtostrf(ptrLogger->ac_current_offset,0,3,conv_string));txString(_COM1," ac current offset, normally 2.500, send X to update\r\n");
}

 void trans_to_string(){

	char temp_conv[20];				/**registre de convertion*/


	 	strcpy(dataString, dtostrf(ptrTime->timestamp,0,0,temp_conv)) ;					/**copier la valeur timestamp de la structure Time, qui est convertie en chaine de caractére, dans le registre datastring*/
	 	strcat(dataString,",") ;														/**concatener la chaine de caractére de datastring avec ","*/
	 	strcat(dataString,dtostrf(ptrLogger->measureAverage.speed1,0,1,temp_conv)) ;	/**copier la valeur speed1 de la structure Measure qui est convertie en chaine de caractére dans le registre datastring*/
	 	strcat(dataString,",") ;														/**concatener la chaine de caractére de datastring avec ","*/
	 	strcat(dataString,dtostrf(ptrLogger->measureAverage.speed2,0,1,temp_conv)) ;	/**copier la valeur speed2 de la structure Measure, qui est convertie en chaine de caractére, dans le registre datastring*/
	 	strcat(dataString,",") ;														/**concatener la chaine de caractére de datastring avec ","*/
	 	strcat(dataString,dtostrf(ptrLogger->measureAverage.degree,0,1,temp_conv)) ;	/**copier la valeur degree de la structure Measure, qui est convertie en chaine de caractére, dans le registre datastring*/
	 	strcat(dataString,",") ;														/**concatener la chaine de caractére de datastring avec ","*/
	 	strcat(dataString,dtostrf(ptrLogger->measureAverage.temp,0,1,temp_conv)) ;		/**copier la valeur temp de la structure Measure, qui est convertie en chaine de caractére, dans le registre datastring*/
	 	strcat(dataString,",") ;														/**concatener la chaine de caractére de datastring avec ","*/
	 	strcat(dataString,dtostrf(ptrLogger->measureAverage.acPower,0,1,temp_conv)) ;	/**copier la valeur acPower de la structure Measure, qui est convertie en chaine de caractére, dans le registre datastring*/
	 	strcat(dataString,",") ;														/**concatener la chaine de caractére de datastring avec ","*/
	 	strcat(dataString,dtostrf(ptrLogger->measureAverage.dcPower,0,1,temp_conv)) ;	/**copier la valeur dcPower de la structure Measure, qui est convertie en chaine de caractére, dans le registre datastring*/
	 	strcat(dataString,",") ;														/**concatener la chaine de caractére de datastring avec ","*/
	 	strcat(dataString,dtostrf(ptrLogger->measureAverage.rpm,0,1,temp_conv)) ;		/**copier la valeur rpm de la structure Measure, qui est convertie en chaine de caractére, dans le registre datastring*/
	 	strcat(dataString,";\n") ;														/**concatener la chaine de caractére de datastring avec ";" ,et à la ligne apres la finde la chaine*/

}

 void build_filename(){

	char temp_conv[20];				/**registre de convertion*/

	 	strcpy(ptrLogger->forme_filename,dtostrf(ptrTime->month,0,0,temp_conv));		/**copier la valeur month de la structure Time, qui est convertie en chaine de caractére, dans le registre forme_filename de la structure Logger*/
	 	strcat(ptrLogger->forme_filename,"_") ;											/**concatener la chaine de caractére de forme_filename avec "_"*/
	 	strcat(ptrLogger->forme_filename, dtostrf(ptrTime->year,0,0,temp_conv)) ;		/**copier la valeur year de la structure Time, qui est convertie en chaine de caractére, dans le registre forme_filename de la structure Logger*/
	 	strcat(ptrLogger->forme_filename,".csv") ;										/**concatener la chaine de caractére de forme_filename avec ".csv"*/

 }
