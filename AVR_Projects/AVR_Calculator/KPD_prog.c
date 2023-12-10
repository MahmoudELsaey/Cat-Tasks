/*
 * prog.c
 *
 *  Created on: Nov 30, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "KPD_config.h"
#include "KPD_int.h"
#include "KPD_priv.h"

ES_t KPD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	//Setting Columns to output
	DIO_enuSetPinDirection(KPD_PORT ,KPD_COLUMN0_PIN , DIO_u8HIGH);
	DIO_enuSetPinDirection(KPD_PORT ,KPD_COLUMN1_PIN , DIO_u8HIGH);
	DIO_enuSetPinDirection(KPD_PORT ,KPD_COLUMN2_PIN , DIO_u8HIGH);
	DIO_enuSetPinDirection(KPD_PORT ,KPD_COLUMN3_PIN , DIO_u8HIGH);

	//Setting Rows to input
	DIO_enuSetPinDirection(KPD_PORT ,KPD_ROW0_PIN , DIO_u8LOW);
	DIO_enuSetPinDirection(KPD_PORT ,KPD_ROW1_PIN , DIO_u8LOW);
	DIO_enuSetPinDirection(KPD_PORT ,KPD_ROW2_PIN , DIO_u8LOW);
	DIO_enuSetPinDirection(KPD_PORT ,KPD_ROW3_PIN , DIO_u8LOW);

	//Setting Columns to high & Rows to Pull_UP
	DIO_enuSetPortValue(KPD_PORT , 0b11111111);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}


u8 KPD_u8GetPressedKey(void)
{
	//pressed button & loops iterators
	u8 Local_u8PressedKey= KPD_NO_PRESSED_KEY, Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState;

	static u8 Local_u8KPDArr[ROW_NUMBER][COLUMN_NUMBER]= KPD_ARR_VALUE;

	static u8 Local_u8KPDColumnArr[COLUMN_NUMBER] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUMBER] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};


	for(Local_u8ColumnIdx=0; Local_u8ColumnIdx < COLUMN_NUMBER; Local_u8ColumnIdx++)
	{
		//Activate Current Column (Set its pin to low)
		DIO_enuSetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIdx], DIO_u8LOW);

		for(Local_u8RowIdx=0; Local_u8RowIdx< ROW_NUMBER; Local_u8RowIdx++)
		{
			//Read current Row
			DIO_enuGetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);
			//Check SW is pressed
			if(Local_u8PinState == DIO_u8LOW)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				//Polling (Busy Waiting): Solving the problem of Still pressing the Button (the difference in performance between SW & USER
				while(Local_u8PinState == DIO_u8LOW)
				{
					DIO_enuGetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		//DeActivate Current Column (HIGH)
		DIO_enuSetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIdx], DIO_u8HIGH);
	}
	return Local_u8PressedKey;
}
