/*
 * WDT_int.h
 *
 *  Created on: Mar 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_WDT_WDT_INT_H_
#define MCAL_WDT_WDT_INT_H_

#define WDT_16_3ms		0b000
#define WDT_32_5ms		0b001
#define WDT_65ms		0b010
#define WDT_0_13s		0b011
#define WDT_0_26s		0b100
#define WDT_0_52s		0b101
#define WDT_1s			0b110
#define WDT_2_1s		0b111

void MWDT_vTurnON(u8 A_u8Timeout);
void MWDT_vTurnOff(void);

#endif /* MCAL_WDT_WDT_INT_H_ */
