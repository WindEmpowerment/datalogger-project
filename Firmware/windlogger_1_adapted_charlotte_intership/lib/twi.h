/**
 * @file   twi.h
 * @author gilou
 * @date   3 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef HEADERS_LIB_TWI_H_
#define HEADERS_LIB_TWI_H_

//#define DEBUG_TWI	/**< use to debug the twi lib*/

// Init function for the TWI protocol
// Return : unsigned char = return 0 if initialisation is a success
// Parameter 1 : void
unsigned char TWI_init(void);

uint8_t TWI_set_char(uint8_t addr,uint8_t reg, uint8_t data);

uint8_t TWI_get_char(uint8_t addr, uint8_t reg);


// Function to write a data on the fly, on a periph, included in a register on a defined number of registers
// Return : unsigned char = the function returns an error code corresponding to the sub function concerned (cf:datasheet Atmega 128)
// Parameter 1 : unsigned char = periph address
// Parameter 2 : unsigned char = register address
// Parameter 3 : unsigned char = number of registers to write
// Parameter 4 : unsigned char = value to write
unsigned char TWI_print(unsigned char , unsigned char, unsigned char, unsigned char *);

// Function to read a data , on a periph, included in a register on a defined number of registers
// Return : unsigned char = the function returns an error code corresponding to the sub function concerned  (cf: datasheet Atmega 128)
// Parameter 1 : peripheral address
// Parameter 2 : register address
// Parameter 3 : number of registers
// Parameter 4 : value of pointer's adress to read
unsigned char TWI_receive(unsigned char, unsigned char, unsigned char, unsigned char *);


#endif /* HEADERS_LIB_TWI_H_ */
