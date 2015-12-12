EESchema Schematic File Version 2
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
LIBS:special
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
LIBS:Windlogger-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 7
Title "Fonction Wattmètre DC"
Date "12 dec 2015"
Rev ""
Comp "Wind Empowerment"
Comment1 "GIRAULT Etienne"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3050 2950 4650 2950
Text HLabel 3050 2950 0    60   Input ~ 0
UDC_hi
$Comp
L R R503
U 1 1 561287F5
P 4650 4800
F 0 "R503" V 4730 4800 40  0000 C CNN
F 1 "10k" V 4657 4801 40  0000 C CNN
F 2 "SM0805" V 4580 4800 30  0001 C CNN
F 3 "~" H 4650 4800 30  0000 C CNN
F 4 "0.125W" V 4650 4800 60  0001 C CNN "Puissance"
F 5 "1%" V 4650 4800 60  0001 C CNN "Tolérance"
	1    4650 4800
	1    0    0    -1  
$EndComp
$Comp
L LM358 U301
U 2 1 56128804
P 6600 4550
F 0 "U301" H 6550 4750 60  0000 L CNN
F 1 "LMV358" H 6550 4300 60  0000 L CNN
F 2 "SO8N" H 6600 4550 60  0001 C CNN
F 3 "" H 6600 4550 60  0000 C CNN
	2    6600 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 5050 4650 5450
$Comp
L AGND #PWR054
U 1 1 5612881E
P 4650 5450
F 0 "#PWR054" H 4650 5450 40  0001 C CNN
F 1 "AGND" H 4650 5380 50  0000 C CNN
F 2 "" H 4650 5450 60  0000 C CNN
F 3 "" H 4650 5450 60  0000 C CNN
	1    4650 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 4550 7650 4550
Wire Wire Line
	6100 4650 5900 4650
Wire Wire Line
	5900 4650 5900 5250
Wire Wire Line
	5900 5250 7350 5250
Wire Wire Line
	7350 5250 7350 4550
Connection ~ 7350 4550
$Comp
L AGND #PWR055
U 1 1 56128847
P 6500 5100
F 0 "#PWR055" H 6500 5100 40  0001 C CNN
F 1 "AGND" H 6500 5030 50  0000 C CNN
F 2 "" H 6500 5100 60  0000 C CNN
F 3 "" H 6500 5100 60  0000 C CNN
	1    6500 5100
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR056
U 1 1 56128856
P 6500 3950
F 0 "#PWR056" H 6500 3910 30  0001 C CNN
F 1 "+3.3V" H 6500 4060 30  0000 C CNN
F 2 "" H 6500 3950 60  0000 C CNN
F 3 "" H 6500 3950 60  0000 C CNN
	1    6500 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 4150 6500 3950
Wire Wire Line
	6500 4950 6500 5100
Text HLabel 7650 4550 2    60   Output ~ 0
Ubat
$Comp
L JUMPER3 JP501
U 1 1 561BC8BD
P 4650 3150
F 0 "JP501" H 4700 3050 40  0000 L CNN
F 1 "JUMPER3" H 4650 3250 40  0000 C CNN
F 2 "PIN_ARRAY_3X1_Windlogger" H 4650 3150 60  0001 C CNN
F 3 "~" H 4650 3150 60  0000 C CNN
	1    4650 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4300 3150 4400 3150
Wire Wire Line
	4900 3150 5000 3150
Text Label 4350 3150 2    60   ~ 0
64V
Text Label 4950 3150 0    60   ~ 0
640V
Wire Wire Line
	4300 4100 4300 4350
Wire Wire Line
	4300 4350 5000 4350
Wire Wire Line
	5000 4350 5000 4100
Wire Wire Line
	4650 4350 4650 4550
Connection ~ 4650 4350
Wire Wire Line
	4650 4450 6100 4450
Connection ~ 4650 4450
Text Notes 3800 3200 2    60   ~ 0
Use the jumper to select the maximum voltage :\n64V for Battery system\n640V to monitor a DC bus from an on grid system
$Comp
L R R501
U 1 1 561E1CF9
P 4300 3850
F 0 "R501" V 4380 3850 40  0000 C CNN
F 1 "360k" V 4307 3851 40  0000 C CNN
F 2 "SM0805" V 4230 3850 30  0001 C CNN
F 3 "~" H 4300 3850 30  0000 C CNN
F 4 "0.125W" V 4300 3850 60  0001 C CNN "Puissance"
F 5 "1%" V 4300 3850 60  0001 C CNN "Tolérance"
	1    4300 3850
	1    0    0    -1  
$EndComp
$Comp
L R R504
U 1 1 561E1D08
P 5000 3850
F 0 "R504" V 5080 3850 40  0000 C CNN
F 1 "3.3M" V 5007 3851 40  0000 C CNN
F 2 "SM0805" V 4930 3850 30  0001 C CNN
F 3 "~" H 5000 3850 30  0000 C CNN
F 4 "0.125W" V 5000 3850 60  0001 C CNN "Puissance"
F 5 "1%" V 5000 3850 60  0001 C CNN "Tolérance"
	1    5000 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3150 5000 3600
Wire Wire Line
	4300 3150 4300 3600
$Comp
L DIODE D501
U 1 1 561FC38B
P 5500 4100
F 0 "D501" H 5500 4200 40  0000 C CNN
F 1 "1N4148" H 5500 4000 40  0000 C CNN
F 2 "SOD-323" H 5500 4100 60  0001 C CNN
F 3 "~" H 5500 4100 60  0000 C CNN
	1    5500 4100
	0    -1   -1   0   
$EndComp
$Comp
L DIODE D502
U 1 1 561FC398
P 5500 4800
F 0 "D502" H 5500 4900 40  0000 C CNN
F 1 "1N4148" H 5500 4700 40  0000 C CNN
F 2 "SOD-323" H 5500 4800 60  0001 C CNN
F 3 "~" H 5500 4800 60  0000 C CNN
	1    5500 4800
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR057
U 1 1 561FC3A0
P 5500 3700
F 0 "#PWR057" H 5500 3660 30  0001 C CNN
F 1 "+3.3V" H 5500 3810 30  0000 C CNN
F 2 "" H 5500 3700 60  0000 C CNN
F 3 "" H 5500 3700 60  0000 C CNN
	1    5500 3700
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR058
U 1 1 561FC3AF
P 5500 5200
F 0 "#PWR058" H 5500 5200 40  0001 C CNN
F 1 "AGND" H 5500 5130 50  0000 C CNN
F 2 "" H 5500 5200 60  0000 C CNN
F 3 "" H 5500 5200 60  0000 C CNN
	1    5500 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3700 5500 3900
Wire Wire Line
	5500 4300 5500 4600
Connection ~ 5500 4450
Wire Wire Line
	5500 5000 5500 5200
Wire Wire Line
	4650 2950 4650 3050
$EndSCHEMATC
