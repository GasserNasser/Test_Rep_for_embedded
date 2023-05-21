/*
 * main.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Ahmed Ebd ELNasser
 */
#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

int main (void){
	DDRA=0xff; // PA0 -> OUTPUT
	u8 arr[10]={~(0b00111111)
				,~(0b00000110)
				,~(0b01011011)
				,~(0b01001111)
				,~(0b01100110)
				,~(0b01101101)
				,~(0b01111101)
				,~(0b00000111)
				,~(0b01111111)
				,~(0b01101111)};

	while(1){
		for(u8 i =0; i<10l;i++){
			PORTA=arr[i];
			_delay_ms(500);
		}



	}
	return 0;

}
