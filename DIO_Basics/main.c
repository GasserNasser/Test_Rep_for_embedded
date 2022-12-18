/*
 * main.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Ahmed Ebd ELNasser
 */
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"

int main (void){
	DDRA=0b00001111; //PA0 PA1 PA2 PA3 -> OUTPUT

	while(1){
		PORTA=0b00000001;
		for(int i=0;i<4;i++){
			_delay_ms(500);
			PORTA<<=1;

		}

		/*if(GET_BIT(PINA,1)==0){
			while(GET_BIT(PINA,1)==0){

			}

			_delay_ms(10);
			TOG_BIT(PORTA,0);*/
		}
	return 0;
	}


