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
void USART0_init(void);

/**
 *	USART0 char sender function
 * @param character The character to send on the USART0
 */
void USART0_set(char character);

/**
 * USART string sender function
 * @param string The string to send on the USART0
 */
void USART0_print(char *string);

unsigned char get_Arg(char *string);

void USART0_print_conf();


#endif /* DATALOGGER_TEST_SENSORS_HEADERS_USART_H_ */
