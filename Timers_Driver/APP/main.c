/*
 * main.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include"../LIB/STD_TYPES.h"
#include"../MCAL/DIO/DIO_int.h"

#include "../MCAL/TIMERS/TIMERS_int.h"
#include"../MCAL/GIE/GIE_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <avr/delay.h>

#include "../MCAL/TIMERS/TIMERS_prv.h"
//void toggle (void){
//	MDIO_vTogPinVal(DIO_PORTB,DIO_PIN0);
//}

volatile u8 Reading_flag = 0;
volatile u16 PT;
volatile u16 ONT;

void ReadPwm(void){
	static u8 counter=0;
	static u16 TimeReadings[3];

	counter++;
	HLCD_vPrintNumber(5);
	switch(counter){

	case 1:
		TimeReadings[counter-1]=MTIMERS_u16GetCapturedValue();
		MTIMERS_vSetIcuTrigger(ICU_Rising);
		break;
	case 2:
		TimeReadings[counter-1]=MTIMERS_u16GetCapturedValue();
		MTIMERS_vSetIcuTrigger(ICU_Falling);
		PT=TimeReadings[1]-TimeReadings[0];
		break;
	case 3:
		TimeReadings[counter-1]=MTIMERS_u16GetCapturedValue();
		MTIMERS_vSetIcuTrigger(ICU_Rising);
		MTIMERS_vDisableINterrupt(0);
		ONT=TimeReadings[2]-TimeReadings[1];
		counter=0;

		Reading_flag = 1;
		break;
	}


}

int main (void){
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	MTIMERS_vSetCallback(ReadPwm);
	MTIMERS_vSetCompareValue(TIMER0,127);
	MTIMERS_vInit();
	HLCD_vInit();
	MTIMERS_vStartTimer();
	MGIE_vEnableGlobalInterrupt();

	while(1){
		if(Reading_flag==1){
			Reading_flag=0;
			HLCD_vSendCommand(LCD_CLEAR);
			HLCD_vSetCursorPosition(0,0);
			HLCD_vPrintNumber(ONT);
			HLCD_vSetCursorPosition(1,0);
			HLCD_vPrintNumber(PT);
			MTIMERS_vEnableInterrupt(0);
		}
	}
}
//int main(void){
//
//	//MDIO_vSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
//	//MDIO_vSetPinDir(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
//	//MGIE_vEnableGlobalInterrupt();
//	MTIMERS_vInit();
//	MDIO_vSetPinDir(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
//	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
//	//MTIMERS_vSetInterval_OverFlow_Asynch(10000,toggle);
//	//MTIMERS_vSetInterval_CTC_Asynch(2000,250,toggle);
//	//MTIMERS_vSetCompareValue(TIMER0,);
////	MTIMERS_vStartTimer();
//	//u16 A_u16Angle=180;
//
//	//MTIMERS_vSetCompareValue(TIMER_1A, ((125*A_u16Angle)/180)+125);
//	//MTIMERS_vSetCompareValue(TIMER_1A,500);
//	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
//	while(1){
//
//
//		for(u16 x=500;x<2500;x++){
//			MTIMERS_vSetCompareValue(TIMER_1A,x);
//			_delay_ms(12);
//
//		}
//
////		for (u8 i=0; i<254;i++){
////
////			MTIMERS_vSetCompareValue(TIMER0,i);
////			_delay_ms(10);
////
////		}
////
////		for (u8 i=0; i<254;i++){
////
////			MTIMERS_vSetCompareValue(TIMER0,255-i);
////			_delay_ms(10);
////
////		}
//
//	}
//
//}







