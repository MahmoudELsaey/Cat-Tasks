/*
 * Calc_prog.c
 *
 *  Created on: Dec 7, 2023
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


#include <stdbool.h>

s32 ExtractOperands(u8 *expr, s32 *operand1, s32 *operand2, u8 *operator) {

	// Find the operator index in the expression
    u8 operatorIndex = -1;
    if(expr[0]== '-')
    {
        for (u8 i = 1; i < MAX_DIGIT_COUNT; ++i)
        {
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
            {
                operatorIndex = i;
                *operator = expr[i];
                break;
            }
        }

    }
    else
    {
        for (u8 i = 0; i < MAX_DIGIT_COUNT; ++i)
        {
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
            {
                operatorIndex = i;
                *operator = expr[i];
                break;
            }
        }

    }

    if (operatorIndex == -1)
    {
        // Operator not found
    	LCD_enuSendCommand(0x01);
    	LCD_enuDisplayChar('E');
    	return ERROR;
    }

    // Extract the operands as strings
    char operand1Str[operatorIndex + 1];
    char operand2Str[MAX_DIGIT_COUNT - operatorIndex - 1];
    strncpy(operand1Str, expr, operatorIndex);
    operand1Str[operatorIndex] = '\0';
    strcpy(operand2Str, &expr[operatorIndex + 1]);

    // Convert operands to integers
    *operand1 = atoi(operand1Str);
    *operand2 = atoi(operand2Str);

    return OK;
}


