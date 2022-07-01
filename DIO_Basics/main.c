/*
 * main.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Ahmed Ebd ELNasser
 */
#include <avr/io.h>
#include <util/delay.h>
int main (void){
	DDRB=0b00001111;

	while(1){

		PORTA=0b00000001;

		for(int i=0;i<4;i++){
			_delay_ms(500);
			PORTB<<=1;


		}
	}
	return 0;
}
