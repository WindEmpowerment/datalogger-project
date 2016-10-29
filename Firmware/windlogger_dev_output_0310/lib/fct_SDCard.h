/*

 * fct_SDCard.h
 *
 *  Created on: 21 juin 2016
 *      Author: formateur
 */

#ifndef HEADERS_FCT_SDCARD_H_
#define HEADERS_FCT_SDCARD_H_


//Use following macro if you don't want to activate the multiple block access functions
//those functions are not required for FAT32

#define FAT_TESTING_ONLY	// a commenter pour desactiver les fonctions FAT32



// macros  SS (PG1) pin  Chip Select of SD actif a 0
#define SD_CS_ASSERT     PORTG &= ~0x02				/**mettre le 2em bit a 0 (cs)*/
#define SD_CS_DEASSERT   PORTG |= 0x02				/**mettre le 2em bit a 1 (cs)*/

//SD commands, many of these are not used here
#define GO_IDLE_STATE            0					/**logiciel reset*/
#define SEND_OP_COND             1					/**introduire le processus d'initialisation*/
#define SEND_IF_COND			 8					/**seulement Pour SDC V2. Vérifiez gamme de tension*/
#define SEND_CSD                 9					/**lire CSD(card specific data)register*/
#define STOP_TRANSMISSION        12					/**Stop la lécture data*/
#define SEND_STATUS              13					/**envoyer le statu*/
#define SET_BLOCK_LEN            16					/**Changez taille de bloc de R/W*/
#define READ_SINGLE_BLOCK        17					/**lire un block*/
#define READ_MULTIPLE_BLOCKS     18					/**lire un multi block*/
#define WRITE_SINGLE_BLOCK       24					/**écrire un block*/
#define WRITE_MULTIPLE_BLOCKS    25					/**écrire un multi block*/
#define ERASE_BLOCK_START_ADDR   32					/**effacer l'addresse du début du block*/
#define ERASE_BLOCK_END_ADDR     33					/**effacer l'addresse du fin du block*/
#define ERASE_SELECTED_BLOCKS    38					/**effacer le block séléctioner*/
#define SD_SEND_OP_COND			 41   //ACMD		/**seulement pr SDC. introduire le processus d'initialisation*/
#define APP_CMD					 55					/**---*/
#define READ_OCR				 58					/**lire OCR(operation condition register*/
#define CRC_ON_OFF               59					/**---*/


#define ON     1
#define OFF    0

volatile unsigned long startBlock, totalBlocks;
volatile unsigned char SDHC_flag, cardType, buffer[512];

/**
 * Fonction d'initialisation de la carte SD dans le mode SPI
 * @return	0 lorsque l'initialisation a réussie, 1 lorsque la carte est non détécter, 2 lorsque l'initialisation a échoué
 */
unsigned char SD_init(void);

/**
 * Fonction pour envoyé une commande a la carte SD
 * @param cmd	valeur de la commande sur 8bit
 * @param arg	paramétre de la commande sur 32bit
 * @return	reponse	l'état du bus SPI
 */
unsigned char SD_sendCommand(unsigned char cmd, unsigned long arg);

/**
 * Fonction pour lire un seul block de la carte SD
 * @param startBlock	le début du block
 * @return 0	si y'a pas d'erreur sur la lécture,	1	si le temps est écoulé, reponse 	autrement
 */
unsigned char SD_readSingleBlock(unsigned long startBlock);

/**
 * Fonction pour écrire un seul block
 * @param startBlock	le début du block
 * @return	 0	si y'a pas d'erreur sur l'écriture,	1	si le temps est écoulé, reponse 	autrement
 */
unsigned char SD_writeSingleBlock(unsigned long startBlock);

/**
 * Fonction pour effacer un nombre de block précisé de la carte SD
 * @param startBlock	le début du block
 * @param totalBlocks
 * @return
 */
unsigned char SD_erase (unsigned long startBlock, unsigned long totalBlocks);

//not implemented
//unsigned char SD_readMultipleBlock (unsigned long startBlock, unsigned long totalBlocks);
//unsigned char SD_writeMultipleBlock(unsigned long startBlock, unsigned long totalBlocks);


#endif /* HEADERS_FCT_SDCARD_H_ */
