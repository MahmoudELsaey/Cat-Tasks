/*
 * main.c
 *
 *  Created on: Dec 6, 2023
 *      Author: mahmo
 */
#include "stdTypes.h"
#include "errorStates.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "KPD_int.h"

#include "Calc_priv.h"
#include "Calc_config.h"
#include "Calc_int.h"

int main()
{
	//Intialization
	DIO_enuInit();
	LCD_enuInit();
	KPD_enuInit();

	u8 Local_u8ArrForDigits[16];
	u8 Local_u8ArrForDigitsIDX=0;
	u8 feedback[16];
	while (1)
	{
        //Appending Previous Result into my array of digits
		for (u8 Local_u8Iter_FeedbackArr = 0; feedback[Local_u8Iter_FeedbackArr] != '\0' && Local_u8Iter_FeedbackArr < 16; Local_u8Iter_FeedbackArr++)
		{
		    Local_u8ArrForDigits[Local_u8ArrForDigitsIDX++]= feedback[Local_u8Iter_FeedbackArr];
		}

		// Null-terminate Local_u8ArrForDigits
		Local_u8ArrForDigits[Local_u8ArrForDigitsIDX] = '\0';

		u8 Local_u8KeyValue = KPD_u8GetPressedKey();

		if(Local_u8KeyValue!=0xff)
		{
			if(Local_u8KeyValue>=0 && Local_u8KeyValue<=9)
			{
				Local_u8ArrForDigits[Local_u8ArrForDigitsIDX++]=Local_u8KeyValue+'0';
				LCD_enuDisplayChar(Local_u8KeyValue+'0');
			}
			else if(Local_u8KeyValue==SumKey)
			{
				Local_u8ArrForDigits[Local_u8ArrForDigitsIDX++]= '+';
				LCD_enuDisplayChar('+');
			}
			else if(Local_u8KeyValue==SubKey)
			{
				Local_u8ArrForDigits[Local_u8ArrForDigitsIDX++]= '-';
				LCD_enuDisplayChar('-');
			}
			else if(Local_u8KeyValue==MultKey)
			{
				Local_u8ArrForDigits[Local_u8ArrForDigitsIDX++]= '*';
				LCD_enuDisplayChar('*');
			}
			else if(Local_u8KeyValue==DivKey)
			{
				Local_u8ArrForDigits[Local_u8ArrForDigitsIDX++]= '/';
				LCD_enuDisplayChar('/');
			}
			else if(Local_u8KeyValue==ClearKey)
			{
				LCD_enuSendCommand(0x01);
				Local_u8ArrForDigitsIDX=0;
				Local_u8ArrForDigits[0]= '\0';
			}
			else if (Local_u8KeyValue== EqualKey)
			{
				//Search on the operator / atoi arr before it to eperand1 / atoi arr after it to eperand2 / switch on operator.
				Local_u8ArrForDigits[Local_u8ArrForDigitsIDX++]= '\0';
				Local_u8ArrForDigitsIDX=0;
				LCD_enuSendCommand(0x01);
				LCD_enuDisplayChar('=');
				s32 Local_u8Operand1;
				s32 Local_u8Operand2;
				u8 Local_u8Operator;

				s32 extractionResult = ExtractOperands(Local_u8ArrForDigits, &Local_u8Operand1, &Local_u8Operand2, &Local_u8Operator);
				Local_u8ArrForDigits[0]= '\0';

				                if (extractionResult == OK)
				                {

				                    s32 result = 0;

				                    switch (Local_u8Operator)
				                    {
				                        case '+':
				                            result = Local_u8Operand1 + Local_u8Operand2;
				                            break;
				                        case '-':
				                            result = Local_u8Operand1 - Local_u8Operand2;
				                            break;
				                        case '*':
				                            result = Local_u8Operand1 * Local_u8Operand2;
				                            break;
				                        case '/':
				                            if (Local_u8Operand2 != 0)
				                            {
				                            	result = Local_u8Operand1 / Local_u8Operand2;
				                            }
				                            else
				                            {
				                            	LCD_enuDisplayChar('E');
				                            }
				                            break;
				                    }


				                    // Display the result on the LCD
				                     char resultStr[16];
				                     sprintf(resultStr, "%d", result);
				                     // Determine the length of the result string
				                     u8 resultLength = strlen(resultStr);
				                         resultStr[resultLength] = '\0';

				                     strcpy(feedback, resultStr);
				                     if(Local_u8Operand2 != 0)
				                     {
					                     for(u8 Local_u8Iter_resStrArr=0; resultStr[Local_u8Iter_resStrArr]!='\0'; Local_u8Iter_resStrArr++)
					                     {
					                    	 LCD_enuDisplayChar(resultStr[Local_u8Iter_resStrArr]);
					                     }
				                     }


				                }
			}
		}
	}
	return OK;
}
