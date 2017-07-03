/**
 * @file   twi.c
 * @author gilou
 * @date   3 août 2016
 * @brief  Atmega2560 twi driver.
 *
 * Library to talk on the TWI protocol (I2C). MicroC = atmega2560
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../lib/main.h"
#include "../lib/usart.h"


uint8_t TWI_init ()	// Starting function for the TWI protocol
{
	TWSR = 0x00; 					//prescaler set to 1
	TWBR = (F_CPU / 100000UL - 16) / 2;					//bite rate register set to 0x20 = 32, 0x0C for 400kHz
	TWCR = (1<<TWEN);				//enable TWI
#ifdef DEBUG_TWI
	USART0_print("init TWI\r\n");
#endif
	return 0;
}


//  Starting function for the TWI protocol
// Return : void
// Parameter 1 : void
void TWI_start () 	//  Starting function for the TWI protocol

{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); 	// set to 1 twint, twstart, twenable in the control register (TWCR)
	while (!(TWCR & (1<<TWINT))); 				// wait for TWINT to be high again

}

// Restarting function for the TWI protocol
// Return : void
// Parameter 1 : void
void TWI_restart () // Restarting function for the TWI protocol
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);		//set to 1 twint, twstart, twenable in the control register (TWCR)
	while (!(TWCR & (1<<TWINT)));				//wait for TWINT to be high again

}

// Stopping function for the TWI protocol
// Return : void
// Parameter 1 : void
void TWI_stop ()	// Stopping function for the TWI protocol
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);		//set to 1 twint, twstop, twenable in the control register (TWCR)
}

//Writing function of an byte in the data register (TWDR)
// Return : void
// Parameter 1 : unsigned char = register's peripheral address or data's value to write on TWDR
void TWI_set (uint8_t data)	//the function returns an error code corresponding to the sub function concerned
{
	TWDR = data;							// The data register (TWDR) receives "data" 's value
	TWCR = (1<<TWINT)|(1<<TWEN);			//set to 1 twint, twen in the control register (TWCR)
	while (!(TWCR & (1<<TWINT)));			//wait for TWINT to be high again
}

// Reading function for the data register and ACKNOWLEDGEMENT
// Return : unsigned char = the function returns data register's value (TWDR)
// Parameter 1 : void
uint8_t TWI_get_ack(void)	// Reading function for the data register and ACKNOWLEDGEMENT
{
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);	//set to 1 twint, twen, twea in the control register (TWCR)
    while (!(TWCR & (1<<TWINT)));			//wait for TWINT to be high again
    return TWDR;							//wait for TWINT to be high again, return the the data register's value (TWDR)
}

// Reading function for the data register and NOT ACKNOWLEDGEMENT
// Retour : unsigned char = the function returns data register's value (TWDR)
// Parameter 1 : void
uint8_t TWI_get_nack(void)	// Reading function for the data register and NOT ACKNOWLEDGEMENT

{
	TWCR = (1<<TWINT)|(1<<TWEN);			//set to 1 twint, twen in the control register (TWCR)
	while (!(TWCR & (1<<TWINT)));			//wait for TWINT to be high again
	return TWDR;							//wait for TWINT to be high again, return the the data register's value (TWDR)
}

// Reading function for the status register (TWSR)
// Return : unsigned char = the function returns the value of the status register (TWSR) by masking prescaler's bits
// Parameter 1 : void
uint8_t TWI_get_status(void)	// Reading function for the status register (TWSR)

{
    return TWSR & 0xF8; 		// return the value of the status register (TWSR) by masking prescaler's bits
}


uint8_t TWI_set_char(uint8_t addr,uint8_t reg, uint8_t data)	//Function to write a data on the fly, on a periph, included in a register on a defined number of registers
{
	TWI_start();
	if (TWI_get_status()!= 0x08)		// If start condition isn't recognised return error : 0x08
		return 0x08;

	TWI_set(addr);
	if (TWI_get_status() != 0x18)		//If set condition isn't recognised return error : 0x18
		return 0x18;

	TWI_set(reg);
	if (TWI_get_status() != 0x28)	//If set condition isn't recognised return error : 0x18
		return 0x19;

	TWI_set(data);
	if (TWI_get_status() != 0x28)	//If set condition isn't recognised return error : 0x28
		return 0x28;

	TWI_stop();

	return 0x00;						//return the code 0x00 if the function TWI_print is executed without any error
}

uint8_t TWI_get_char(uint8_t addr, uint8_t reg)	//Function to write a data on the fly, on a periph, included in a register on a defined number of registers

{

	uint8_t data=0;						//creation of a local index variable

	TWI_start();
	if (TWI_get_status() != 0x08)return 0x08;		//If start condition isn't recognised return error : 0x08

	TWI_set(addr);
	if (TWI_get_status() != 0x18)return 0x18;		//If set condition isn't recognised return error : 0x18

	TWI_set(reg);
	if(TWI_get_status() != 0x28)return 0x28;		//If set condition isn't recognised return error : 0x28

	TWI_restart();
	if (TWI_get_status() != 0x10)return 0x10;		//If set condition isn't recognised return error : 0x10

	TWI_set(addr+1);

	if (TWI_get_status() != 0x40)return 0x40;		//If set condition isn't recognised in master mode, return error : 0x40

	//The byte to get must be without aknowledgement
	data = TWI_get_nack();		//read_data's address value receive the value of the data register (TWDR) when there is no ACK
	if (TWI_get_status() != 0x58)	//If the condition to read the data isn't recognised, return error code : 0x58
		return 0x58;

	TWI_stop();

	return data;						// The function TWI_receive returns the value 0xF0 when the function is executed without any error
}




uint8_t TWI_print (uint8_t addr,uint8_t reg, uint8_t nb, uint8_t *write_data)	// Function to write a data on the fly, on a periph, included in a register on a defined number of registers

{
	uint8_t i;							//creation of a local index variable

	TWI_start();
	if (TWI_get_status()!= 0x08)		//creation of a local index variable : 0x08
		return 0x08;

	TWI_set(addr);
	if (TWI_get_status() != 0x18)		//If set condition isn't recognised return error : 0x18
		return 0x18;

	TWI_set(reg);
	if (TWI_get_status() != 0x28)	//If set condition isn't recognised return error : 0x18
		return 0x19;

	for(i=0; i < nb; i++)
	{
		TWI_set(*(write_data+i));
		if (TWI_get_status() != 0x28)	//If set condition isn't recognised return error : 0x28
			return 0x28;
	}
	TWI_stop();
	return 0x00;						//The function returns the value 0x00 when the function is executed without any error
}

uint8_t TWI_receive(uint8_t addr, uint8_t reg, uint8_t nb, uint8_t *read_data)	//   Function to write a data on a pointer, on a periph, included in a register on a defined number of registers

{
	uint8_t i=0;						//creation of a local index variable

	TWI_start();
	if (TWI_get_status() != 0x08)		//If start condition isn't recognised return error : 0x08
		return 0x08;

	TWI_set(addr);
	if (TWI_get_status() != 0x18)		//If set condition isn't recognised return error : 0x18
		return 0x18;

	TWI_set(reg);
	if(TWI_get_status() != 0x28)		//If set condition isn't recognised return error : 0x28
		return 0x28;

	TWI_restart();
	if (TWI_get_status() != 0x10)		//If restart condition isn't recognised return error : 0x10
		return 0x10;

	TWI_set(addr+1);

	if (TWI_get_status() != 0x40) 		//If set condition isn't recognised in master receiver mode, return error : 0x40
		return 0x40;

	for (i = 0; i < nb-1; i++)			//start of a "for" with the index i initialised at 0 which increases until nb-1 to end on the last with TWI_get_nack, and we increment it
	{
		*(read_data+i) = TWI_get_ack();	// the value of the address of the pointer read_data+i receives data register's value (TWDR) when sending a ACK
if (TWI_get_status() != 0x50)	// If the reading condition isn't recognised after an ACK, return error code : 0x50
			return 0x50;
	}

	// The last byte to get must be without aknowledgement
	*(read_data+nb-1) = TWI_get_nack();		//the value of the address of the pointer read_data+i receives data register's value (TWDR) when there is no ACK
	if (TWI_get_status() != 0x58)	//If the reading data condition isn't recognised after an ACK, return error code : 0x58

	TWI_stop();

	return 0x00;						//return the code 0x00 if the function TWI_receive is executed without any error
}
