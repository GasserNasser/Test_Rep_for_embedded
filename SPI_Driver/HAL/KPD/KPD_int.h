/*
 * KPD_int.h
 *
 *  Created on: Jan 4, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_

#define KPD_PORT DIO_PORTD

void KPD_vInit(void);
u8 KPD_u8GetPressedKey(void);

#endif /* HAL_KPD_KPD_INT_H_ */
