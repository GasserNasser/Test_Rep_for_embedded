/*
 * LCD_int.h
 *
 *  Created on: Jan 7, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_CTRL_PORT DIO_PORTA
#define LCD_DATA_PORT DIO_PORTC
#define LCD_RS_PIN    DIO_PIN0
#define LCD_RW_PIN    DIO_PIN1
#define LCD_EN_PIN    DIO_PIN2

void LCD_vSendCommand(u8 A_u8Command);
void LCD_vSendChar(u8 A_u8Char);
void LCD_vInit(void);
void LCD_vPrintString(char A_s8String[]);
void LCD_vPrintNumber(s32 A_s32Number);
void LCD_vSetCursorPosition(u8 A_u8LinePos,u8 A_u8LineNo);
void LCD_vSaveCustomChar();
void LCD_vDisplayCustomChar();

#endif /* HAL_LCD_LCD_INT_H_ */
