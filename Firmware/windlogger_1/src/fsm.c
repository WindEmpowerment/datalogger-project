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

#include "../lib/main.h"
#include "../lib/fsm.h"
#include "../lib/usart.h"
#include "../lib/debug.h"
#include "../lib/pcf8563.h"
#include "../lib/sensors.h"
#include "../lib/config.h"
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
		//temp_value(&(logger.measureAverage));

		//calcVI(8,900);
		//serialprint();


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
			logger.meas_count = 0; // remise à zéro du compteur de mesure

			//if(flag_pass_first_measure==1)
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
	debug_printd("output", "speed2", logger.measureAverage.speed2,1);
	debug_printd("output","degree",logger.measureAverage.degree,1);
	debug_printd("output","temp",logger.measureAverage.temp,1);
#endif
	char tmp_char[12];

	// output_config registre de configuration des sorties
		// si == 0 pas de sortie
		// si ==1 juste sur uart0
		// si == 2 uart0 + sd
		// si ==3 uart0 + gprs

	// mettre en forme la chaine de caractère de sortie ( du type timestamp data1 data2\r\n")
		char output_string[50];
		// écrire sur l'uart0 usart0_print
		strcpy(output_string,itoa(logger.node,tmp_char,10));	// node number
		strcat(output_string," ");
		strcat(output_string,ltoa(timestamp, tmp_char, 10));	// timestamp
		strcat(output_string," ");
		strcat(output_string,dtostrf(logger.measureAverage.speed1, 0, 1, tmp_char));	// speed1
		strcat(output_string," ");
		strcat(output_string,itoa(logger.measureAverage.degree,tmp_char,10));	// degree
//		strcat(output_string," ");
//		strcat(output_string,dtostrf(logger.measureAverage.temp, 0, 1, tmp_char));	// temperature
		strcat(output_string," ");
		strcat(output_string,dtostrf(logger.measureAverage.apparentPower, 0, 0, tmp_char));
		strcat(output_string," ");
		strcat(output_string,dtostrf(logger.measureAverage.realPower, 0, 0, tmp_char));// realpower
		strcat(output_string,"\r\n");														// close the string

		USART0_print(output_string);
		// écrire sur la carte sd

		// envoi sur gprs

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
