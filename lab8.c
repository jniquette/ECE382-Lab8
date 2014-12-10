//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"
#include "lab7.h"
#include "ir_sensor/ir_sensor.h"
#include "movements.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {


	initMotors();


	P1DIR |= BIT0;	// Set the red (left) LED as output
	P1DIR |= BIT6;	// Set the green (right) LED as output

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	stop();

//	calibrateSensors();


	doMazeMovements();

	while(1) {



		if(isFrontActive(480) == true){
			LEFT_LED_ON;
			RIGHT_LED_ON;
		}
		else{
			RIGHT_LED_OFF;
			LEFT_LED_OFF;
		}

		//Max value = 1023(dec)
		if(isRightActive(512) == true)
			RIGHT_LED_ON;
		else
			RIGHT_LED_OFF;


		if(isLeftActive(512) == true)
			LEFT_LED_ON;
		else
			LEFT_LED_OFF;


	} // end infinite loop

} // end main

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

void doMazeMovements(){
	goForward();

	while(getLeftValue() >= 235);
	stop();

}

void lightSequence(unsigned char counts){
	unsigned char i = 0;
	for(i=0; i<counts; i++){
		LEFT_LED_ON;
		RIGHT_LED_OFF;
		_delay_cycles(400000);
		LEFT_LED_OFF;
		RIGHT_LED_ON;
		_delay_cycles(400000);
	}
	RIGHT_LED_OFF;
}

