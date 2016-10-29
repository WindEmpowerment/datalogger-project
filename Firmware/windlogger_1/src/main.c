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
#include <util/delay.h>
#include <stdlib.h>

#include "../lib/main.h"
#include "../lib/eeprom_manage.h"
#include "../lib/time.h"
#include "../lib/usart.h"
#include "../lib/fsm.h"
#include "../lib/debug.h"
#include "../lib/pcf8563.h"
#include "../lib/sensors.h"
#include "../lib/config.h"
#include "../lib/emonLib.h"


int main()
{
	// init port
	DDRL = 0x00;

	/// FSM initialization
	logger.to_cent = 0;
	logger.old_state = STATE_IDLE;
	logger.next_state = STATE_IDLE;
	logger.second_count = 0;
	logger.meas_count = 0;
	logger.millis = 0;
	logger.node = 3;
	ee_read_logger();
	measure_clear(&(logger.measureAverage));
	ptrTime = &time;

	// flags init
	flag_next_state = 0;
	flag_config_request = 0;
	flag_new_measure = 0;
	flag_anemo_ok = 0;
	flag_new_sec = 0;
	flag_timestamp = 0;
	flag_USART0_read =  0;
	flag_error = 0;
	flag_pass_first_measure = 1;	// don't send the first measures at wake up.

	// constant timestamp au 01/01/2016 à 00:00:00 :1451599200
	epoch_010116.secs=0;
	epoch_010116.mins=0;
	epoch_010116.hours=0;
	epoch_010116.day=1;
	epoch_010116.month=1;
	epoch_010116.year=15;
	epoch_010116.timestamp=1420070400;



	//ee_erase_logger();

	RTC_init();

	// variable initialisation
	data_udr0 = 0;
	flag_USART0_read = 0;
	config_request_i = 0;

	/// Choose USART0 baud rate (BR_57600 or BR_115200)
	usart0_baudrate = BR_9600;
	USART0_init();

#ifdef DEBUG
	debug_print("wake up:","v0.5 fsm,rtc,measure and config process : ok\r\n",1);
#endif

	init_FSM();

	sei();
	uint8_t i=0;
	for(i=0;i<10;i++)
	{
		calcVI(8,900);
	}


	while(1)
	{

		if(logger.to_cent==100)
		{
			flag_new_sec = 1;
			logger.to_cent = 0;
		}

		if(flag_next_state==1)
		{
			(*StateList[logger.next_state])();
			flag_next_state = 0;
#ifdef DEBUG_FSM
			if(logger.next_state!=logger.old_state) debug_printu("new state", "=",logger.next_state,1);
#endif
		logger.old_state = logger.next_state;
		}

		if(flag_USART0_read==1)								/**< if new char ready */
		{
			config_request[config_request_i] = data_udr0;	/**< save the char in the config_request string */
			USART0_set(config_request[config_request_i]);	/**< do a echo to print on the serial terminal */
			config_request_i++;								/**< increment index : config_request_i++ */

			if (data_udr0 == 0x08)							/**< if char is backspace */
			{
				config_request_i = config_request_i-2;		/**< move on left */
			}
			else if(data_udr0=='\r')						/**< if char is end line */
			{
				USART0_print("\r\n");						/**< print carriage return and new line on the serial termial */

				config_request[config_request_i-1] = '\0';	/**< put end string in config_request */

				flag_config_request = 1;					/**< set flag to go in conf mode to do config update */
			}

			flag_USART0_read=0;								/**< reset the flag */
		}

		/**
		 * at each second, up the second_count
		 * and if it's egal to time to do a new measure:
		 * set the flag and clear the counter
		 */
		if(flag_new_sec==1)
		{
			logger.second_count++;
			//debug_printu("main","sec counter",logger->second_count++,1);
			if(logger.meas_conf!=0)
			{
				if(logger.second_count==logger.meas_stamp)
				{
					//USART0_print("new_meas");
					flag_new_measure=1;
					logger.second_count=0;
				}
			}

			flag_new_sec=0;
		}
	}

	return 0;
}
