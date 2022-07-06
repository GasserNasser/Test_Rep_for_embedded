/*
 * main.c
 *
 *  Created on: Jul 6, 2022
 *      Author: Ahmed Ebd ELNasser
 */
#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "7SEGMENT_NUMBERS.H"


void KEYPAD_Init(void)
{
	/*PORTD -> 4inputs/4outputs */
	DDRB=0x0f;
	/* PULL UP resistors activation on inputs*/
	PORTB=0xff; // here u set the first half with ones so that u can deactivate the columns
}

u8 GetPressedKey(void){

	u8 pressed_key=0;

	for(u8 col=0; col<4; col++){
		CLR_BIT(PORTB,col);  //Activate Current Columns

		for(u8 row=0;row<4;row++){


			if(GET_BIT(PINB,row+4)==0){


				while(GET_BIT(PINB,row+4)==0){

				}
				_delay_ms(10);
				pressed_key=row+(col*4)+1;
			}
		}
		SET_BIT(PORTB,col);//Deactivate Column
	}
	return pressed_key ;
}

int main(void){
	KEYPAD_Init();
	DDRA=0xff;
	PORTA=0xff;
	u8 key=0;
	while(1)
	{
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


	return 0;
}

