/*
 * UART_int.h
 *
 *  Created on: Mar 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

void MUART_vInit(void);
void MUART_vTransmit(u8 A_u8Byte);
u8 MUART_u8Recieve(void);


void MUART_vSendString(char* str);
void MUART_vSendNumber(s32 Num);
void MUART_vReceieveString(char str[],u32 size);
#endif /* MCAL_UART_UART_INT_H_ */
