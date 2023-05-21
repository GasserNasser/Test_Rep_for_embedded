/*
 * SPI_prg.c
 *
 *  Created on: Mar 15, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"

#include "SPI_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"


void MSPI_vInit(void){

#if SPI_MODE==SPI_MASTER
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);//	MOSI ->OUTPUT
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN6,DIO_INPUT);// MISO -> INPUT
	MDIO_vSetPinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);
	MDIO_vSetPinDir(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);// SCL -> OUTPUT
#endif

	u8 L_u8Spcr_Setting= 0b01011110;

	//Write your code configurations here

	SPCR = L_u8Spcr_Setting;

}
u8 MSPI_u8Transceive(u8 A_u8Data){
	/* Start transmission */
	SPDR = A_u8Data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
	return SPDR;
}
