EESchema Schematic File Version 2
LIBS:shield-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:shield-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title "Windlogger Shield main frame"
Date "2016-10-16"
Rev "A"
Comp "ALEEA"
Comment1 "LONGUET Gilles"
Comment2 "AGPLv3"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2475 925  2    60   ~ 0
Anemometer1 : Hall effect or ILS
Text Notes 2475 2250 2    60   ~ 0
Winevane : potentiometer
Text Notes 2475 3075 2    60   ~ 0
9V transformer : AC voltage
$Sheet
S 3900 600  1400 850 
U 560A35D3
F0 "F1 Anemometers" 50
F1 "F1_anemometers.sch" 50
F2 "Wind1" I L 3900 800 60 
F3 "Wind2" I L 3900 1250 60 
F4 "Speed2" O R 5300 1250 60 
F5 "Speed1" O R 5300 800 60 
$EndSheet
$Sheet
S 3900 1750 1400 850 
U 560A35DE
F0 "F2 windvane" 50
F1 "F2_windvane.sch" 50
F2 "Udir" O R 5300 2200 60 
F3 "vane_v+" I L 3900 2100 60 
F4 "vane_sig" I L 3900 2300 60 
F5 "vane_v-" I L 3900 2200 60 
$EndSheet
$Sheet
S 3900 2800 1400 950 
U 560A361A
F0 "F3_Voltage_sensors" 50
F1 "F3_Voltage_sensors.sch" 50
F2 "UAC_hi" I L 3900 2950 60 
F3 "UAC_lo" I L 3900 3050 60 
F4 "Uac" O R 5300 3100 60 
F5 "Ubat" I L 3900 3350 60 
F6 "UDC" O R 5300 3500 60 
$EndSheet
$Sheet
S 3900 4225 1400 1450
U 560A3643
F0 "F4_Current_sensors" 50
F1 "F4_Current_sensors.sch" 50
F2 "I1_hi" I L 3900 4375 60 
F3 "I1_lo" I L 3900 4475 60 
F4 "I1" O R 5300 4425 60 
F5 "I2_hi" I L 3900 4725 60 
F6 "I2_lo" I L 3900 4825 60 
F7 "I2" O R 5300 4775 60 
F8 "I3_hi" I L 3900 5075 60 
F9 "I3_lo" I L 3900 5175 60 
F10 "I3" O R 5300 5125 60 
F11 "I4_hi" I L 3900 5425 60 
F12 "I4_lo" I L 3900 5525 60 
F13 "I4" O R 5300 5475 60 
$EndSheet
Text Label 3300 800  0    60   ~ 0
Wind1
Text Label 3350 1250 0    60   ~ 0
Wind2
Text Label 3250 2300 0    60   ~ 0
vane_sig
Text Label 3350 2950 0    60   ~ 0
UAC_hi
Text Label 3350 3050 0    60   ~ 0
UAC_lo
Text Notes 10300 4450 0    60   ~ 0
CLKO/ICP1
Text Notes 10300 4350 0    60   ~ 0
OC1A/PWM
Text Notes 10300 4250 0    60   ~ 0
OC1B/SS/PWM
Text Notes 10300 4150 0    60   ~ 0
OC2A/MOSI/PWM
Text Notes 10300 4050 0    60   ~ 0
MISO
Text Notes 10300 3950 0    60   ~ 0
SCK
Text Notes 10300 3850 0    60   ~ 0
GND
Text Notes 10300 3750 0    60   ~ 0
AREF
Text Notes 8600 4725 0    60   ~ 0
ADC0
Text Notes 8600 4825 0    60   ~ 0
ADC1
Text Notes 8600 4925 0    60   ~ 0
ADC2
Text Notes 8600 5025 0    60   ~ 0
ADC3
Text Notes 8600 5125 0    60   ~ 0
ADC4
Text Notes 8600 5225 0    60   ~ 0
ADC5
Text Notes 10300 5300 0    60   ~ 0
RXD
Text Notes 10300 5200 0    60   ~ 0
TXD
Text Notes 10300 5100 0    60   ~ 0
INT0
Text Notes 10300 5000 0    60   ~ 0
INT1/OC2B
Text Notes 10300 4900 0    60   ~ 0
XCK/T0
Text Notes 10300 4800 0    60   ~ 0
OC0B/T1
Text Notes 10300 4700 0    60   ~ 0
OC0A/AIN0
Text Notes 8800 4150 0    60   ~ 0
GND
Text Notes 8800 3950 0    60   ~ 0
3.3V
Text Notes 8800 4050 0    60   ~ 0
5V
Text Notes 8800 3850 0    60   ~ 0
RESET
Text Notes 10300 4600 0    60   ~ 0
AIN1
Text Label 5675 800  2    60   ~ 0
Speed1
Text Label 5675 1250 2    60   ~ 0
Speed2
Text Label 5450 2200 0    60   ~ 0
Udir
Text Label 5450 3100 0    60   ~ 0
Uad
Text Label 5600 6600 2    60   ~ 0
Utemp
Text Label 7925 4675 0    60   ~ 0
Udir
Text Label 7925 4775 0    60   ~ 0
Utemp
Text Label 7925 4875 0    60   ~ 0
Uac
Text Label 7925 4975 0    60   ~ 0
Udc
Text Label 9350 5050 0    60   ~ 0
Speed1
Text Label 9350 4950 0    60   ~ 0
Speed2
Text Label 8050 4000 0    60   ~ 0
5V
NoConn ~ 8300 4300
Text Label 5600 7400 2    60   ~ 0
RPM
Text Label 9400 4550 0    60   ~ 0
RPM
Text Notes 10300 3650 0    60   ~ 0
SDA
Text Notes 10300 3550 0    60   ~ 0
SCL
NoConn ~ 9800 3500
NoConn ~ 9800 3600
NoConn ~ 9800 3700
NoConn ~ 9800 3900
NoConn ~ 9800 4000
NoConn ~ 9800 4200
NoConn ~ 9800 4300
NoConn ~ 9800 4400
Text Notes 2000 7375 0    60   ~ 0
RPM\nSensor
NoConn ~ 9800 5150
NoConn ~ 9800 5250
NoConn ~ 9800 4100
Text Notes 8800 3750 0    60   ~ 0
IOREF
Text Notes 8800 4250 0    60   ~ 0
GND
Text Notes 8800 4350 0    60   ~ 0
Vin
Text Notes 8800 3650 0    60   ~ 0
Reserved
Text Notes 8600 3350 0    60   ~ 0
Arduino style but with Atmega 1284P
Text Label 3600 6500 2    60   ~ 0
temp_hi
Text Label 3600 6600 2    60   ~ 0
temp_lo
Text Notes 2525 6550 2    60   ~ 0
Temperature sensor
Text Label 3250 2200 0    60   ~ 0
vane_v-
Text Label 3250 2100 0    60   ~ 0
vane_v+
NoConn ~ 8300 3600
NoConn ~ 8300 3700
NoConn ~ 8300 3800
Text Notes 2475 1375 2    60   ~ 0
Anemometer2 : Hall effect or ILS
$Sheet
S 3900 6200 1400 800 
U 560A36CB
F0 "F5 Temperature" 50
F1 "F5_temperature.sch" 50
F2 "Utemp" O R 5300 6600 60 
F3 "temp_hi" I L 3900 6500 60 
F4 "temp_lo" I L 3900 6600 60 
$EndSheet
$Comp
L +5V #PWR01
U 1 1 573C32C6
P 3000 7100
F 0 "#PWR01" H 3000 6950 50  0001 C CNN
F 1 "+5V" H 3000 7240 50  0000 C CNN
F 2 "" H 3000 7100 50  0000 C CNN
F 3 "" H 3000 7100 50  0000 C CNN
	1    3000 7100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 573C3921
P 7950 4000
F 0 "#PWR02" H 7950 3850 50  0001 C CNN
F 1 "+5V" H 7950 4140 50  0000 C CNN
F 2 "" H 7950 4000 50  0000 C CNN
F 3 "" H 7950 4000 50  0000 C CNN
	1    7950 4000
	1    0    0    -1  
$EndComp
NoConn ~ 8300 3900
NoConn ~ 9800 4650
$Comp
L CONN_01X08 P118
U 1 1 57E71CF7
P 10000 5850
F 0 "P118" H 10000 6300 50  0000 C CNN
F 1 "Communication" V 10100 5850 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Socket_Strip_Arduino_1x08" H 10000 5850 50  0001 C CNN
F 3 "" H 10000 5850 50  0000 C CNN
	1    10000 5850
	1    0    0    -1  
$EndComp
Text Notes 8500 1300 2    60   ~ 0
+5V
Text Notes 8500 1550 2    60   ~ 0
GND
$Comp
L +5V #PWR03
U 1 1 57E72DB5
P 9700 1150
F 0 "#PWR03" H 9700 1000 50  0001 C CNN
F 1 "+5V" H 9700 1290 50  0000 C CNN
F 2 "" H 9700 1150 50  0000 C CNN
F 3 "" H 9700 1150 50  0000 C CNN
	1    9700 1150
	1    0    0    -1  
$EndComp
$Comp
L C C102
U 1 1 57E733BC
P 9600 1400
F 0 "C102" H 9625 1500 50  0000 L CNN
F 1 "C" H 9625 1300 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L6_P2.5" H 9638 1250 50  0001 C CNN
F 3 "" H 9600 1400 50  0000 C CNN
	1    9600 1400
	1    0    0    -1  
$EndComp
$Comp
L CP C101
U 1 1 57E734D2
P 9350 1400
F 0 "C101" H 9375 1500 50  0000 L CNN
F 1 "CP" H 9375 1300 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L6_P2.5" H 9388 1250 50  0001 C CNN
F 3 "" H 9350 1400 50  0000 C CNN
	1    9350 1400
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG04
U 1 1 57E743BD
P 10150 1150
F 0 "#FLG04" H 10150 1245 50  0001 C CNN
F 1 "PWR_FLAG" H 10150 1330 50  0000 C CNN
F 2 "" H 10150 1150 50  0000 C CNN
F 3 "" H 10150 1150 50  0000 C CNN
	1    10150 1150
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG05
U 1 1 57E7446B
P 10150 1550
F 0 "#FLG05" H 10150 1645 50  0001 C CNN
F 1 "PWR_FLAG" H 10150 1730 50  0000 C CNN
F 2 "" H 10150 1550 50  0000 C CNN
F 3 "" H 10150 1550 50  0000 C CNN
	1    10150 1550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P106
U 1 1 57E7A6F1
P 2675 4175
F 0 "P106" H 2675 4425 50  0000 C CNN
F 1 "current1" V 2775 4175 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-4pol" H 2675 4175 50  0001 C CNN
F 3 "" H 2675 4175 50  0000 C CNN
	1    2675 4175
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X04 P107
U 1 1 57E7A807
P 2675 4725
F 0 "P107" H 2675 4975 50  0000 C CNN
F 1 "current2" V 2775 4725 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-4pol" H 2675 4725 50  0001 C CNN
F 3 "" H 2675 4725 50  0000 C CNN
	1    2675 4725
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X04 P108
U 1 1 57E7A941
P 2675 5275
F 0 "P108" H 2675 5525 50  0000 C CNN
F 1 "current3" V 2775 5275 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-4pol" H 2675 5275 50  0001 C CNN
F 3 "" H 2675 5275 50  0000 C CNN
	1    2675 5275
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X04 P109
U 1 1 57E7AA46
P 2675 5775
F 0 "P109" H 2675 6025 50  0000 C CNN
F 1 "current4" V 2775 5775 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-4pol" H 2675 5775 50  0001 C CNN
F 3 "" H 2675 5775 50  0000 C CNN
	1    2675 5775
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR06
U 1 1 57E7ADEC
P 2975 3975
F 0 "#PWR06" H 2975 3825 50  0001 C CNN
F 1 "+5V" H 2975 4115 50  0000 C CNN
F 2 "" H 2975 3975 50  0000 C CNN
F 3 "" H 2975 3975 50  0000 C CNN
	1    2975 3975
	1    0    0    -1  
$EndComp
Text Notes 2450 4800 2    60   ~ 0
The 4 current sensor are design \nto are HTFS 200 or Hass 50-s
Text Notes 2475 3350 2    60   ~ 0
Ubat
Text Label 3600 3350 2    60   ~ 0
Ubat
$Comp
L CONN_01X08 P113
U 1 1 57E7EF3A
P 8500 5025
F 0 "P113" H 8500 5475 50  0000 C CNN
F 1 "Analog" V 8600 5025 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Socket_Strip_Arduino_1x08" H 8500 5025 50  0001 C CNN
F 3 "" H 8500 5025 50  0000 C CNN
	1    8500 5025
	1    0    0    -1  
$EndComp
NoConn ~ 9800 4750
NoConn ~ 9800 4850
Text Label 7925 5075 0    60   ~ 0
I1
Text Label 7925 5175 0    60   ~ 0
I2
Text Label 7925 5275 0    60   ~ 0
I3
Text Label 7925 5375 0    60   ~ 0
I4
$Comp
L CONN_01X04 P115
U 1 1 57E80721
P 9300 2200
F 0 "P115" H 9300 2450 50  0000 C CNN
F 1 "POWER_SOURCE" V 9450 2225 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04" H 9300 2200 50  0001 C CNN
F 3 "" H 9300 2200 50  0000 C CNN
	1    9300 2200
	1    0    0    -1  
$EndComp
Text Label 8750 2050 0    60   ~ 0
Ubat
Text Label 8750 2250 0    60   ~ 0
Uac_hi
Text Label 8750 2350 0    60   ~ 0
Uac_lo
Text Notes 8300 2625 0    60   ~ 0
To feed power supply from voltage sensor.\nThe power supply block is on the digital board.
Text Notes 2325 3525 0    60   ~ 0
gnd
$Comp
L CONN_01X02 P101
U 1 1 580078B6
P 2675 850
F 0 "P101" H 2650 1000 50  0000 C CNN
F 1 "anemo1" V 2775 850 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 2675 850 50  0001 C CNN
F 3 "" H 2675 850 50  0000 C CNN
	1    2675 850 
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P102
U 1 1 58007F6A
P 2675 1300
F 0 "P102" H 2650 1450 50  0000 C CNN
F 1 "anemo2" V 2775 1300 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 2675 1300 50  0001 C CNN
F 3 "" H 2675 1300 50  0000 C CNN
	1    2675 1300
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X03 P103
U 1 1 5800924D
P 2675 2200
F 0 "P103" H 2675 2400 50  0000 C CNN
F 1 "vane" V 2775 2200 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-3pol" H 2675 2200 50  0001 C CNN
F 3 "" H 2675 2200 50  0000 C CNN
	1    2675 2200
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P104
U 1 1 5800A29C
P 2675 3000
F 0 "P104" H 2675 3150 50  0000 C CNN
F 1 "AC_in" V 2775 3000 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 2675 3000 50  0001 C CNN
F 3 "" H 2675 3000 50  0000 C CNN
	1    2675 3000
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P105
U 1 1 5800A389
P 2675 3400
F 0 "P105" H 2675 3550 50  0000 C CNN
F 1 "DC_in" V 2775 3400 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 2675 3400 50  0001 C CNN
F 3 "" H 2675 3400 50  0000 C CNN
	1    2675 3400
	-1   0    0    1   
$EndComp
Text Label 5475 3500 0    60   ~ 0
Udc
$Comp
L CONN_01X02 P110
U 1 1 580177E1
P 2675 6550
F 0 "P110" H 2675 6700 50  0000 C CNN
F 1 "temp" V 2775 6550 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 2675 6550 50  0001 C CNN
F 3 "" H 2675 6550 50  0000 C CNN
	1    2675 6550
	-1   0    0    1   
$EndComp
Wire Wire Line
	2875 800  3900 800 
Wire Wire Line
	2875 1250 3900 1250
Wire Wire Line
	2875 2950 3900 2950
Wire Wire Line
	2875 3350 3900 3350
Wire Wire Line
	5300 800  5675 800 
Wire Wire Line
	5300 1250 5675 1250
Wire Wire Line
	7925 4675 8300 4675
Wire Wire Line
	7925 4775 8300 4775
Wire Wire Line
	7925 4875 8300 4875
Wire Wire Line
	7925 4975 8300 4975
Wire Wire Line
	7925 5075 8300 5075
Wire Wire Line
	7925 5175 8300 5175
Wire Wire Line
	5300 2200 5625 2200
Wire Wire Line
	5300 3100 5625 3100
Wire Wire Line
	5300 3500 5650 3500
Wire Wire Line
	5300 6600 5600 6600
Wire Wire Line
	2875 7375 3025 7375
Wire Wire Line
	3025 7375 3025 7425
Wire Wire Line
	9800 4550 9400 4550
Wire Wire Line
	9800 4950 9350 4950
Wire Wire Line
	9800 5050 9350 5050
Wire Wire Line
	9800 3800 9550 3800
Wire Wire Line
	9550 3800 9550 3900
Wire Wire Line
	7950 4100 7950 4350
Wire Wire Line
	7950 4100 8300 4100
Wire Wire Line
	2875 6500 3900 6500
Wire Wire Line
	2875 2200 3900 2200
Wire Wire Line
	2875 2100 3900 2100
Wire Wire Line
	2875 2300 3900 2300
Wire Wire Line
	2875 900  3075 900 
Wire Wire Line
	3075 900  3075 950 
Wire Wire Line
	2875 1350 3075 1350
Wire Wire Line
	3075 1350 3075 1400
Wire Wire Line
	2875 7275 3500 7275
Wire Wire Line
	9200 1400 9200 1600
Wire Wire Line
	9200 1200 9200 1300
Wire Wire Line
	9200 1300 9000 1300
Wire Wire Line
	9200 1600 10150 1600
Wire Wire Line
	9700 1600 9700 1650
Wire Wire Line
	9700 1200 9700 1150
Wire Wire Line
	9200 1200 10150 1200
Wire Wire Line
	9350 1250 9350 1200
Connection ~ 9350 1200
Wire Wire Line
	9600 1250 9600 1200
Connection ~ 9600 1200
Wire Wire Line
	9600 1550 9600 1600
Connection ~ 9600 1600
Wire Wire Line
	9350 1550 9350 1600
Connection ~ 9350 1600
Wire Wire Line
	7950 4200 8300 4200
Connection ~ 7950 4200
Wire Wire Line
	8300 4000 7950 4000
Wire Wire Line
	10150 1200 10150 1150
Connection ~ 9700 1200
Wire Wire Line
	10150 1600 10150 1550
Connection ~ 9700 1600
Wire Wire Line
	2875 4025 2975 4025
Wire Wire Line
	2975 3975 2975 5625
Wire Wire Line
	2975 4575 2875 4575
Connection ~ 2975 4025
Wire Wire Line
	2975 5125 2875 5125
Connection ~ 2975 4575
Wire Wire Line
	2975 5625 2875 5625
Connection ~ 2975 5125
Wire Wire Line
	2875 4125 3075 4125
Wire Wire Line
	3075 4125 3075 6025
Wire Wire Line
	2875 4675 3075 4675
Connection ~ 3075 4675
Wire Wire Line
	2875 5225 3075 5225
Connection ~ 3075 5225
Wire Wire Line
	2875 5725 3075 5725
Connection ~ 3075 5725
Wire Wire Line
	3500 5075 3500 5325
Wire Wire Line
	3500 5325 2875 5325
Wire Wire Line
	3900 5075 3500 5075
Wire Wire Line
	3900 5175 3600 5175
Wire Wire Line
	3600 5175 3600 5425
Wire Wire Line
	3600 5425 2875 5425
Wire Wire Line
	3900 4825 3725 4825
Wire Wire Line
	3725 4825 3725 4875
Wire Wire Line
	3725 4875 2875 4875
Wire Wire Line
	2875 4775 3675 4775
Wire Wire Line
	3675 4775 3675 4725
Wire Wire Line
	3675 4725 3900 4725
Wire Wire Line
	3900 4475 3575 4475
Wire Wire Line
	3575 4475 3575 4325
Wire Wire Line
	3575 4325 2875 4325
Wire Wire Line
	2875 4225 3650 4225
Wire Wire Line
	3650 4225 3650 4375
Wire Wire Line
	3650 4375 3900 4375
Wire Wire Line
	3900 5425 3675 5425
Wire Wire Line
	3675 5425 3675 5825
Wire Wire Line
	3675 5825 2875 5825
Wire Wire Line
	2875 5925 3750 5925
Wire Wire Line
	3750 5925 3750 5525
Wire Wire Line
	3750 5525 3900 5525
Wire Wire Line
	8300 5275 7925 5275
Wire Wire Line
	7925 5375 8300 5375
Wire Wire Line
	8750 2050 9100 2050
Wire Wire Line
	8750 2150 9100 2150
Wire Wire Line
	8750 2250 9100 2250
Wire Wire Line
	8750 2350 9100 2350
Wire Wire Line
	2975 3600 2975 3450
Wire Wire Line
	2975 3450 2875 3450
Wire Wire Line
	3900 3050 2875 3050
Wire Wire Line
	2875 6600 3900 6600
NoConn ~ 9800 5500
NoConn ~ 9800 5600
NoConn ~ 9800 5700
NoConn ~ 9800 5800
NoConn ~ 9800 5900
NoConn ~ 9800 6000
NoConn ~ 9800 6100
NoConn ~ 9800 6200
Text Label 8750 2150 0    60   ~ 0
gnd
Text Label 10000 1600 2    60   ~ 0
gnd
$Comp
L CONN_01X02 P111
U 1 1 58022AE3
P 2675 7325
F 0 "P111" H 2675 7475 50  0000 C CNN
F 1 "RPM" V 2775 7325 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 2675 7325 50  0001 C CNN
F 3 "" H 2675 7325 50  0000 C CNN
	1    2675 7325
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-Windlogger R101
U 1 1 560B9C15
P 3250 7150
F 0 "R101" V 3330 7150 40  0000 C CNN
F 1 "10k" V 3257 7151 40  0000 C CNN
F 2 "Discret:R4" V 3180 7150 30  0001 C CNN
F 3 "~" H 3250 7150 30  0000 C CNN
F 4 "0.125W" V 3250 7150 60  0001 C CNN "Puissance"
F 5 "1%" V 3250 7150 60  0001 C CNN "Tolérance"
	1    3250 7150
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 7150 3000 7100
Wire Wire Line
	3500 7150 3500 7400
Connection ~ 3500 7275
Wire Wire Line
	3500 7400 5600 7400
Text Notes 8225 925  0    60   ~ 0
alternative power supply to test or use this board alone
$Comp
L CONN_01X08 P112
U 1 1 5803D534
P 8500 3950
F 0 "P112" H 8500 4400 50  0000 C CNN
F 1 "Power" V 8600 3950 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Socket_Strip_Arduino_1x08" H 8500 3950 50  0001 C CNN
F 3 "" H 8500 3950 50  0000 C CNN
	1    8500 3950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 P117
U 1 1 5803DC4C
P 10000 4900
F 0 "P117" H 10000 5350 50  0000 C CNN
F 1 "PWM" V 10100 4900 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Socket_Strip_Arduino_1x08" H 10000 4900 50  0001 C CNN
F 3 "" H 10000 4900 50  0000 C CNN
	1    10000 4900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X10 P116
U 1 1 5803E61D
P 10000 3950
F 0 "P116" H 10000 4500 50  0000 C CNN
F 1 "PWM" V 10100 3950 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Socket_Strip_Arduino_1x10" H 10000 3950 50  0001 C CNN
F 3 "" H 10000 3950 50  0000 C CNN
	1    10000 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5803EC79
P 9700 1650
F 0 "#PWR07" H 9700 1400 50  0001 C CNN
F 1 "GND" H 9700 1500 50  0000 C CNN
F 2 "" H 9700 1650 50  0000 C CNN
F 3 "" H 9700 1650 50  0000 C CNN
	1    9700 1650
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P114
U 1 1 5803F54B
P 8800 1350
F 0 "P114" H 8800 1500 50  0000 C CNN
F 1 "5VDC" V 8900 1350 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x02" H 8800 1350 50  0001 C CNN
F 3 "" H 8800 1350 50  0000 C CNN
	1    8800 1350
	-1   0    0    1   
$EndComp
Wire Wire Line
	9000 1400 9200 1400
$Comp
L GND #PWR08
U 1 1 58041636
P 7950 4350
F 0 "#PWR08" H 7950 4100 50  0001 C CNN
F 1 "GND" H 7950 4200 50  0000 C CNN
F 2 "" H 7950 4350 50  0000 C CNN
F 3 "" H 7950 4350 50  0000 C CNN
	1    7950 4350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 58041ACE
P 9550 3900
F 0 "#PWR09" H 9550 3650 50  0001 C CNN
F 1 "GND" H 9550 3750 50  0000 C CNN
F 2 "" H 9550 3900 50  0000 C CNN
F 3 "" H 9550 3900 50  0000 C CNN
	1    9550 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 58042172
P 3025 7425
F 0 "#PWR010" H 3025 7175 50  0001 C CNN
F 1 "GND" H 3025 7275 50  0000 C CNN
F 2 "" H 3025 7425 50  0000 C CNN
F 3 "" H 3025 7425 50  0000 C CNN
	1    3025 7425
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 58043951
P 3075 6025
F 0 "#PWR011" H 3075 5775 50  0001 C CNN
F 1 "GND" H 3075 5875 50  0000 C CNN
F 2 "" H 3075 6025 50  0000 C CNN
F 3 "" H 3075 6025 50  0000 C CNN
	1    3075 6025
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 58044479
P 2975 3600
F 0 "#PWR012" H 2975 3350 50  0001 C CNN
F 1 "GND" H 2975 3450 50  0000 C CNN
F 2 "" H 2975 3600 50  0000 C CNN
F 3 "" H 2975 3600 50  0000 C CNN
	1    2975 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 58044D95
P 3075 950
F 0 "#PWR013" H 3075 700 50  0001 C CNN
F 1 "GND" H 3075 800 50  0000 C CNN
F 2 "" H 3075 950 50  0000 C CNN
F 3 "" H 3075 950 50  0000 C CNN
	1    3075 950 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 58044FD5
P 3075 1400
F 0 "#PWR014" H 3075 1150 50  0001 C CNN
F 1 "GND" H 3075 1250 50  0000 C CNN
F 2 "" H 3075 1400 50  0000 C CNN
F 3 "" H 3075 1400 50  0000 C CNN
	1    3075 1400
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P120
U 1 1 5803AC24
P 7300 6050
F 0 "P120" H 7575 6050 50  0000 C CNN
F 1 "h2" H 7400 6050 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 7300 6050 50  0001 C CNN
F 3 "" H 7300 6050 50  0000 C CNN
	1    7300 6050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P121
U 1 1 5803AD27
P 7300 6175
F 0 "P121" H 7575 6175 50  0000 C CNN
F 1 "h3" H 7400 6175 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 7300 6175 50  0001 C CNN
F 3 "" H 7300 6175 50  0000 C CNN
	1    7300 6175
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P122
U 1 1 5803AE2D
P 7300 6300
F 0 "P122" H 7575 6300 50  0000 C CNN
F 1 "h4" H 7400 6300 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 7300 6300 50  0001 C CNN
F 3 "" H 7300 6300 50  0000 C CNN
	1    7300 6300
	1    0    0    -1  
$EndComp
NoConn ~ 7100 6050
NoConn ~ 7100 6175
NoConn ~ 7100 6300
$Comp
L CONN_01X01 P123
U 1 1 5803B1D2
P 8075 5925
F 0 "P123" H 8350 5925 50  0000 C CNN
F 1 "h5" H 8175 5925 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 8075 5925 50  0001 C CNN
F 3 "" H 8075 5925 50  0000 C CNN
	1    8075 5925
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P124
U 1 1 5803B1D8
P 8075 6050
F 0 "P124" H 8350 6050 50  0000 C CNN
F 1 "h6" H 8175 6050 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 8075 6050 50  0001 C CNN
F 3 "" H 8075 6050 50  0000 C CNN
	1    8075 6050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P125
U 1 1 5803B1DE
P 8075 6175
F 0 "P125" H 8350 6175 50  0000 C CNN
F 1 "h7" H 8175 6175 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 8075 6175 50  0001 C CNN
F 3 "" H 8075 6175 50  0000 C CNN
	1    8075 6175
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P126
U 1 1 5803B1E4
P 8075 6300
F 0 "P126" H 8350 6300 50  0000 C CNN
F 1 "h8" H 8175 6300 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 8075 6300 50  0001 C CNN
F 3 "" H 8075 6300 50  0000 C CNN
	1    8075 6300
	1    0    0    -1  
$EndComp
NoConn ~ 7875 5925
NoConn ~ 7875 6050
NoConn ~ 7875 6175
NoConn ~ 7875 6300
Text Notes 7425 5825 0    60   ~ 0
Fixation Holes
$EndSCHEMATC
