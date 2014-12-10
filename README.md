ECE382-Lab8 Robot Maze
======================

Item	|Grade	|Points	|Out of	|Date	|Due
---|---|---|---|---|---
Prelab	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus	|	|10	|	|BOC L38
Required Functionality	|On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|40	|	|COB L40
B Functionality	|On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
A Functionality	|On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Bonus Functionality	|On-Time -------------------------------------------------------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Use of Git / Github	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Code Style	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
README	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Total	|	|	|100	|


##Purpose


##Prelab
Include whatever information from this lab you think will be useful in creating your program.

Test your sensors with a DMM. Ensure they are functional. What would good reference values be?

Center Sensor:
- Reference Voltage for obstacle at zero inches: 3.27V
- Reference Voltage for obstacle at ten inches (turn time): 0.91V
- Reference Voltage for obstacle at one foot: 0.89V

Left Sensor:
- Reference Voltage for obstacle at zero inches: 3.00V
- Reference Voltage for obstacle at six inches (Centered in corridor): 0.560V

Right Sensor:
- Reference Voltage for obstacle at zero inches: 2.791V
- Reference Voltage for obstacle at six inches (Centered in corridor): 0.670V

Vref+	|Vref	|Voltage	|Quantized
3.3v	|0v	|0.0v	| 	0000000000b
3.3v	|0v	|1.35v	| 	0110011111b
3.3v	|0v	|1.65v	| 	1000000000b
3.3v	|0v	|1.95v	| 	1001010111b
3.3v	|0v	|3.3v	| 	1111111111b

Vref/Vref+ * 1024

Consider how you'll setup the ADC10 subsystem. What are the registers you'll need to use? Which bits in those registers are important? What's the initialization sequence you'll need?

Registers Used:
	ADC10CTL0, ADC10CTL1, ADC10CTL2 
	ADC10AE0, ADC10AE1, ADC10AE2

Consider the hardware interface. Which ADC10 channels will you use? Which pins correspond to those channels?
	P1.0 = Analog Input A0, but used for LED1
	P1.1 = Analog Input A1 (Left)
	P1.2 = Analog Input A2 (Center)
	P1.3 = ADC10CLK
	P1.4 = Analog Input A4 (Right)


Consider the interface you'll create to your sensors. Will you block or use interrupts? Will you convert one sensor at a time or multiple?
	I'll use polling to check the values of my sensor and use a running average of the last three polls to try and get an accurate value from my IR sensors.

	
###PseudoCode
	//Required Functionality
	
		
		Move Forward Continuous
		
		while(true){
		checkSideSensors()
		if front sensor is within 10 inches
			turn left 90 degrees
			Move Forward Continuous
			while(true){
				checkSideSensors()
			}
		}

	}
	
	checkSideSensors(){
		else if right sensor is within 4 inches
			turn 10 degrees to the left
			Turn on LED2
		else if left sensor is within 4 inches
			turn 10 degrees to the right
			Turn on LED1
		else
			Turn off LED1 and LED2
	}
	
##Troubleshooting
	I didn't have any issues getting my right sensor to work, but I did encounter some problems getting the front and left sensors to work. With no connection to the MSP430, both sensors operated correctly giving valid analog values between 0 and 3.3 volts. However, when I connected the sensors to the MSP430 on ports 1.1 and 1.0, the voltage between the sensors and the MSP430 was +3.55 volts. Even with no connection to the IR sensor, pin 1.1 was high, so I hypothesized that the issue was with configuring the MSP430.
	
	
##Documentation Statement
Nothing to report.