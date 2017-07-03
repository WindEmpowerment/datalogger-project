/**
 * @file   pcf8563.c
 * @author gilou
 * @date   3 août 2016
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

#include <avr/io.h>
#include <stdlib.h>

#include "../lib/main.h"
#include "../lib/pcf8563.h"
#include "../lib/twi.h"
#include "../lib/debug.h"
#include <avr/interrupt.h>


//(JOURS = DAYS) declaration of the tab in which we use pcf8563's registers
char JOURS[8][3]={"Su","Mo","Tu","We","Th","Fr","Sa","er"};

void debug_RTC_print_Time(Time *time)
{
	debug_print("","",1);
	debug_print("_______________","_______________",1);
	debug_print("|weekday","",0);
	debug_print("=",time->weekday,1);
	debug_printu("|seconds","=",time->secs,1);
	debug_printu("|minutes","=",time->mins,1);
	debug_printu("|hours	","=",time->hours,1);
	debug_printu("|day	","=",time->day,1);
	debug_printu("|month	","=",time->month,1);
	debug_printu("|year	","=",time->year,1);
	debug_print("_______________","_______________",1);
	debug_print("","",1);
}

void debug_RTC_timestamp_calc(Time *start,Time *stop,unsigned char leapY, double result_timesamp)
{
	//send a report on timestamp calculation
	debug_print("","",1);
	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",1);
	debug_printu("|start year","=",start->year,0);
	debug_printu("	stop year","=",stop->year,0);
	debug_printu("	add to days","=",stop->year-start->year,1);

	debug_printu("|start month","=",start->month,0);
	debug_printu("	stop month","=",stop->month,0);
	debug_printu("	add to days","=",stop->month-start->month,1);

	debug_printu("|start day","=",start->day,0);
	debug_printu("	stop day","=",stop->day,0);
	debug_printu("	add to days","=",stop->day-start->day,1);

	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",1);

	debug_printl("|timestamp result",":",result_timesamp,1);
	//debug_printl("|epoch timestamp",":",epoch_010116.timestamp,1);
	///debug_printl("|writed timestamp",":",stop->timestamp,1);
	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",1);
	debug_printu("leap  Years","=",leapY,1);
	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",0);
	debug_print("_______________","_______________",1);
	debug_print("","",1);
}

uint8_t RTC_init()
{
#ifdef DEBUG_RTC
	debug_print("wake-up:","init RTC",1);
#endif
	//return TWI_init();
	//change for internal rtc on timer2
	TIMSK2 |= _BV(TOIE2);				// enable overflow interrupt
	TCNT2 = 0;
	TCCR2B = _BV(CS22) | _BV(CS20); // prescaler for overload interrupt each 1 second : CS2[2:0]=101;
	ASSR |=  _BV(AS2);					// Set the bit AS2 in the ASSR register to clock the timer 2 from the external crystal

	return 1;
}
ISR(TIMER2_OVF_vect){
	timestamp++;
}

/*
 * A year will be a leap year if it is divisible by 4 but not by 100.
 * If a year is divisible by 4 and by 100, it is not a leap year unless it is also divisible by 400.
 */
/**
 * function to return if the ear is leap
 * @param year the year to test
 * @return 0 for false, 1 for true
 */
unsigned char is_leap_year(unsigned int year)
{
	if(year%4==0)
	{
		if(year%100==0){
			if(year%400==0)return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}

uint32_t rtc_time_to_epoch(Time *start, Time *stop)
{
	unsigned int months_days[] = {31,59,90,120,151,181,212,243,273,304,334};
	uint32_t convtemp;

	// years work
	unsigned int i =0;
	unsigned char leapY =0;
	unsigned int days = (stop->year-start->year)*365; // convert years in days

	if((stop->year-start->year)>1)
	{
		for(i = start->year; i<stop->year;i++)
			{
				if(is_leap_year(start->year+i)) leapY++; // add a day for each leap years
			}
	}

	if(stop->month>2&&is_leap_year(stop->year))
	{
		leapY++;	// stop time month > February, check leap year
		days+=leapY;
	}

	// months work
	if(stop->month>1) days = days + months_days[(stop->month-2)];

	// days work
	days += (stop->day-start->day);

	//convert in seconds
	uint32_t now_timestamp = days*86400; //*constants seconds/day

	//add time

	convtemp= stop->hours*60;
	convtemp = (convtemp+stop->mins)*60;
	convtemp += stop->secs;
	//stop->hours*3600+stop->mins*60+stop->secs;
	now_timestamp += convtemp;
#ifdef DEBUG_RTC
	debug_RTC_timestamp_calc(start,stop,leapY,now_timestamp);
#endif
	return now_timestamp;
}

uint8_t RTC_get_date(Time *time)
{
	uint8_t pcf8563[7];	//tab for using the 8 registers of the RTC (ds1307)
	uint8_t i;
	uint8_t temp_unit, temp_diz_unit;
	uint8_t error = 0;
	Time *ptrepoch_010116;
	ptrepoch_010116=&epoch_010116;

	for(i = 0; i<7;i++)
	{
		pcf8563[i] = 0;								//Registers Initialisation to 0x00 in order to check the change
	}													//in their value after data receiving
	error = TWI_receive(0xA2,0x02,7,pcf8563);					//data receiving in the 8 registers on Ds1307

	if(pcf8563[3] == 0x00)								//testing of day's numero which can't be equal to 0 (1->31)
	{
		return error;										//return a critical errror
	}
	else
	{	// formatting seconds
		temp_unit = pcf8563[0] & 0x0F;						//convertion BCD to Int (cf datasheet Ds1307)
		temp_diz_unit = (pcf8563[0] & 0x70)>>4;
		time->secs = temp_diz_unit*10 + temp_unit;
		//debug_printu("time","secs",time->secs,1);

		// formatting minutes
		temp_unit = pcf8563[1] & 0x0F;
		temp_diz_unit = (pcf8563[1] & 0x70)>>4;
		time->mins = temp_diz_unit*10 + temp_unit;
		//debug_printu("time","mins",time->mins,1);


		// formatting hours
		temp_unit = pcf8563[2] & 0x0F;
		temp_diz_unit = (pcf8563[2] & 0x30)>>4;
		time->hours = temp_diz_unit*10 + temp_unit;
		//debug_printu("time","hours",time->hours,1);

		// We chose the day in the tab JOURS (days)
		time->weekday[0] = JOURS[(pcf8563[4]&0b00000111)][0];
		time->weekday[1] = JOURS[(pcf8563[4]&0b00000111)][1];
		time->weekday[2] = '\0';

		// formatting day's number
		temp_unit = pcf8563[3] & 0x0F;
		temp_diz_unit = (pcf8563[3] & 0x30)>>4;
		time->day = temp_diz_unit*10 + temp_unit;

		// formatting mounth's number
		temp_unit = pcf8563[5] & 0x0F;
		temp_diz_unit = (pcf8563[5] & 0x10)>>4;
		time->month = temp_diz_unit*10 + temp_unit;

		// formatting year's number
		temp_unit = pcf8563[6] & 0x0F;
		temp_diz_unit = (pcf8563[6] & 0xF0)>>4;
		time->year = (temp_diz_unit*10 + temp_unit);

		//time->timestamp = ptrepoch_010116->timestamp;
		//time->timestamp = rtc_time_to_epoch(ptrepoch_010116, time)+ ptrepoch_010116->timestamp;

#ifdef DEBUG_RTC
		debug_RTC_print_Time(time);.
#endif
		return error;
	}

	//return 0 if the function is executed without any error
}

char a2toBCD (char *s_nombre) // the pointer s_nombre points the tens of the number which needs to be converted, s_nombre+1 points its units

{
	uint8_t temp_unit;  	//temporary variable receiving the integer value of the character "unit" from the sting pointer
	uint8_t temp_diz_unit; 	//temporary variable recevant la valeur entière du caractère "dizaine" du pointeur string
	uint8_t conversion=0;	//temporary variable receiving the ''string'' number conversion in BCD

	temp_unit = (uint8_t) (*(s_nombre+1) - '0');		// the pointer s_nombre+1 points the units of the number which needs to be converted
	temp_diz_unit = (uint8_t) (*s_nombre - '0');		// the pointer s_nombre points the tens of the number which needs to be converted


	conversion = (temp_diz_unit << 4)|temp_unit;		/// 4 bits offset with the tens to code the number in BCD with 2 quartets (1 byte)
	return conversion;			//return the converted number
}

uint8_t utoBCD(uint8_t _data)
{
	uint8_t number = _data;
	return (number/10<<4) | (number%10);
}



uint8_t RTC_update(char *s_datetime)
{
	uint8_t pcf8563[7]; 							//tableau contenant les 7 registres de la RTC (h/min/sec/j/DAY/mois/année)

	pcf8563[0] = (uint8_t)a2toBCD(s_datetime+11); 					//stocks the converted value of the index 11 and 12 corresponding to the secs (units and tens)
	pcf8563[1] = (uint8_t)a2toBCD(s_datetime+9); 					//stocks the converted value of the index 9 et 11 corresponding to the mins (units and tens)
	pcf8563[2] = (uint8_t)a2toBCD(s_datetime+7);  					//stocks the converted value of the index 7 et 8 corresponding to the hours (units and tens)
	pcf8563[4] = (uint8_t)(s_datetime[0] -'0'); 					//stocks the converted value of the  l'index 0 corresponding to the day (sunday, monday etc...)
	pcf8563[3] = (uint8_t)a2toBCD(s_datetime+1);  					//stocks the converted value of the  l'index 1 et 2 corresponding to day's number
	pcf8563[5] = (uint8_t)a2toBCD(s_datetime+3);  					//stocks the converted value of the  l'index 3 et 4 corresponding to mounth's number
	pcf8563[6] = (uint8_t)a2toBCD(s_datetime+5);  					//stocks the converted value of the  l'index 5 et 6 corresponding to year's number

	return TWI_print(0xA2, 0x02, 7,pcf8563);					//reset the RTC with the tab Ds1307
}

void RTC_update_reg(uint8_t reg, uint8_t data)
{

	TWI_set_char(0xA2, reg, utoBCD(data));					//reset the RTC with the tab Ds1307
}
