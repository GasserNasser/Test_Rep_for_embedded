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
#include "../MCAL/SPI/SPI_int.h"

#include<avr/interrupt.h>
#include<util/delay.h>

int main (void){
	_delay_ms(2000);
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_LOW);
	MSPI_vInit();

	u8 c;
	c=MSPI_u8Transceive('G');
	if(c=='G'){
		MDIO_vSetPinVal(DIO_PORTB,DIO_PIN0,DIO_HIGH);
	}
	while(1){

	}
}






