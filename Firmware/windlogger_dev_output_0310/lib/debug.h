/**
 * @file   debug.h
 * @author gilou
 * @date   20 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef LIB_DEBUG_H_
#define LIB_DEBUG_H_

/**
 * Function to send message on usart0 to help on debug code
 * @param item String with the state name
 * @param msg The message
 * @param end Set to 1 print "\r\n" end line or set 0 to no change line
 */
void debug_print(char *item, char *msg, char end);

/**
 * Function to send in state double value
 * @param state	String with the state name
 * @param msg Normally variable name or explicit description
 * @param value double Value
 * @param end
 */
void debug_printd(char *state, char *msg, double value, char end);

/**
 * Function to send in state unsigned integer value (work with unsigned char too)
 * @param state String with the state name
 * @param msg Normally variable name or explicit description
 * @param value unsigned integer value
 * @param end
 */
void debug_printu(char *state, char *msg, unsigned int value, char end);

/**
 * Function to send in state unsigned long value
 * @param state String with the state name
 * @param msg Normally variable name or explicit description
 * @param value Unsigned long value
 * @param end
 */
void debug_printl(char *state, char *msg, uint32_t value, char end);



#endif /* LIB_DEBUG_H_ */
