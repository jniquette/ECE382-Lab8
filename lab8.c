//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"
#include "lab8.h"
#include "ir_sensor/ir_sensor.h"
#include "movements.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {




	P1DIR |= BIT0;	// Set the red (left) LED as output
	P1DIR |= BIT6;	// Set the green (right) LED as output

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	initMotors();

	stop();

	bFunctionality();



} //End Main

//////////////////////////////////
//Required Functionality
void reqFunctionality(){
	_delay_cycles(4000000);
	stepForward();
	lookForLeftCorner();
	pivotForwardLeft();
	stepForward();
}


////////////////////////////////////
////B Functionality
void bFunctionality(){
	_delay_cycles(4000000);
	stepForward();
	lookForLeftCorner();
	_delay_cycles(1000000);
	pivotForwardLeft();

	stepForward();
	lookForRightCorner();
	pivotForwardRight();
	goForward();
	_delay_cycles(1000000);
	stop();
}


////////////////////////////////////
////A Functionality
//aFunctionality(){
//	bFunctionality()
//
//	lookForForwardWall()
//	turn right 90 degrees
//	Move Forward Continuously
//
//	lookForForwardWall()
//	turn left 90 degrees
//	Move Forward Continuously
//}
//
////////////////////////////////////
////Bonus Functionality
//Waiting on rule clarification as to how the robot will be placed back into the maze after it exits door 3.
//
//
////Use this method to stay on a "straight" path
//checkSideSensors(){
//	else if right sensor is within 4 inches
//		turn 10 degrees to the left
//		Turn on LED2
//	else if left sensor is within 4 inches
//		turn 10 degrees to the right
//		Turn on LED1
//	else
//		Turn off LED1 and LED2
//}

void lookForLeftCorner(){
	while(true){
		//checkSideSensors();
		if(isLeftActive(325) == false)
			break;
		stepForward();
	}
}

void lookForRightCorner(){
	while(true){
		//checkSideSensors();
		if(isRightActive(290) == false)
			break;
		stepForward();
	}
}

//lookForForwardWall(){
//	while(true){
//		checkSideSensors()
//		if forward wall is within 6 inches{
//			break()
//		}
//}


void calibrateSensors(){
	stop();
	lightSequence(10);

	unsigned short forwardWallDistance;

	while(true){
		forwardWallDistance = getLeftValue();
		lightSequence(2);

		if(forwardWallDistance != 0){
			LEFT_LED_OFF;
		}
	}

}



void lightSequence(unsigned char counts){
	unsigned char i = 0;
	for(i=0; i<counts; i++){
		LEFT_LED_ON;
		RIGHT_LED_OFF;
		_delay_cycles(600000);
		LEFT_LED_OFF;
		RIGHT_LED_ON;
		_delay_cycles(600000);
	}
	RIGHT_LED_OFF;
}

