/**
 * @file   twi.c
 * @author gilou
 * @date   3 août 2016
 * @brief  Atmega2560 twi driver.
 *
 * Library to talk on the TWI protocol (I2C). MicroC = atmega2560
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../lib/main.h"
#include "../lib/usart.h"


uint8_t TWI_init ()	// Fonction de démarrage du protocole TWI

{
	TWSR = 0x00; 					//prescaler à 1
	TWBR = (F_CPU / 100000UL - 16) / 2;					//bite rate register à 0x20 = 32, 0x0C for 400kHz
	TWCR = (1<<TWEN);				//enable TWI
#ifdef DEBUG_TWI
	USART0_print("init TWI\r\n");
#endif
	return 0;
}


// Fonction de démarrage du protocole TWI
// Retour : void
// Paramètre 1 : void
void TWI_start () 	// Fonction de démarrage du protocole TWI

{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); 	//mettre à 1 twint, twstart, twenable sur le registre de controle (TWCR)
	while (!(TWCR & (1<<TWINT))); 				//attendre que TWINT soit denouveau à l'état haut

}

// Fonction de redémarrage du protocole TWI
// Retour : void
// Paramètre 1 : void
void TWI_restart () // Fonction de redémarrage du protocole TWI
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);		//mettre à 1 twint, twstart, twenable sur le registre de controle (TWCR)
	while (!(TWCR & (1<<TWINT)));				//attendre que TWINT soit denouveau à l'état haut

}

// Fonction d'arrêt du protocole TWI
// Retour : void
// Paramètre 1 : void
void TWI_stop ()	// Fonction d'arrêt du protocole TWI
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);		//mettre à 1 twint, twstop, twenable sur le registre de controle (TWCR)
}

// Fonction d'ecriture d'un octet dans le registre de donnée (TWDR)
// Retour : void
// Paramètre 1 : unsigned char = adresse du périph, du registre ou valeur de la donnée à écrire sur TWDR
void TWI_set (uint8_t data)	// Fonction d'ecriture d'un octet dans le registre de donnée (TWDR)
{
	TWDR = data;							//le registre de donnée (TWDR) reçoit la valeur de "data"
	TWCR = (1<<TWINT)|(1<<TWEN);			//mettre à 1 twint et twen dans le registre de controle (TWCR)
	while (!(TWCR & (1<<TWINT)));			//attendre que TWINT soit denouveau à l'état haut
}

// Fonction de lecture du registre de donnée et ACKNOWLEDGEMENT
// Retour : unsigned char = la fonction renvoi la valeur du registre de donnée (TWDR)
// Paramètre 1 : void
uint8_t TWI_get_ack(void)	// Fonction de lecture du registre de donnée et d'envoie d'ACKNOWLEDGEMENT
{
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);	//mettre à 1 twint, twen, et twea dans le registre de controle (TWCR)
    while (!(TWCR & (1<<TWINT)));			//attendre que TWINT soit denouveau à l'état haut
    return TWDR;							//quand twint denouveau à l'état haut, renvoie la valeur du registre de donnée (TWDR)
}

// Fonction de lecture du registre de donnée et NOT ACKNOWLEDGEMENT
// Retour : unsigned char = la fonction renvoi la valeur du registre de donnée (TWDR)
// Paramètre 1 : void
uint8_t TWI_get_nack(void)	// Fonction de lecture du registre de donnée et pas d'envoie d'ACKNOWLEDGEMENT

{
	TWCR = (1<<TWINT)|(1<<TWEN);			//mettre à 1 twint, et twen dans le registre de controle (TWCR)
	while (!(TWCR & (1<<TWINT)));			//attendre que twint soit denouveau à l'état haut
	return TWDR;							//quand twint denouveau à l'état haut, renvoie la valeur du registre de donnée (TWDR)
}

// Fonction de lecture du registre de status (TWSR)
// Retour : unsigned char = la fonction renvoi la valeur du registre de status (TWSR) en masquant les deux bits de prescaler
// Paramètre 1 : void
uint8_t TWI_get_status(void)	// Fonction de lecture du registre de status (TWSR)

{
    return TWSR & 0xF8; 		//renvoie la valeur du registre de status (TWSR) en masquant les bits de prescaler
}


uint8_t TWI_set_char(uint8_t addr,uint8_t reg, uint8_t data)	// Fonction d'écriture à la volée d'une donnée, sur un périph, inclus dans un registre, sur un nombre de registres définis

{
	TWI_start();
	if (TWI_get_status()!= 0x08)		//Si condition Start non reconnue renvoie erreur : 0x08
		return 0x08;

	TWI_set(addr);
	if (TWI_get_status() != 0x18)		//Si condition set non reconnue renvoie erreur : 0x18
		return 0x18;

	TWI_set(reg);
	if (TWI_get_status() != 0x28)	//Si condition set non reconnue renvoie erreur : 0x18
		return 0x19;

	TWI_set(data);
	if (TWI_get_status() != 0x28)	//Si condition set non reconnue renvoie erreur : 0x28
		return 0x28;

	TWI_stop();

	return 0x00;						//renvoie le code 0x00 si la fonction TWI_print c'est executée sans soucis
}

uint8_t TWI_get_char(uint8_t addr, uint8_t reg)	// Fonction d'écriture d'une donnée sur un pointeur, sur un périph, inclus dans un registre, sur un nombre de registres définis

{

	uint8_t data=0;						//création d'une variable d'index locale à la fonction

	TWI_start();
	if (TWI_get_status() != 0x08)return 0x08;		//Si condition Start non reconnue renvoie erreur : 0x08

	TWI_set(addr);
	if (TWI_get_status() != 0x18)return 0x18;		//Si condition set non reconnue renvoie erreur : 0x18

	TWI_set(reg);
	if(TWI_get_status() != 0x28)return 0x28;		//Si condition set non reconnue renvoie erreur : 0x28

	TWI_restart();
	if (TWI_get_status() != 0x10)return 0x10;		//si la condition repeted start non reconnue renvoie erreur : 0x10

	TWI_set(addr+1);

	if (TWI_get_status() != 0x40)return 0x40;		//si la condition set non reconnue en mode master receiver renvoie erreur : 0x40

	// l' octet à récupérer doit être sans acknowlegdment
	data = TWI_get_nack();		//la valeur de l'adresse du point read_data recoit la valeur du registre de donnée (TWDR) lorsqu'il n'y a pas d'ACK
	if (TWI_get_status() != 0x58)	//si la condition de lecture de donnée non reconnue après un NACK, renvoie code erreur : 0x58
		return 0x58;

	TWI_stop();

	return data;						//la fonction TWI_receive renvoie la valeur 0xF0 quand la fonction s'est déroulé sans erreur
}




uint8_t TWI_print (uint8_t addr,uint8_t reg, uint8_t nb, uint8_t *write_data)	// Fonction d'écriture à la volée d'une donnée, sur un périph, inclus dans un registre, sur un nombre de registres définis

{
	uint8_t i;							//création d'une variable d'index locale à la fonction

	TWI_start();
	if (TWI_get_status()!= 0x08)		//Si condition Start non reconnue renvoie erreur : 0x08
		return 0x08;

	TWI_set(addr);
	if (TWI_get_status() != 0x18)		//Si condition set non reconnue renvoie erreur : 0x18
		return 0x18;

	TWI_set(reg);
	if (TWI_get_status() != 0x28)	//Si condition set non reconnue renvoie erreur : 0x18
		return 0x19;

	for(i=0; i < nb; i++)
	{
		TWI_set(*(write_data+i));
		if (TWI_get_status() != 0x28)	//Si condition set non reconnue renvoie erreur : 0x28
			return 0x28;
	}
	TWI_stop();
	return 0x00;						//renvoie le code 0x00 si la fonction TWI_print c'est executée sans soucis
}

uint8_t TWI_receive(uint8_t addr, uint8_t reg, uint8_t nb, uint8_t *read_data)	// Fonction d'écriture d'une donnée sur un pointeur, sur un périph, inclus dans un registre, sur un nombre de registres définis

{
	uint8_t i=0;						//création d'une variable d'index locale à la fonction

	TWI_start();
	if (TWI_get_status() != 0x08)		//Si condition Start non reconnue renvoie erreur : 0x08
		return 0x08;

	TWI_set(addr);
	if (TWI_get_status() != 0x18)		//Si condition set non reconnue renvoie erreur : 0x18
		return 0x18;

	TWI_set(reg);
	if(TWI_get_status() != 0x28)		//Si condition set non reconnue renvoie erreur : 0x28
		return 0x28;

	TWI_restart();
	if (TWI_get_status() != 0x10)		//si la condition repeted start non reconnue renvoie erreur : 0x10
		return 0x10;

	TWI_set(addr+1);

	if (TWI_get_status() != 0x40) 		//si la condition set non reconnue en mode master receiver renvoie erreur : 0x40
		return 0x40;

	for (i = 0; i < nb-1; i++)			//début boucle for d'index i initialisé à 0, qui va jusqu'au paramètre nb-1 pour finir sur le dernier par TWI_get_nack, et on l'incrémente
	{
		*(read_data+i) = TWI_get_ack();	//la valeur de l'adresse du pointeur read_data+i reçoit la valeur de registre de donnée (TWDR) à l'envoie d'un ACK
		if (TWI_get_status() != 0x50)	//si la condition de lecture de donnée non reconnue après un ACK, renvoie code erreur : 0x50
			return 0x50;
	}

	// le dernier octet à récupérer doit être sans acknowlegdment
	*(read_data+nb-1) = TWI_get_nack();		//la valeur de l'adresse du point read_data recoit la valeur du registre de donnée (TWDR) lorsqu'il n'y a pas d'ACK
		if (TWI_get_status() != 0x58)	//si la condition de lecture de donnée non reconnue après un NACK, renvoie code erreur : 0x58
		return 0x58;

	TWI_stop();

	return 0x00;						//la fonction TWI_receive renvoie la valeur 0xF0 quand la fonction s'est déroulé sans erreur
}
