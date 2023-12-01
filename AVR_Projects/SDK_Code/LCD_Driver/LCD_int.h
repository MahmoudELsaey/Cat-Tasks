/*
 * LCD_int.h
 *
 *  Created on: Nov 29, 2023
 *      Author: mahmo
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

#endif /* LCD_INT_H_ */
