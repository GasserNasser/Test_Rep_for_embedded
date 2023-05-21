/*
 * main.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include"../LIB/STD_TYPES.h"
#include"../MCAL/DIO/DIO_int.h"

#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/GIE/GIE_int.h"

#include <avr/io.h>
#include <avr/interrupt.h>


ISR(INT0_vect){

	DIO_vTogPinVal(DIO_PORTB,DIO_PIN0);//TOG LED

}
int main(void){
	DIO_vSetPinDir(DIO_PORTD,DIO_PIN2,DIO_INPUT);//SET INT0 PIN as INPUT
	DIO_vSetPinVal(DIO_PORTD,DIO_PIN2,DIO_HIGH);//Enable PILLUP Resistor on INT0 pin as we connect a switch to it
	DIO_vSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);//SET LED PIN as OUTPUT
	MGIE_vEnableGlobalInterrupt();
	MEXTI_vInit();


	while(1){

	}
}

