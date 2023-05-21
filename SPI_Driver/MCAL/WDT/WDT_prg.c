/*
 * WDT_prg.c
 *
 *  Created on: Mar 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_int.h"
#include "WDT_prv.h"
#include "WDT_cfg.h"


void MWDT_vTurnON(u8 A_u8Timeout){
	/*Set Time*/
	WDTCR = (WDTCR & 0xF8) | A_u8Timeout;
	/*Enable WDT*/
	SET_BIT(WDTCR,WDE);

}

void MWDT_vTurnOff(void){

	WDTCR = 0b00011000 ;
	WDTCR = 0;
}
