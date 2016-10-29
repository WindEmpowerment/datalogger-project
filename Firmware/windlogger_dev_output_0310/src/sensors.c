/**
 * @file   sensors.c
 * @author gilou
 * @date   30 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

#include <avr/interrupt.h>
#include "../lib/main.h"
#include "../lib/sensors.h"



void measure_clear(Measure *_measure)
{
	_measure->speed1 = 0;
	_measure->speed2 = 0;
	_measure->degree = 0;
	_measure->acPower = 0;
	_measure->dcPower = 0;
	_measure->temp = 0;
	_measure->rpm = 0;
}

void anemos_init(void)
{

}

void anemo_start_count(void)
{



}

void anemo_read_value(Measure *_measure)
{

}



void dir_value(Measure *_measure)
{

}

void temp_value(Measure *_measure)
{

}

float inst_AC_voltage()
{

	return 0;
}

float inst_AC_current()
{

	return 0;
}

float AC_voltage_offset()
{

return 0;
}

float AC_current_offset()
{

return 0;
}
