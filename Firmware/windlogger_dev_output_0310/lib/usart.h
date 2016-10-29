/**
 * @file   usart.h
 * @author gilou
 * @date   15 juil. 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef DATALOGGER_TEST_SENSORS_HEADERS_USART_H_
#define DATALOGGER_TEST_SENSORS_HEADERS_USART_H_

/**
 *	USART0 initialization function on asynchronous mode
 */
//void USART0_init(void);

/**
 *	USART0 char sender function
 * @param character The character to send on the USART0
 */
//void USART0_set(char character);

/**
 * USART string sender function
 * @param string The string to send on the USART0
 */
//void USART0_print(char *string);

unsigned char get_Arg(char *string);

/**
 * fonction pour afficher le menu de configuration
 */
void USART0_print_conf();

/**
 * Fonction pour transformé la data en chaine de caractére
 */
void trans_to_string(void);

/**
 * Fonction pour construire le nom de fichier a base des valeurs de month et year
 */

void build_filename(void);

#endif /* DATALOGGER_TEST_SENSORS_HEADERS_USART_H_ */
