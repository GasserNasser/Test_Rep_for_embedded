/*
 * LCD_prg.c
 *
 *  Created on: Jan 7, 2023
 *      Author: Ahmed Ebd ELNasser
 */


#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"util/delay.h"
#include"LCD_int.h"

void LCD_vSendCommand(u8 A_u8Command){
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);//RS
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);//RW
	DIO_vSetPortVal(LCD_DATA_PORT,A_u8Command);//SEND COMMAND

	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);//EN
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);//EN
	_delay_ms(1);


}
void LCD_vSendChar(u8 A_u8Char){
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);//RS
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);//RW
	DIO_vSetPortVal(LCD_DATA_PORT,A_u8Char);//SEND COMMAND

	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);//EN
	_delay_ms(1);
	DIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);//EN
	_delay_ms(1);


}
void LCD_vInit(void){
	DIO_vSetPortDir(LCD_DATA_PORT,0xff);                //SET LCD_DATA_PORT AS OUTPUT
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);/* SET RS RW EN AS OUTPUT PINS*/
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_vSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);

	/*Initialization Sequence*/
	_delay_ms(50);
	LCD_vSendCommand(0b00111000);//Function Set Command
	_delay_ms(1);
	LCD_vSendCommand(0b00001100);//DISPLAY ON/OFF CONTROL Command
	_delay_ms(1);
	LCD_vSendCommand(0b00000001);//DISPLAY CLEAR Command
	_delay_ms(3);
	LCD_vSendCommand(0b00000110);//ENTRY MODE SET Command
	_delay_ms(1);

}
void LCD_vPrintString(char A_s8String[]){
	u8 L_u8i=0;
	while(A_s8String[L_u8i]!='\0'){
		LCD_vSendChar(A_s8String[L_u8i]);
		L_u8i++;


	}

}
void LCD_vPrintNumber(s32 A_s32Number){

	s32 s32_CopyNumber=A_s32Number;

	s32 s32_F=0;
	u32 u32_S=1;
	u32 u32_SCopy=1;
	while(s32_CopyNumber>0){
		s32_CopyNumber=s32_CopyNumber/10;
		u32_S*=10;
	}
	u32_S=u32_S/10;
	u32_SCopy=u32_S;
	while(A_s32Number>0){
		if(A_s32Number%10==0){
			s32_F+=u32_S*10;
		}
		else{
			s32_F+=(A_s32Number%10)*u32_S;
		}

		s32_F+=(A_s32Number%10)*u32_S;

		A_s32Number=A_s32Number/10;
		u32_S/=10;

	}
	while(u32_SCopy>0){
		LCD_vSendChar((s32_F % 10) + 48);
		s32_F/=10;
		u32_SCopy/=10;

	}


}
void LCD_vSetCursorPosition(u8 A_u8LinePos,u8 A_u8LineNo){

}
void LCD_vSaveCustomChar(){

}
void LCD_vDisplayCustomChar(){

}
