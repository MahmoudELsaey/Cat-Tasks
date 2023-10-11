/*
 * main.c
 *
 *  Created on: Oct 10, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "util/delay.h"

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

#define DDRB *((u8*)0x37)
#define PINB *((u8*)0x36)
#define PORTB *((u8*)0x38)

int main(void)
{
	//switch input
	DDRB = 0;
	// Pull-Up Resistor
	PORTB= 0b111;

	//LED Output
	DDRA = 0b11;
	//LED LOW INTIAL STATE
	PORTA =0;

	while(1)
	{
		if(PINB==6)
			PORTA = 1;
		else if(PINB==5)
			PORTA = 2;
		else if(PINB==3)
			PORTA = 3;
		else
			PORTA = 0;
	}



	return 0;
}

