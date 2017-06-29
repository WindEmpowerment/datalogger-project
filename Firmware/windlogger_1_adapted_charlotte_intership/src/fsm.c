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
#include "../lib/time.h"
#include "../lib/fsm.h"
#include "../lib/usart.h"
#include "../lib/debug.h"
#include "../lib/pcf8563.h"
#include "../lib/sensors.h"
#include "../lib/config.h"
#include "../lib/fct_SDCard.h"
#include "../lib/fct_spi.h"
#include "../lib/FAT32.h"
//#include "../lib/emonLib.h"

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
		USART0_print("Not a request !\r\n");
	}

	config_request_i = 0;
	config_request[config_request_i] = '\0';

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
		if(logger.meas_count==0) measure_clear(&(logger.measureAverage));

		//
		/**
		 * @todo if en, measure dir, PowerAC, PowerDC, temp, RPM
		 * @todo add x/meas in measure struct
		 */
		dir_value(&(logger.measureAverage));
		flag_new_measure = 0;

#ifdef DEBUG_MEASURE
		RTC_get_date(ptrTime);
		debug_printl("measure", "time",ptrTime->timestamp,1);
		debug_printu("measure", "meas_count",logger.meas_count,1);
		debug_printd("measure", "degree",logger.measureAverage.degree,1);
		debug_printd("measure", "temp", logger.measureAverage.temp,1);
#endif
	}// end if(flag_new_measure==1)

	if(flag_anemo_ok==1)
	{
		flag_anemo_ok=0;
		anemo_read_value(&(logger.measureAverage));
		logger.meas_count++;
		if(logger.meas_count == logger.meas_max)
		{
			logger.meas_count = 0; // Measure counting reset

			//if(flag_pass_first_measure == 1)
			//{
				//flag_pass_first_measure = 0;
				//skip the fisrt burst of data and wait the next
			//}
			//else flag_timestamp = 1;			// go to timestamp and output
			flag_timestamp = 1;			// go to timestamp and output
		}

#ifdef DEBUG_MEASURE
	RTC_get_date(ptrTime);
	debug_printl("measure", "read anemos values",ptrTime->timestamp,1);
#endif
	}

	//exit case
	if(flag_config_request) logger.next_state = STATE_CONFIG;
	if(flag_anemo_ok==1) logger.next_state = STATE_MEASURE;
	if(flag_timestamp==1) {
		logger.next_state = STATE_TIMESTAMP;
	}
	else logger.next_state = STATE_SLEEP;
}

void state_timestamp(void)
{
	//program code
	//RTC_get_date(ptrTime);

	flag_timestamp = 0;

	//exit case
	if(flag_config_request) {
		logger.next_state = STATE_CONFIG;
	}
	else logger.next_state = STATE_OUTPUT;
}

void state_output(void)
{
#ifdef DEBUG_MEASURE
	debug_printl("output","timestamp",timestamp,1); // change by global timestamp
	debug_printd("output", "speed1", logger.measureAverage.speed1,1);
	//debug_printd("output", "speed2", logger.measureAverage.speed2,1);
	debug_printd("output","degree",logger.measureAverage.degree,1);
	//debug_printd("output","temp",logger.measureAverage.temp,1);*/
#endif
	char tmp_char[12];

	// output_config    => outputs configuration register
	// formatting the output string ( for example timestamp data1 data2\r\n")
		// écrire sur l'uart0 usart0_print
		strcpy(dataString,itoa(logger.node,tmp_char,10));	// node number
		strcat(dataString," ");
		strcat(dataString,ltoa(timestamp, tmp_char, 10));	// timestamp
		strcat(dataString," ");
		strcat(dataString,dtostrf(logger.measureAverage.speed1, 0, 1, tmp_char));	// speed1
		strcat(dataString,"m/s  ");
		strcat(dataString,itoa(logger.measureAverage.degree,tmp_char,10));	// degree
		strcat(dataString,"degrees ");
		strcat(dataString,"\r\n");														// close the string

		USART0_print(dataString);
		// write on the sd card
		if	((PORTC & 0x08)==0x00){						/**si PG2 = 0 => la carte SD est dans le lécteur*/
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

					strcpy(logger.tmp_filename, logger.filename) ;		/**copier le nom de fichier dans le registre temporaire*/

					j = readFile(VERIFY, logger.tmp_filename);				/**vérifier si le fichier éxiste*/

					strcpy(logger.tmp_filename, logger.filename) ;		/**copier le nom de fichier dans le registre temporaire*/

					if(j==0){													/**si le fichier n'éxiste pas*/
						strcpy(dataString, "timestamp,speed1,degree\n") ; /**init datastring avec cette chaine de caractére*/
						writeFile(logger.tmp_filename);													/** construire le fichier avec l'entête au début*/
															/** recopier les donner pr les envoyé*/
					}

					strcpy(logger.tmp_filename, logger.filename) ;		/**copier le nom de fichier dans le registre temporaire*/
					writeFile(logger.tmp_filename);
				}
				else {															/**si PG2 = 1 => la carte SD est hors lécteur*/

						USART0_print("\rpas de carte sd, insérez une dans le lécteur\n\r");
						flag_reinit = 0;										/**rénitialiser i a la sortie de cette boucle pour lancé l'init si PG2 change*/
					}

		// send on gprs

	//exit case
	if(flag_config_request) {
		logger.next_state = STATE_CONFIG;
	}
	else if (flag_new_measure){
		logger.next_state = STATE_MEASURE;
	}
	else logger.next_state = STATE_SLEEP;
}

void state_sleep(void)
{
	//program code

	//exit case
		if(flag_config_request) {
			logger.next_state = STATE_CONFIG;
		}
		else if (flag_new_measure==1||flag_anemo_ok==1){
			logger.next_state = STATE_MEASURE;
		}
		else logger.next_state = STATE_SLEEP;
}

void state_idle(void)
{
	//program code

	//exit case
		if(flag_config_request) {
			logger.next_state = STATE_CONFIG;
		}
		else if (flag_new_measure) {
			logger.next_state = STATE_MEASURE;
		}
		else logger.next_state = STATE_SLEEP;
}
