/*
 * main.c
 *
 *  Created on: Oct 4, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "util/delay.h"

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)


int main(void)
{
	DDRA |=1;

	while(1)
	{
		PORTA |=1;
		_delay_ms(1000);
		PORTA &=~1;
		_delay_ms(1000);
	}
	return 0;
}
