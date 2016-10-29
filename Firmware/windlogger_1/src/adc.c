/**
 * @file   adc.c
 * @author gilou
 * @date   15 juil. 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */


#include <avr/io.h>

int adc_value(unsigned char channel)
{
	ADMUX = (1<<REFS0)|channel;													/// Use the AVcc for voltage reference and add the channel number
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0) | (1<<ADPS0) | (1<<ADSC);		/// ADEN : conversion enable, ADPS[2:0] : divide the ADC frequency clock, ADSC : start one conversion

	while (ADCSRA & (1<<ADSC)); 												/// wait for conversion to complete

	ADCSRA = 0x00;																/// Stop the ADC (reduce power)

	return ADCW;
}

