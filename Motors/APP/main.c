/*
 * main.c
 *
 *  Created on: Feb 5, 2023
 *      Author: Ahmed Ebd ELNasser
 */


#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/DCM/DCM_int.h"
#include <util/delay.h>
int main(void){

	DCM_t motor1=HDCM_xInit(DCM1_PORT,DCM1_PIN1,DCM1_PIN2);
	HDCM_vRotateCW(&motor1);
	_delay_ms(2000);
	HDCM_vRotateCCW(&motor1);






//	//DIO_vSetPinDir(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
//	DIO_vSetPortDir(DIO_PORTB,0x0f);
//	u8 steps[]={1,2,4,8};
//	for(u8 x=0;x<16;x++){
//		for (u8 j=0;j<16;j++){
//				for(u8 i=0;i<4;i++){
//					DIO_vSetPortVal(DIO_PORTB,steps[i]);
//					_delay_ms(2);
//				}
//			}
//
//	}
//
//	while(1){
//
//
//
//		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN1,DIO_HIGH);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN2,DIO_HIGH);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN3,DIO_LOW);
		//		_delay_ms(3000);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN1,DIO_LOW);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN2,DIO_HIGH);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN3,DIO_LOW);
		//		_delay_ms(2000);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN1,DIO_LOW);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN2,DIO_LOW);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN3,DIO_HIGH);
		//		_delay_ms(2000);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN1,DIO_LOW);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN2,DIO_HIGH);
		//		DIO_vSetPinVal(DIO_PORTA,DIO_PIN3,DIO_LOW);
		//		_delay_ms(2000);

	}


