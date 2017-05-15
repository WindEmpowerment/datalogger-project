/**
 * @file   eeprom_manage.c
 * @author gilou
 * @date   29 août 2016
 * @brief  Manage the Logger struct read and write on the internal eeprom
 *
 * Detailed description of file.
 */

#include <avr/eeprom.h>

#include "../lib/main.h"

void ee_erase_logger()
{
	eeprom_update_byte((uint8_t *)0x0000, 0);
	eeprom_update_word((uint16_t *)0x0001, 0);
	eeprom_update_byte((uint8_t *)0x0003, 0);
	eeprom_update_float((float *)0x0020, 0);
	eeprom_update_float((float *)0x0024, 0);
	eeprom_update_byte((uint8_t *)0x0030, 0);
	eeprom_update_byte((uint8_t *)0x0031, 0);
	eeprom_update_float((float *)0x0040, 0);
	eeprom_update_float((float *)0x0045, 0);
	eeprom_update_float((float *)0x004A, 0);
	eeprom_update_word((uint16_t *)0x0050,0);
	eeprom_update_byte((uint8_t *)0x0053, 0);
}

void ee_write_logger()
{
	eeprom_update_byte((uint8_t *)0x0000, logger.meas_conf);
	eeprom_update_word((uint16_t *)0x0001,logger.meas_max);
	eeprom_update_byte((uint8_t *)0x0003, logger.meas_stamp);
	eeprom_update_float((float *)0x0020, logger.anemo1_factor);
	eeprom_update_float((float *)0x0024, logger.anemo1_offset);
/*
	eeprom_update_byte((uint8_t *)0x0030,logger.inPinV);
	eeprom_update_byte((uint8_t *)0x0031,logger.inPinI);
	eeprom_update_float((float *)0x0040,logger.VCAL);
	eeprom_update_float((float *)0x0045,logger.ICAL);
	eeprom_update_float((float *)0x004A,logger.PHASECAL);
	eeprom_update_word((uint16_t *)0x0050,logger.degree_offset);
  */  eeprom_update_byte((uint8_t *)0x0053,logger.inPinVane);


}

void ee_read_logger()
{

	logger.meas_conf = eeprom_read_byte((uint8_t *)0x0000);
	logger.meas_max = eeprom_read_word((uint16_t *)0x0001);
	logger.meas_stamp = eeprom_read_byte((uint8_t *)0x0003);
	logger.anemo1_factor = eeprom_read_float((float *)0x0020);
	logger.anemo1_offset = eeprom_read_float((float *)0x0024);
/*	logger.inPinV = eeprom_read_byte((uint8_t *)0x0030);
	logger.inPinI = eeprom_read_byte((uint8_t *)0x0031);
	logger.VCAL = eeprom_read_float((float *)0x0040);
	logger.ICAL = eeprom_read_float((float *)0x0045);
	logger.PHASECAL = eeprom_read_float((float *)0x004A);
	logger.degree_offset = eeprom_read_word((uint16_t *) 0x0050);
	*/logger.inPinVane = eeprom_read_byte((uint8_t *)0x0053);
}
