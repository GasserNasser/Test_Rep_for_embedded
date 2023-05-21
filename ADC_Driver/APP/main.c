/*
 * main.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include"../LIB/STD_TYPES.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/ADC/ADC_int.h"
#include"../HAL/LCD/LCD_int.h"
#include"../MCAL/GIE/GIE_int.h"

#include<avr/interrupt.h>
#include<util/delay.h>

void ADC_BATTERY(void);

volatile u16 led_value=0;

volatile u16 adc_value=0;




void ADC_BATTERY(void){
	 MADC_vStartConversion(7);
	 led_value=MADC_u16GetADCData();



	if(led_value>0 && led_value<=128){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);
	}
	else if(led_value>128 && led_value<=256){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);

	}
	else if(led_value>256 && led_value<=384){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);

	}
	else if(led_value>384 && led_value<=512){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);

	}
	else if(led_value>512 && led_value<=640){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);

	}
	else if(led_value>640 && led_value<=786){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);
	}
	else if(led_value>786 && led_value<=896){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);
	}
	else if(led_value>896 && led_value<=1024){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN1,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN2,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN3,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN7,DIO_HIGH);
	}


}

int main(void){
	MGIE_vEnableGlobalInterrupt();

	MADC_vSetCallback(ADC_BATTERY);

	MADC_vInit();

	HLCD_vInit();

	MDIO_vSetPortDir(DIO_PORTB,0xFF);

	//MADC_vStartConversion(3);

	HLCD_vSendCommand(LCD_CLEAR);




	while(1){
		ADC_BATTERY();
		HLCD_vPrintNumber(led_value);
		_delay_ms(10);
		HLCD_vSendCommand(LCD_CLEAR);
	}
}







