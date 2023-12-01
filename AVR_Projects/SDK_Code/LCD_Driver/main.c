/*
 * main.c
 *
 *  Created on: Nov 29, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "LCD_int.h"

#include "util/delay.h"


int main (void)
{
	LCD_enuInit();
	LCD_enuDisplayChar('M');
	LCD_enuDisplayChar('a');
	LCD_enuDisplayChar('h');
	LCD_enuDisplayChar('m');
	LCD_enuDisplayChar('o');
	LCD_enuDisplayChar('u');
	LCD_enuDisplayChar('d');

	while (1);
	return 0;
}
