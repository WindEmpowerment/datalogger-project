/*
 * fct_rs232.h
 *
 *  Created on: 6 juin 2016
 *      Author: formateur
 */

#ifndef HEADERS_FCT_RS232_H_
#define HEADERS_FCT_RS232_H_

#define 	_COM1 	0			/**sélection du port*/
#define		_COM2	1

#define 	EnIT	1		// enable IT
#define 	DisIT	0		// disable IT

#define 	B9600	103		// valeurs pour U2X = 1
#define 	B19200	51
#define		B38400	25
#define		B57600	16
#define		B115200	8

#define 	D7		2
#define		D8		3

#define		PN		0		// sans parité
#define		PP		2		// parité paire
#define		PI		3		// parité impaire

#define 	STP1	0
#define 	STP2	1



/*--------------------------------------------------------------------------------
 *  configuration port serie:
 *  port: com1 ou com2
 *  vitesse: de 2400 à 115200 bps
 *  parité: sans, paire, impaire
 *  trame: nb de bits de data 7 ou 8
 *  IT: valide ou invalide IT en reception
 */

/**
 * Fonction pour initialiser le RS232
 * @param port		_COM1
 * @param vitesse	B57600
 * @param parite	PN
 * @param trame		D8
 * @param stop		STP2
 * @param IT		EnIT
 */
void openRS232(unsigned char port, unsigned int vitesse, unsigned char parite, unsigned char trame, unsigned char stop, unsigned char IT);

/**
 * fonction pour fermer le port
 * @param port	"_COM1 ou _COM2"
 */
void close_port(unsigned char port);

/**
 * Fonction pour envoyer un octet sur le port
 * @param port	"_COM1 ou _COM2"
 * @param data	l'octet qu'on veut envoyer sur le port
 */
void txchar(unsigned char port, unsigned char data);

/**
 * Fonction pour le saut de ligne
 * @param port	"_COM1 ou _COM2"
 */
void newline(unsigned char port);

/**
 * Fonction pour envoyer une chaine de caractére sur le port
 * @param port	"_COM1 ou _COM2"
 * @param chaine	la chaine de caractére qu'on veut envoyer
 */
void txString(unsigned char port, char *chaine);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

/**
 * Fonction pour lire la data stockée dans le registre UDR de l'uart
 * @param port	"_COM1 ou _COM2"
 * @return	data ou 1 si le port séléctionné est different de "_COM1 ou _COM2"
 */
unsigned char rxchar(unsigned char port);

/**
 * Fonction pour lire le registre tempon dara_udr0
 * @return data_udr0
 */
unsigned char rxchar_IT();

/**
 * Fonction pour autoriser IT en reception si EnIT ou l'interdire si DisIT
 * @param port	"_COM1 ou _COM2"
 * @param IT	"EnIT ou DisIT"
 */
void enableIT_RX(unsigned char port, unsigned char IT);

/**
 * Fonction pour lire la chaine de caractére dans data_udr0
 * @param str
 * @param arret
 * @param taille
 */
void rxString(char *str, char arret, char taille);

/**
 * Fonction pour transmettre une chaine de caractére dans la mémoire Flash
 * @param string	chaine de caractére
 */
void transmitString_F(const char* string);

/**
 * Fonction pour transmettre une chaine de caractére dans la mémoire RAM
 * @param string	chaine de caractére
 */
void transmitString(unsigned char* string);


#endif /* HEADERS_FCT_RS232_H_ */
