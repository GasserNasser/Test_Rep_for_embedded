/*
 * DCM_prg.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "DCM_int.h"
#include "DCM_cfg.h"


DCM_t HDCM_xInit(u8 A_u8Port,u8 A_u8Pin1,u8 A_u8Pin2){

	MDIO_vSetPinDir(A_u8Port,A_u8Pin1,DIO_OUTPUT);
	MDIO_vSetPinDir(A_u8Port,A_u8Pin2,DIO_OUTPUT);

	DCM_t L_xNewMotor;
	L_xNewMotor.Port=A_u8Port;
	L_xNewMotor.Pin1=A_u8Pin1;
	L_xNewMotor.Pin2=A_u8Pin2;

	return L_xNewMotor;

}
void HDCM_vRotateCW(DCM_t* A_xMotor){
	/*TODO: implement speed as input */
	MDIO_vSetPinVal(A_xMotor->Port,A_xMotor->Pin1,DIO_HIGH);
	MDIO_vSetPinVal(A_xMotor->Port,A_xMotor->Pin2,DIO_LOW);

}
void HDCM_vRotateCCW(DCM_t* A_xMotor){
	/*TODO: implement speed as input */
	MDIO_vSetPinVal(A_xMotor->Port,A_xMotor->Pin1,DIO_LOW);
	MDIO_vSetPinVal(A_xMotor->Port,A_xMotor->Pin2,DIO_HIGH);
}
void HDCM_vStop(DCM_t* A_xMotor){
	MDIO_vSetPinVal(A_xMotor->Port,A_xMotor->Pin1,DIO_LOW);
	MDIO_vSetPinVal(A_xMotor->Port,A_xMotor->Pin2,DIO_LOW);

}


