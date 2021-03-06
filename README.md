ECE382-Lab8 Robot Maze
======================

Item	|Grade	|Points	|Out of	|Date	|Due
---|---|---|---|---|---
Prelab	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus	|	|10	|	|BOC L38
Required Functionality	|On-Time ----- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|40	|	|COB L40
B Functionality	|On-Time ----- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
A Functionality	|On-Time ----- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Bonus Functionality	|On-Time ----- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Use of Git / Github	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Code Style	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
README	|On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days	|	|10	|	|COB L40
Total	|	|	|100	|


##Purpose
The purpose of the lab is to demonstrate proficiency in using hardware and software design to navigate a robot through a simple maze using IR sensors. The lab requires a good working knowledge of the MSP430, Motor Controller, Pulse Width Modulation (PWM), and Analog to Digital Converters (ADC).


##Prelab
The major task of Lab 8 is to implement the functionality of Lab 7 to actually navigate the robot through the maze. I will attempt to achieve Required Functionality, B Functionality, A Functionality, and the Bonus Functionality. However, I will program incrementally and go for one functionality at a time. 

###Plan of Attack
During Lab 7 I noticed that the IR sensors are not very useful at detecting walls at a distance of more than ~8 inches. Therefore, my plan of attack is to use the starboard and port sensors to detect when the robot moves around a corner as opposed to when it approaches a wall. I should be able to achieve this for the first two turns, but then I will have to use the front sensor for the third and fourth turns. I hope that by doing this I can safely utilize a higher average PWM signal and move the robot through the maze faster. 

###Maze Diagram
![alt text](https://github.com/jniquette/ECE382-Lab8/blob/master/images/map.png "Maze Diagram")
	
###PseudoCode
	//////////////////////////////////
	//Required Functionality
	reqFunctionality(){
		Move Forward Continuous
		
		lookForLeftCorner()
		pivot left 90 degrees
		Move Forward Continuous
	}
	
	//////////////////////////////////
	//B Functionality
	bFunctionality(){
		reqFunctionality()
		lookForRightCorner()
		pivot right 90 degrees
		Move Forward Continuously
	}
	
	
	//////////////////////////////////
	//A Functionality
	aFunctionality(){
		bFunctionality()
		
		lookForForwardWall()
		turn right 90 degrees
		Move Forward Continuously
		
		lookForForwardWall()
		turn left 90 degrees
		Move Forward Continuously
	}
	
	//////////////////////////////////
	//Bonus Functionality
	Waiting on rule clarification as to how the robot will be placed back into the maze after it exits door 3.

	
	//Use this method to stay on a "straight" path
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
	
	lookForLeftCorner(){
		while(true){
			checkSideSensors()
			if left sensor is at the ambient IR level{
				break()
			}
	}
	
	lookForRightCorner(){
		while(true){
			checkSideSensors()
			if right sensor is at the ambient IR level{
				break()
			}
	}	
	
	lookForForwardWall(){
		while(true){
			checkSideSensors()
			if forward wall is within 6 inches{
				break()
			}
	}
	
##Troubleshooting
The biggest issue I had is that the IR sensor readings were incredibly inconsistent. While debugging the robot while attached to the computer the sensors read values up to .65 volts (out of 3.3 volts) different from when the robot was not connected to the computer. After long hours of debugging, I achieved required functionality. 

##Video
[A Functionality Using Sensors](https://www.youtube.com/watch?v=WgxF5JTip8I&list=UUAXhf3d2OrbDpP-IZgnnAvQ)

[B Functionality Using Dead Reckoning](https://www.youtube.com/watch?v=TC9hxc7y6YM&list=UUAXhf3d2OrbDpP-IZgnnAvQ)
	
	
##Documentation Statement
Nothing to report.