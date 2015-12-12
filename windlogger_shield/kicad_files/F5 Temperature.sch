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
Sheet 7 7
Title "Fonction Température"
Date "12 dec 2015"
Rev ""
Comp "Wind Empowerment"
Comment1 "GIRAULT Etienne"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L THERMISTOR NTC701
U 1 1 56151420
P 4100 4050
F 0 "NTC701" V 4200 4100 50  0000 C CNN
F 1 "2.2k" V 4000 4050 50  0000 C CNN
F 2 "SM0805" H 4100 4050 60  0001 C CNN
F 3 "~" H 4100 4050 60  0000 C CNN
F 4 "1%" V 4100 4050 60  0001 C CNN "Tolérance"
	1    4100 4050
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR070
U 1 1 561521EF
P 4100 2600
F 0 "#PWR070" H 4100 2560 30  0001 C CNN
F 1 "+3.3V" H 4100 2710 30  0000 C CNN
F 2 "" H 4100 2600 60  0000 C CNN
F 3 "" H 4100 2600 60  0000 C CNN
	1    4100 2600
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR071
U 1 1 56152203
P 4100 5250
F 0 "#PWR071" H 4100 5250 40  0001 C CNN
F 1 "AGND" H 4100 5180 50  0000 C CNN
F 2 "" H 4100 5250 60  0000 C CNN
F 3 "" H 4100 5250 60  0000 C CNN
	1    4100 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 2600 4100 2750
Wire Wire Line
	4100 3250 4100 3800
Wire Wire Line
	4100 4300 4100 4600
$Comp
L LM358 U701
U 1 1 561522D1
P 6000 3700
F 0 "U701" H 5950 3900 60  0000 L CNN
F 1 "LMV358" H 5950 3450 60  0000 L CNN
F 2 "SO8N" H 6000 3700 60  0001 C CNN
F 3 "" H 6000 3700 60  0000 C CNN
	1    6000 3700
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR072
U 1 1 561522E6
P 5900 4250
F 0 "#PWR072" H 5900 4250 40  0001 C CNN
F 1 "AGND" H 5900 4180 50  0000 C CNN
F 2 "" H 5900 4250 60  0000 C CNN
F 3 "" H 5900 4250 60  0000 C CNN
	1    5900 4250
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR073
U 1 1 561522F5
P 5900 3150
F 0 "#PWR073" H 5900 3110 30  0001 C CNN
F 1 "+3.3V" H 5900 3260 30  0000 C CNN
F 2 "" H 5900 3150 60  0000 C CNN
F 3 "" H 5900 3150 60  0000 C CNN
	1    5900 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3300 5900 3150
Wire Wire Line
	5900 4100 5900 4250
Wire Wire Line
	5200 3800 5500 3800
Wire Wire Line
	6500 3700 7050 3700
Text HLabel 9700 3600 2    60   Output ~ 0
Utemp
$Comp
L C C701
U 1 1 5615255D
P 7250 5500
F 0 "C701" H 7250 5600 40  0000 L CNN
F 1 "100nF" H 7256 5415 40  0000 L CNN
F 2 "SM0805" H 7288 5350 30  0001 C CNN
F 3 "~" H 7250 5500 60  0000 C CNN
F 4 "25V" H 7250 5500 60  0001 C CNN "Tension"
	1    7250 5500
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR074
U 1 1 5615256C
P 7250 5150
F 0 "#PWR074" H 7250 5110 30  0001 C CNN
F 1 "+3.3V" H 7250 5260 30  0000 C CNN
F 2 "" H 7250 5150 60  0000 C CNN
F 3 "" H 7250 5150 60  0000 C CNN
	1    7250 5150
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR075
U 1 1 5615257B
P 7250 5850
F 0 "#PWR075" H 7250 5850 40  0001 C CNN
F 1 "AGND" H 7250 5780 50  0000 C CNN
F 2 "" H 7250 5850 60  0000 C CNN
F 3 "" H 7250 5850 60  0000 C CNN
	1    7250 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 5300 7250 5150
Wire Wire Line
	7250 5700 7250 5850
Wire Wire Line
	3300 4400 4500 4400
Connection ~ 4100 4400
Text HLabel 3300 3600 0    60   Input ~ 0
temp_hi
Text HLabel 3300 4400 0    60   Input ~ 0
temp_lo
$Comp
L R R701
U 1 1 561E1EE7
P 4100 3000
F 0 "R701" V 4180 3000 40  0000 C CNN
F 1 "20k" V 4107 3001 40  0000 C CNN
F 2 "SM0805" V 4030 3000 30  0001 C CNN
F 3 "~" H 4100 3000 30  0000 C CNN
F 4 "0.125W" V 4100 3000 60  0001 C CNN "Puissance"
F 5 "1%" V 4100 3000 60  0001 C CNN "Tolérance"
	1    4100 3000
	1    0    0    -1  
$EndComp
$Comp
L R R703
U 1 1 5624BBCD
P 4100 4850
F 0 "R703" V 4180 4850 40  0000 C CNN
F 1 "20k" V 4107 4851 40  0000 C CNN
F 2 "SM0805" V 4030 4850 30  0001 C CNN
F 3 "~" H 4100 4850 30  0000 C CNN
	1    4100 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 5100 4100 5250
$Comp
L LM358 U701
U 2 1 5627929A
P 8600 3600
F 0 "U701" H 8550 3800 60  0000 L CNN
F 1 "LMV358" H 8550 3350 60  0000 L CNN
F 2 "SO8N" H 8600 3600 60  0001 C CNN
F 3 "" H 8600 3600 60  0000 C CNN
	2    8600 3600
	1    0    0    -1  
$EndComp
$Comp
L R R702
U 1 1 562792A9
P 5200 4250
F 0 "R702" V 5280 4250 40  0000 C CNN
F 1 "10k" V 5207 4251 40  0000 C CNN
F 2 "SM0805" V 5130 4250 30  0001 C CNN
F 3 "~" H 5200 4250 30  0000 C CNN
F 4 "1%" V 5200 4250 60  0001 C CNN "Tolérance"
F 5 "1/8W" V 5200 4250 60  0001 C CNN "Puissance"
	1    5200 4250
	1    0    0    -1  
$EndComp
$Comp
L R R704
U 1 1 562792B8
P 5900 4700
F 0 "R704" V 5980 4700 40  0000 C CNN
F 1 "10k" V 5907 4701 40  0000 C CNN
F 2 "SM0805" V 5830 4700 30  0001 C CNN
F 3 "~" H 5900 4700 30  0000 C CNN
F 4 "1%" V 5900 4700 60  0001 C CNN "Tolérance"
F 5 "1/8W" V 5900 4700 60  0001 C CNN "Puissance"
	1    5900 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 3800 5200 4000
Wire Wire Line
	5200 4500 5200 5200
Wire Wire Line
	5650 4700 5200 4700
Connection ~ 5200 4700
Wire Wire Line
	6150 4700 6650 4700
Wire Wire Line
	6650 4700 6650 3700
Connection ~ 6650 3700
$Comp
L R R705
U 1 1 5627934E
P 7300 3700
F 0 "R705" V 7380 3700 40  0000 C CNN
F 1 "10k" V 7307 3701 40  0000 C CNN
F 2 "SM0805" V 7230 3700 30  0001 C CNN
F 3 "~" H 7300 3700 30  0000 C CNN
F 4 "1%" V 7300 3700 60  0001 C CNN "Tolérance"
F 5 "1/8W" V 7300 3700 60  0001 C CNN "Puissance"
	1    7300 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7550 3700 8100 3700
$Comp
L AGND #PWR076
U 1 1 56279377
P 5200 5200
F 0 "#PWR076" H 5200 5200 40  0001 C CNN
F 1 "AGND" H 5200 5130 50  0000 C CNN
F 2 "" H 5200 5200 60  0000 C CNN
F 3 "" H 5200 5200 60  0000 C CNN
	1    5200 5200
	1    0    0    -1  
$EndComp
$Comp
L R R706
U 1 1 562793BC
P 8500 4700
F 0 "R706" V 8580 4700 40  0000 C CNN
F 1 "10k" V 8507 4701 40  0000 C CNN
F 2 "SM0805" V 8430 4700 30  0001 C CNN
F 3 "~" H 8500 4700 30  0000 C CNN
F 4 "1%" V 8500 4700 60  0001 C CNN "Tolérance"
F 5 "1/8W" V 8500 4700 60  0001 C CNN "Puissance"
	1    8500 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7800 3700 7800 4700
Wire Wire Line
	7800 4700 8250 4700
Connection ~ 7800 3700
Wire Wire Line
	9100 3600 9700 3600
Wire Wire Line
	8500 3000 8500 3200
$Comp
L +3.3V #PWR077
U 1 1 56279444
P 8500 3000
F 0 "#PWR077" H 8500 2960 30  0001 C CNN
F 1 "+3.3V" H 8500 3110 30  0000 C CNN
F 2 "" H 8500 3000 60  0000 C CNN
F 3 "" H 8500 3000 60  0000 C CNN
	1    8500 3000
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR078
U 1 1 56279453
P 8500 4250
F 0 "#PWR078" H 8500 4250 40  0001 C CNN
F 1 "AGND" H 8500 4150 50  0000 C CNN
F 2 "" H 8500 4250 60  0000 C CNN
F 3 "" H 8500 4250 60  0000 C CNN
	1    8500 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 4000 8500 4250
Wire Wire Line
	8750 4700 9400 4700
Wire Wire Line
	9400 4700 9400 3600
Connection ~ 9400 3600
Wire Wire Line
	4500 4400 4500 3600
Wire Wire Line
	4500 3600 5500 3600
Wire Wire Line
	3300 3600 4300 3600
Connection ~ 4100 3600
Wire Wire Line
	4300 3600 4300 2900
Wire Wire Line
	4300 2900 7800 2900
Wire Wire Line
	7800 2900 7800 3500
Wire Wire Line
	7800 3500 8100 3500
$EndSCHEMATC
