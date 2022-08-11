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
L SD:SD U1
U 1 1 62F53B84
P 7250 2900
F 0 "U1" H 8078 2946 50  0000 L CNN
F 1 "SD" H 8078 2855 50  0000 L CNN
F 2 "Connector_Card:SD_Kyocera_145638009511859+" H 7250 3100 50  0001 C CNN
F 3 "" H 7250 3100 50  0001 C CNN
	1    7250 2900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male J1
U 1 1 62F5505E
P 4850 2900
F 0 "J1" H 4958 3281 50  0000 C CNN
F 1 "Conn_01x06_Male" H 4958 3190 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4850 2900 50  0001 C CNN
F 3 "~" H 4850 2900 50  0001 C CNN
	1    4850 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2900 5050 2900
Wire Wire Line
	5400 2800 5050 2800
Wire Wire Line
	6150 2800 6350 2800
Wire Wire Line
	6350 2900 5700 2900
Wire Wire Line
	5050 3000 6350 3000
Wire Wire Line
	5500 2450 6200 2450
Wire Wire Line
	6200 2450 6200 2700
Wire Wire Line
	6200 2700 6350 2700
Wire Wire Line
	5500 2450 5500 2900
Wire Wire Line
	5400 2350 6250 2350
Wire Wire Line
	6250 2350 6250 2600
Wire Wire Line
	6250 2600 6350 2600
Wire Wire Line
	5400 2350 5400 2800
Wire Wire Line
	5700 2700 5050 2700
Wire Wire Line
	5700 2700 5700 2900
Wire Wire Line
	6350 3200 6250 3200
Wire Wire Line
	6250 3200 6250 3300
Wire Wire Line
	6250 3300 5150 3300
Wire Wire Line
	5150 3300 5150 3100
Wire Wire Line
	5150 3100 5050 3100
Wire Wire Line
	5050 3200 6150 3200
Wire Wire Line
	6150 2800 6150 3100
Wire Wire Line
	6350 3100 6150 3100
Connection ~ 6150 3100
Wire Wire Line
	6150 3100 6150 3200
Text Label 5050 2700 0    50   ~ 0
+5V
Text Label 5050 2800 0    50   ~ 0
CS
Text Label 5050 2900 0    50   ~ 0
MOSI
Text Label 5050 3000 0    50   ~ 0
SCK
Text Label 5050 3100 0    50   ~ 0
MISO
Text Label 5050 3200 0    50   ~ 0
+1,8V
$EndSCHEMATC
