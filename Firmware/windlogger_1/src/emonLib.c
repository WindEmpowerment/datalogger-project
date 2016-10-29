/*
  Emon.cpp - Library for openenergymonitor
  Created by Trystan Lea, April 27 2010
  GNU GPL
  modified to use up to 12 bits ADC resolution (ex. Arduino Due)
  by boredman@boredomprojects.net 26.12.2013
  Low Pass filter for offset removal replaces HP filter 1/1/2015 - RW
*/

// Proboscide99 10/08/2016 - Added ADMUX settings for ATmega1284 e 1284P (644 / 644P also, but not tested) in readVcc function

//#include "WProgram.h" un-comment for use on older versions of Arduino IDE
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdlib.h>

#include "../lib/main.h"
#include "../lib/emonLib.h"
#include "../lib/adc.h"
#include "../lib/usart.h"
#include "../lib/time.h"

//--------------------------------------------------------------------------------------
// emon_calc procedure
// Calculates realPower,apparentPower,powerFactor,Vrms,Irms,kWh increment
// From a sample window of the mains AC voltage and current.
// The Sample window length is defined by the number of half wavelengths or crossings we choose to measure.
//--------------------------------------------------------------------------------------
void calcVI(unsigned int crossings, unsigned int timeout)
{

	int SupplyVoltage = readVcc();


  unsigned int crossCount = 0;                             //Used to measure number of times threshold is crossed.
  unsigned int numberOfSamples = 0;                        //This is now incremented  

  //-------------------------------------------------------------------------------------------------------------------------
  // 1) Waits for the waveform to be close to 'zero' (mid-scale adc) part in sin curve.
  //-------------------------------------------------------------------------------------------------------------------------
  uint8_t st=0;                                  //an indicator to exit the while loop
  init_millis();
  unsigned long start = logger.millis;    //millis()-start makes sure it doesnt get stuck in the loop if there is an error.

  while(st==0)                                   //the while loop...
  {
     startV = adc_value(logger.inPinV);                    //using the voltage waveform
     if ((startV < (ADC_COUNTS*0.55)) && (startV > (ADC_COUNTS*0.45))) st=1;  //check its within range
     if ((logger.millis-start)>timeout) st = 1;
  }
  
  //-------------------------------------------------------------------------------------------------------------------------
  // 2) Main measurement loop
  //------------------------------------------------------------------------------------------------------------------------- 
  start = logger.millis;

  while ((crossCount < crossings) && ((logger.millis-start)<timeout))
  {
    numberOfSamples++;                       //Count number of times looped.
    lastFilteredV = filteredV;               //Used for delay/phase compensation
    
    //-----------------------------------------------------------------------------
    // A) Read in raw voltage and current samples
    //-----------------------------------------------------------------------------
    sampleV = adc_value(logger.inPinV);                 //Read in raw voltage signal
    sampleI = adc_value(logger.inPinI);                 //Read in raw current signal

    //-----------------------------------------------------------------------------
    // B) Apply digital low pass filters to extract the 2.5 V or 1.65 V dc offset,
    //     then subtract this - signal is now centred on 0 counts.
    //-----------------------------------------------------------------------------
    offsetV = offsetV + ((sampleV-offsetV)/1024);
	filteredV = sampleV - offsetV;
    offsetI = offsetI + ((sampleI-offsetI)/1024);
	filteredI = sampleI - offsetI;
   
    //-----------------------------------------------------------------------------
    // C) Root-mean-square method voltage
    //-----------------------------------------------------------------------------  
    sqV= filteredV * filteredV;                 //1) square voltage values
    sumV += sqV;                                //2) sum
    
    //-----------------------------------------------------------------------------
    // D) Root-mean-square method current
    //-----------------------------------------------------------------------------   
    sqI = filteredI * filteredI;                //1) square current values
    sumI += sqI;                                //2) sum 
    
    //-----------------------------------------------------------------------------
    // E) Phase calibration
    //-----------------------------------------------------------------------------
    phaseShiftedV = lastFilteredV + logger.PHASECAL * (filteredV - lastFilteredV);
    
    //-----------------------------------------------------------------------------
    // F) Instantaneous power calc
    //-----------------------------------------------------------------------------   
    instP = phaseShiftedV * filteredI;          //Instantaneous Power
    sumP +=instP;                               //Sum  
    
    //-----------------------------------------------------------------------------
    // G) Find the number of times the voltage has crossed the initial voltage
    //    - every 2 crosses we will have sampled 1 wavelength 
    //    - so this method allows us to sample an integer number of half wavelengths which increases accuracy
    //-----------------------------------------------------------------------------       
    lastVCross = checkVCross;                     
    if (sampleV > startV) checkVCross = 1;
                     else checkVCross = 0;
    if (numberOfSamples==1) lastVCross = checkVCross;                  
                     
    if (lastVCross != checkVCross) crossCount++;
  }
 
  //-------------------------------------------------------------------------------------------------------------------------
  // 3) Post loop calculations
  //------------------------------------------------------------------------------------------------------------------------- 
  //Calculation of the root of the mean of the voltage and current squared (rms)
  //Calibration coefficients applied. 
  
  double V_RATIO = logger.VCAL *((SupplyVoltage/1000.0) / (ADC_COUNTS));
  logger.measureAverage.Vrms = (V_RATIO * sqrt(sumV / numberOfSamples));
  
  double I_RATIO = logger.ICAL *((SupplyVoltage/1000.0) / (ADC_COUNTS));
  logger.measureAverage.Irms = (I_RATIO * sqrt(sumI / numberOfSamples));

  //Calculation power values
  logger.measureAverage.realPower += (V_RATIO * I_RATIO * sumP / numberOfSamples)/logger.meas_max;
  logger.measureAverage.apparentPower += (logger.measureAverage.Vrms * logger.measureAverage.Irms)/logger.meas_max;
  logger.measureAverage.powerFactor += (logger.measureAverage.realPower / logger.measureAverage.apparentPower)/logger.meas_max;

  //Reset accumulators
  sumV = 0;
  sumI = 0;
  sumP = 0;
//--------------------------------------------------------------------------------------       
  stop_millis();
}

//--------------------------------------------------------------------------------------
double calcIrms(unsigned int Number_of_Samples)
{

	int SupplyVoltage = readVcc();

  
  for (unsigned int n = 0; n < Number_of_Samples; n++)
  {
    sampleI = adc_value(logger.inPinI);

    // Digital low pass filter extracts the 2.5 V or 1.65 V dc offset, 
	//  then subtract this - signal is now centered on 0 counts.
    offsetI = (offsetI + (sampleI-offsetI)/1024);
	filteredI = sampleI - offsetI;

    // Root-mean-square method current
    // 1) square current values
    sqI = filteredI * filteredI;
    // 2) sum 
    sumI += sqI;
  }

  double I_RATIO = logger.ICAL *((SupplyVoltage/1000.0) / (ADC_COUNTS));
  logger.measureAverage.Irms = I_RATIO * sqrt(sumI / Number_of_Samples);

  //Reset accumulators
  sumI = 0;
//--------------------------------------------------------------------------------------       
 
  return logger.measureAverage.Irms;
}

void serialprint()
{
	char tmp_char[12];

    USART0_print(dtostrf(logger.measureAverage.realPower,0,3,tmp_char));
    USART0_print(" ");
    USART0_print(dtostrf(logger.measureAverage.apparentPower,0,3,tmp_char));
    USART0_print(" ");
    USART0_print(dtostrf(logger.measureAverage.Vrms,0,3,tmp_char));
    USART0_print(" ");
    USART0_print(dtostrf(logger.measureAverage.Irms,0,3,tmp_char));
    USART0_print(" ");
    USART0_print(dtostrf(logger.measureAverage.powerFactor,0,3,tmp_char));
    USART0_print("\r\n");
    _delay_ms(100);
}

//thanks to http://hacking.majenko.co.uk/making-accurate-adc-readings-on-arduino
//and Jérôme who alerted us to http://provideyourown.com/2012/secret-arduino-voltmeter-measure-battery-voltage/

long readVcc() {
  long result;
  
  //not used on emonTx V3 - as Vcc is always 3.3V - eliminates bandgap error and need for calibration http://harizanov.com/2013/09/thoughts-on-avr-adc-accuracy/

  #if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328__) || defined (__AVR_ATmega328P__)
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);  
  #elif defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #elif defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_AT90USB1286__)
  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  ADCSRB &= ~_BV(MUX5);   // Without this the function always returns -1 on the ATmega2560 http://openenergymonitor.org/emon/node/2253#comment-11432
  #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
  ADMUX = _BV(MUX5) | _BV(MUX0);
  #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
  ADMUX = _BV(MUX3) | _BV(MUX2);
	
  #endif


  #if defined(__AVR__) 
  _delay_ms(2);                                        // Wait for Vref to settle
  ADCSRA |= _BV(ADSC);                             // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = READVCC_CALIBRATION_CONST / result;  //1100mV*1024 ADC steps http://openenergymonitor.org/emon/node/1186
  return result;
 #elif defined(__arm__)
  return (3300);                                  //Arduino Due
 #else 
  return (3300);                                  //Guess that other un-supported architectures will be running a 3.3V!
 #endif
}

