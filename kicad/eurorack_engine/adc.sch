EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
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
L Analog_ADC:MCP3208 U?
U 1 1 5FA35FA1
P 6200 2150
AR Path="/5F91B719/5FA35FA1" Ref="U?"  Part="1" 
AR Path="/5FA315BA/5FA35FA1" Ref="U7"  Part="1" 
F 0 "U7" H 6200 2831 50  0000 C CNN
F 1 "MCP3208" H 6200 2740 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 6300 2250 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21298c.pdf" H 6300 2250 50  0001 C CNN
	1    6200 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5FA35FA7
P 6400 1350
AR Path="/5F91B719/5FA35FA7" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA35FA7" Ref="#PWR033"  Part="1" 
F 0 "#PWR033" H 6400 1200 50  0001 C CNN
F 1 "+3V3" H 6415 1523 50  0000 C CNN
F 2 "" H 6400 1350 50  0001 C CNN
F 3 "" H 6400 1350 50  0001 C CNN
	1    6400 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 1650 6400 1350
Wire Wire Line
	6100 1650 6100 1350
Wire Wire Line
	6100 1350 6400 1350
Connection ~ 6400 1350
$Comp
L power:GND #PWR?
U 1 1 5FA35FB1
P 6100 2850
AR Path="/5F91B719/5FA35FB1" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA35FB1" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 6100 2600 50  0001 C CNN
F 1 "GND" H 6105 2677 50  0000 C CNN
F 2 "" H 6100 2850 50  0001 C CNN
F 3 "" H 6100 2850 50  0001 C CNN
	1    6100 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2750 6100 2850
Wire Wire Line
	6400 2750 6400 2850
Wire Wire Line
	6400 2850 6100 2850
Connection ~ 6100 2850
Text Label 7100 2350 0    50   ~ 0
adc_cs
Wire Wire Line
	7100 2350 6800 2350
Text Label 7100 2150 0    50   ~ 0
adc_miso
Text Label 7100 2050 0    50   ~ 0
adc_clk
Wire Wire Line
	7100 2050 6800 2050
Wire Wire Line
	6800 2150 7100 2150
Wire Wire Line
	7100 2250 6800 2250
Text Label 7100 2250 0    50   ~ 0
adc_mosi
Text Label 5350 1850 2    50   ~ 0
adc_ch0
Text Label 5350 1950 2    50   ~ 0
adc_ch1
Text Label 5350 2050 2    50   ~ 0
adc_ch2
Text Label 5350 2150 2    50   ~ 0
adc_ch3
Text Label 5350 2250 2    50   ~ 0
adc_ch4
Text Label 5350 2350 2    50   ~ 0
adc_ch5
Text Label 5350 2450 2    50   ~ 0
adc_ch6
Text Label 5350 2550 2    50   ~ 0
adc_ch7
Wire Wire Line
	5350 1850 5600 1850
Wire Wire Line
	5350 1950 5600 1950
Wire Wire Line
	5350 2050 5600 2050
Wire Wire Line
	5350 2150 5600 2150
Wire Wire Line
	5350 2250 5600 2250
Wire Wire Line
	5350 2350 5600 2350
Wire Wire Line
	5350 2450 5600 2450
Wire Wire Line
	5350 2550 5600 2550
$Comp
L Device:R_POT RV?
U 1 1 5FA35FD3
P 2950 4450
AR Path="/5F91B719/5FA35FD3" Ref="RV?"  Part="1" 
AR Path="/5FA315BA/5FA35FD3" Ref="RV1"  Part="1" 
F 0 "RV1" H 2881 4496 50  0000 R CNN
F 1 "R_POT" H 2881 4405 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09K_Single_Vertical" H 2950 4450 50  0001 C CNN
F 3 "~" H 2950 4450 50  0001 C CNN
	1    2950 4450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5FA35FD9
P 2950 4100
AR Path="/5F91B719/5FA35FD9" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA35FD9" Ref="#PWR026"  Part="1" 
F 0 "#PWR026" H 2950 3950 50  0001 C CNN
F 1 "+3V3" H 2965 4273 50  0000 C CNN
F 2 "" H 2950 4100 50  0001 C CNN
F 3 "" H 2950 4100 50  0001 C CNN
	1    2950 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FA35FDF
P 2950 4800
AR Path="/5F91B719/5FA35FDF" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA35FDF" Ref="#PWR027"  Part="1" 
F 0 "#PWR027" H 2950 4550 50  0001 C CNN
F 1 "GND" H 2955 4627 50  0000 C CNN
F 2 "" H 2950 4800 50  0001 C CNN
F 3 "" H 2950 4800 50  0001 C CNN
	1    2950 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 4100 2950 4300
Wire Wire Line
	2950 4600 2950 4800
Text Label 3400 4450 0    50   ~ 0
adc_ch4
Wire Wire Line
	3100 4450 3400 4450
$Comp
L Device:R_POT RV?
U 1 1 5FA35FE9
P 4500 4450
AR Path="/5F91B719/5FA35FE9" Ref="RV?"  Part="1" 
AR Path="/5FA315BA/5FA35FE9" Ref="RV2"  Part="1" 
F 0 "RV2" H 4431 4496 50  0000 R CNN
F 1 "R_POT" H 4431 4405 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09K_Single_Vertical" H 4500 4450 50  0001 C CNN
F 3 "~" H 4500 4450 50  0001 C CNN
	1    4500 4450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5FA35FEF
P 4500 4100
AR Path="/5F91B719/5FA35FEF" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA35FEF" Ref="#PWR028"  Part="1" 
F 0 "#PWR028" H 4500 3950 50  0001 C CNN
F 1 "+3V3" H 4515 4273 50  0000 C CNN
F 2 "" H 4500 4100 50  0001 C CNN
F 3 "" H 4500 4100 50  0001 C CNN
	1    4500 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FA35FF5
P 4500 4800
AR Path="/5F91B719/5FA35FF5" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA35FF5" Ref="#PWR029"  Part="1" 
F 0 "#PWR029" H 4500 4550 50  0001 C CNN
F 1 "GND" H 4505 4627 50  0000 C CNN
F 2 "" H 4500 4800 50  0001 C CNN
F 3 "" H 4500 4800 50  0001 C CNN
	1    4500 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4100 4500 4300
Wire Wire Line
	4500 4600 4500 4800
Text Label 4950 4450 0    50   ~ 0
adc_ch5
Wire Wire Line
	4650 4450 4950 4450
$Comp
L Device:R_POT RV?
U 1 1 5FA35FFF
P 5850 4450
AR Path="/5F91B719/5FA35FFF" Ref="RV?"  Part="1" 
AR Path="/5FA315BA/5FA35FFF" Ref="RV3"  Part="1" 
F 0 "RV3" H 5781 4496 50  0000 R CNN
F 1 "R_POT" H 5781 4405 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09K_Single_Vertical" H 5850 4450 50  0001 C CNN
F 3 "~" H 5850 4450 50  0001 C CNN
	1    5850 4450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5FA36005
P 5850 4100
AR Path="/5F91B719/5FA36005" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA36005" Ref="#PWR030"  Part="1" 
F 0 "#PWR030" H 5850 3950 50  0001 C CNN
F 1 "+3V3" H 5865 4273 50  0000 C CNN
F 2 "" H 5850 4100 50  0001 C CNN
F 3 "" H 5850 4100 50  0001 C CNN
	1    5850 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FA3600B
P 5850 4800
AR Path="/5F91B719/5FA3600B" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA3600B" Ref="#PWR031"  Part="1" 
F 0 "#PWR031" H 5850 4550 50  0001 C CNN
F 1 "GND" H 5855 4627 50  0000 C CNN
F 2 "" H 5850 4800 50  0001 C CNN
F 3 "" H 5850 4800 50  0001 C CNN
	1    5850 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 4100 5850 4300
Wire Wire Line
	5850 4600 5850 4800
Text Label 6300 4450 0    50   ~ 0
adc_ch6
Wire Wire Line
	6000 4450 6300 4450
$Comp
L Device:R_POT RV?
U 1 1 5FA36015
P 7300 4450
AR Path="/5F91B719/5FA36015" Ref="RV?"  Part="1" 
AR Path="/5FA315BA/5FA36015" Ref="RV4"  Part="1" 
F 0 "RV4" H 7231 4496 50  0000 R CNN
F 1 "R_POT" H 7231 4405 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Alps_RK09K_Single_Vertical" H 7300 4450 50  0001 C CNN
F 3 "~" H 7300 4450 50  0001 C CNN
	1    7300 4450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5FA3601B
P 7300 4100
AR Path="/5F91B719/5FA3601B" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA3601B" Ref="#PWR034"  Part="1" 
F 0 "#PWR034" H 7300 3950 50  0001 C CNN
F 1 "+3V3" H 7315 4273 50  0000 C CNN
F 2 "" H 7300 4100 50  0001 C CNN
F 3 "" H 7300 4100 50  0001 C CNN
	1    7300 4100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FA36021
P 7300 4800
AR Path="/5F91B719/5FA36021" Ref="#PWR?"  Part="1" 
AR Path="/5FA315BA/5FA36021" Ref="#PWR035"  Part="1" 
F 0 "#PWR035" H 7300 4550 50  0001 C CNN
F 1 "GND" H 7305 4627 50  0000 C CNN
F 2 "" H 7300 4800 50  0001 C CNN
F 3 "" H 7300 4800 50  0001 C CNN
	1    7300 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 4100 7300 4300
Wire Wire Line
	7300 4600 7300 4800
Text Label 7750 4450 0    50   ~ 0
adc_ch7
Wire Wire Line
	7450 4450 7750 4450
$EndSCHEMATC
