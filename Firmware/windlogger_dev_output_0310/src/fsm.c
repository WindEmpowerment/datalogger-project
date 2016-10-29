/**
 * @file   fsm.c
 * @author gilou
 * @date   28 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#include "../lib/main.h"
#include "../lib/fsm.h"
#include "../lib/usart.h"
#include "../lib/debug.h"
#include "../lib/sensors.h"
#include "../lib/config.h"
#include "../lib/FAT32.h"
#include "../lib/fct_rs232.h"
#include "../lib/fct_SDCard.h"
#include "../lib/time.h"


/**
 * function pointer array, use to call the new state
 *
 *\dot
digraph finite_state_machine {
	rankdir=LR;
	size="10,10"
	node [shape = point]start;
	node [shape = doublecircle]; IDLE;
	node [shape = circle];
	start -> IDLE			[ label = "Start" ];
	IDLE -> CONFIG			[label = "flag_config_request"];
	IDLE -> MEASURE			[label = "flag_new_measure"];
	IDLE -> SLEEP			[label = "else"];
	SLEEP -> CONFIG			[label = "flag_config_request"];
	SLEEP -> MEASURE		[label = "flag_new_measure or flag_anemo_ok"];
	SLEEP -> SLEEP			[label = "else"];
	OUTPUT -> CONFIG		[label = "flag_config_request"];
	OUTPUT -> MEASURE		[label = "flag_new_measure"];
	OUTPUT -> SLEEP			[label = "else"];
	TIMESTAMP -> CONFIG 	[label = "flag_config_request"];
	TIMESTAMP -> OUTPUT 	[label = "else"];
	MEASURE -> MEASURE		[label = "flag_anemo_ok"];
	MEASURE -> CONFIG		[label = "flag_config_request"];
	MEASURE -> TIMESTAMP	[label = "flag_timestamp"];
	MEASURE -> SLEEP		[label = "else"];
	CONFIG -> SLEEP			[label = "else"];;
}
\enddot
 */
void (*StateList[8])(void) = {
		state_config,
		state_measure,
		state_timestamp,
		state_output,
		state_sleep,
		state_idle
};

/**
 *
 */
void state_config(void)
{
	if(strcmp(config_request,"$$")==0)
	{
		USART0_print_conf();
	}
	else if (config_request[0]=='$' && config_request[3]=='=')
	{
		config_update(config_request);
	}
	else {
		txString(_COM1,"Not a request !\r\n");
	}

	config_request_i = 0;
	config_request[config_request_i] = '\0';

#ifdef DEBUG_FSM
	debug_print("state_config", "enter in state",1);
#endif

	flag_config_request = 0;
	//exit case
	logger.next_state=STATE_SLEEP;
}

void state_measure(void)
{
	if(flag_new_measure==1)	/// Start frequencies measurement, stop with timer0 overflow
	{
		// init timers frequencies measurement
		anemo_start_count();

		// clear measure struct
		if(ptrLogger->meas_count==0) measure_clear(&(ptrLogger->measureAverage));

		//
		/**
		 * @todo if en, measure dir, PowerAC, PowerDC, temp, RPM
		 * @todo add x/meas in measure struct
		 */
		ptrLogger->measureAverage.degree = ptrTime->timestamp;
		ptrLogger->measureAverage.temp = ptrTime->timestamp;

		ptrLogger->measureAverage.acPower = ptrTime->timestamp;
		ptrLogger->measureAverage.dcPower = ptrTime->timestamp;

		ptrLogger->measureAverage.rpm = ptrTime->timestamp;

		ptrLogger->measureAverage.speed1 = ptrTime->timestamp;
		ptrLogger->measureAverage.speed2 = ptrTime->timestamp;

		ptrLogger->meas_count++;
		if(ptrLogger->meas_count == ptrLogger->meas_max)
		{
			ptrLogger->meas_count = 0; // remise à zéro du compteur de mesure
			flag_timestamp = 1;			// go to timestamp and output
		}

		flag_new_measure = 0;


#ifdef DEBUG_MEASURE
		RTC_get_date(ptrTime);
		debug_printl("measure", "time",ptrTime->timestamp,1);
		debug_printu("measure", "meas_count",ptrLogger->meas_count,1);
		debug_printd("measure", "degree",ptrLogger->measureAverage.degree,1);
		debug_printd("measure", "temp", ptrLogger->measureAverage.temp,1);
#endif
	}// end if(flag_new_measure==1)

	//exit case
	if(flag_config_request) logger.next_state = STATE_CONFIG;
	if(flag_anemo_ok==1) logger.next_state = STATE_MEASURE;
	if(flag_timestamp==1) logger.next_state = STATE_TIMESTAMP;
	else logger.next_state = STATE_SLEEP;
}

void state_timestamp(void)
{
	//program code
#ifdef DEBUG_FSM
	debug_print("state_timestamp", "enter in state",1);
#endif
	ptrTime->timestamp++;

	flag_timestamp = 0;

	//exit case
	if(flag_config_request) logger.next_state = STATE_CONFIG;
	else logger.next_state = STATE_OUTPUT;
}

void state_output(void)
{
	// function to debug, comment DEBUG_OUTPUT in fsm.h to disable
#ifdef DEBUG_OUTPUT

	txString(_COM1,"\r\n");
	debug_printl("output","timestamp" , ptrTime->timestamp,1);
	debug_printd("output", "speed1", ptrLogger->measureAverage.speed1,1);
	debug_printd("output", "speed2", ptrLogger->measureAverage.speed2,1);
	debug_printd("output","degree",ptrLogger->measureAverage.degree,1);
	debug_printd("output","temp",ptrLogger->measureAverage.temp,1);
	debug_printd("output","ac power",ptrLogger->measureAverage.acPower,1);
	debug_printd("output","dc power",ptrLogger->measureAverage.dcPower,1);
	debug_printd("output","rpm",ptrLogger->measureAverage.rpm,1);
	txString(_COM1,"\r\n");
#endif
	// ----------------------------INSERER CODE OUTPUT ICI-----------------------------------------//

	// output_enable registre pour savoir quelles sorties utiliser
	/**
	 * Register to choose witch output are enable
	 * output_enable : 	1 USARTO only
	 * 					2 USART0 + SD card
	 * 					3 USART0 + GPRS
	 */


	//mettre en forme la chaine de caractére avec toute les donner a écrire
	trans_to_string();								/**pour transformé les data de sortie en chaine de caractére*/
	// écrire sur l'USART0
	if(ptrLogger->output_enable==1){				/**si uart0 only séléctionné on écrit la chaine de caractére juste sur l'uart*/
		txString(_COM1,dataString);
		txString(_COM1,"\r\n");
	}

	// écrire sur la carte sd
	if(ptrLogger->output_enable==2){				/**si uart0+sd card séléctionné on écrit sur les deux*/

		txString(_COM1,dataString);					/**ecrire sur l'UART a chaque fois*/


		if	((PING & 0x04)==0){						/**si PG2 = 0 => la carte SD est dans le lécteur*/
			if(flag_reinit == 0){								/** envoyer un init de la carte si elle est remise dans le lécteur*/
				//SDCard init
				SD_init();
				// OUVERTURE DE LA PARTITION
				getBootSectorData();				/** envoyer cette fonction pour l'identification du péripherique ( a faire toujours apres l'init de SD)*/
				init_FSM();
				sei();
				flag_reinit = 1;								/** set flag_reinit*/
			}
		char j=0;

			strcpy(ptrLogger->tmp_filename, ptrLogger->filename) ;		/**copier le nom de fichier dans le registre temporaire*/

			j = readFile(VERIFY, ptrLogger->tmp_filename);				/**vérifier si le fichier éxiste*/

			strcpy(ptrLogger->tmp_filename, ptrLogger->filename) ;		/**copier le nom de fichier dans le registre temporaire*/

			if(j==0){													/**si le fichier n'éxiste pas*/
				strcpy(dataString, "timestamp,speed1,speed2,degree,temp,acPower,dcPower,rpm\n") ; /**init datastring avec cette chaine de caractére*/
				writeFile(ptrLogger->tmp_filename);													/** construire le fichier avec l'entête au début*/
				trans_to_string();																	/** recopier les donner pr les envoyé*/
			}

			strcpy(ptrLogger->tmp_filename, ptrLogger->filename) ;		/**copier le nom de fichier dans le registre temporaire*/

			writeFile(ptrLogger->tmp_filename);

		}
		else {															/**si PG2 = 1 => la carte SD est hors lécteur*/

				txString(_COM1,"\rpas de carte sd, insérez une dans le lécteur\n\r");
				flag_reinit = 0;										/**rénitialiser i a la sortie de cette boucle pour lancé l'init si PG2 change*/

			}


	}


	// écrire sur gprs

	//si output_enable = 3


	// --------------------------------- FIN CODE OUTPUT --------------------------------------------//
#ifdef DEBUG_FSM
	debug_print("state_output", "enter in state",1);
#endif

	//exit case
	if(flag_config_request) logger.next_state = STATE_CONFIG;
	else if (flag_new_measure) logger.next_state = STATE_MEASURE;
	else logger.next_state = STATE_SLEEP;
}

void state_sleep(void)
{
	//program code
#ifdef DEBUG_FSM
	debug_print("state_sleep", "enter in state",1);
#endif

	//exit case
		if(flag_config_request) logger.next_state = STATE_CONFIG;
		else if (flag_new_measure==1||flag_anemo_ok==1) logger.next_state = STATE_MEASURE;
		else logger.next_state = STATE_SLEEP;
}

void state_idle(void)
{
	//program code
#ifdef DEBUG_FSM
	debug_print("state_idle", "enter in state",1);
#endif


	//exit case
		if(flag_config_request) logger.next_state = STATE_CONFIG;
		else if (flag_new_measure) logger.next_state = STATE_MEASURE;
		else logger.next_state = STATE_SLEEP;
}
