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
#include "../MCAL/WDT/WDT_int.h"
#include <avr/delay.h>


int main (void){

	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
	MWDT_vTurnON(WDT_1s);
	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
	_delay_ms(500);
	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_LOW);

	MWDT_vTurnOff();
	while(1){

	}
}
