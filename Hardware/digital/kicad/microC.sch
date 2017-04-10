EESchema Schematic File Version 2
LIBS:digital
LIBS:ftdi
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
LIBS:Hope_RFM
LIBS:Oscillators
LIBS:dc-dc
LIBS:lm2672
LIBS:digital-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
Title "Windlogger digital"
Date "2017-03-28"
Rev "1.1.1"
Comp "ALEEA"
Comment1 "LONGUET Gilles"
Comment2 "AGPL3"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L C C2
U 1 1 58752FE3
P 3825 2575
F 0 "C2" H 3825 2675 40  0000 L CNN
F 1 "18p" H 3831 2490 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 3925 2425 30  0001 C CNN
F 3 "~" H 3825 2575 60  0000 C CNN
	1    3825 2575
	0    -1   -1   0   
$EndComp
$Comp
L C C3
U 1 1 58752FEA
P 3825 2975
F 0 "C3" H 3825 3075 40  0000 L CNN
F 1 "18p" H 3831 2890 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 3863 2825 30  0001 C CNN
F 3 "~" H 3825 2975 60  0000 C CNN
	1    3825 2975
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 58752FF8
P 3275 1950
F 0 "R2" V 3355 1950 40  0000 C CNN
F 1 "470k" V 3282 1951 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3205 1950 30  0001 C CNN
F 3 "~" H 3275 1950 30  0000 C CNN
	1    3275 1950
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 58752FFF
P 2400 5450
F 0 "C5" H 2400 5550 40  0000 L CNN
F 1 "100n" H 2406 5365 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2.5_P5" H 2500 5300 30  0001 C CNN
F 3 "~" H 2400 5450 60  0000 C CNN
	1    2400 5450
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 58753006
P 2700 5450
F 0 "C6" H 2700 5550 40  0000 L CNN
F 1 "100n" H 2706 5365 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2.5_P5" H 2800 5300 30  0001 C CNN
F 3 "~" H 2700 5450 60  0000 C CNN
	1    2700 5450
	1    0    0    -1  
$EndComp
Text Label 3975 3375 0    60   ~ 0
AREF
$Comp
L C C4
U 1 1 5875301E
P 3975 3600
F 0 "C4" H 3975 3700 40  0000 L CNN
F 1 "100n" H 3981 3515 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2.5_P5" H 4075 3450 30  0001 C CNN
F 3 "~" H 3975 3600 60  0000 C CNN
	1    3975 3600
	1    0    0    -1  
$EndComp
Text Label 3875 2175 0    60   ~ 0
RESET
Text Notes 3775 3175 0    60   ~ 0
Main crystal
$Comp
L Crystal X2
U 1 1 5875302A
P 7225 4675
F 0 "X2" V 7425 4625 60  0000 C CNN
F 1 "32.768Hz" V 7000 4650 60  0000 C CNN
F 2 "Crystals:Crystal_Round_Horizontal_3mm_BigPad" H 7225 4675 60  0001 C CNN
F 3 "" H 7225 4675 60  0000 C CNN
	1    7225 4675
	0    1    -1   0   
$EndComp
$Comp
L C C7
U 1 1 58753031
P 7550 4525
F 0 "C7" H 7550 4625 40  0000 L CNN
F 1 "12p" H 7556 4440 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 7588 4375 30  0001 C CNN
F 3 "" H 7550 4525 60  0000 C CNN
	1    7550 4525
	0    1    1    0   
$EndComp
$Comp
L C C8
U 1 1 58753038
P 7550 4825
F 0 "C8" H 7550 4925 40  0000 L CNN
F 1 "12p" H 7556 4740 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 7588 4675 30  0001 C CNN
F 3 "" H 7550 4825 60  0000 C CNN
	1    7550 4825
	0    1    1    0   
$EndComp
$Comp
L GND #PWR08
U 1 1 5875303F
P 7825 4675
F 0 "#PWR08" H 7825 4425 50  0001 C CNN
F 1 "GND" H 7825 4525 50  0000 C CNN
F 2 "" H 7825 4675 50  0000 C CNN
F 3 "" H 7825 4675 50  0000 C CNN
	1    7825 4675
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 58753045
P 2400 5675
F 0 "#PWR09" H 2400 5425 50  0001 C CNN
F 1 "GND" H 2400 5525 50  0000 C CNN
F 2 "" H 2400 5675 50  0000 C CNN
F 3 "" H 2400 5675 50  0000 C CNN
	1    2400 5675
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 5875304B
P 2400 5225
F 0 "#PWR010" H 2400 5075 50  0001 C CNN
F 1 "+5V" H 2400 5365 50  0000 C CNN
F 2 "" H 2400 5225 50  0000 C CNN
F 3 "" H 2400 5225 50  0000 C CNN
	1    2400 5225
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 58753051
P 5125 5950
F 0 "#PWR011" H 5125 5700 50  0001 C CNN
F 1 "GND" H 5125 5800 50  0000 C CNN
F 2 "" H 5125 5950 50  0000 C CNN
F 3 "" H 5125 5950 50  0000 C CNN
	1    5125 5950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 58753057
P 3975 3800
F 0 "#PWR012" H 3975 3550 50  0001 C CNN
F 1 "GND" H 3975 3650 50  0000 C CNN
F 2 "" H 3975 3800 50  0000 C CNN
F 3 "" H 3975 3800 50  0000 C CNN
	1    3975 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 5875305D
P 2875 2650
F 0 "#PWR013" H 2875 2400 50  0001 C CNN
F 1 "GND" H 2875 2500 50  0000 C CNN
F 2 "" H 2875 2650 50  0000 C CNN
F 3 "" H 2875 2650 50  0000 C CNN
	1    2875 2650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 58753063
P 3275 1775
F 0 "#PWR014" H 3275 1625 50  0001 C CNN
F 1 "+5V" H 3275 1915 50  0000 C CNN
F 2 "" H 3275 1775 50  0000 C CNN
F 3 "" H 3275 1775 50  0000 C CNN
	1    3275 1775
	1    0    0    -1  
$EndComp
$Comp
L Crystal X1
U 1 1 58753069
P 4150 2750
F 0 "X1" H 4150 2900 60  0000 C CNN
F 1 "16M" H 4150 2600 60  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 4150 3000 60  0001 C CNN
F 3 "~" H 4150 2750 60  0000 C CNN
	1    4150 2750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR015
U 1 1 58753070
P 3525 2775
F 0 "#PWR015" H 3525 2525 50  0001 C CNN
F 1 "GND" H 3525 2625 50  0000 C CNN
F 2 "" H 3525 2775 50  0000 C CNN
F 3 "" H 3525 2775 50  0000 C CNN
	1    3525 2775
	1    0    0    -1  
$EndComp
Wire Wire Line
	5275 5900 5275 5875
Wire Wire Line
	5075 5875 5075 5900
Wire Wire Line
	6275 4575 6975 4575
Wire Wire Line
	6275 4675 6975 4675
Wire Wire Line
	5125 5900 5125 5950
Connection ~ 3275 2175
Wire Wire Line
	2875 2175 2875 2300
Wire Wire Line
	2725 2175 4275 2175
Wire Wire Line
	3975 3375 3975 3450
Wire Wire Line
	3975 3800 3975 3750
Wire Wire Line
	3275 1775 3275 1800
Wire Wire Line
	3975 2975 4275 2975
Wire Wire Line
	4150 2900 4150 2975
Connection ~ 4150 2975
Wire Wire Line
	3975 2575 4275 2575
Wire Wire Line
	4150 2600 4150 2575
Connection ~ 4150 2575
Wire Wire Line
	3650 2975 3675 2975
Wire Wire Line
	3650 2575 3650 2975
Wire Wire Line
	3650 2575 3675 2575
Wire Wire Line
	3525 2775 3525 2725
Wire Wire Line
	3525 2725 3650 2725
Connection ~ 3650 2725
Wire Wire Line
	2400 5675 2400 5600
Wire Wire Line
	2400 5225 2400 5300
$Comp
L +5V #PWR016
U 1 1 587530B7
P 5175 1725
F 0 "#PWR016" H 5175 1575 50  0001 C CNN
F 1 "+5V" H 5175 1865 50  0000 C CNN
F 2 "" H 5175 1725 50  0000 C CNN
F 3 "" H 5175 1725 50  0000 C CNN
	1    5175 1725
	1    0    0    -1  
$EndComp
Wire Wire Line
	6975 4575 6975 4525
Wire Wire Line
	6975 4525 7400 4525
Wire Wire Line
	6975 4825 7400 4825
Wire Wire Line
	6975 4675 6975 4825
Connection ~ 7225 4525
Connection ~ 7225 4825
Wire Wire Line
	7725 4825 7700 4825
Wire Wire Line
	7725 4525 7725 4825
Wire Wire Line
	7725 4525 7700 4525
Wire Wire Line
	7825 4675 7725 4675
Connection ~ 7725 4675
Wire Wire Line
	2875 2650 2875 2600
Text Notes 7200 4350 0    60   ~ 0
RTC crystal
Text Notes 2600 3250 0    60   ~ 0
Reset button
Wire Wire Line
	3275 2175 3275 2100
Wire Wire Line
	6525 2175 6275 2175
Wire Wire Line
	6525 2275 6275 2275
Wire Wire Line
	6525 2375 6275 2375
Wire Wire Line
	6525 2475 6275 2475
Wire Wire Line
	6525 2575 6275 2575
Wire Wire Line
	6525 2675 6275 2675
Wire Wire Line
	6525 2775 6275 2775
Wire Wire Line
	6525 2875 6275 2875
Wire Wire Line
	6525 3075 6275 3075
Wire Wire Line
	6525 3175 6275 3175
Wire Wire Line
	6525 3275 6275 3275
Wire Wire Line
	6525 3375 6275 3375
Wire Wire Line
	6525 3475 6275 3475
Wire Wire Line
	6525 3575 6275 3575
Wire Wire Line
	6525 3675 6275 3675
Wire Wire Line
	6525 3775 6275 3775
Wire Wire Line
	6525 4875 6275 4875
Wire Wire Line
	6525 4975 6275 4975
Wire Wire Line
	6525 5075 6275 5075
Wire Wire Line
	6525 5175 6275 5175
Wire Wire Line
	6525 5275 6275 5275
Wire Wire Line
	6525 5375 6275 5375
Wire Wire Line
	6525 5475 6275 5475
Wire Wire Line
	6525 5575 6275 5575
Wire Wire Line
	6525 3975 6275 3975
Wire Wire Line
	6525 4075 6275 4075
Wire Wire Line
	6525 4175 6275 4175
Wire Wire Line
	6525 4275 6275 4275
Wire Wire Line
	6525 4375 6275 4375
Wire Wire Line
	6525 4475 6275 4475
Text HLabel 6525 2175 2    60   Input ~ 0
ACD0
Text HLabel 6525 2275 2    60   Input ~ 0
ACD1
Text HLabel 6525 2375 2    60   Input ~ 0
ACD2
Text HLabel 6525 2475 2    60   Input ~ 0
ACD3
Text HLabel 6525 2575 2    60   Input ~ 0
ACD4
Text HLabel 6525 2675 2    60   Input ~ 0
ACD5
Text HLabel 6525 2775 2    60   Input ~ 0
ACD6
Text HLabel 6525 2875 2    60   Input ~ 0
ACD7
Text HLabel 6525 3075 2    60   Input ~ 0
PB0
Text HLabel 6525 3175 2    60   Input ~ 0
PB1
Text HLabel 6525 3275 2    60   Input ~ 0
PB2
Text HLabel 6525 3375 2    60   Input ~ 0
PB3
Text HLabel 6525 3475 2    60   Input ~ 0
PB4
Text HLabel 6525 3575 2    60   Input ~ 0
PB5
Text HLabel 6525 3675 2    60   Input ~ 0
PB6
Text HLabel 6525 3775 2    60   Input ~ 0
PB7
Text HLabel 6525 3975 2    60   Input ~ 0
PC0
Text HLabel 6525 4075 2    60   Input ~ 0
PC1
Text HLabel 6525 4175 2    60   Input ~ 0
PC2
Text HLabel 6525 4275 2    60   Input ~ 0
PC3
Text HLabel 6525 4375 2    60   Input ~ 0
PC4
Text HLabel 6525 4475 2    60   Input ~ 0
PC5
Text HLabel 6525 4875 2    60   Input ~ 0
PD0
Text HLabel 6525 4975 2    60   Input ~ 0
PD1
Text HLabel 6525 5075 2    60   Input ~ 0
PD2
Text HLabel 6525 5175 2    60   Input ~ 0
PD3
Text HLabel 6525 5275 2    60   Input ~ 0
PD4
Text HLabel 6525 5375 2    60   Input ~ 0
PD5
Text HLabel 6525 5475 2    60   Input ~ 0
PD6
Text HLabel 6525 5575 2    60   Input ~ 0
PD7
Text HLabel 3800 1850 0    60   Input ~ 0
RESET
Wire Wire Line
	3800 1850 3800 2175
Connection ~ 3800 2175
Text HLabel 3550 3375 0    60   Input ~ 0
AREF
Connection ~ 3975 3375
Wire Wire Line
	3550 3375 4275 3375
Wire Wire Line
	5075 1875 5075 1775
$Comp
L button-touch-6x6mm SW1
U 1 1 5885D018
P 2800 2450
F 0 "SW1" H 2805 2280 50  0000 C CNN
F 1 "button-touch-6x6mm" H 2835 2630 50  0000 C CNN
F 2 "digital:button-touch-6x6mm" H 2125 2850 50  0001 C CNN
F 3 "" H 2125 2850 50  0000 C CNN
	1    2800 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2725 2300 2725 2175
Connection ~ 2875 2175
Wire Wire Line
	2725 2600 2725 2650
Wire Wire Line
	2725 2650 2875 2650
Connection ~ 2875 2650
$Comp
L PWR_FLAG #FLG017
U 1 1 587FC76C
P 3600 3350
F 0 "#FLG017" H 3600 3445 50  0001 C CNN
F 1 "PWR_FLAG" H 3600 3530 50  0000 C CNN
F 2 "" H 3600 3350 50  0000 C CNN
F 3 "" H 3600 3350 50  0000 C CNN
	1    3600 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3375 3600 3350
Connection ~ 3600 3375
Wire Wire Line
	5275 1775 5275 1875
Wire Wire Line
	5175 1775 5175 1725
Connection ~ 5175 1775
Wire Wire Line
	5075 5900 5275 5900
Connection ~ 5125 5900
$Comp
L ATMEGA1284P-P IC1
U 1 1 58B70CC5
P 5275 3875
F 0 "IC1" H 4425 5755 50  0000 L BNN
F 1 "ATMEGA1284P-P" H 5675 1925 50  0000 L BNN
F 2 "Housings_DIP:DIP-40_W15.24mm_LongPads" H 5275 3875 50  0000 C CIN
F 3 "" H 5275 3875 50  0000 C CNN
	1    5275 3875
	1    0    0    -1  
$EndComp
Wire Wire Line
	5075 1775 5275 1775
Wire Wire Line
	2700 5300 2700 5275
Wire Wire Line
	2700 5275 2400 5275
Connection ~ 2400 5275
Wire Wire Line
	2700 5600 2700 5625
Wire Wire Line
	2700 5625 2400 5625
Connection ~ 2400 5625
Text Notes 7950 4550 0    60   ~ 0
Vérifier si on peut trouver un quartz avec condensateur 6pF dans ce cas pas besoin de C externe
$EndSCHEMATC
