EESchema Schematic File Version 2
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
LIBS:digital
LIBS:Oscillators
LIBS:dc-dc
LIBS:digital-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title "Windlogger digital"
Date "2017-02-02"
Rev "1.0.1"
Comp "ALEEA"
Comment1 "LONGUET Gilles"
Comment2 "AGPL3"
Comment3 ""
Comment4 ""
$EndDescr
Text Label 10825 1250 2    60   ~ 0
AREF
Text Label 8700 1475 0    60   ~ 0
RESET
$Comp
L GND #PWR01
U 1 1 58047CE8
P 8350 1925
F 0 "#PWR01" H 8350 1675 50  0001 C CNN
F 1 "GND" H 8350 1775 50  0000 C CNN
F 2 "" H 8350 1925 50  0000 C CNN
F 3 "" H 8350 1925 50  0000 C CNN
	1    8350 1925
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 58047D8D
P 11000 1375
F 0 "#PWR02" H 11000 1125 50  0001 C CNN
F 1 "GND" H 11000 1225 50  0000 C CNN
F 2 "" H 11000 1375 50  0000 C CNN
F 3 "" H 11000 1375 50  0000 C CNN
	1    11000 1375
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 Power1
U 1 1 58047F00
P 9350 1625
F 0 "Power1" H 9350 2075 50  0000 C CNN
F 1 "CONN_01X08" V 9450 1625 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x08" H 9350 1625 50  0001 C CNN
F 3 "" H 9350 1625 50  0000 C CNN
	1    9350 1625
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 Analog1
U 1 1 58047F99
P 9350 2575
F 0 "Analog1" H 9350 3025 50  0000 C CNN
F 1 "CONN_01X08" V 9450 2575 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x08" H 9350 2575 50  0001 C CNN
F 3 "" H 9350 2575 50  0000 C CNN
	1    9350 2575
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 PWM2
U 1 1 5804800C
P 10000 2450
F 0 "PWM2" H 9825 2875 50  0000 C CNN
F 1 "CONN_01X08" V 10100 2450 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x08" H 10000 2450 50  0001 C CNN
F 3 "" H 10000 2450 50  0000 C CNN
	1    10000 2450
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X08 Communication1
U 1 1 58048116
P 10000 3400
F 0 "Communication1" H 10000 3850 50  0000 C CNN
F 1 "CONN_01X08" V 10100 3400 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x08" H 10000 3400 50  0001 C CNN
F 3 "" H 10000 3400 50  0000 C CNN
	1    10000 3400
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X10 PWM1
U 1 1 580481BB
P 10000 1500
F 0 "PWM1" H 10000 2050 50  0000 C CNN
F 1 "CONN_01X10" V 10100 1500 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x10" H 10000 1500 50  0001 C CNN
F 3 "" H 10000 1500 50  0000 C CNN
	1    10000 1500
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X01 P6
U 1 1 5804CFD9
P 10725 6075
F 0 "P6" H 11000 6075 50  0000 C CNN
F 1 "hole" H 10850 6075 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 10725 6075 50  0001 C CNN
F 3 "" H 10725 6075 50  0000 C CNN
	1    10725 6075
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P8
U 1 1 5804D04C
P 10725 6200
F 0 "P8" H 11000 6200 50  0000 C CNN
F 1 "hole" H 10850 6200 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 10725 6200 50  0001 C CNN
F 3 "" H 10725 6200 50  0000 C CNN
	1    10725 6200
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X01 P9
U 1 1 5804D0CA
P 10725 6325
F 0 "P9" H 11000 6325 50  0000 C CNN
F 1 "hole" H 10850 6325 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 10725 6325 50  0001 C CNN
F 3 "" H 10725 6325 50  0000 C CNN
	1    10725 6325
	1    0    0    -1  
$EndComp
NoConn ~ 10525 6075
NoConn ~ 10525 6200
NoConn ~ 10525 6325
$Comp
L CONN_01X01 P5
U 1 1 5804D472
P 10725 5950
F 0 "P5" H 11000 5950 50  0000 C CNN
F 1 "hole" H 10850 5950 50  0000 C CNN
F 2 "Socket_Arduino_Mega:Arduino_1pin" H 10725 5950 50  0001 C CNN
F 3 "" H 10725 5950 50  0000 C CNN
	1    10725 5950
	1    0    0    -1  
$EndComp
NoConn ~ 10525 5950
$Comp
L CONN_01X04 POWER_SOURCE1
U 1 1 5804EF26
P 4650 6475
F 0 "POWER_SOURCE1" H 4650 6725 50  0000 C CNN
F 1 "CONN_01X04" V 4750 6425 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04" H 4650 6475 50  0001 C CNN
F 3 "" H 4650 6475 50  0000 C CNN
	1    4650 6475
	-1   0    0    -1  
$EndComp
Text Notes 10500 5700 0    60   ~ 0
mecanic holes
Text Notes 8925 825  0    60   ~ 0
Arduino style but with Atmega 1284P
$Comp
L CONN_02X03 P3
U 1 1 58519427
P 8900 3425
F 0 "P3" H 8900 3625 50  0000 C CNN
F 1 "ISP" H 8900 3225 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x03" H 8900 2225 50  0001 C CNN
F 3 "" H 8900 2225 50  0000 C CNN
	1    8900 3425
	1    0    0    -1  
$EndComp
Text Label 8400 3525 0    60   ~ 0
RESET
$Comp
L GND #PWR03
U 1 1 5851A232
P 9250 3575
F 0 "#PWR03" H 9250 3325 50  0001 C CNN
F 1 "GND" H 9250 3425 50  0000 C CNN
F 2 "" H 9250 3575 50  0000 C CNN
F 3 "" H 9250 3575 50  0000 C CNN
	1    9250 3575
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 5851ACCA
P 9275 3275
F 0 "#PWR04" H 9275 3125 50  0001 C CNN
F 1 "+5V" H 9275 3415 50  0000 C CNN
F 2 "" H 9275 3275 50  0000 C CNN
F 3 "" H 9275 3275 50  0000 C CNN
	1    9275 3275
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 P7
U 1 1 586AB0B8
P 9925 6100
F 0 "P7" H 9925 6450 50  0000 C CNN
F 1 "USART0" V 10025 6100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06" H 9925 6100 50  0001 C CNN
F 3 "" H 9925 6100 50  0000 C CNN
	1    9925 6100
	1    0    0    -1  
$EndComp
Text Notes 10075 6400 0    60   ~ 0
DTR
Text Notes 10075 6300 0    60   ~ 0
RXI
Text Notes 10075 6200 0    60   ~ 0
TXO
Text Notes 10075 5875 0    60   ~ 0
GND
Text Notes 10075 6075 0    60   ~ 0
+5V
$Comp
L +5V #PWR05
U 1 1 586ADB1D
P 8275 1600
F 0 "#PWR05" H 8275 1450 50  0001 C CNN
F 1 "+5V" H 8275 1740 50  0000 C CNN
F 2 "" H 8275 1600 50  0000 C CNN
F 3 "" H 8275 1600 50  0000 C CNN
	1    8275 1600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR06
U 1 1 586AF4A7
P 8500 1475
F 0 "#PWR06" H 8500 1325 50  0001 C CNN
F 1 "+3.3V" H 8500 1615 50  0000 C CNN
F 2 "" H 8500 1475 50  0000 C CNN
F 3 "" H 8500 1475 50  0000 C CNN
	1    8500 1475
	1    0    0    -1  
$EndComp
NoConn ~ 9150 1275
$Sheet
S 8325 5600 875  825 
U 586F0800
F0 "uart0_interace" 60
F1 "uart0_interace.sch" 60
F2 "GND" O R 9200 5850 60 
F3 "CTS" O R 9200 5950 60 
F4 "POWER" O R 9200 6050 60 
F5 "TXO" O R 9200 6150 60 
F6 "RXI" O R 9200 6250 60 
F7 "DTR" O R 9200 6350 60 
$EndSheet
Text Notes 10075 5975 0    60   ~ 0
CTS
Text Label 9625 5850 2    60   ~ 0
GND
Text Label 9600 6350 2    60   ~ 0
DTR
Text Label 9625 6050 2    60   ~ 0
+5V
$Sheet
S 1400 1200 1075 3575
U 587527C3
F0 "microC" 60
F1 "microC.sch" 60
F2 "ACD0" I R 2475 1300 60 
F3 "ACD1" I R 2475 1400 60 
F4 "ACD2" I R 2475 1500 60 
F5 "ACD3" I R 2475 1600 60 
F6 "ACD4" I R 2475 1700 60 
F7 "ACD5" I R 2475 1800 60 
F8 "ACD6" I R 2475 1900 60 
F9 "ACD7" I R 2475 2000 60 
F10 "PB0" I R 2475 2200 60 
F11 "PB1" I R 2475 2300 60 
F12 "PB2" I R 2475 2400 60 
F13 "PB3" I R 2475 2500 60 
F14 "PB4" I R 2475 2600 60 
F15 "PB5" I R 2475 2700 60 
F16 "PB6" I R 2475 2800 60 
F17 "PB7" I R 2475 2900 60 
F18 "PC0" I R 2475 3075 60 
F19 "PC1" I R 2475 3175 60 
F20 "PC2" I R 2475 3275 60 
F21 "PC3" I R 2475 3375 60 
F22 "PC5" I R 2475 3575 60 
F23 "PD0" I R 2475 3950 60 
F24 "PD1" I R 2475 4050 60 
F25 "PD2" I R 2475 4150 60 
F26 "PD3" I R 2475 4250 60 
F27 "PD4" I R 2475 4350 60 
F28 "PD5" I R 2475 4450 60 
F29 "PD6" I R 2475 4550 60 
F30 "PD7" I R 2475 4650 60 
F31 "RESET" I L 1400 2000 60 
F32 "AREF" I L 1400 2600 60 
F33 "PC4" I R 2475 3475 60 
$EndSheet
Text Label 3100 2700 2    60   ~ 0
D11-MOSI
Text Label 3100 2800 2    60   ~ 0
D12-MISO
Text Label 3100 2900 2    60   ~ 0
D13-SCLK
Text Label 3100 3950 2    60   ~ 0
D0-RX0
Text Label 3100 4050 2    60   ~ 0
D1-TX0
Text Label 3100 4150 2    60   ~ 0
D24-RX1
Text Label 3100 4250 2    60   ~ 0
D25-TX1
Text Label 3100 2300 2    60   ~ 0
D5
Text Label 3100 2200 2    60   ~ 0
D4
Text Label 3100 3075 2    60   ~ 0
D22-SCL
Text Label 3100 3175 2    60   ~ 0
D23-SDA
Text Label 3100 2400 2    60   ~ 0
D6
Text Label 2875 1900 2    60   ~ 0
D15-A6
Text Label 2875 2000 2    60   ~ 0
D14-A7
Text Label 2875 1300 2    60   ~ 0
D21-A0
Text Label 3100 2500 2    60   ~ 0
D7
Text Label 2875 1400 2    60   ~ 0
D20-A1
Text Label 2875 1500 2    60   ~ 0
D19-A2
Text Label 2875 1600 2    60   ~ 0
D18-A3
Text Label 2875 1700 2    60   ~ 0
D17-A4
Text Label 3100 3275 2    60   ~ 0
D2
Text Label 975  2000 0    60   ~ 0
RESET
Text Label 975  2600 0    60   ~ 0
AREF
$Comp
L C C2
U 1 1 587726C6
P 875 1700
F 0 "C2" H 900 1800 50  0000 L CNN
F 1 "100nF" H 900 1600 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2.5_P5" H 913 1550 50  0001 C CNN
F 3 "" H 875 1700 50  0000 C CNN
	1    875  1700
	1    0    0    -1  
$EndComp
Text Label 875  1375 0    60   ~ 0
DTR
$Comp
L CONN_02X05 P4
U 1 1 5876E57F
P 10525 4700
F 0 "P4" H 10525 5000 50  0000 C CNN
F 1 "CONN_02X05" H 10525 4400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05" H 10525 3500 50  0001 C CNN
F 3 "" H 10525 3500 50  0000 C CNN
	1    10525 4700
	1    0    0    -1  
$EndComp
Text Label 10000 4500 0    60   ~ 0
TCK
Text Label 10000 4600 0    60   ~ 0
TDO
Text Label 10000 4700 0    60   ~ 0
TMS
Text Label 10000 4900 0    60   ~ 0
TDI
$Comp
L +3.3V #PWR07
U 1 1 5876E594
P 10975 4475
F 0 "#PWR07" H 10975 4325 50  0001 C CNN
F 1 "+3.3V" H 10975 4615 50  0000 C CNN
F 2 "" H 10975 4475 50  0000 C CNN
F 3 "" H 10975 4475 50  0000 C CNN
	1    10975 4475
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5876E59A
P 10875 4975
F 0 "#PWR08" H 10875 4725 50  0001 C CNN
F 1 "GND" H 10875 4825 50  0000 C CNN
F 2 "" H 10875 4975 50  0000 C CNN
F 3 "" H 10875 4975 50  0000 C CNN
	1    10875 4975
	1    0    0    -1  
$EndComp
NoConn ~ 10775 4700
NoConn ~ 10775 4800
NoConn ~ 10275 4800
Text Notes 11000 4175 2    60   ~ 0
CPLD Jtag connector
Text Notes 9475 5450 2    60   ~ 0
Microcontroler Uart
$Sheet
S 4575 2225 675  2000
U 58753377
F0 "CPLD" 60
F1 "CPLD.sch" 60
F2 "38" I R 5250 2725 60 
F3 "40" I R 5250 2625 60 
F4 "2" B L 4575 2325 60 
F5 "3" B L 4575 2425 60 
F6 "5" B L 4575 2525 60 
F7 "6" B L 4575 2625 60 
F8 "42" B R 5250 2525 60 
F9 "43" B R 5250 2425 60 
F10 "44" B R 5250 2325 60 
F11 "8" B L 4575 2725 60 
F12 "10" B L 4575 2825 60 
F13 "12" B L 4575 2925 60 
F14 "13" B L 4575 3025 60 
F15 "14" B L 4575 3125 60 
F16 "15" B L 4575 3225 60 
F17 "25" B R 5250 3425 60 
F18 "23" B R 5250 3525 60 
F19 "22" B R 5250 3625 60 
F20 "21" B L 4575 3625 60 
F21 "20" B L 4575 3525 60 
F22 "19" B L 4575 3425 60 
F23 "18" B L 4575 3325 60 
F24 "35" B R 5250 2825 60 
F25 "34" B R 5250 2925 60 
F26 "33" B R 5250 3025 60 
F27 "31" B R 5250 3125 60 
F28 "28" B R 5250 3225 60 
F29 "27" B R 5250 3325 60 
F30 "TDI" I L 4575 4125 60 
F31 "TMS" I L 4575 4025 60 
F32 "TCK" I L 4575 3825 60 
F33 "TDO" O L 4575 3925 60 
$EndSheet
Text Label 4350 3825 0    60   ~ 0
TCK
Text Label 4350 3925 0    60   ~ 0
TDO
Text Label 4350 4025 0    60   ~ 0
TMS
Text Label 4350 4125 0    60   ~ 0
TDI
Text Label 2875 1800 2    60   ~ 0
D16-A5
$Sheet
S 6700 2224 1225 1875
U 5804AD31
F0 "output" 60
F1 "output.sch" 60
F2 "RF_IRQ_3V3" I L 6700 2425 60 
F3 "RF_CS_3V3" I L 6700 2325 60 
F4 "GPRS_reset_2V8" I L 6700 4025 60 
F5 "GPRS_RX_2V8" I L 6700 3925 60 
F6 "GPRS_TX_2V8" O L 6700 3825 60 
F7 "huzzah_LDO_enable_3V3" I L 6700 3675 60 
F8 "huzzah_RX_3V3" I L 6700 3575 60 
F9 "huzzah_TX_3V3" O L 6700 3475 60 
F10 "huzzah_reset_3V3" I L 6700 3375 60 
F11 "huzzah_enable_3v3" I L 6700 3275 60 
F12 "SD_CD_5V" O L 6700 3100 60 
F13 "MISO_3V3" O L 6700 2550 60 
F14 "SCLK_3V3" I L 6700 2750 60 
F15 "MOSI_3V3" I L 6700 2650 60 
F16 "SD_CS_3V3" I L 6700 2975 60 
$EndSheet
Text Label 3100 2600 2    60   ~ 0
D10
Text Label 3100 3375 2    60   ~ 0
D3
Text Label 3100 4450 2    60   ~ 0
D8
Text Label 3100 4350 2    60   ~ 0
D30
Text Label 3100 4550 2    60   ~ 0
D9
Text Label 3100 4650 2    60   ~ 0
D31
Wire Wire Line
	6075 4025 6700 4025
Wire Wire Line
	6075 4400 6075 4025
Wire Wire Line
	4200 4400 6075 4400
Wire Wire Line
	4200 3625 4200 4400
Wire Wire Line
	4200 3625 4575 3625
Wire Wire Line
	5250 3625 5850 3625
Wire Wire Line
	5850 3625 5850 3925
Wire Wire Line
	5850 3925 6700 3925
Wire Wire Line
	5900 3825 6700 3825
Wire Wire Line
	5900 3525 5900 3825
Wire Wire Line
	5250 3525 5900 3525
Wire Wire Line
	5250 3425 5950 3425
Wire Wire Line
	5950 3425 5950 3675
Wire Wire Line
	5950 3675 6700 3675
Wire Wire Line
	6000 3575 6700 3575
Wire Wire Line
	6000 3325 6000 3575
Wire Wire Line
	5250 3325 6000 3325
Wire Wire Line
	5250 3225 6075 3225
Wire Wire Line
	6075 3225 6075 3475
Wire Wire Line
	6075 3475 6700 3475
Wire Wire Line
	6125 3375 6700 3375
Wire Wire Line
	6125 3125 6125 3375
Wire Wire Line
	5250 3125 6125 3125
Wire Wire Line
	5250 3025 6200 3025
Wire Wire Line
	6200 3025 6200 3275
Wire Wire Line
	6200 3275 6700 3275
Wire Wire Line
	6325 3100 6700 3100
Wire Wire Line
	5250 2925 6325 2925
Wire Wire Line
	6325 2925 6325 3100
Wire Wire Line
	5250 2825 6400 2825
Wire Wire Line
	6400 2825 6400 2975
Wire Wire Line
	6400 2975 6700 2975
Wire Wire Line
	6500 2750 6700 2750
Wire Wire Line
	6500 2725 6500 2750
Wire Wire Line
	5250 2625 6525 2625
Wire Wire Line
	6525 2625 6525 2650
Wire Wire Line
	6525 2650 6700 2650
Wire Wire Line
	5950 2550 6700 2550
Wire Wire Line
	5250 2425 6700 2425
Wire Wire Line
	5250 2325 6700 2325
Wire Wire Line
	4350 4125 4575 4125
Wire Wire Line
	4350 4025 4575 4025
Wire Wire Line
	4350 3925 4575 3925
Wire Wire Line
	4575 3825 4350 3825
Wire Notes Line
	8150 5225 11200 5225
Wire Wire Line
	10975 4600 10975 4475
Wire Wire Line
	10775 4600 10975 4600
Connection ~ 10875 4900
Wire Wire Line
	10775 4900 10875 4900
Wire Wire Line
	10875 4500 10875 4975
Wire Wire Line
	10775 4500 10875 4500
Wire Wire Line
	10000 4900 10275 4900
Wire Wire Line
	10000 4700 10275 4700
Wire Wire Line
	10000 4600 10275 4600
Wire Wire Line
	10000 4500 10275 4500
Wire Wire Line
	875  1375 875  1550
Wire Wire Line
	875  1850 875  2000
Wire Wire Line
	975  2600 1400 2600
Wire Wire Line
	875  2000 1400 2000
Wire Wire Line
	2875 2000 2475 2000
Wire Wire Line
	2875 1900 2475 1900
Wire Wire Line
	2875 1800 2475 1800
Wire Wire Line
	2875 1700 2475 1700
Wire Wire Line
	2875 1600 2475 1600
Wire Wire Line
	2875 1500 2475 1500
Wire Wire Line
	2875 1400 2475 1400
Wire Wire Line
	2875 1300 2475 1300
Wire Wire Line
	2475 2600 4200 2600
Wire Wire Line
	2475 4650 4050 4650
Wire Wire Line
	2475 4550 4000 4550
Wire Wire Line
	3950 4450 2475 4450
Wire Wire Line
	3900 4350 2475 4350
Wire Wire Line
	3100 4050 2475 4050
Wire Wire Line
	3100 3950 2475 3950
Wire Wire Line
	2475 3575 3100 3575
Wire Wire Line
	2475 3475 3100 3475
Wire Wire Line
	2475 2500 4125 2500
Wire Wire Line
	2475 2400 4050 2400
Wire Wire Line
	3100 3175 2475 3175
Wire Wire Line
	3100 3075 2475 3075
Wire Wire Line
	2475 2900 3450 2900
Wire Wire Line
	2475 2800 3375 2800
Wire Wire Line
	2475 2700 4175 2700
Wire Wire Line
	2475 3375 3525 3375
Wire Wire Line
	2475 3275 3100 3275
Wire Wire Line
	2475 2300 3100 2300
Wire Wire Line
	2475 2200 3100 2200
Wire Wire Line
	9725 6350 9200 6350
Wire Wire Line
	9200 6250 9725 6250
Wire Wire Line
	9200 6150 9725 6150
Wire Wire Line
	9200 6050 9725 6050
Wire Wire Line
	9725 5950 9200 5950
Wire Wire Line
	9200 5850 9725 5850
Wire Wire Line
	8275 1675 8275 1600
Wire Notes Line
	10325 5225 10325 6525
Wire Wire Line
	9275 3325 9150 3325
Wire Wire Line
	9275 3275 9275 3325
Wire Wire Line
	9250 3525 9250 3575
Wire Wire Line
	9150 3525 9250 3525
Wire Wire Line
	9150 3425 9600 3425
Wire Wire Line
	8400 3525 8650 3525
Wire Wire Line
	8200 3325 8650 3325
Wire Wire Line
	8200 3425 8650 3425
Wire Notes Line
	8150 3925 11225 3925
Wire Notes Line
	8150 6525 8150 500 
Wire Wire Line
	5000 6325 4850 6325
Wire Wire Line
	4850 6425 5000 6425
Wire Wire Line
	5000 6525 4850 6525
Wire Wire Line
	4850 6625 5000 6625
Wire Wire Line
	8500 1475 8500 1575
Connection ~ 8350 1875
Wire Wire Line
	8350 1775 8350 1925
Wire Wire Line
	8350 1875 9150 1875
Wire Wire Line
	8350 1775 9150 1775
Wire Wire Line
	8275 1675 9150 1675
Wire Wire Line
	8500 1575 9150 1575
Wire Wire Line
	8700 1475 9150 1475
Wire Wire Line
	10200 1350 11000 1350
Wire Wire Line
	10200 1250 10825 1250
Text Label 3100 3475 2    60   ~ 0
D26
Text Label 3100 3575 2    60   ~ 0
D27
Text Label 10825 2800 2    60   ~ 0
D0-RX0
Text Label 10825 2700 2    60   ~ 0
D1-TX0
Text Label 10825 2300 2    60   ~ 0
D5
Text Label 10825 2400 2    60   ~ 0
D4
Text Label 10825 1050 2    60   ~ 0
D22-SCL
Text Label 10825 1150 2    60   ~ 0
D23-SDA
Text Label 10825 2600 2    60   ~ 0
D2
Text Label 10825 2500 2    60   ~ 0
D3
Text Label 10825 2200 2    60   ~ 0
D6
Text Label 10825 1750 2    60   ~ 0
D10
Text Label 10825 2100 2    60   ~ 0
D7
Text Label 10825 1950 2    60   ~ 0
D8
Text Label 10825 3150 2    60   ~ 0
D30
Text Label 10825 1850 2    60   ~ 0
D9
Text Label 10825 3050 2    60   ~ 0
D31
Wire Wire Line
	10825 1750 10200 1750
Wire Wire Line
	10825 3050 10200 3050
Wire Wire Line
	10825 1850 10200 1850
Wire Wire Line
	10825 1950 10200 1950
Wire Wire Line
	10825 3150 10200 3150
Wire Wire Line
	10825 2700 10200 2700
Wire Wire Line
	10825 2800 10200 2800
Wire Wire Line
	10200 3250 10825 3250
Wire Wire Line
	10200 3350 10825 3350
Wire Wire Line
	10200 2500 10825 2500
Wire Wire Line
	10200 2600 10825 2600
Wire Wire Line
	10825 1150 10200 1150
Wire Wire Line
	10825 1050 10200 1050
Wire Wire Line
	10825 2100 10200 2100
Wire Wire Line
	10200 2200 10825 2200
Wire Wire Line
	10200 2300 10825 2300
Wire Wire Line
	10200 2400 10825 2400
Text Label 10825 3350 2    60   ~ 0
D26
Text Label 10825 3250 2    60   ~ 0
D27
Text Label 10825 3750 2    60   ~ 0
D22-SCL
Text Label 10825 3650 2    60   ~ 0
D23-SDA
Wire Wire Line
	10825 3650 10200 3650
Wire Wire Line
	10825 3750 10200 3750
Text Label 8750 2825 0    60   ~ 0
D15-A6
Text Label 8750 2925 0    60   ~ 0
D14-A7
Text Label 8750 2225 0    60   ~ 0
D21-A0
Text Label 8750 2325 0    60   ~ 0
D20-A1
Text Label 8750 2425 0    60   ~ 0
D19-A2
Text Label 8750 2525 0    60   ~ 0
D18-A3
Text Label 8750 2625 0    60   ~ 0
D17-A4
Text Label 8750 2725 0    60   ~ 0
D16-A5
Wire Wire Line
	9150 2925 8750 2925
Wire Wire Line
	9150 2825 8750 2825
Wire Wire Line
	9150 2725 8750 2725
Wire Wire Line
	9150 2625 8750 2625
Wire Wire Line
	9150 2525 8750 2525
Wire Wire Line
	9150 2425 8750 2425
Wire Wire Line
	9150 2325 8750 2325
Wire Wire Line
	9150 2225 8750 2225
Wire Wire Line
	10825 3450 10200 3450
Wire Wire Line
	10825 3550 10200 3550
Text Label 10825 3550 2    60   ~ 0
D24-RX1
Text Label 10825 3450 2    60   ~ 0
D25-TX1
Text Notes 2950 1325 0    60   ~ 0
Uac
Text Notes 2950 1400 0    60   ~ 0
I1
Text Notes 2950 1500 0    60   ~ 0
I2
Text Notes 2950 1600 0    60   ~ 0
I3
Text Notes 2950 1700 0    60   ~ 0
I4
Text Notes 2950 1900 0    60   ~ 0
Udir
Text Notes 2950 2000 0    60   ~ 0
Udc
Text Notes 3150 2200 0    60   ~ 0
speed1
Text Notes 3150 2300 0    60   ~ 0
speed2
Text Notes 3150 3475 0    60   ~ 0
1_wire_PWR
Text Notes 3150 3575 0    60   ~ 0
1_wire_data
Text Label 9700 6150 2    60   ~ 0
D0-RX0
Text Label 9700 6250 2    60   ~ 0
D1-TX0
Text Notes 3200 3950 0    60   ~ 0
FTDI
Text Notes 3200 4050 0    60   ~ 0
FTDI
Text Label 9600 3425 2    60   ~ 0
D11-MOSI
Text Label 8200 3325 0    60   ~ 0
D12-MISO
Text Label 8200 3425 0    60   ~ 0
D13-SCLK
Text Label 10825 1650 2    60   ~ 0
D11-MOSI
Text Label 10825 1550 2    60   ~ 0
D12-MISO
Text Label 10825 1450 2    60   ~ 0
D13-SCLK
Wire Wire Line
	10825 1450 10200 1450
Wire Wire Line
	10825 1550 10200 1550
Wire Wire Line
	10825 1650 10200 1650
Text Notes 3150 3275 0    60   ~ 0
RPM
Wire Wire Line
	4050 2400 4050 2325
Wire Wire Line
	4125 2425 4575 2425
Wire Wire Line
	4125 2500 4125 2425
Wire Wire Line
	4200 2525 4575 2525
Wire Wire Line
	4200 2600 4200 2525
Wire Wire Line
	4175 2625 4575 2625
Wire Wire Line
	4175 2700 4175 2625
Wire Wire Line
	3375 2725 4575 2725
Wire Wire Line
	3375 2800 3375 2725
Wire Wire Line
	3450 2900 3450 2825
Wire Wire Line
	3450 2825 4575 2825
Wire Wire Line
	3525 3375 3525 2925
Wire Wire Line
	3525 2925 4575 2925
Wire Wire Line
	3750 3025 3750 4150
Wire Wire Line
	3750 3025 4575 3025
Wire Wire Line
	3800 3125 4575 3125
Wire Wire Line
	3800 3125 3800 4250
Wire Wire Line
	3900 3225 4575 3225
Wire Wire Line
	3900 3225 3900 4350
Wire Wire Line
	3950 3325 4575 3325
Wire Wire Line
	3950 3325 3950 4450
Wire Wire Line
	3750 4150 2475 4150
Wire Wire Line
	3800 4250 2475 4250
Wire Wire Line
	4000 4550 4000 3425
Wire Wire Line
	4000 3425 4575 3425
Wire Wire Line
	4050 3525 4575 3525
Wire Wire Line
	4050 4650 4050 3525
Wire Wire Line
	9150 1375 9025 1375
Wire Wire Line
	9025 1375 9025 1675
Connection ~ 9025 1675
NoConn ~ 9150 1975
Wire Wire Line
	5950 2725 5950 2550
Wire Wire Line
	5250 2725 5950 2725
Wire Wire Line
	6500 2725 6100 2725
Wire Wire Line
	6100 2725 6100 2500
Wire Wire Line
	6100 2500 5650 2500
Wire Wire Line
	5650 2500 5650 2525
Wire Wire Line
	5650 2525 5250 2525
$Comp
L CONN_01X14 P1
U 1 1 5882D99A
P 4300 2975
F 0 "P1" H 4300 3725 50  0000 C CNN
F 1 "CONN_01X14" V 4400 2975 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x14" H 4300 2975 50  0001 C CNN
F 3 "" H 4300 2975 50  0000 C CNN
	1    4300 2975
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X14 P2
U 1 1 5882DC2D
P 5500 2975
F 0 "P2" H 5500 3725 50  0000 C CNN
F 1 "CONN_01X14" V 5600 2975 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x14" H 5500 2975 50  0001 C CNN
F 3 "" H 5500 2975 50  0000 C CNN
	1    5500 2975
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2325 4575 2325
Connection ~ 4500 2325
Connection ~ 4500 2425
Connection ~ 4500 2525
Connection ~ 4500 2625
Connection ~ 4500 2725
Connection ~ 4500 2825
Connection ~ 4500 2925
Connection ~ 4500 3025
Connection ~ 4500 3125
Connection ~ 4500 3225
Connection ~ 4500 3325
Connection ~ 4500 3425
Connection ~ 4500 3525
Connection ~ 4500 3625
Connection ~ 5300 3625
Connection ~ 5300 3525
Connection ~ 5300 3425
Connection ~ 5300 3325
Connection ~ 5300 3225
Connection ~ 5300 3125
Connection ~ 5300 3025
Connection ~ 5300 2925
Connection ~ 5300 2825
Connection ~ 5300 2725
Connection ~ 5300 2625
Connection ~ 5300 2525
Connection ~ 5300 2425
Connection ~ 5300 2325
$Sheet
S 5000 5950 1275 1050
U 5886192F
F0 "power_supply" 60
F1 "power_supply.sch" 60
F2 "UDC" I L 5000 6325 60 
F3 "GND" I L 5000 6425 60 
F4 "Uac_hi" I L 5000 6525 60 
F5 "Uac_lo" I L 5000 6625 60 
$EndSheet
Wire Wire Line
	11000 1350 11000 1375
Text Label 4875 1350 2    60   ~ 0
D13-SCLK
$Comp
L R R13
U 1 1 5892FF65
P 5125 1350
F 0 "R13" V 5205 1350 50  0000 C CNN
F 1 "270" V 5125 1350 50  0000 C CNN
F 2 "Discret:R3-LARGE_PADS" V 5055 1350 50  0001 C CNN
F 3 "" H 5125 1350 50  0000 C CNN
	1    5125 1350
	0    1    1    0   
$EndComp
$Comp
L Led_Small D12
U 1 1 58930F4F
P 5500 1350
F 0 "D12" H 5450 1475 50  0000 L CNN
F 1 "Led_Small" H 5325 1250 50  0000 L CNN
F 2 "LEDs:LED-3MM" V 5500 1350 50  0001 C CNN
F 3 "" V 5500 1350 50  0000 C CNN
	1    5500 1350
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR09
U 1 1 589311BC
P 5725 1350
F 0 "#PWR09" H 5725 1100 50  0001 C CNN
F 1 "GND" H 5725 1200 50  0000 C CNN
F 2 "" H 5725 1350 50  0000 C CNN
F 3 "" H 5725 1350 50  0000 C CNN
	1    5725 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5725 1350 5600 1350
Wire Wire Line
	5400 1350 5275 1350
Wire Wire Line
	4975 1350 4875 1350
$EndSCHEMATC
