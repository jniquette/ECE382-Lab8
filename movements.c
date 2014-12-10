//-----------------------------------------------------------------
// Name:	C2C Justin Niquette
// File:	movements.c
// Date:	25 Nov 2014
// Purp:	Contains the methods for each maneuver of the MSP430
//			Robot.
//-----------------------------------------------------------------


#include <msp430g2553.h>
#include "lab7.h"
#include "movements.h"

void initMotors(){
	//Enable Motor Outputs
	P2DIR |= BIT0 | BIT1;			//Right Motor Enable and Direction
	P2DIR |= BIT3 | BIT5;			//Left Motor Enable and Direction


	//Setup Timer A1 for motor output PWM
    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1
    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 1000;						// set signal period
    TA1CCR1 = 500;						// Set an appropriate duty cycle
    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode
    TA1CCR2 = 500;						// set an appropriate duty cycle
    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

	_enable_interrupt();
}

void stop(){
	DISABLE_RIGHT;
	DISABLE_LEFT;
}

void stepForward(){
	goForward();
	__delay_cycles(2000000);
	stop();
}

void stepBackward(){
	goBackward();
	__delay_cycles(2000000);
	stop();
}

void stepRight(){
	turnRight();
	__delay_cycles(1600000);
	stop();
}

void stepLeft(){
	turnLeft();
	__delay_cycles(1600000);
	stop();
}

void goForward(){
	rightForward();
	leftForward();
}

void goBackward(){
	rightBackward();
	leftBackward();
}

void turnRight(){
	rightBackward();
	leftForward();
}

void turnLeft(){
	leftBackward();
	rightForward();
}

void rightForward(){
	RIGHT_FORWARD;
	ENABLE_RIGHT;
	TA1CCTL1 = OUTMOD_3;
}

void rightBackward(){
	RIGHT_BACKWARD;
	ENABLE_RIGHT;
	TA1CCTL1 = OUTMOD_7;
}

void leftForward(){
	LEFT_FORWARD;
	ENABLE_LEFT;
	TA1CCTL2 = OUTMOD_7;
}

void leftBackward(){
	LEFT_BACKWARD;
	ENABLE_LEFT;
	TA1CCTL2 = OUTMOD_3;
}

void pivotForwardLeft(){
	rightForward();
	__delay_cycles(2600000);
	stop();
}

void pivotForwardRight(){
	leftForward();
	__delay_cycles(2600000);
	stop();
}

void pivotBackwardLeft(){
	rightBackward();
	__delay_cycles(3800000);
	stop();
}

void pivotBackwardRight(){
	leftBackward();
	__delay_cycles(3800000);
	stop();
}

void reqFunctionality(){
	stepForward();
	__delay_cycles(16000000);
	stepBackward();
	__delay_cycles(16000000);
	stepRight();
	__delay_cycles(16000000);
	stepLeft();
	__delay_cycles(16000000);
	stepForward();
	__delay_cycles(16000000);
	stepBackward();
}
