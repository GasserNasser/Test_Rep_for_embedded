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


void HLCD_vSendCommand(u8 A_u8Command){
	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);//RS
	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);//RW
	MDIO_vSetPortVal(LCD_DATA_PORT,A_u8Command);//SEND COMMAND

	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);//EN
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);//EN
	_delay_ms(1);


}
void HLCD_vSendChar(u8 A_u8Char){
	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);//RS
	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);//RW

	MDIO_vSetPortVal(LCD_DATA_PORT,A_u8Char);//SEND CHAR

	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);//EN
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);//EN
	_delay_ms(1);


}
void HLCD_vInit(void){
	MDIO_vSetPortDir(LCD_DATA_PORT,0xff);                //SET LCD_DATA_PORT AS OUTPUT
	MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);/* SET RS RW EN AS OUTPUT PINS*/
	MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);

	/*Initialization Sequence*/
	_delay_ms(50);
	HLCD_vSendCommand(0b00111000);//Function Set Command
	_delay_ms(1);
	HLCD_vSendCommand(0b00001100);//DISPLAY ON/OFF CONTROL Command
	_delay_ms(1);
	HLCD_vSendCommand(0b00000001);//DISPLAY CLEAR Command
	_delay_ms(3);
	HLCD_vSendCommand(0b00000110);//ENTRY MODE SET Command
	_delay_ms(1);

}
void HLCD_vPrintString(char A_s8String[]){
	u8 L_u8i=0;
	while(A_s8String[L_u8i]!='\0'){
		HLCD_vSendChar(A_s8String[L_u8i]);
		L_u8i++;


	}

}
void HLCD_vPrintNumber(u32 A_s32Number){

	int L_u8Digits[10]={0};
	int L_u8Counter=0;
	//TODO: Implement Negative Number Handling
	//TODO: Implement Zero in units corner case

                      /*Save Reversed in Array*/
	while(A_s32Number>0){
		L_u8Digits[L_u8Counter]=A_s32Number%10;
		A_s32Number/=10;
		L_u8Counter++;



	}
           /*Print Array in Reverse*/

	for (s8 L_s8PrintIndex=L_u8Counter-1;L_s8PrintIndex>=0;L_s8PrintIndex--){

		HLCD_vSendChar(L_u8Digits[L_s8PrintIndex]+'0');
	}


	//	s32 s32_Reversed=0;
	//	u8 L_u8Counter=0;
	//	u8 L_u8firstattempt=0;
	//
	//	while(A_s32Number){
	//		if(A_s32Number%10==0 && L_u8firstattempt==0){
	//			L_u8Counter++;
	//		}
	//		L_u8firstattempt=1;
	//		s32_Reversed=s32_Reversed*10 +A_s32Number%10;
	//
	//		A_s32Number=A_s32Number/10;
	//
	//	}
	//
	//
	//	while(s32_Reversed){
	//		LCD_vSendChar((s32_Reversed%10) + 48);
	//		s32_Reversed/=10;
	//
	//	}
	//	if(L_u8Counter>0){
	//		LCD_vSendChar('0');
	//	}


}
void HLCD_vSetCursorPosition(u8 A_u8LinePos,u8 A_u8LineNo){

	switch(A_u8LineNo){
	case LCD_LINE0:
		HLCD_vSendCommand(0x80+A_u8LinePos);
		break;
	case LCD_LINE1:
		HLCD_vSendCommand((0x80+A_u8LinePos+0x40));
	}


}
void HLCD_vSaveCustomChar(u8 A_u8CgramIndex,u8 A_8CustomCharData[]){
	/*SET CGRAM ADDRESS*/
	HLCD_vSendCommand( 0b01000000 +((A_u8CgramIndex) * 8));

	/*Send Custom Char Data*/


	for(u8 L_u8Index=0;L_u8Index<8;L_u8Index++){
		HLCD_vSendChar(A_8CustomCharData[L_u8Index]);

	}
	/*Set DDRAM Address*/
	HLCD_vSendCommand(0x80);

}
void HLCD_vDisplayCustomChar(u8 A_u8CgramIndex){
	if(A_u8CgramIndex<8){
		HLCD_vSendChar(A_u8CgramIndex);
	}



}
