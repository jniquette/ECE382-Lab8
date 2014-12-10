/*
 * movements.h
 *
 *  Created on: Dec 8, 2014
 *      Author: C16Justin.Niquette
 */

#ifndef MOVEMENTS_H_
#define MOVEMENTS_H_

//----Method Declarations---
void initMotors();
void stop();
void stepForward();
void stepBackward();
void stepRight();
void stepLeft();
void goForward();
void goBackward();
void turnRight();
void turnLeft();
void rightForward();
void rightBackward();
void leftForward();
void leftBackward();
void reqFunctionality();
void pivotForwardLeft();
void pivotForwardRight();
void pivotBackwardLeft();
void pivotBackwardRight();




//-----------------------------------------------------------------
// Define Macros Here for Self Commenting Code
// This setup uses software to reverse the direction of the 2nd motor
//-----------------------------------------------------------------
#define		RIGHT_DIRECTION		BIT1;
#define		RIGHT_ENABLE		BIT0;
#define		RIGHT_PWM			BIT2;

#define		LEFT_DIRECTION		BIT5;
#define		LEFT_ENABLE			BIT3;
#define		LEFT_PWM			BIT4;

#define		ENABLE_RIGHT		P2OUT |= RIGHT_ENABLE;
#define		DISABLE_RIGHT		P2OUT &= ~RIGHT_ENABLE;
#define		RIGHT_FORWARD		P2OUT &= ~RIGHT_DIRECTION;
#define		RIGHT_BACKWARD		P2OUT |= RIGHT_DIRECTION;

#define		ENABLE_LEFT			P2OUT |= LEFT_ENABLE;
#define		DISABLE_LEFT		P2OUT &= ~LEFT_ENABLE;
#define		LEFT_FORWARD		P2OUT |= LEFT_DIRECTION;
#define		LEFT_BACKWARD		P2OUT &= ~LEFT_DIRECTION;

#define		S2_BUTTON			P1IN & BIT3



#endif /* MOVEMENTS_H_ */
