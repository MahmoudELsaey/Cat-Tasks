/*
 * LCD_priv.h
 *
 *  Created on: Nov 29, 2023
 *      Author: mahmo
 */
#define EIGHT_BIT 8
#define FOUR_BIT 4

static inline void LCD_invidSendCommand(u8 Copy_u8Command);
static void LCD_vidLatch(u8 copy_u8Data);
