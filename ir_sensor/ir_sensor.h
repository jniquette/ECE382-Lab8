/**
 * 	File: 		ir_sensor.h
 * 	Author:		C2C Justin Niquette
 * 	Date:		8 Dec 14
 * 	Purpose:	This package contains the constants and declarations needed to use the ECE382
 * 				IR Sensor Boards with an MSP430 having an Analog to Digital (ADC) Converter.
 * 				It is calibrated to robot #47.
 */
#include "msp430g2553.h"

#ifndef IR_SENSOR_H_
#define IR_SENSOR_H_

typedef enum { false, true } bool;			//Create Boolean Typedef




unsigned int getRunningAverage(unsigned short values[]);
bool isRightActive(unsigned int threshold);
bool isLeftActive(unsigned int threshold);
bool isFrontActive(unsigned int threshold);

unsigned short getFrontValue();
unsigned short getLeftValue();
unsigned short getRightValue();

////////////////////////////////////////////////////////////////////////////////
//				CONSTANTS FOR SELF-COMMENTING CODE
////////////////////////////////////////////////////////////////////////////////
#define LEFT_LED_ON			P1OUT |= BIT0
#define LEFT_LED_OFF		P1OUT &= ~BIT0
#define RIGHT_LED_ON		P1OUT |= BIT6
#define RIGHT_LED_OFF		P1OUT &= ~BIT6

#define CHANGE_THRESHOLD	25


#endif /* IR_SENSOR_H_ */
