/**
 * @file   adc.h
 * @author gilou
 * @date   15 juil. 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef DATALOGGER_TEST_SENSORS_HEADERS_ADC_H_
#define DATALOGGER_TEST_SENSORS_HEADERS_ADC_H_

/**
 * Return the int value from the channel 5
 * @param channel Select channel
 * @return 0 - 1024 adc result
 */
int adc_value(unsigned char channel);

#endif /* DATALOGGER_TEST_SENSORS_HEADERS_ADC_H_ */
