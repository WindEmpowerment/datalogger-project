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

//#define DEBUG	/**< DEBUG keyword used to enter in verbose mode on the USART0, uncomment to verbose mode, comment to normal mode**/

#define BR_9600		207
#define BR_57600	34	/**< UBBRn registers value to work at 57600 baud**/
#define BR_115200	16	/**< UBBRn registers value to work at 115200 baud**/

//variables
uint16_t usart0_baudrate;	/**< Variable to choose the baud rate speed, use the BR_57600 or BR_115200 macros */
char data_udr0;
char config_request[10];
uint8_t config_request_i;


//flags
uint8_t flag_next_state;				/**< flag set when timer1 interrupt come **/
uint8_t flag_config_request;			/**< flag set when the sentence from UART0 is config request **/
uint8_t flag_new_measure;				/**< flag set when new measure is coming **/
uint8_t flag_anemo_ok;					/**< flag set by the timer0 overflow interrupt */
uint8_t flag_USART0_read;
uint8_t flag_new_sec;
uint8_t flag_timestamp;
uint8_t flag_error;
uint8_t flag_pass_first_measure;

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
	double	count_speed1;
	double 	speed1;
	double 	speed2;
	int 	degree;
	double 	realPower;
	double	apparentPower;
	double	Vrms;
	double	Irms;
	double	powerFactor;
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
	uint8_t		old_state;
	uint16_t	second_count;	/**< second counter use by the measure frequency management */
	uint16_t	millis;			/**< millisecond counter up by the timer2 */
	uint8_t 	meas_conf;		/**< Choose the config frequency between 1:10sec, 2:1min or 3:10min average measurement */
	uint8_t		meas_count;		/**< To count the number of measure */
	uint8_t		meas_max;		/**< the number of measure for the average */
	uint8_t		meas_stamp;		/**< Period between two measure cycle */
	Measure		measureAverage;	/**< were all measures average are stored */
	double		anemo1_factor;
	double		anemo1_offset;
	double		anemo2_factor;
	double		anemo2_offset;
	double		degree_factor;
	uint16_t	degree_offset;
	double		temp_factor;
	double		temp_offset;
	double		ac_voltage_offset;
	double		ac_current_offset;
	unsigned int inPinV;//Set AC Voltage pin
	unsigned int inPinI;// set ac current pin
	//Calibration coefficients
	//These need to be set in order to obtain accurate results
	double 		VCAL;
	double 		ICAL;
	double 		PHASECAL;
	uint8_t		node;
}Logger;

Logger 	logger;		/**< stuct with parameters for the main work */


#endif /* LIB_MAIN_H_ */
