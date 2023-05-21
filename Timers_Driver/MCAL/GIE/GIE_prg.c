/*
 * GIE_prg.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_prv.h"
#include "GIE_int.h"

void MGIE_vEnableGlobalInterrupt(void){
	SET_BIT(SREG,7);
}
void MGIE_vDisableGlobalInterrupt(void){
	CLR_BIT(SREG,7);

}
