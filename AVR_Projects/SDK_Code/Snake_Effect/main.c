/*
 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "util/delay.h"

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

int main(void)
{
	DDRA = 255;
	s8 i = 0;
	while(1)
	{
		for(i=7;i>=0;i--)
		{
			PORTA |= (1<<i);
			_delay_ms(500);
		}
		for(i=7;i>=0;i--)
		{
			PORTA &=~(1<<i);
			_delay_ms(500);
		}
	}
}

