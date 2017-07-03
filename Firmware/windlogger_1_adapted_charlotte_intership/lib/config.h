/**
 * @file   config.h
 * @author gilou
 * @date   31 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */
#ifndef LIB_CONFIG_H_
#define LIB_CONFIG_H_

/**
 * Function to update a config parameter.
 * @param config_request Pointer on a string with parameter number and the new value
 */
void config_update(char *config_request);

/**
 * @todo convert to use a list of params for config in eeprom
 * like :
 * "name",value,min,max,"desc" but with uc and double variation
 * @todo make function to display a more "proper" list  of params
 * @todo make function to write details when come a wrong value
 */


#endif /* LIB_CONFIG_H_ */
