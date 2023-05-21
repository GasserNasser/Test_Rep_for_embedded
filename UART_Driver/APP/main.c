/*
 * main.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include"../LIB/STD_TYPES.h"
#include"../MCAL/DIO/DIO_int.h"

#include "../MCAL/UART/UART_int.h"

int main (void){

	MUART_vInit();
	MUART_vTransmit('G');
	while(1){


	}
}



