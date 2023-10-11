/*
 * main.c
 *
 *  Created on: Oct 11, 2023
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
	//SWITCH INPUT
	DDRA=0b00;
	//SWITCH PULL_UP
	PORTA=0b11;

	//SEGMENT OUTPUT
	DDRB = 0xff;
	//SEGMENT LOW INTIAL STATE
	PORTB = 0x00;

	while(1)
	{
		if (PINA==2)
		{
			switch(PINB)
			{
			case 0x00:
				PORTB=0x3f;
				_delay_ms(500);
				break;
			case 0x3f:
				PORTB=0x06;
				_delay_ms(500);
				break;
			case 0x06:
				PORTB=0x5b;
				_delay_ms(500);
				break;
			case 0x5b:
				PORTB=0x4f;
				_delay_ms(500);
				break;
			case 0x4f:
				PORTB=0x66;
				_delay_ms(500);
				break;
			case 0x66:
				PORTB=0x6d;
				_delay_ms(500);
				break;
			case 0x6d:
				PORTB=0x7d;
				_delay_ms(500);
				break;
			case 0x7d:
				PORTB=0x07;
				_delay_ms(500);
				break;
			case 0x07:
				PORTB=0x7f;
				_delay_ms(500);
				break;
			case 0x7f:
				PORTB=0x6f;
				_delay_ms(500);
				break;
			default:
				break;
			}
		}
		else if (PINA==1)
		{
			switch(PINB)
			{
			case 0x6f:
				PORTB=0x7f;
				_delay_ms(500);
				break;
			case 0x7f:
				PORTB=0x07;
				_delay_ms(500);
				break;
			case 0x07:
				PORTB=0x7d;
				_delay_ms(500);
				break;
			case 0x7d:
				PORTB=0x6d;
				_delay_ms(500);
				break;
			case 0x6d:
				PORTB=0x66;
				_delay_ms(500);
				break;
			case 0x66:
				PORTB=0x4f;
				_delay_ms(500);
				break;
			case 0x4f:
				PORTB=0x5b;
				_delay_ms(500);
				break;
			case 0x5b:
				PORTB=0x06;
				_delay_ms(500);
				break;
			case 0x06:
				PORTB=0x3f;
				_delay_ms(500);
				break;
			default:
				break;
			}


		}
	}
}

