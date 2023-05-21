/*
 * KPD_prg.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_int.h"
#include"KPD_int.h"
#include<util/delay.h>

void HKPD_vInit(void){


	MDIO_vSetPortDir(KPD_PORT,0x0f);
	/* PULL UP  Resistors Activation    Deactivation for the coulumns */
	MDIO_vSetPortVal(KPD_PORT,0xff);


}

u8 HKPD_u8GetPressedKey(void){
	u8 L_Pressedkey=0;

	for(u8 col=0;col<4;col++){
		/*Activate The Column*/

		MDIO_vSetPinVal(KPD_PORT,col,DIO_LOW);

		for(u8 row=0;row<4;row++){

			if(MDIO_u8GetPinVAl(KPD_PORT,row+4)==0){

				L_Pressedkey= row + (col*4)+1;

			}
			while(MDIO_u8GetPinVAl(KPD_PORT,row+4)==0){

			}
			_delay_ms(10);
		}
		/*Deactivate The Column*/
		MDIO_vSetPinVal(KPD_PORT,col,DIO_HIGH);
	}

	return L_Pressedkey;

}

