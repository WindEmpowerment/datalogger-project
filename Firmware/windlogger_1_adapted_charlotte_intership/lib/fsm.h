/**
 * @file   fsm.h
 * @author gilou
 * @date   28 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef LIB_FSM_H_
#define LIB_FSM_H_

//#define DEBUG_FSM	/**< use to debug the fsm lib*/
//#define DEBUG_MEASURE	/**< use to debug the measurement process*/

// state definition for bit selection in config registers
#define  STATE_CONFIG 0;	/**< State config constant definition */
#define STATE_MEASURE 1;	/**< State measure constant definition */
#define STATE_TIMESTAMP 2;	/**< State timestamp constant definition */
#define  STATE_OUTPUT 3;	/**< State output constant definition */
#define  STATE_SLEEP 4;	/**< State sleep constant definition */
#define  STATE_IDLE 5;	/**< State idle constant definition */

/**
 * function pointer array definition
 */
void (*StateList[8])(void);

void state_config(void);	/**< The config state permit to config the differents parameters */
void state_measure(void);	/**< The measure state do each measure process */
void state_timestamp(void);	/**< The timestamp state build the present timestamp value */
void state_output(void);	/**< The output state, use spi to write data on sd card or send data on lan or use uart to send on usb, wifi or gprs */
void state_sleep(void);		/**< The sleep state is to reduce power consummation */
void state_idle(void);		/**< Is a wait state */


#endif /* LIB_FSM_H_ */
