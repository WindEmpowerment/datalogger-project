/**
 * @file	fct_spi.c
 * @author	stetd
 * @date	5 sept. 2016
 * @brief	source de la librairie fct_spi
 *
 * description sur plusieurs lignes de fichier
 */


#include <avr/io.h>
#include "../lib/fct_spi.h"


//----------------------------------------------------------------------------------

//SPI initialize for SD card


void spi_init(void)
{

	SPCR = 0x52; 	/**< setup SPI: Master mode, MSB first, SCK phase low, SCK idle low*/
	SPSR = 0x00;
}

//----------------------------------------------------------------------------------

unsigned char SPI_transmit(unsigned char data)
{
	SPDR = data;					/**< Start transmission*/

	while(!(SPSR & (1<<SPIF)));		/**< Wait for transmission complete*/

	data = SPDR;

	return(data);
}

//----------------------------------------------------------------------------------

unsigned char SPI_receive(void)
{
	unsigned char data;

	SPDR = 0xff;				/**< mettre tous les bits a 1 pour vérifier la reception de data si un bit change*/

	while(!(SPSR & (1<<SPIF)));	/**< Wait for reception complete*/

	data = SPDR;				/**< data prend la valeur du SPDR*/

	// Return data register
	return data;
}


