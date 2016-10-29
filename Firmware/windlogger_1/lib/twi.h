/**
 * @file   twi.h
 * @author gilou
 * @date   3 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef HEADERS_LIB_TWI_H_
#define HEADERS_LIB_TWI_H_

//#define DEBUG_TWI	/**< use to debug the twi lib*/

// Fonction d'initialisation du protocole TWI
// Retour : unsigned char = renvoi la valeur 0 si initialisation réussie
// Paramètre 1 : void
unsigned char TWI_init(void);

uint8_t TWI_set_char(uint8_t addr,uint8_t reg, uint8_t data);

uint8_t TWI_get_char(uint8_t addr, uint8_t reg);


// Fonction d'écriture à la volée d'une donnée, sur un périph, inclus dans un registre, sur un nombre de registres définis
// Retour : unsigned char = la fonction renvoi un code erreur correspondant à la sous fonction en défaut (cf:datasheet Atmega 128)
// Paramètre 1 : unsigned char = adresse du périphérique
// Paramètre 2 : unsigned char = adresse du registre
// Paramètre 3 : unsigned char = nombre de registres à écrire
// Paramètre 4 : unsigned char = valeur à écrire
unsigned char TWI_print(unsigned char , unsigned char, unsigned char, unsigned char *);

// Fonction de lecture d'une donnée, sur un périph, inclus dans un registre, sur un nombre de registres définis
// Retour : unsigned char = la fonction renvoi un code erreur correspondant à la sous fonction en défaut (cf: datasheet Atmega 128)
// Paramètre 1 : adresse du périphérique
// Paramètre 2 : adresse du registre
// Paramètre 3 : nombre de registres
// Paramètre 4 : valeur de l'adresse du pointeur à lire
unsigned char TWI_receive(unsigned char, unsigned char, unsigned char, unsigned char *);


#endif /* HEADERS_LIB_TWI_H_ */
