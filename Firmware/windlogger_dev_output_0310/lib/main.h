/**
 * @file   main.h
 * @author gilou
 * @date   20 août 2016
 * @brief  Brief description of file.
 *
 * @version
 *
 * Detailed description of file.
 */
#ifndef LIB_MAIN_H_
#define LIB_MAIN_H_

#include <avr/io.h>
#include "../lib/FAT32.h"


#define DEBUG	/**< DEBUG keyword used to enter in verbose mode on the USART0, uncomment to verbose mode, comment to normal mode**/

char dataString[MAX_STRING_SIZE];

//variables
char data_udr0, data_udr1;				/** registre tempon pour enregistrer les caractére écrit sur l'UART*/
char config_request[10];				/** config_request string**/
//unsigned char pre_card ;				//normalement je n'ai pas besoin je la suprime
uint8_t config_request_i;				/** config_request indice**/
unsigned int  k ;						/** un compteur utilisé dans la procédure de génération de nom de fichier( pour incrémenter month et year)**/


//flags
uint8_t flag_next_state;				/**< flag set when timer1 interrupt come **/
uint8_t flag_config_request;			/**< flag set when the sentence from UART0 is config request **/
uint8_t flag_new_measure;				/**< flag set when new measure is coming **/
uint8_t flag_anemo_ok;					/**< flag set by the timer0 overflow interrupt */
uint8_t flag_USART0_read;				/** flag set when USART0 is read**/
uint8_t flag_USART1_read;				/** flag set when USART1 is read**/
uint8_t flag_new_sec;					/**	flag set when new second**/
uint8_t flag_timestamp;					/** flag set when time stamp**/
uint8_t flag_error;
uint8_t flag_reinit;					/** flag set apres SD_init pour ne pas la renvoyer tant que la carte est dans le lécteur et on écris toujours**/

/**
 * @brief The Time structure save date and time value
 */
typedef struct Time
{
	unsigned char secs;		//!< contain seconds number from last min
	unsigned char mins;		//!< Contain minutes number from last hour
	unsigned char hours;	//!< Contain hours number from last day
	char weekday[3];		//!< Contain the weekday short name
	unsigned char day;		//!< Contain day number from the last month
	unsigned char month;	//!< Contain month number from the last year
	unsigned char year;		//!< Contain year's counter
	uint32_t timestamp;		//!< Contain date/time in epoch format
} Time;
Time time, *ptrTime;

/**
 *
 */
typedef struct Measure
{
	double 	speed1;
	double 	speed2;
	int 	degree;
	double	acPower;
	double	ACvoltage[100];		// for test
	double	ACcurrent[100];		// for test
	double 	dcPower;
	double 	temp;
	double 	rpm;
} Measure;

/**
 * The Logger structure save configuration for the logger
 */
typedef struct Logger
{
	uint8_t		to_cent;		/**< to have 100 timer5 interrupt to have 1s*/
	uint8_t		next_state;		/**< The next step to do */
	uint16_t	second_count;	/**< second counter use by the measure frequency management */
	uint8_t 	meas_conf;		/**< Choose the config frequency between 3sec, 10sec, 1min or 10min average measurement */
	uint8_t		meas_count;		/**< To count the number of measure */
	uint8_t		meas_max;		/**< the number of measure for the average */
	uint8_t		meas_stamp;		/**< Period between two measure cycle */
	Measure		measureAverage;	/**< were all measures average are stored */
	float		anemo1_factor;
	float		anemo1_offset;
	float		anemo2_factor;
	float		anemo2_offset;
	float		degree_factor;
	float		degree_offset;
	float		temp_factor;
	float		temp_offset;
	float		ac_voltage_offset;
	float		ac_current_offset;
	uint8_t		output_enable;		/**< Use to select witch outup is enable */
	//char 		output_string[100]; // s'est remplacer par dataString[MAX_STRING_SIZE]
	char  		forme_filename[13];	/** registre temporaire pour construire le nom de fichier**/
	char 		filename[13];		/** nom de fichier a écrire sur la carte**/
	char 		tmp_filename[13];	/** registre temporaire pour copier le nom de fichier **/
}Logger;

Logger 	logger,		/**< stuct with parameters for the main work */
		*ptrLogger;	/**< Pointer on the legger member */


#endif /* LIB_MAIN_H_ */
