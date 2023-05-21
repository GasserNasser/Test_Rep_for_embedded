/*
 * DCM_int.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef HAL_DCM_DCM_INT_H_
#define HAL_DCM_DCM_INT_H_

#include"DCM_cfg.h"

typedef struct
{
	u8 Port;
	u8 Pin1;
	u8 Pin2;

}DCM_t;



DCM_t HDCM_xInit(u8 A_u8Port,u8 A_u8Pin1,u8 A_u8Pin2);
void HDCM_vRotateCW(DCM_t* A_xMotor);
void HDCM_vRotateCCW(DCM_t* A_xMotor);
void HDCM_vStop(DCM_t* A_xMotor);


#endif /* HAL_DCM_DCM_INT_H_ */
