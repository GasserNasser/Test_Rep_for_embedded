/*
 * EXTI_int.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_
/*Drive USING CONFIGRATION FILE
 * You write the drive and using the EXTI.cfg file u edit which features you want to use*/
void MEXTI_vInit(void);

/***************************Driver Using Functions**************************************/
void MEXTI_vEnableInterrupt(u8 A_u8ExtiIntNo );
void MEXTI_vDisableInterrupt(u8 A_u8ExtiIntNo);
void MEXTI_vSetSenseControl(u8 A_u8ExtiIntNo,u8 A_u8SenseCtrl);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
