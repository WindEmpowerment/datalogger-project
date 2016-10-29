/**
 * @file   main.c
 * @author gilou
 * @date   20 août 2016
 * @brief  Brief This is the main file program
 *
 * Detailed description of file.
 */

#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#include "../lib/main.h"
#include "../lib/eeprom_manage.h"
#include "../lib/time.h"
#include "../lib/usart.h"
#include "../lib/fsm.h"
#include "../lib/debug.h"
#include "../lib/sensors.h"
#include "../lib/config.h"
#include "../lib/FAT32.h"
#include "../lib/fct_rs232.h"
#include "../lib/fct_SDCard.h"



int main()
{
	// FSM initialization
	ptrLogger = &logger;
	ptrLogger->to_cent = 0;
	ptrLogger->next_state = STATE_IDLE;
	ptrLogger->second_count = 0;
	ptrLogger->meas_count = 0;
	ptrLogger->output_enable = 1;	// 1: USART0 only, 2: USART0 + SD card, 3:USART0 + GPRS
	ee_read_logger(ptrLogger);
	measure_clear(&(ptrLogger->measureAverage));
	ptrTime = &time;

	// flags init
	flag_next_state = 0;
	flag_config_request = 0;
	flag_new_measure = 0;
	flag_anemo_ok = 0;
	flag_new_sec = 0;
	flag_timestamp = 0;
	flag_USART0_read =  0;
	//flag_USART1_read =  0;
	flag_error = 0;
	flag_reinit = 0 ;

	//ee_erase_logger();

	// I/O initialisation
	DDRC = 0xFF;					/** initialiser le portD comme sortie**/
	PORTC = 0x00;					/** mettre les pins du portC a 0**/
	DDRG = 0x02;					/** PG1 CS SD Card Out, PG2 SC Card detect In**/
	DDRB = 0xF7;					/** MISO PB3 In; / SCK PB1, MOSI PB2 out**/



	// variable initialisation
	data_udr0 = 0;
	//data_udr1 = 0; 		a utilisé apres pour le GPRS
	config_request_i = 0;
	cardType=0;
	k = 0 ;

	//RS232 init
	openRS232(_COM1,B57600,PN,D8,STP2,EnIT);

	init_FSM();

	sei();


#ifdef DEBUG
	debug_print("wake up:","v0.5.0 fsm,rtc,measure process,config : ok, dev output\r\n",1);
#endif

	// PREPARATION NOM DE FICHIER CARTE SD
		ptrTime->month = 12;										/**init mois*/
		ptrTime->year = 16;											/**init année*/
		build_filename();											/**construire le nom de fichier dans le registre forme_filename*/
		strcpy(ptrLogger->filename, ptrLogger->forme_filename);		/** copier forme_filename dans filename*/


	while(1)
	{
		// PROCEDURE POUR TESTER LA PREP DU NOM DE FICHIER EN TEMPS DINAMIQUE (juste pour le test)
		if(k==4700){												/** car je veux 4500 écriture sur la carte( dans 1 mois on a 4464 écriture au max sur la carte si on ecrit chaque 10min)*/
				ptrTime->month++;									/**incrémenter le mois*/
				if(ptrTime->month > 12){
					ptrTime->year++;								/**incrémenter l'année apres 12 mois*/
					ptrTime->month = 1;								/**remettre mois a 1*/
				}
				build_filename();									/**construire le nom de fichier dans forme_filename partir de month et year**/
				strcpy(ptrLogger->filename, ptrLogger->forme_filename);		/** copier forme_filename dans filename**/
				k = 0;
		}
		//fin de procédure de test

		if(ptrLogger->to_cent>=100)
		{
			PORTC^=PORTC;
			flag_new_sec = 1;
			ptrLogger->to_cent = 0;
		}

		if(flag_next_state==1)
		{
			(*StateList[logger.next_state])();
			flag_next_state = 0;
		}

		if(flag_USART0_read==1)									/**< if new char ready */
		{
			config_request[config_request_i] = data_udr0;		/**< save the char in the config_request string */
			txchar(_COM1, config_request[config_request_i]);	/**< do a echo to print on the serial terminal */
			config_request_i++;									/**< increment index : config_request_i++ */

			if (data_udr0 == 0x08)								/**< if char is backspace */
			{
				config_request_i = config_request_i-2;			/**< move on left */
			}
			else if(data_udr0=='\r')							/**< if char is end line */
			{
				txString(_COM1,"\r\n");							/**< print carriage return and new line on the serial termial */

				config_request[config_request_i-1] = '\0';		/**< put end string in config_request */

				flag_config_request = 1;						/**< set flag to go in conf mode to do config update */
			}

			flag_USART0_read=0;									/**< reset the flag */
		}

		/**
		 * at each second, up the second_count
		 * and if it's egal to time to do a new measure:
		 * set the flag and clear the counter
		 */
		if(flag_new_sec==1)
		{
			ptrLogger->second_count++;
			if(ptrLogger->second_count==ptrLogger->meas_stamp)
			{
				flag_new_measure=1;
				ptrLogger->second_count=0;
				k++;											/**incrémenter le compteur de test que j'ai mis dans la procédure de génération de nom de fichier*/
			}
			flag_new_sec=0;
		}

	}

	return 0;
}
