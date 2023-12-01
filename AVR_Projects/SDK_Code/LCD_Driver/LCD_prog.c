/*
 * LCD_prog.c
 *
 *  Created on: Nov 29, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "errorStates.h"
#include "util/delay.h"

#include "DIO_Int.h"

#include "LCD_config.h"
#include "LCD_priv.h"

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	_delay_ms(35);
	//Control Pins
	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);
	//Data 7:4
	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);

#if LCD_MODE == EIGHt_BIT
	//Data 3:0
	DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);

	//function set
	LCD_invidSendCommand(0x38);
#elif LCD_MODE == FOUR_BIT
	LCD_invidSendCommand(0x28);
#endif
	_delay_ms(1);
	LCD_invidSendCommand(0x0f); //display
	_delay_ms(1);
	LCD_invidSendCommand(0x01); //Clear
	_delay_ms(2);
	LCD_invidSendCommand(0x06); //Entry Mode

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	// Set Register As Data
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);
	//Setting Data
	LCD_vidLatch(Copy_u8Data);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;

}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;
	// Set Register As Command
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);
	//Setting Data
	LCD_vidLatch(Copy_u8Command);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;

}

// setting the repeated part in a separate function
static void LCD_vidLatch(u8 copy_u8Data)
{
	// Set RW As Write
		DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);

		//Set Enable to low
		DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

		//Write Data
		DIO_enuSetPinValue(D7_PORT, D7_PIN, ((copy_u8Data>>7)&1));
		DIO_enuSetPinValue(D6_PORT, D6_PIN, ((copy_u8Data>>6)&1));
		DIO_enuSetPinValue(D5_PORT, D5_PIN, ((copy_u8Data>>6)&1));
		DIO_enuSetPinValue(D4_PORT, D4_PIN, ((copy_u8Data>>5)&1));
#if LCD_MODE == EIGHT_BIT
		DIO_enuSetPinValue(D3_PORT, D3_PIN, ((copy_u8Data>>4)&1));
		DIO_enuSetPinValue(D2_PORT, D2_PIN, ((copy_u8Data>>3)&1));
		DIO_enuSetPinValue(D1_PORT, D1_PIN, ((copy_u8Data>>2)&1));
		DIO_enuSetPinValue(D0_PORT, D0_PIN, ((copy_u8Data>>1)&1));
#elif LCD_MODE == FOUR_BIT
#endif
		//Set Enable to High
		DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
		_delay_ms(10);
		//Set Enable to low
		DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
}

static inline void LCD_invidSendCommand(u8 Copy_u8Command)
{
	// Set Register As Command
	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);

	// Set RW As Write
	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);

	//Set Enable to low
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

	//Write Data
	DIO_enuSetPinValue(D7_PORT, D7_PIN, ((Copy_u8Command>>7)&1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN, ((Copy_u8Command>>6)&1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN, ((Copy_u8Command>>6)&1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN, ((Copy_u8Command>>5)&1));
	DIO_enuSetPinValue(D3_PORT, D3_PIN, ((Copy_u8Command>>4)&1));
	DIO_enuSetPinValue(D2_PORT, D2_PIN, ((Copy_u8Command>>3)&1));
	DIO_enuSetPinValue(D1_PORT, D1_PIN, ((Copy_u8Command>>2)&1));
	DIO_enuSetPinValue(D0_PORT, D0_PIN, ((Copy_u8Command>>1)&1));

	//Set Enable to High
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10);
	//Set Enable to low
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
}
