/**
 * @file	fct_spi.h
 * @author	stetd
 * @date	5 sept. 2016
 * @brief	Une librairie pour utiliser le périphérique SPI sur l'Atmega128
 *
 * description sur plusieurs lignes de fichier
 */

#ifndef HEADERS_FCT_SPI_H_
#define HEADERS_FCT_SPI_H_



//#define SPI_SD             SPCR = 0x52	/** Pas utilisé , configuration mode spi normal*/
//#define SPI_HIGH_SPEED     SPCR = 0x50; SPSR |= (1<<SPI2X) /** Pas utilisé , configuration en mode spi grande vitesse*/

/**
 * Fonction d'initialision du SPI\n
 * Clock rate: 125Khz
 */
void spi_init(void);

/**
 * Fonction de transmission d'un octet
 * @param	data	Envoie d'un caractère sur le périphérique SPI
 * @return	0		lorsque la transmission est complete
 */
unsigned char SPI_transmit(unsigned char data);

/**
 *	Fonction pour recevoir un caractère
 * @return	Octet recu sur le périphérique SPI
 */
unsigned char SPI_receive(void);


#endif /* HEADERS_FCT_SPI_H_ */
