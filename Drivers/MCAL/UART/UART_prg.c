/*
 * UART_prg.c
 *
 *  Created on: Mar 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_int.h"
#include "UART_prv.h"
#include "UART_cfg.h"



void MUART_vInit(void){
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	UBRRL=51;

}


void MUART_vTransmit(u8 A_u8Byte){
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = A_u8Byte;
}
u8 MUART_u8Recieve(void){
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

void MUART_vSendString(char* str){

	for(u32 i=0;str[i]!='\0';i++){

		MUART_vTransmit(str[i]);
	}

	/*                             OR                 */
//	while(*str !='\0'){
//
//		MUART_vTransmit(*str);
//		str++;
//	}

}
void MUART_vSendNumber(s32 Num){

}
void MUART_vReceieveString(char str[],u32 size){

	for(u32 i=0;i<size;i++){
		str[i]=MUART_u8Recieve();
		if(str[i]=='\n' ||str[i]=='\r'){

			str[i]='\0';
			break;
		}
	}

}
