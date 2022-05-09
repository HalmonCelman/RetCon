EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L schemat_dip40-rescue:SD_card_reader-Connector U4
U 1 1 61D7A0EB
P 7250 4000
F 0 "U4" H 8028 4046 50  0000 L CNN
F 1 "SD_card_reader" H 8028 3955 50  0000 L CNN
F 2 "Connector_Card:SD_Kyocera_145638009511859+" H 7200 4000 50  0001 C CNN
F 3 "" H 7200 4000 50  0001 C CNN
	1    7250 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Female J1
U 1 1 61D899A2
P 6650 5300
F 0 "J1" H 6678 5276 50  0000 L CNN
F 1 "Conn_01x06_Female" H 6678 5185 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 6650 5300 50  0001 C CNN
F 3 "~" H 6650 5300 50  0001 C CNN
	1    6650 5300
	1    0    0    -1  
$EndComp
Text Notes 6700 5850 0    50   ~ 0
USBASP programator
Text Notes 6800 5650 0    50   ~ 0
GND\n
Text Notes 6800 5550 0    50   ~ 0
VCC
Text Notes 6800 5450 0    50   ~ 0
MOSI
Text Notes 6800 5350 0    50   ~ 0
MISO
Text Notes 6800 5250 0    50   ~ 0
SCK\n
Text Notes 6800 5150 0    50   ~ 0
RST
Wire Wire Line
	6100 2150 5550 2150
Wire Wire Line
	5550 2150 5550 1550
Wire Wire Line
	6100 2250 5450 2250
Wire Wire Line
	5450 2250 5450 1650
Wire Wire Line
	6100 2350 5350 2350
Wire Wire Line
	5350 2350 5350 1750
Wire Wire Line
	6100 2450 5250 2450
Wire Wire Line
	5250 2450 5250 1850
Wire Wire Line
	6100 2550 5150 2550
Wire Wire Line
	5150 2550 5150 1950
Wire Wire Line
	6100 2650 5050 2650
Wire Wire Line
	5050 2650 5050 2050
Wire Wire Line
	6100 2750 4950 2750
Wire Wire Line
	4950 2750 4950 2150
Wire Wire Line
	6100 2850 4850 2850
Wire Wire Line
	4850 2850 4850 2250
Wire Wire Line
	6100 1650 5950 1650
Wire Wire Line
	5950 1650 5950 1200
Wire Wire Line
	5950 1200 3500 1200
Wire Wire Line
	3500 1200 3500 3350
Wire Wire Line
	6100 1750 5850 1750
Wire Wire Line
	5850 1750 5850 1300
Wire Wire Line
	5850 1300 3600 1300
Wire Wire Line
	3600 1300 3600 3550
$Comp
L power:VCC #PWR08
U 1 1 61D95FE0
P 7850 1050
F 0 "#PWR08" H 7850 900 50  0001 C CNN
F 1 "VCC" H 7865 1223 50  0000 C CNN
F 2 "" H 7850 1050 50  0001 C CNN
F 3 "" H 7850 1050 50  0001 C CNN
	1    7850 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 61D975F7
P 8700 3200
F 0 "#PWR010" H 8700 2950 50  0001 C CNN
F 1 "GND" H 8705 3027 50  0000 C CNN
F 2 "" H 8700 3200 50  0001 C CNN
F 3 "" H 8700 3200 50  0001 C CNN
	1    8700 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 1850 6050 1850
Wire Wire Line
	6050 1850 6050 1050
Wire Wire Line
	6050 1050 6600 1050
Wire Wire Line
	6600 1450 6600 1050
Connection ~ 6600 1050
Wire Wire Line
	6600 1050 7600 1050
Wire Wire Line
	6100 1950 5750 1950
Wire Wire Line
	5750 1950 5750 1450
Wire Wire Line
	5750 1450 3700 1450
Wire Wire Line
	3700 1450 3700 3450
Wire Wire Line
	6600 3050 6600 3200
Wire Wire Line
	6600 3200 8100 3200
Wire Wire Line
	6300 3650 5950 3650
Wire Wire Line
	5950 3200 6600 3200
Connection ~ 6600 3200
Wire Wire Line
	7100 2750 7500 2750
Wire Wire Line
	7500 2750 7500 3300
Wire Wire Line
	7500 3300 3850 3300
Wire Wire Line
	3850 3300 3850 3950
Wire Wire Line
	7100 2850 7400 2850
Wire Wire Line
	7400 2850 7400 3400
Wire Wire Line
	7400 3400 4000 3400
Wire Wire Line
	4000 3400 4000 3850
Wire Wire Line
	7100 2350 7600 2350
Wire Wire Line
	7600 2350 7600 1050
Connection ~ 7600 1050
Wire Wire Line
	7600 1050 7850 1050
Wire Wire Line
	7100 2450 8100 2450
Wire Wire Line
	8100 2450 8100 3200
Connection ~ 8100 3200
Wire Wire Line
	8100 3200 8700 3200
Wire Wire Line
	10150 1050 7850 1050
Connection ~ 7850 1050
$Comp
L power:VCC #PWR02
U 1 1 61DB3E6A
P 2250 900
F 0 "#PWR02" H 2250 750 50  0001 C CNN
F 1 "VCC" H 2265 1073 50  0000 C CNN
F 2 "" H 2250 900 50  0001 C CNN
F 3 "" H 2250 900 50  0001 C CNN
	1    2250 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 900  2250 900 
Connection ~ 2250 900 
$Comp
L power:GND #PWR05
U 1 1 61DBB00B
P 5850 6000
F 0 "#PWR05" H 5850 5750 50  0001 C CNN
F 1 "GND" H 5855 5827 50  0000 C CNN
F 2 "" H 5850 6000 50  0001 C CNN
F 3 "" H 5850 6000 50  0001 C CNN
	1    5850 6000
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR03
U 1 1 61DBD527
P 5450 3750
F 0 "#PWR03" H 5450 3600 50  0001 C CNN
F 1 "VCC" H 5465 3923 50  0000 C CNN
F 2 "" H 5450 3750 50  0001 C CNN
F 3 "" H 5450 3750 50  0001 C CNN
	1    5450 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3850 5450 3850
Wire Wire Line
	5450 3850 5450 3750
Wire Wire Line
	6450 5100 4000 5100
Wire Wire Line
	4000 5100 4000 5800
Wire Wire Line
	4000 5800 1350 5800
Wire Wire Line
	1350 5800 1350 1550
Wire Wire Line
	6450 5200 3300 5200
Wire Wire Line
	3300 5200 3300 4150
Wire Wire Line
	6450 5300 3200 5300
Wire Wire Line
	3200 5300 3200 4250
Wire Wire Line
	6450 5400 3100 5400
Wire Wire Line
	3100 5400 3100 4050
Wire Wire Line
	6300 3950 4300 3950
Wire Wire Line
	4300 3950 4300 2650
Wire Wire Line
	6300 4050 3100 4050
Connection ~ 3100 4050
Wire Wire Line
	3100 4050 3100 2950
Wire Wire Line
	6300 4150 3300 4150
Connection ~ 3300 4150
Wire Wire Line
	3300 4150 3300 3150
Wire Wire Line
	6300 4250 3200 4250
Connection ~ 3200 4250
Wire Wire Line
	3200 4250 3200 3050
$Comp
L Switch:SW_Push SW3
U 1 1 6261EEBB
P 8900 4600
F 0 "SW3" H 8900 4885 50  0000 C CNN
F 1 "Up" H 8900 4794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8900 4800 50  0001 C CNN
F 3 "~" H 8900 4800 50  0001 C CNN
	1    8900 4600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 6261FEC3
P 8900 5150
F 0 "SW4" H 8900 5435 50  0000 C CNN
F 1 "Down" H 8900 5344 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8900 5350 50  0001 C CNN
F 3 "~" H 8900 5350 50  0001 C CNN
	1    8900 5150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 6262059D
P 9500 4850
F 0 "SW5" H 9500 5135 50  0000 C CNN
F 1 "Right" H 9500 5044 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 9500 5050 50  0001 C CNN
F 3 "~" H 9500 5050 50  0001 C CNN
	1    9500 4850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 62620D64
P 8300 4850
F 0 "SW2" H 8300 5135 50  0000 C CNN
F 1 "Left" H 8300 5044 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8300 5050 50  0001 C CNN
F 3 "~" H 8300 5050 50  0001 C CNN
	1    8300 4850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW6
U 1 1 626213AA
P 10500 5150
F 0 "SW6" H 10500 5435 50  0000 C CNN
F 1 "Jump" H 10500 5344 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 10500 5350 50  0001 C CNN
F 3 "~" H 10500 5350 50  0001 C CNN
	1    10500 5150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW7
U 1 1 6262299A
P 10900 4800
F 0 "SW7" H 10900 5085 50  0000 C CNN
F 1 "Punch" H 10900 4994 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 10900 5000 50  0001 C CNN
F 3 "~" H 10900 5000 50  0001 C CNN
	1    10900 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1550 1650 1550
Wire Wire Line
	3300 3150 2850 3150
Wire Wire Line
	3200 3050 2850 3050
Wire Wire Line
	3100 2950 2850 2950
Wire Wire Line
	5550 1550 2850 1550
Wire Wire Line
	5450 1650 2850 1650
Wire Wire Line
	5350 1750 2850 1750
Wire Wire Line
	5250 1850 2850 1850
Wire Wire Line
	5150 1950 2850 1950
Wire Wire Line
	5050 2050 2850 2050
Wire Wire Line
	4950 2150 2850 2150
Wire Wire Line
	4850 2250 2850 2250
Wire Wire Line
	2350 1250 2350 900 
Wire Wire Line
	4300 2650 2850 2650
Wire Wire Line
	3850 3950 2850 3950
Wire Wire Line
	4000 3850 2850 3850
Wire Wire Line
	3600 3550 2850 3550
Wire Wire Line
	3700 3450 2850 3450
Wire Wire Line
	3500 3350 2850 3350
Wire Wire Line
	2250 5250 2250 5600
Wire Wire Line
	2250 1250 2250 900 
Wire Wire Line
	8700 5150 7050 5150
Wire Wire Line
	7050 5150 7050 4700
Wire Wire Line
	7050 4700 3900 4700
Wire Wire Line
	3900 4700 3900 4350
Wire Wire Line
	9300 4850 8650 4850
Wire Wire Line
	8650 4850 8650 4750
Wire Wire Line
	8100 4850 3750 4850
Wire Wire Line
	3750 4850 3750 4550
Wire Wire Line
	10300 5150 9400 5150
Wire Wire Line
	9400 5150 9400 4950
Wire Wire Line
	9400 4950 3650 4950
Wire Wire Line
	3650 4950 3650 4650
Wire Wire Line
	10700 4800 9900 4800
Wire Wire Line
	9900 4800 9900 5050
Wire Wire Line
	9900 5050 3550 5050
Wire Wire Line
	3550 5050 3550 4750
Wire Wire Line
	8500 5350 8500 4850
$Comp
L schemat_dip40-rescue:WG12864B-STBL-schemat_dip40-rescue U3
U 1 1 6264714C
P 6600 2300
F 0 "U3" H 6600 3331 50  0000 C CNN
F 1 "WG12864B-STBL" H 6600 3240 50  0000 C CNN
F 2 "Blue:WG12864BL" H 6600 2300 50  0001 C CNN
F 3 "" H 6600 2300 50  0001 C CNN
	1    6600 2300
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega32A-AU U1
U 1 1 6264DA55
P 2250 3250
F 0 "U1" H 2250 1161 50  0000 C CNN
F 1 "ATmega32A-AU" H 2250 1070 50  0000 C CNN
F 2 "Package_QFP:TQFP-44_10x10mm_P0.8mm" H 2250 3250 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-8155-8-bit-microcontroller-avr-atmega32a_datasheet.pdf" H 2250 3250 50  0001 C CNN
	1    2250 3250
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U2
U 1 1 62650285
P 6100 6600
F 0 "U2" H 6100 6842 50  0000 C CNN
F 1 "L7805" H 6100 6751 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-2" H 6125 6450 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 6100 6550 50  0001 C CNN
	1    6100 6600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 SW1
U 1 1 626527EA
P 3250 6750
F 0 "SW1" H 3250 7017 50  0000 C CNN
F 1 "SW_DIP_x01" H 3250 6926 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3250 6750 50  0001 C CNN
F 3 "~" H 3250 6750 50  0001 C CNN
	1    3250 6750
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT1
U 1 1 6265C2FE
P 1150 7000
F 0 "BT1" H 1258 7046 50  0000 L CNN
F 1 "9V battery" H 1258 6955 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" V 1150 7060 50  0001 C CNN
F 3 "~" V 1150 7060 50  0001 C CNN
	1    1150 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 6800 1150 6600
Wire Wire Line
	1150 6600 2950 6600
Wire Wire Line
	2950 6600 2950 6750
$Comp
L power:VCC #PWR07
U 1 1 6266E18D
P 6750 6650
F 0 "#PWR07" H 6750 6500 50  0001 C CNN
F 1 "VCC" H 6767 6823 50  0000 C CNN
F 2 "" H 6750 6650 50  0001 C CNN
F 3 "" H 6750 6650 50  0001 C CNN
	1    6750 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 6600 6500 6600
Wire Wire Line
	6550 6600 6550 6650
Wire Wire Line
	6550 6650 6750 6650
$Comp
L power:GND #PWR06
U 1 1 62676E00
P 6000 6950
F 0 "#PWR06" H 6000 6700 50  0001 C CNN
F 1 "GND" H 6005 6777 50  0000 C CNN
F 2 "" H 6000 6950 50  0001 C CNN
F 3 "" H 6000 6950 50  0001 C CNN
	1    6000 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 6950 6100 6950
Wire Wire Line
	6100 6950 6100 6900
$Comp
L power:GND #PWR01
U 1 1 6268019B
P 1150 7550
F 0 "#PWR01" H 1150 7300 50  0001 C CNN
F 1 "GND" H 1155 7377 50  0000 C CNN
F 2 "" H 1150 7550 50  0001 C CNN
F 3 "" H 1150 7550 50  0001 C CNN
	1    1150 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 7200 1150 7550
Wire Wire Line
	7100 1650 9450 1650
$Comp
L Device:C C1
U 1 1 6265D991
P 5650 6750
F 0 "C1" H 5765 6796 50  0000 L CNN
F 1 "330N" H 5765 6705 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5688 6600 50  0001 C CNN
F 3 "~" H 5650 6750 50  0001 C CNN
	1    5650 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 6600 5800 6600
Wire Wire Line
	5650 6600 3550 6600
Wire Wire Line
	3550 6600 3550 6750
Connection ~ 5650 6600
Wire Wire Line
	5650 6900 6100 6900
Connection ~ 6100 6900
$Comp
L Device:C C2
U 1 1 62674904
P 6500 6750
F 0 "C2" H 6615 6796 50  0000 L CNN
F 1 "100N" H 6615 6705 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6538 6600 50  0001 C CNN
F 3 "~" H 6500 6750 50  0001 C CNN
	1    6500 6750
	1    0    0    -1  
$EndComp
Connection ~ 6500 6600
Wire Wire Line
	6500 6600 6550 6600
Wire Wire Line
	6100 6900 6500 6900
Wire Wire Line
	10150 1050 10150 1950
$Comp
L Device:R_POT RV1
U 1 1 626D32CE
P 9450 1950
F 0 "RV1" V 9335 1950 50  0000 C CNN
F 1 "R_POT" V 9244 1950 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296Z_Horizontal" H 9450 1950 50  0001 C CNN
F 3 "~" H 9450 1950 50  0001 C CNN
	1    9450 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9450 1800 9450 1650
Wire Wire Line
	7100 1950 9300 1950
Wire Wire Line
	9600 1950 10150 1950
Connection ~ 10150 1950
Wire Wire Line
	10150 1950 10150 5500
Wire Wire Line
	8650 4750 3800 4750
Wire Wire Line
	3800 4750 3800 4300
Wire Wire Line
	3800 4300 2950 4300
Wire Wire Line
	2950 4300 2950 4250
Wire Wire Line
	2950 4250 2850 4250
Wire Wire Line
	3750 4550 3550 4550
Wire Wire Line
	2850 4350 3900 4350
Wire Wire Line
	2250 5600 5850 5600
Wire Wire Line
	5850 6000 5850 5600
Connection ~ 5850 5600
Wire Wire Line
	5850 5600 6450 5600
$Comp
L power:GND #PWR04
U 1 1 626E5836
P 5550 4350
F 0 "#PWR04" H 5550 4100 50  0001 C CNN
F 1 "GND" V 5555 4222 50  0000 R CNN
F 2 "" H 5550 4350 50  0001 C CNN
F 3 "" H 5550 4350 50  0001 C CNN
	1    5550 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 3200 5950 3650
$Comp
L Device:Crystal Y1
U 1 1 626DC911
P 1150 1900
F 0 "Y1" V 1104 2031 50  0000 L CNN
F 1 "16Mhz" V 1195 2031 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_HC49-SD" H 1150 1900 50  0001 C CNN
F 3 "~" H 1150 1900 50  0001 C CNN
	1    1150 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	1150 1750 1650 1750
Wire Wire Line
	1150 2050 1550 2050
Wire Wire Line
	1550 1950 1650 1950
Wire Wire Line
	1550 1950 1550 2050
Wire Wire Line
	3550 4550 3550 4450
Wire Wire Line
	3550 4450 2850 4450
Wire Wire Line
	3650 4650 2850 4650
Wire Wire Line
	3550 4750 2850 4750
Wire Wire Line
	8700 4600 3000 4600
Wire Wire Line
	3000 4600 3000 4550
Wire Wire Line
	3000 4550 2850 4550
Wire Wire Line
	9100 5150 9100 5600
$Comp
L power:GND #PWR09
U 1 1 627E1A64
P 8500 5350
F 0 "#PWR09" H 8500 5100 50  0001 C CNN
F 1 "GND" V 8505 5222 50  0000 R CNN
F 2 "" H 8500 5350 50  0001 C CNN
F 3 "" H 8500 5350 50  0001 C CNN
	1    8500 5350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 627E22B0
P 9100 4600
F 0 "#PWR011" H 9100 4350 50  0001 C CNN
F 1 "GND" H 9105 4427 50  0000 C CNN
F 2 "" H 9100 4600 50  0001 C CNN
F 3 "" H 9100 4600 50  0001 C CNN
	1    9100 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 627E2F19
P 11100 4800
F 0 "#PWR013" H 11100 4550 50  0001 C CNN
F 1 "GND" H 11105 4627 50  0000 C CNN
F 2 "" H 11100 4800 50  0001 C CNN
F 3 "" H 11100 4800 50  0001 C CNN
	1    11100 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 627E3595
P 10700 5150
F 0 "#PWR012" H 10700 4900 50  0001 C CNN
F 1 "GND" H 10705 4977 50  0000 C CNN
F 2 "" H 10700 5150 50  0001 C CNN
F 3 "" H 10700 5150 50  0001 C CNN
	1    10700 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 4850 9700 5600
Wire Wire Line
	9700 5600 9100 5600
Wire Wire Line
	5550 4350 6300 4350
Connection ~ 9100 5600
Connection ~ 6450 5600
Wire Wire Line
	6450 5500 10150 5500
Wire Wire Line
	6450 5600 9100 5600
$EndSCHEMATC
