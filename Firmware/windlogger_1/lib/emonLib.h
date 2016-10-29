/*
  Emon.h - Library for openenergymonitor
  Created by Trystan Lea, April 27 2010
  GNU GPL
  modified to use up to 12 bits ADC resolution (ex. Arduino Due)
  by boredman@boredomprojects.net 26.12.2013
  Low Pass filter for offset removal replaces HP filter 1/1/2015 - RW
*/

#ifndef EmonLib_h
#define EmonLib_h


// define theoretical vref calibration constant for use in readvcc()
// 1100mV*1024 ADC steps http://openenergymonitor.org/emon/node/1186
// override in your code with value for your specific AVR chip
// determined by procedure described under "Calibrating the internal reference voltage" at
// http://openenergymonitor.org/emon/buildingblocks/calibration
#ifndef READVCC_CALIBRATION_CONST
#define READVCC_CALIBRATION_CONST 1126400L
#endif

// to enable 12-bit ADC resolution on Arduino Due, 
// include the following line in main sketch inside setup() function:
//  analogReadResolution(ADC_BITS);
// otherwise will default to 10 bits, as in regular Arduino-based boards.
#if defined(__arm__)
#define ADC_BITS    12
#else
#define ADC_BITS    10
#endif

#define ADC_COUNTS  (1<<ADC_BITS)

void calcVI(unsigned int crossings, unsigned int timeout);
double calcIrms(unsigned int NUMBER_OF_SAMPLES);
void serialprint();

long readVcc();

//--------------------------------------------------------------------------------------
// Variable declaration for emon_calc procedure
//--------------------------------------------------------------------------------------
int sampleV;  							 //sample_ holds the raw analog read value
int sampleI;

double lastFilteredV,filteredV;          //Filtered_ is the raw analog value minus the DC offset
double filteredI;
double offsetV;                          //Low-pass filter output
double offsetI;                          //Low-pass filter output

double phaseShiftedV;                             //Holds the calibrated phase shifted voltage.

double sqV,sumV,sqI,sumI,instP,sumP;              //sq = squared, sum = Sum, inst = instantaneous

int startV;                                       //Instantaneous voltage at start of sample window.

uint8_t lastVCross, checkVCross;                  //Used to measure number of times threshold is crossed.


#endif
