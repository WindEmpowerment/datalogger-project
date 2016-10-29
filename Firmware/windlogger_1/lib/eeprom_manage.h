/**
 * @file   eeprom_manage.h
 * @author gilou
 * @date   29 août 2016
 * @brief  Manage the Logger struct read and write on the internal eeprom
 *
 * Detailed description of file.
 */
#ifndef LIB_EEPROM_MANAGE_H_
#define LIB_EEPROM_MANAGE_H_

void ee_erase_logger();

void ee_write_logger(void);

void ee_read_logger(void);

#endif /* LIB_EEPROM_MANAGE_H_ */
