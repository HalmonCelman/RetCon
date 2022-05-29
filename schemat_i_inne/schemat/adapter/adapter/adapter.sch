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
L Connector:RJ45 J2
U 1 1 62A92177
P 6550 3400
F 0 "J2" H 6607 4067 50  0000 C CNN
F 1 "RJ45" H 6607 3976 50  0000 C CNN
F 2 "Connector_RJ:RJ45_Amphenol_54602-x08_Horizontal" V 6550 3425 50  0001 C CNN
F 3 "~" V 6550 3425 50  0001 C CNN
	1    6550 3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	6150 3100 6050 3100
Wire Wire Line
	6150 3200 5750 3200
Text Label 5050 3100 0    50   ~ 0
VCC
Text Label 5050 3200 0    50   ~ 0
GND
Text Label 5050 3650 0    50   ~ 0
MOSI
Text Label 5050 3550 0    50   ~ 0
MISO
Text Label 5050 3450 0    50   ~ 0
SCK
Text Label 5050 3350 0    50   ~ 0
RST
$Comp
L Device:C C1
U 1 1 627FB761
P 5900 2850
F 0 "C1" V 5648 2850 50  0000 C CNN
F 1 "C" V 5739 2850 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5938 2700 50  0001 C CNN
F 3 "~" H 5900 2850 50  0001 C CNN
	1    5900 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 2850 5750 3200
Connection ~ 5750 3200
Wire Wire Line
	5750 3200 5250 3200
Wire Wire Line
	6050 2850 6050 3100
Connection ~ 6050 3100
Wire Wire Line
	6050 3100 5250 3100
$Comp
L Connector:Conn_01x06_Female J1
U 1 1 62A94AE0
P 5450 3300
F 0 "J1" H 5478 3276 50  0000 L CNN
F 1 "Conn_01x06_Female" H 5478 3185 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 5450 3300 50  0001 C CNN
F 3 "~" H 5450 3300 50  0001 C CNN
	1    5450 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3300 5900 3300
Wire Wire Line
	5900 3300 5900 3500
Wire Wire Line
	5900 3500 6150 3500
Wire Wire Line
	5850 3400 5850 3600
Wire Wire Line
	5850 3600 6150 3600
Wire Wire Line
	5250 3500 5750 3500
Wire Wire Line
	5750 3500 5750 3700
Wire Wire Line
	5750 3700 6150 3700
Wire Wire Line
	5250 3600 5650 3600
Wire Wire Line
	5650 3600 5650 3800
Wire Wire Line
	5650 3800 6150 3800
Wire Wire Line
	5250 3400 5850 3400
$EndSCHEMATC
