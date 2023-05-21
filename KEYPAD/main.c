/*
 * main.c
 *
 *  Created on: Jan 3, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include"STD_TYPES.h"
#include<avr/io.h>
#include<util/delay.h>
#include"BIT_MATH.h"
#include"7SEGMENT_NUMBERS.h"

void KEYPAD_Init(){
	/* PORTD INPUTS OUTPUTS*/
	DDRD=0x0f;

	/* PULL UP  Resistors Activation    Deactivation for the coulumns */
	PORTD=0xff ;
}
void SevenSegment_Init(void){
	/*PORTA OUTPUT      7 segment is common anode */
	DDRA=0xff;
	PORTA=0xff;
}
u8 GetPressedKey(void){
	u8 pressed_key= 0;

	for(u8 col=0;col<4;col++){
		/*Activate The Column*/
		CLR_BIT(PORTD,col);

		for(u8 row=0;row<4;row++){
			if(GET_BIT(PIND,row+4)==0){
				pressed_key= row + (col*4)+1;

			}
			while(GET_BIT(PIND,row+4)==0){

			}
			_delay_ms(10);
		}
		/*Deactivate The Column*/
		SET_BIT(PORTD,col);
	}

	return pressed_key;
}

int main(void){
	u8 key=0;
	KEYPAD_Init();
	SevenSegment_Init();
	while(1){
		key=GetPressedKey();
		switch(key){
				case 1:PORTA=one;
						break;
				case 2:PORTA=two;
						break;
				case 3:PORTA=three;
						break;
				case 4:PORTA=four;
						break;
				case 5:PORTA=five;
						break;
				case 6:PORTA=six;
						break;
				case 7:PORTA=seven;
						break;
				case 8:PORTA=eight;
						break;
				case 9:PORTA=nine;
						break;

				}



	}
	return 1;
}
