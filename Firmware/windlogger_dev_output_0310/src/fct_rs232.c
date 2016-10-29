/*
 * fct_rs232.c
 *
 *  Created on: 6 juin 2016
 *      Author: formateur
 */

#include <avr/io.h>
#include<avr/interrupt.h>
#include <avr/pgmspace.h>

#include "../lib/main.h"
#include "../lib/fct_rs232.h"



//extern volatile char nr_IT ;



//--------------------------------------------------------------------------------

void openRS232(unsigned char port, unsigned int vitesse, unsigned char parite, unsigned char trame, unsigned char stop,
unsigned char IT)
{
	switch(port)
	{
		case _COM1:

			UCSR0B |= (1<<RXEN0) | (1<<TXEN0);

			UCSR0A |= (1 << U2X);						/** mise à 1 bit U2X*/

			UBRR0L = (char)vitesse;
			UBRR0H = (char)(vitesse >> 8);

			UCSR0C |= (parite << UPM00) | (trame << UCSZ00 );

			if(stop == STP1)
				UCSR0C &= 0xF7;
			else
				UCSR0C |= (stop << USBS0);


			if(IT == EnIT)
			{
				UCSR0B |= (1<< RXCIE);					/** mise a 1 autorisation IT en reception*/
			}
			else
			{
				UCSR0B &= ~(1<< RXCIE);					/** mise a 0 autorisation IT en reception*/
			}

			break;

		case _COM2:

			UCSR1B |= (1<<RXEN1) | (1<<TXEN1);


			UCSR1A |= (1 << U2X);						/** mise à 1 bit U2X*/

			UBRR1L = (char)vitesse;
			UBRR1H = (char)(vitesse >> 8);

			UCSR1C |= (parite << UPM10) | (trame << UCSZ10 );

			if(stop == STP1)
				UCSR1C &= 0xF7;
			else
				UCSR1C |= (stop << USBS1);

			if(IT == EnIT)
			{
				UCSR1B |= (1<< RXCIE);					/** mise a 1 autorisation IT en reception*/
			}
			else
			{
				UCSR1B &= ~(1<< RXCIE);					/** mise a 0 autorisation IT en reception*/
			}
	}
}

//--------------------------------------------------------------------------------

void close_port(unsigned char port)
{
	switch(port)
	{
		case _COM1:
			UCSR0B &= ~(1<<RXEN0); 						/** invalide la reception*/
			UCSR0B &= ~(1<<TXEN0);						/** invalide l'emission*/

			break;

		case _COM2:
			UCSR1B &= ~(1<<RXEN0); 						/** invalide la reception*/
			UCSR1B &= ~(1<<TXEN0);						/** invalide l'emission*/

	}
}

//--------------------------------------------------------------------------------

void txchar(unsigned char port, unsigned char data)
{

	switch(port)
	{
		case _COM1:

			while(!(UCSR0A & (1<< UDRE0)));				/** on attend que le registre d'emission soit libre*/
				UDR0 = data;							/** pour emettre le car suivant*/

			break;

		case _COM2:
			while(!(UCSR1A & (1<< UDRE1)));				/** on attend que le registre d'emission soit libre*/
				UDR1 = data;							/** pour emettre le car suivant*/

	}

}

//--------------------------------------------------------------------------------

void newline(unsigned char port)
{
	txchar(port,0x0D);
	txchar(port,0x0A);
}

//--------------------------------------------------------------------------------

void txString(unsigned char port, char *chaine)
{
	char *ptr;

	ptr = chaine;

	do
	{
		txchar(port, *ptr);
	}
	while(*(++ptr) != '\0');

}

//--------------------------------------------------------------------------------

unsigned char rxchar(unsigned char port)
{

	switch(port)
	{
	case _COM1:

		while(!(UCSR0A & (1<<RXC0)));
		return UDR0;
		break;

	case _COM2:

		while(!(UCSR1A & (1<<RXC1)));
		return UDR1;
	}
	return 1;												/**  if port different of _COM1 or _COM2 return 1*/
}

//--------------------------------------------------------------------------------

void enableIT_RX(unsigned char port, unsigned char IT)
{
	switch(port)
	{
		case _COM1:
			if(IT == EnIT)
			{
				UCSR0B |= (1<< RXCIE);						/** mise a 1 autorisation IT en reception*/
			}
			else
			{
				UCSR0B &= ~(1<< RXCIE);						/** mise a 0 autorisation IT en reception*/
			}
				break;

		case _COM2:

			if(IT == EnIT)
			{
				UCSR1B |= (1<< RXCIE);						/** mise a 1 autorisation IT en reception*/
			}
			else
			{
				UCSR1B &= ~(1<< RXCIE);						/** mise a 0 autorisation IT en reception*/
			}
	}
}

//--------------------------------------------------------------------------------


unsigned char rxchar_IT()
{
		return data_udr0;
}

//--------------------------------------------------------------------------------

void rxString(char *str, char arret, char taille)
{
	unsigned char i=0, j, car=0;

	do
	{
		if(flag_USART0_read)
		{
			flag_USART0_read = 0;
			if((car = data_udr0)!= arret)
			{
				str[i++] = car;
				txchar(_COM1, data_udr0);
			}
		}
	}
	while(car != arret && i<taille-1);						 /** arret sur cararactere d'arret ou nb car saisis = 7*/

	for(j=i; j<taille-1; j++)
		str[j] = ' ';										 /** complete le nom avec car ' '*/

	str[taille-1] = '\0';
}

//--------------------------------------------------------------------------------


ISR(USART0_RX_vect)
{
	data_udr0 = UDR0;
	flag_USART0_read = 1;
}

/*
ISR(INT0_vect)
{
	nr_IT = 0;
}

ISR(INT1_vect)
{
	nr_IT = 1;
}

ISR(INT2_vect)
{
	nr_IT = 2;
}*/




void transmitString_F(const char* string)
{
  while (pgm_read_byte(&(*string)))
	  txchar(_COM1, pgm_read_byte(&(*string++)));
}


void transmitString(unsigned char* string)
{
  while (*string)
	  txchar(_COM1,*string++);
}




