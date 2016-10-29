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
	eeprom_update_byte((uint8_t *)0x0004,0);
	eeprom_update_float((float *)0x0020, 0.0);
	eeprom_update_float((float *)0x0024, 0.0);
	eeprom_update_float((float *)0x0030, 0.0);
	eeprom_update_float((float *)0x0034, 0.0);
}

void ee_write_logger(Logger *_logger)
{
	eeprom_update_byte((uint8_t *)0x0000, _logger->meas_conf);
	eeprom_update_word((uint16_t *)0x0001,_logger->meas_max);
	eeprom_update_byte((uint8_t *)0x0003, _logger->meas_stamp);
	eeprom_update_byte((uint8_t *)0x0004,_logger->output_enable);
	eeprom_update_float((float *)0x0020, _logger->anemo1_factor);
	eeprom_update_float((float *)0x0024, _logger->anemo1_offset);
	eeprom_update_float((float *)0x0030, _logger->ac_voltage_offset);
	eeprom_update_float((float *)0x0034, _logger->ac_current_offset);

}

void ee_read_logger(Logger *_logger)
{

	_logger->meas_conf = eeprom_read_byte((uint8_t *)0x0000);
	_logger->meas_max = eeprom_read_word((uint16_t *)0x0001);
	_logger->meas_stamp = eeprom_read_byte((uint8_t *)0x0003);
	_logger->output_enable = eeprom_read_byte((uint8_t *)0x0004);
	_logger->anemo1_factor = eeprom_read_float((float *)0x0020);
	_logger->anemo1_offset = eeprom_read_float((float *)0x0024);
	_logger->ac_voltage_offset = eeprom_read_float((float *)0x0030);
	_logger->ac_current_offset = eeprom_read_float((float *)0x0034);
}
