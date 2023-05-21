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
	DDRA=0b00000001;
	PORTA=0b00000010;
	while(1){

		if(GET_BIT(PINA,1)==0){
			while(GET_BIT(PINA,1)==0){

			}

			_delay_ms(10);
			TOG_BIT(PORTA,0);
		}

	}
	return 0;

}
