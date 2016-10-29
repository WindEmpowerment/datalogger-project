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
 * Fonction d'initialisation du Real Time Clock
 * @return	renvoi la valeur 0 si initialisation réussie
 */
uint8_t RTC_init();

/**
 * Fonction pour récupérer les informations date et heure du RTC dans le DS1307
 * @param _time pointeur d'une structure Time, dans lequel sera mis en forme la date et l'heure
 * @return renvoi la valeur 0 si récupération réussie, et 1 si defaut de TWI
 *
 * Utiliser une structure de type Time :
 * typedef struct Time
 *{
 *	unsigned int secondes;
 *	unsigned int minutes;
 *	unsigned int heures;
 *	char jour[5];
 *	unsigned int mois;
 *	unsigned int annee;
 *	unsigned int jsemaine;
 *}Time;
 *
 */
uint8_t RTC_get_date(Time * _time);

/**
 * Fonction d'update du RTC qui permet la mise à jour du DS1307 à partir d'une chaine de carac composé de la date et de l'heure
 * @param _datetime pointeur vers string = %u%e%m%y%H%M%S (format linux fonction : date +%u%e%m%y%H%M%S)
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
