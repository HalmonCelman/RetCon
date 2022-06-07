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
L Device:IRF7476 U1
U 1 1 629F01C3
P 5750 3000
F 0 "U1" H 5750 3375 50  0000 C CNN
F 1 "IRF7476" H 5750 3284 50  0000 C CNN
F 2 "Package_SO:PowerIntegrations_SO-8" H 5750 3000 50  0001 C CNN
F 3 "" H 5750 3000 50  0001 C CNN
	1    5750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2850 5450 2950
Wire Wire Line
	5450 2950 5450 3050
Connection ~ 5450 2950
Wire Wire Line
	6050 2850 6050 2950
Wire Wire Line
	6050 3150 6050 3050
Wire Wire Line
	6050 3050 6050 2950
Connection ~ 6050 3050
Connection ~ 6050 2950
Wire Wire Line
	5250 3150 5450 3150
Wire Wire Line
	5450 2850 5450 2650
Connection ~ 5450 2850
$Comp
L Device:R R1
U 1 1 629FC923
P 6600 2900
F 0 "R1" H 6670 2946 50  0000 L CNN
F 1 "10K" H 6670 2855 50  0000 L CNN
F 2 "" V 6530 2900 50  0001 C CNN
F 3 "~" H 6600 2900 50  0001 C CNN
	1    6600 2900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 629FD370
P 4900 2750
F 0 "J1" H 5008 3031 50  0000 C CNN
F 1 "Conn_01x04_Male" H 5008 2940 50  0000 C CNN
F 2 "" H 4900 2750 50  0001 C CNN
F 3 "~" H 4900 2750 50  0001 C CNN
	1    4900 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3050 6050 3050
$Comp
L power:+1V8 #PWR02
U 1 1 629FEED6
P 6600 2750
F 0 "#PWR02" H 6600 2600 50  0001 C CNN
F 1 "+1V8" H 6615 2923 50  0000 C CNN
F 2 "" H 6600 2750 50  0001 C CNN
F 3 "" H 6600 2750 50  0001 C CNN
	1    6600 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 629FF313
P 7200 3150
F 0 "J2" H 7308 3431 50  0000 C CNN
F 1 "Conn_01x04_Male" H 7308 3340 50  0000 C CNN
F 2 "" H 7200 3150 50  0001 C CNN
F 3 "~" H 7200 3150 50  0001 C CNN
	1    7200 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3050 7400 3050
Connection ~ 6600 3050
$Comp
L power:GND #PWR01
U 1 1 629FFFE7
P 5250 3150
F 0 "#PWR01" H 5250 2900 50  0001 C CNN
F 1 "GND" H 5255 2977 50  0000 C CNN
F 2 "" H 5250 3150 50  0001 C CNN
F 3 "" H 5250 3150 50  0001 C CNN
	1    5250 3150
	1    0    0    -1  
$EndComp
Text Notes 4700 2650 0    50   ~ 0
MOSI
$Comp
L power:GND #PWR03
U 1 1 62A028F5
P 5150 4000
F 0 "#PWR03" H 5150 3750 50  0001 C CNN
F 1 "GND" H 5155 3827 50  0000 C CNN
F 2 "" H 5150 4000 50  0001 C CNN
F 3 "" H 5150 4000 50  0001 C CNN
	1    5150 4000
	1    0    0    -1  
$EndComp
Text Notes 4700 2750 0    50   ~ 0
MISO
Text Notes 6350 3850 0    50   ~ 0
<-inny\n
$Comp
L Device:IRF7476 U3
U 1 1 62A10EB9
P 5800 4750
F 0 "U3" H 5800 5125 50  0000 C CNN
F 1 "IRF7476" H 5800 5034 50  0000 C CNN
F 2 "Package_SO:PowerIntegrations_SO-8" H 5800 4750 50  0001 C CNN
F 3 "" H 5800 4750 50  0001 C CNN
	1    5800 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4600 5500 4700
Wire Wire Line
	5500 4700 5500 4800
Connection ~ 5500 4700
Wire Wire Line
	6100 4600 6100 4700
Wire Wire Line
	6100 4900 6100 4800
Wire Wire Line
	6100 4800 6100 4700
Connection ~ 6100 4800
Connection ~ 6100 4700
Wire Wire Line
	5300 4900 5500 4900
Wire Wire Line
	5500 4600 5500 4400
Connection ~ 5500 4600
Wire Wire Line
	6650 4800 6100 4800
$Comp
L Device:R R3
U 1 1 62A12BBF
P 6650 4650
F 0 "R3" H 6720 4696 50  0000 L CNN
F 1 "10K" H 6720 4605 50  0000 L CNN
F 2 "" V 6580 4650 50  0001 C CNN
F 3 "~" H 6650 4650 50  0001 C CNN
	1    6650 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+1V8 #PWR06
U 1 1 62A12BC6
P 6650 4500
F 0 "#PWR06" H 6650 4350 50  0001 C CNN
F 1 "+1V8" H 6665 4673 50  0000 C CNN
F 2 "" H 6650 4500 50  0001 C CNN
F 3 "" H 6650 4500 50  0001 C CNN
	1    6650 4500
	1    0    0    -1  
$EndComp
Connection ~ 6650 4800
$Comp
L power:GND #PWR04
U 1 1 62A158A3
P 5300 4900
F 0 "#PWR04" H 5300 4650 50  0001 C CNN
F 1 "GND" H 5305 4727 50  0000 C CNN
F 2 "" H 5300 4900 50  0001 C CNN
F 3 "" H 5300 4900 50  0001 C CNN
	1    5300 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:IRF7476 U4
U 1 1 62A18FB9
P 5800 5650
F 0 "U4" H 5800 6025 50  0000 C CNN
F 1 "IRF7476" H 5800 5934 50  0000 C CNN
F 2 "Package_SO:PowerIntegrations_SO-8" H 5800 5650 50  0001 C CNN
F 3 "" H 5800 5650 50  0001 C CNN
	1    5800 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 5500 5500 5600
Wire Wire Line
	5500 5600 5500 5700
Connection ~ 5500 5600
Wire Wire Line
	6100 5500 6100 5600
Wire Wire Line
	6100 5800 6100 5700
Wire Wire Line
	6100 5700 6100 5600
Connection ~ 6100 5700
Connection ~ 6100 5600
Wire Wire Line
	5300 5800 5500 5800
Wire Wire Line
	5500 5500 5500 5300
Connection ~ 5500 5500
Wire Wire Line
	6650 5700 6100 5700
$Comp
L Device:R R4
U 1 1 62A18FCC
P 6650 5550
F 0 "R4" H 6720 5596 50  0000 L CNN
F 1 "10K" H 6720 5505 50  0000 L CNN
F 2 "" V 6580 5550 50  0001 C CNN
F 3 "~" H 6650 5550 50  0001 C CNN
	1    6650 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+1V8 #PWR07
U 1 1 62A18FD2
P 6650 5400
F 0 "#PWR07" H 6650 5250 50  0001 C CNN
F 1 "+1V8" H 6665 5573 50  0000 C CNN
F 2 "" H 6650 5400 50  0001 C CNN
F 3 "" H 6650 5400 50  0001 C CNN
	1    6650 5400
	1    0    0    -1  
$EndComp
Connection ~ 6650 5700
$Comp
L power:GND #PWR05
U 1 1 62A18FDA
P 5300 5800
F 0 "#PWR05" H 5300 5550 50  0001 C CNN
F 1 "GND" H 5305 5627 50  0000 C CNN
F 2 "" H 5300 5800 50  0001 C CNN
F 3 "" H 5300 5800 50  0001 C CNN
	1    5300 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2750 5300 2750
Wire Wire Line
	5100 2650 5450 2650
Wire Wire Line
	4850 4400 4850 2850
Wire Wire Line
	4850 2850 5100 2850
Wire Wire Line
	4850 4400 5500 4400
Wire Wire Line
	7500 4800 7500 3750
Wire Wire Line
	7500 3750 7100 3750
Wire Wire Line
	7100 3750 7100 3250
Wire Wire Line
	7100 3250 7400 3250
Wire Wire Line
	6650 4800 7500 4800
Wire Wire Line
	4800 5300 4800 2950
Wire Wire Line
	4800 2950 5100 2950
Wire Wire Line
	4800 5300 5500 5300
Wire Wire Line
	7550 5700 7550 3350
Wire Wire Line
	7550 3350 7400 3350
Wire Wire Line
	6650 5700 7550 5700
Text Notes 4650 2850 0    50   ~ 0
SCK
Text Notes 4600 2950 0    50   ~ 0
CS
Wire Wire Line
	6600 3350 6600 3150
Wire Wire Line
	6600 3150 7400 3150
$Comp
L Device:D_Zener D?
U 1 1 62A2A835
P 5450 3350
F 0 "D?" H 5450 3134 50  0000 C CNN
F 1 "4,7V" H 5450 3225 50  0000 C CNN
F 2 "" H 5450 3350 50  0001 C CNN
F 3 "~" H 5450 3350 50  0001 C CNN
	1    5450 3350
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62A2D81A
P 5150 3850
F 0 "R?" H 5220 3896 50  0000 L CNN
F 1 "10K" H 5220 3805 50  0000 L CNN
F 2 "" V 5080 3850 50  0001 C CNN
F 3 "~" H 5150 3850 50  0001 C CNN
	1    5150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3350 5300 3350
Connection ~ 5300 3350
Wire Wire Line
	5300 3350 5300 2750
Wire Wire Line
	5150 3350 5150 3700
Wire Wire Line
	5600 3350 6600 3350
$EndSCHEMATC
