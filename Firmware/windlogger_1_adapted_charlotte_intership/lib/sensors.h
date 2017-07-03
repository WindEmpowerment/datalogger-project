/**
 * @file   sensors.h
 * @author gilou
 * @date   30 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef LIB_SENSORS_H_
#define LIB_SENSORS_H_

//#define DEBUG_SENSORS	/**< use to debug the sensors lib */
uint16_t TCNT0_tmp;

/**
 *	Initialize to 0 each measure variable
 * @param _measure Pointer of a measure structure
 */
void measure_clear(Measure *_measure);

/**
 * Use to set timer0,1 and 3 config
 */
void anemos_init(void);

/**
 * Function to start frequency capture
 */
void anemo_start_count(void);

/**
 * Function to convert the frequency in m/s
 * @param _measure pointer to write the m/s value.
 */
void anemo_read_value(Measure *_measure);

void dir_value(Measure *_measure);

//void temp_value(Measure *_measure);

//double inst_AC_voltage();

//double inst_AC_current();

//double AC_voltage_offset();

//double AC_current_offset();


#endif /* LIB_SENSORS_H_ */
