/**
 * @file   pcf8563.h
 * @author gilou
 * @date   3 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef HEADERS_LIB_PCF8563_H_
#define HEADERS_LIB_PCF8563_H_

//#define DEBUG_RTC	/**< Use to debug the pcf8563 lib*/

#define SECS	0x02	/**< pcf8563 seconds register adress */
#define MINS	0x03	/**< pcf8563 minutes register adress */
#define HOURS	0x04	/**< pcf8563 hours register adress */
#define DAY		0x05	/**< pcf8563 day register adress */
#define WEEKDAY	0x06	/**< pcf8563 weekday register adress */
#define MONTH	0x07	/**< pcf8563 month register adress */
#define YEAR	0x08	/**< pcf8563 year register adress */

/**
 * Init function for the Real Time Clock
 * @return	return 0 if the init function is successfully executed
 */
uint8_t RTC_init();

/**
 * Function to take the date, time of the RTC in the DS1307
 * @param _time pointer of a Time structure in which date and time will be formatted
 * @return return 0 if the operation is a success, 1 if error from TWI
 *
 * Use a structure like Time :
 * typedef struct Time
 *{
 *	unsigned int seconds;
 *	unsigned int minutes;
 *	unsigned int hourss;
 *	char day[5];
 *	unsigned int mounth;
 *	unsigned int year;
 *	unsigned int weekday;
 *}Time;
 *
 */
uint8_t RTC_get_date(Time * _time);

/**
 *RTC's update function to allow the update of the DS1307 based on a characters string composed of the date and time
 * @param _datetime pointer to string = %u%e%m%y%H%M%S (format linux function : date +%u%e%m%y%H%M%S)
 * @return	error...
 */
uint8_t RTC_update (char *_datetime);

/**
 * Function to update a register in the pcf8563
 * @param reg	register adress
 * @param data	byte data
 */
void RTC_update_reg(uint8_t reg, uint8_t data);


Time epoch_010116;	/**< Used to do simple the timestamp calc */

#endif /* HEADERS_LIB_PCF8563_H_ */
