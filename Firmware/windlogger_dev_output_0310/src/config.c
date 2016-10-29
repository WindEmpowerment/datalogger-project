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
#include "../lib/debug.h"
#include "../lib/sensors.h"
#include "../lib/fct_rs232.h"

void config_update(char *_config_request)
{
	uint8_t item = get_Arg(_config_request + 1);

	uint8_t arg_uc = atoi(_config_request + 4);

	float arg_f = atof(_config_request + 4);

	switch (item)
	{
	case 00:
		switch (arg_uc) {
		case 1:
			ptrLogger->meas_conf = 1;
			ptrLogger->meas_max = 2;
			ptrLogger->meas_stamp = 5;
			ee_write_logger(ptrLogger);
			ptrLogger->meas_count =0;
			break;
		case 2:
			ptrLogger->meas_conf = 2;
			ptrLogger->meas_max = 4;
			ptrLogger->meas_stamp = 15;
			ee_write_logger(ptrLogger);
			ptrLogger->meas_count =0;
			break;
		case 3:
			ptrLogger->meas_conf = 3;
			ptrLogger->meas_max = 10;
			ptrLogger->meas_stamp = 60;
			ee_write_logger(ptrLogger);
			ptrLogger->meas_count =0;
			break;
		case 4:
			ptrLogger->meas_conf = 4;
			ptrLogger->meas_max = 1;
			ptrLogger->meas_stamp = 3;
			ee_write_logger(ptrLogger);
			ptrLogger->meas_count =0;
			break;
		default:
			txString(_COM1,"Not a correct value");
			break;
		}
		break;
	case 01:
		switch(arg_uc) {
		case 1:
			ptrLogger->output_enable = 1;
			break;
		case 2:
			ptrLogger->output_enable = 2;
			break;
		case 3:
			ptrLogger->output_enable = 3;
			break;
		default:
			txString(_COM1,"Not a correct value");
			break;
		}
		ee_write_logger(ptrLogger);
		break;
	//	case 11:
	//		if(arg_uc>=0 &&arg_uc<60)	RTC_update_reg(SECS,arg_uc);
	//		else USART0_print("must be: 0=<secs<60");
	//		break;
	//	case 12:
	//		if(arg_uc>=0 &&arg_uc<60)	RTC_update_reg(MINS,arg_uc);
	//		else USART0_print("must be: 0=<mins<60");
	//		break;
	//	case 13:
	//		if(arg_uc>=0 &&arg_uc<24)	RTC_update_reg(HOURS,arg_uc);
	//		else USART0_print("must be: 0=<hour<24");
	//		break;
	//	case 14:
	//		arg_uc = atoi(_config_request+4);
	//		if(arg_uc>=0 &&arg_uc<7)	RTC_update_reg(WEEKDAY,arg_uc);
	//		else USART0_print("must be: 0=<weekday<7");
	//		break;
	//	case 15:
	//		if(arg_uc>0 &&arg_uc<32)	RTC_update_reg(DAY,arg_uc);
	//		else USART0_print("must be: 0<day<32");
	//		break;
	//	case 16:
	//		if(arg_uc>0 &&arg_uc<13)	RTC_update_reg(MONTH,arg_uc);
	//		else USART0_print("must be: 0<month<13");
	//		break;
	//	case 17:
	//		if(arg_uc>=16 &&arg_uc<99)	RTC_update_reg(YEAR,arg_uc);
	//		else USART0_print("must be: 16=<year<99");
	//		break;
	case 20:
		ptrLogger->anemo1_factor = arg_f;
		ee_write_logger(ptrLogger);
		break;
	case 21:
		ptrLogger->anemo1_offset = arg_f;
		ee_write_logger(ptrLogger);
		break;
	case 30:
		if(arg_uc==1)
		{
			ptrLogger->ac_voltage_offset = AC_voltage_offset();
			ee_write_logger(ptrLogger);
		}
		break;
	case 31:
		if(arg_uc==1)
		{
			ptrLogger->ac_current_offset = AC_current_offset();
			ee_write_logger(ptrLogger);
		}
		break;
	default:
		txString(_COM1,"Bad request !\r\n");
		break;
	}
	USART0_print_conf();
}
