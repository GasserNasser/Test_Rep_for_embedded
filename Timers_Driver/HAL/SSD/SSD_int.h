/*
 * SSD_int.h
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#define COM_ANODE   1
#define COM_CATHODE 2

#define SSD_TYPE COM_ANODE
#define SSD_PORT DIO_PORTA

void HSSD_vInit(void);
void HSSD_vDisplayNum(u8 A_u8Num);
void HSSD_vTurnOff();

#endif /* HAL_SSD_SSD_INT_H_ */
