/*
 * main.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include"../LIB/STD_TYPES.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../HAL/SSD/SSD_int.h"
#include"../HAL/LCD/LCD_int.h"
#include<util/delay.h>

int main(void){

	LCD_vInit();
	LCD_vPrintNumber(500);



	while(1){

	}
	return 1;
}

//
//int main(void){
//	SSD_vInit();
//	KPD_vInit();
//	u8 key=0;
//
//	while(1){
//
//		key=KPD_u8GetPressedKey();
//		switch(key){
//		case 1:SSD_vDisplayNum(1);
//		break;
//		case 2:SSD_vDisplayNum(2);
//		break;
//		case 3:SSD_vDisplayNum(3);
//		break;
//		case 4:SSD_vDisplayNum(4);
//		break;
//		case 5:SSD_vDisplayNum(5);
//		break;
//		case 6:SSD_vDisplayNum(6);
//		break;
//		case 7:SSD_vDisplayNum(7);
//		break;
//		case 8:SSD_vDisplayNum(8);
//		break;
//		case 9:SSD_vDisplayNum(9);
//		break;
//
//
//		}
//
//
//
//	}
//
//
//
//
//}


