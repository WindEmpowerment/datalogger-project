/**
 * @file   config.c
 * @author gilou
 * @date   31 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

#include <avr/io.h>
#include <stdlib.h>

#include "../lib/main.h"
#include "../lib/usart.h"
#include "../lib/eeprom_manage.h"
#include "../lib/pcf8563.h"
#include "../lib/debug.h"
#include "../lib/sensors.h"

void config_update(char *_config_request)
{
	uint8_t item = get_Arg(_config_request + 1);

	uint8_t arg_uc = atoi(_config_request + 4);

	double arg_f = atof(_config_request + 4);

	switch (item)
	{
	case 00:
		switch (arg_uc) {
		case 0:
			logger.meas_conf = 0;
			logger.meas_max = 0;
			logger.meas_stamp = 0;
			ee_write_logger();
			logger.meas_count =0;
			break;
		case 1:
			logger.meas_conf = 1;
			logger.meas_max = 1; // used to be the 10s mode max = 2, stamp = 5
			logger.meas_stamp = 1;
			ee_write_logger();
			logger.meas_count =0;
			break;
		case 2:
			logger.meas_conf = 2;
			logger.meas_max = 4;
			logger.meas_stamp = 15;
			ee_write_logger();
			logger.meas_count =0;
			break;
		case 3:
			logger.meas_conf = 3;
			logger.meas_max = 10;
			logger.meas_stamp = 60;
			ee_write_logger();
			logger.meas_count =0;
			break;
		default:
			USART0_print("Not a correct value");
			break;
		}
		break;
	case 11:
		if(arg_uc>=0 &&arg_uc<60)	RTC_update_reg(SECS,arg_uc);
		else USART0_print("must be: 0=<secs<60");
		break;
	case 12:
		if(arg_uc>=0 &&arg_uc<60)	RTC_update_reg(MINS,arg_uc);
		else USART0_print("must be: 0=<mins<60");
		break;
	case 13:
		if(arg_uc>=0 &&arg_uc<24)	RTC_update_reg(HOURS,arg_uc);
		else USART0_print("must be: 0=<hour<24");
		break;
	case 14:
		arg_uc = atoi(_config_request+4);
		if(arg_uc>=0 &&arg_uc<7)	RTC_update_reg(WEEKDAY,arg_uc);
		else USART0_print("must be: 0=<weekday<7");
		break;
	case 15:
		if(arg_uc>0 &&arg_uc<32)	RTC_update_reg(DAY,arg_uc);
		else USART0_print("must be: 0<day<32");
		break;
	case 16:
		if(arg_uc>0 &&arg_uc<13)	RTC_update_reg(MONTH,arg_uc);
		else USART0_print("must be: 0<month<13");
		break;
	case 17:
		if(arg_uc>=16 &&arg_uc<99)	RTC_update_reg(YEAR,arg_uc);
		else USART0_print("must be: 16=<year<99");
		break;
	default:
		USART0_print("Bad request !\r\n");
		break;
	}
	RTC_get_date(ptrTime);
	USART0_print_conf();
}
