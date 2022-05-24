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
P 6300 1100
F 0 "U4" H 7078 1146 50  0000 L CNN
F 1 "SD_card_reader" H 7078 1055 50  0000 L CNN
F 2 "Connector_Card:SD_Kyocera_145638009511859+" H 6250 1100 50  0001 C CNN
F 3 "" H 6250 1100 50  0001 C CNN
	1    6300 1100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR02
U 1 1 61DB3E6A
P 2300 1150
F 0 "#PWR02" H 2300 1000 50  0001 C CNN
F 1 "VCC" H 2315 1323 50  0000 C CNN
F 2 "" H 2300 1150 50  0001 C CNN
F 3 "" H 2300 1150 50  0001 C CNN
	1    2300 1150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 SW1
U 1 1 626527EA
P 3900 5850
F 0 "SW1" H 3900 6117 50  0000 C CNN
F 1 "SW_DIP_x01" H 3900 6026 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3900 5850 50  0001 C CNN
F 3 "~" H 3900 5850 50  0001 C CNN
	1    3900 5850
	-1   0    0    1   
$EndComp
$Comp
L Device:Battery BT1
U 1 1 6265C2FE
P 3400 5850
F 0 "BT1" H 3508 5896 50  0000 L CNN
F 1 "9V battery" H 3508 5805 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" V 3400 5910 50  0001 C CNN
F 3 "~" V 3400 5910 50  0001 C CNN
	1    3400 5850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR01
U 1 1 6268019B
P 3200 5850
F 0 "#PWR01" H 3200 5600 50  0001 C CNN
F 1 "GND" H 3205 5677 50  0000 C CNN
F 2 "" H 3200 5850 50  0001 C CNN
F 3 "" H 3200 5850 50  0001 C CNN
	1    3200 5850
	0    1    1    0   
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 626D32CE
P 4950 3750
F 0 "RV1" V 4835 3750 50  0000 C CNN
F 1 "R_POT" V 4744 3750 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296Z_Horizontal" H 4950 3750 50  0001 C CNN
F 3 "~" H 4950 3750 50  0001 C CNN
	1    4950 3750
	-1   0    0    1   
$EndComp
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
$Comp
L Device:Buzzer BZ1
U 1 1 627A142A
P 3900 1200
F 0 "BZ1" V 3858 1352 50  0000 L CNN
F 1 "Buzzer" V 3949 1352 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 3875 1300 50  0001 C CNN
F 3 "~" V 3875 1300 50  0001 C CNN
	1    3900 1200
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x01_Female J1
U 1 1 627D6C2D
P 10650 800
F 0 "J1" H 10678 826 50  0000 L CNN
F 1 "Hole1" H 10678 735 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 10650 800 50  0001 C CNN
F 3 "~" H 10650 800 50  0001 C CNN
	1    10650 800 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J2
U 1 1 627D7CE4
P 10650 950
F 0 "J2" H 10678 976 50  0000 L CNN
F 1 "Hole2" H 10678 885 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 10650 950 50  0001 C CNN
F 3 "~" H 10650 950 50  0001 C CNN
	1    10650 950 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J3
U 1 1 627D8D77
P 10650 1150
F 0 "J3" H 10678 1176 50  0000 L CNN
F 1 "Hole3" H 10678 1085 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 10650 1150 50  0001 C CNN
F 3 "~" H 10650 1150 50  0001 C CNN
	1    10650 1150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J4
U 1 1 627D9436
P 10650 1300
F 0 "J4" H 10678 1326 50  0000 L CNN
F 1 "Hole4" H 10678 1235 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 10650 1300 50  0001 C CNN
F 3 "~" H 10650 1300 50  0001 C CNN
	1    10650 1300
	1    0    0    -1  
$EndComp
$Comp
L Connector:RJ45 J5
U 1 1 6286835F
P 5700 3050
F 0 "J5" V 5711 3580 50  0000 L CNN
F 1 "RJ45" V 5802 3580 50  0000 L CNN
F 2 "Connector_RJ:RJ45_Amphenol_54602-x08_Horizontal" V 5700 3075 50  0001 C CNN
F 3 "~" V 5700 3075 50  0001 C CNN
	1    5700 3050
	-1   0    0    1   
$EndComp
$Comp
L schemat_dip40-rescue:WG12864B-STBL U3
U 1 1 6288712E
P 4300 4400
F 0 "U3" H 4300 5431 50  0000 C CNN
F 1 "WG12864B-STBL" H 4300 5340 50  0000 C CNN
F 2 "Blue:WG12864BL" H 4300 4400 50  0001 C CNN
F 3 "" H 4300 4400 50  0001 C CNN
	1    4300 4400
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR04
U 1 1 629ACB69
P 4300 3550
F 0 "#PWR04" H 4300 3400 50  0001 C CNN
F 1 "VCC" H 4317 3723 50  0000 C CNN
F 2 "" H 4300 3550 50  0001 C CNN
F 3 "" H 4300 3550 50  0001 C CNN
	1    4300 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3950 3700 3950
Wire Wire Line
	3700 3950 3700 3550
Wire Wire Line
	3700 3550 4300 3550
Connection ~ 4300 3550
$Comp
L power:VCC #PWR08
U 1 1 629CD79E
P 4800 4450
F 0 "#PWR08" H 4800 4300 50  0001 C CNN
F 1 "VCC" H 4817 4623 50  0000 C CNN
F 2 "" H 4800 4450 50  0001 C CNN
F 3 "" H 4800 4450 50  0001 C CNN
	1    4800 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 629CE057
P 4800 4550
F 0 "#PWR09" H 4800 4300 50  0001 C CNN
F 1 "GND" H 4805 4377 50  0000 C CNN
F 2 "" H 4800 4550 50  0001 C CNN
F 3 "" H 4800 4550 50  0001 C CNN
	1    4800 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4050 4950 4050
Wire Wire Line
	4950 4050 4950 3900
Wire Wire Line
	4950 3600 4950 3550
Wire Wire Line
	4950 3550 4300 3550
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
Wire Wire Line
	4900 2950 2850 2950
Wire Wire Line
	5100 3050 2850 3050
Wire Wire Line
	5000 3150 2850 3150
$Comp
L power:GND #PWR013
U 1 1 62AA4B04
P 5350 750
F 0 "#PWR013" H 5350 500 50  0001 C CNN
F 1 "GND" H 5355 577 50  0000 C CNN
F 2 "" H 5350 750 50  0001 C CNN
F 3 "" H 5350 750 50  0001 C CNN
	1    5350 750 
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR014
U 1 1 62AA517D
P 5350 950
F 0 "#PWR014" H 5350 800 50  0001 C CNN
F 1 "VCC" H 5368 1123 50  0000 C CNN
F 2 "" H 5350 950 50  0001 C CNN
F 3 "" H 5350 950 50  0001 C CNN
	1    5350 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 2850 2850 2850
$Comp
L power:GND #PWR015
U 1 1 62AA82B4
P 5350 1450
F 0 "#PWR015" H 5350 1200 50  0001 C CNN
F 1 "GND" H 5355 1277 50  0000 C CNN
F 2 "" H 5350 1450 50  0001 C CNN
F 3 "" H 5350 1450 50  0001 C CNN
	1    5350 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	5300 2950 4900 2950
Connection ~ 4900 2950
Wire Wire Line
	5300 3050 5100 3050
Connection ~ 5100 3050
Wire Wire Line
	5300 3150 5000 3150
Connection ~ 5000 3150
$Comp
L power:VCC #PWR011
U 1 1 62AC0AFC
P 5300 2750
F 0 "#PWR011" H 5300 2600 50  0001 C CNN
F 1 "VCC" H 5317 2923 50  0000 C CNN
F 2 "" H 5300 2750 50  0001 C CNN
F 3 "" H 5300 2750 50  0001 C CNN
	1    5300 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 62AC7AB6
P 5300 2850
F 0 "#PWR012" H 5300 2600 50  0001 C CNN
F 1 "GND" V 5305 2722 50  0000 R CNN
F 2 "" H 5300 2850 50  0001 C CNN
F 3 "" H 5300 2850 50  0001 C CNN
	1    5300 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 1550 1650 700 
Wire Wire Line
	1650 700  3450 700 
Wire Wire Line
	3450 700  3450 3250
Wire Wire Line
	3450 3250 5300 3250
$Comp
L power:GND #PWR03
U 1 1 62AD9C6E
P 2250 5250
F 0 "#PWR03" H 2250 5000 50  0001 C CNN
F 1 "GND" H 2255 5077 50  0000 C CNN
F 2 "" H 2250 5250 50  0001 C CNN
F 3 "" H 2250 5250 50  0001 C CNN
	1    2250 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1250 2250 1150
Wire Wire Line
	2250 1150 2300 1150
Wire Wire Line
	2350 1150 2350 1250
Connection ~ 2300 1150
Wire Wire Line
	2300 1150 2350 1150
Wire Wire Line
	5100 1350 5350 1350
Wire Wire Line
	5100 1350 5100 3050
Wire Wire Line
	5000 1250 5350 1250
Wire Wire Line
	5000 1250 5000 3150
Wire Wire Line
	4900 1150 5350 1150
Wire Wire Line
	4900 1150 4900 2950
Wire Wire Line
	4800 1050 5350 1050
Wire Wire Line
	4800 1050 4800 2850
Wire Wire Line
	3800 1300 3800 1550
Wire Wire Line
	3800 1550 2850 1550
$Comp
L power:GND #PWR07
U 1 1 62B553AC
P 4000 1300
F 0 "#PWR07" H 4000 1050 50  0001 C CNN
F 1 "GND" H 4005 1127 50  0000 C CNN
F 2 "" H 4000 1300 50  0001 C CNN
F 3 "" H 4000 1300 50  0001 C CNN
	1    4000 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1650 2850 1650
Wire Wire Line
	6800 4650 6700 4650
Wire Wire Line
	6700 4650 6700 1750
Wire Wire Line
	6700 1750 2850 1750
Wire Wire Line
	6200 1850 2850 1850
Wire Wire Line
	7400 1950 2850 1950
Wire Wire Line
	8300 2050 2850 2050
Wire Wire Line
	8700 2150 2850 2150
Wire Wire Line
	6600 4350 6600 4900
Wire Wire Line
	9100 4900 9100 4350
Wire Wire Line
	8700 4700 8700 4900
Connection ~ 8700 4900
Wire Wire Line
	8700 4900 9100 4900
Wire Wire Line
	7800 4350 7800 4900
Connection ~ 7800 4900
Wire Wire Line
	7800 4900 8700 4900
$Comp
L power:GND #PWR016
U 1 1 62B79A14
P 7800 4900
F 0 "#PWR016" H 7800 4650 50  0001 C CNN
F 1 "GND" H 7805 4727 50  0000 C CNN
F 2 "" H 7800 4900 50  0001 C CNN
F 3 "" H 7800 4900 50  0001 C CNN
	1    7800 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 6150 5050 6150
$Comp
L Device:C C2
U 1 1 62674904
P 5050 6000
F 0 "C2" H 5165 6046 50  0000 L CNN
F 1 "100N" H 5165 5955 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5088 5850 50  0001 C CNN
F 3 "~" H 5050 6000 50  0001 C CNN
	1    5050 6000
	1    0    0    -1  
$EndComp
Connection ~ 4650 6150
Wire Wire Line
	4200 6150 4650 6150
Wire Wire Line
	4200 5850 4350 5850
$Comp
L Device:C C1
U 1 1 6265D991
P 4200 6000
F 0 "C1" H 4315 6046 50  0000 L CNN
F 1 "330N" H 4315 5955 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4238 5850 50  0001 C CNN
F 3 "~" H 4200 6000 50  0001 C CNN
	1    4200 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 62676E00
P 4650 6150
F 0 "#PWR06" H 4650 5900 50  0001 C CNN
F 1 "GND" H 4655 5977 50  0000 C CNN
F 2 "" H 4650 6150 50  0001 C CNN
F 3 "" H 4650 6150 50  0001 C CNN
	1    4650 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 5850 5050 5850
$Comp
L Regulator_Linear:L7805 U2
U 1 1 62650285
P 4650 5850
F 0 "U2" H 4650 6092 50  0000 C CNN
F 1 "L7805" H 4650 6001 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 4675 5700 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 4650 5800 50  0001 C CNN
	1    4650 5850
	1    0    0    -1  
$EndComp
Connection ~ 4200 5850
$Comp
L power:VCC #PWR010
U 1 1 62BD496D
P 5050 5850
F 0 "#PWR010" H 5050 5700 50  0001 C CNN
F 1 "VCC" H 5067 6023 50  0000 C CNN
F 2 "" H 5050 5850 50  0001 C CNN
F 3 "" H 5050 5850 50  0001 C CNN
	1    5050 5850
	1    0    0    -1  
$EndComp
Connection ~ 5050 5850
Wire Wire Line
	3800 4250 3600 4250
Wire Wire Line
	3600 4250 3600 3350
Wire Wire Line
	3600 3350 2850 3350
Wire Wire Line
	3800 4350 3550 4350
Wire Wire Line
	3550 4350 3550 3450
Wire Wire Line
	3550 3450 2850 3450
Wire Wire Line
	3800 4450 3500 4450
Wire Wire Line
	3500 4450 3500 3550
Wire Wire Line
	3500 3550 2850 3550
Wire Wire Line
	3800 4550 3450 4550
Wire Wire Line
	3450 4550 3450 3650
Wire Wire Line
	3450 3650 2850 3650
Wire Wire Line
	3800 4650 3400 4650
Wire Wire Line
	3400 4650 3400 3750
Wire Wire Line
	3400 3750 2850 3750
Wire Wire Line
	3800 4750 3350 4750
Wire Wire Line
	3350 4750 3350 3850
Wire Wire Line
	3350 3850 2850 3850
Wire Wire Line
	3800 4850 3300 4850
Wire Wire Line
	3300 4850 3300 3950
Wire Wire Line
	3300 3950 2850 3950
Wire Wire Line
	3800 4950 3250 4950
Wire Wire Line
	3250 4950 3250 4050
Wire Wire Line
	3250 4050 2850 4050
Wire Wire Line
	3800 4050 3750 4050
Wire Wire Line
	3750 4050 3750 4900
Wire Wire Line
	3750 4900 3200 4900
Wire Wire Line
	3200 4900 3200 4950
Wire Wire Line
	3200 4950 2850 4950
Wire Wire Line
	3800 3850 3650 3850
Wire Wire Line
	3650 3850 3650 4800
Wire Wire Line
	3650 4800 3200 4800
Wire Wire Line
	3200 4800 3200 4850
Wire Wire Line
	3200 4850 2850 4850
Wire Wire Line
	3800 3750 3800 3700
Wire Wire Line
	3800 3700 3200 3700
Wire Wire Line
	3200 3700 3200 4750
Wire Wire Line
	3200 4750 2850 4750
Wire Wire Line
	4800 4950 4800 5350
Wire Wire Line
	4800 5350 3150 5350
Wire Wire Line
	3150 5350 3150 4650
Wire Wire Line
	3150 4650 2850 4650
Wire Wire Line
	4800 4850 4850 4850
Wire Wire Line
	4850 4850 4850 5400
Wire Wire Line
	4850 5400 3100 5400
Wire Wire Line
	3100 5400 3100 4550
Wire Wire Line
	3100 4550 2850 4550
Wire Wire Line
	8700 4350 8700 2150
$Comp
L Switch:SW_Push SW7
U 1 1 6262299A
P 8900 4350
F 0 "SW7" H 8900 4635 50  0000 C CNN
F 1 "Punch" H 8900 4544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8900 4550 50  0001 C CNN
F 3 "~" H 8900 4550 50  0001 C CNN
	1    8900 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 4700 8300 2050
Wire Wire Line
	7400 4350 7400 1950
Wire Wire Line
	7200 4900 7800 4900
Wire Wire Line
	6600 4900 7200 4900
Connection ~ 7200 4900
Wire Wire Line
	6800 4100 6800 1650
Wire Wire Line
	6200 4350 6200 1850
$Comp
L Switch:SW_Push SW6
U 1 1 626213AA
P 8500 4700
F 0 "SW6" H 8500 4985 50  0000 C CNN
F 1 "Jump" H 8500 4894 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 8500 4900 50  0001 C CNN
F 3 "~" H 8500 4900 50  0001 C CNN
	1    8500 4700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 6262059D
P 7600 4350
F 0 "SW5" H 7600 4635 50  0000 C CNN
F 1 "Right" H 7600 4544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7600 4550 50  0001 C CNN
F 3 "~" H 7600 4550 50  0001 C CNN
	1    7600 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4650 7200 4900
Wire Wire Line
	7200 4100 7200 4650
Connection ~ 7200 4650
$Comp
L Switch:SW_Push SW4
U 1 1 6261FEC3
P 7000 4650
F 0 "SW4" H 7000 4935 50  0000 C CNN
F 1 "Down" H 7000 4844 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7000 4850 50  0001 C CNN
F 3 "~" H 7000 4850 50  0001 C CNN
	1    7000 4650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 6261EEBB
P 7000 4100
F 0 "SW3" H 7000 4385 50  0000 C CNN
F 1 "Up" H 7000 4294 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7000 4300 50  0001 C CNN
F 3 "~" H 7000 4300 50  0001 C CNN
	1    7000 4100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 62620D64
P 6400 4350
F 0 "SW2" H 6400 4635 50  0000 C CNN
F 1 "Left" H 6400 4544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6400 4550 50  0001 C CNN
F 3 "~" H 6400 4550 50  0001 C CNN
	1    6400 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 629577BC
P 4150 5150
F 0 "R1" V 3943 5150 50  0000 C CNN
F 1 "0R" V 4034 5150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4080 5150 50  0001 C CNN
F 3 "~" H 4150 5150 50  0001 C CNN
	1    4150 5150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR05
U 1 1 62958323
P 4000 5150
F 0 "#PWR05" H 4000 4900 50  0001 C CNN
F 1 "GND" H 4005 4977 50  0000 C CNN
F 2 "" H 4000 5150 50  0001 C CNN
F 3 "" H 4000 5150 50  0001 C CNN
	1    4000 5150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
