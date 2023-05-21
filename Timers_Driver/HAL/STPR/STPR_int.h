/*
 * STPR_int.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_STPR_STPR_INT_H_
#define HAL_STPR_STPR_INT_H_

HSTPR_INIT();
HSTPR_RotateCW(u16 A_u8Angle);
HSTPR_RotateCCW(u16 A_u8Angle);

HSTPR_RotateStepsCW(u16 A_u8Steps);
HSTPR_RotateStepsCCW(u16 A_u8Steps);



#endif /* HAL_STPR_STPR_INT_H_ */
