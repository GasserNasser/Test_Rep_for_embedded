/*
 * EXTI_prg.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "EXTI_int.h"
#include "EXTI_cfg.h"
/******************************************************************************************/
void MEXTI_vInit(void){

#if EXTI_LINE0 == ENABLE
#if EXTI_INT0_SENSE_CTRL == EXTI_LOW

	CLR_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);

#elif EXTI_INT0_SENSE_CTRL == EXTI_ONCHANGE

	CLR_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

#elif EXTI_INT0_SENSE_CTRL == EXTI_FALLING

	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);

#elif EXTI_INT0_SENSE_CTRL == EXTI_RISING

	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,0);

#else
#error "Sense Control Must Be Falling,Rising, ..."s
#endif


	SET_BIT(GICR,6);

#endif

#if EXTI_LINE1 == ENABLE
#if EXTI_INT1_SENSE_CTRL == EXTI_LOW

	CLR_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);

#elif EXTI_INT1_SENSE_CTRL == EXTI_ONCHANGE

	CLR_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);

#elif EXTI_INT1_SENSE_CTRL == EXTI_FALLING

	SET_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);

#elif EXTI_INT1_SENSE_CTRL == EXTI_RISING

	SET_BIT(MCUCR,3);
	SET_BIT(MCUCR,2);

#else
#error "Sense Control Must Be Falling,Rising, ..."s
#endif


	SET_BIT(GICR,7);

#endif

#if EXTI_LINE2 == ENABLE

#if EXTI_INT2_SENSE_CTRL == EXTI_FALLING

	CLR_BIT(MCUCSR,6);


#elif EXTI_INT2_SENSE_CTRL == EXTI_RISING

	SET_BIT(MCUCSR,6);

#else
#error "Sense Control Must Be Falling,Rising"
#endif


	SET_BIT(GICR,5);

#endif

}
/****************************************USIN The TRadition way**************************/

void MEXTI_vSetSenseControl(u8 A_u8ExtiIntNo,u8 A_u8SenseCtrl){

	if(A_u8ExtiIntNo== EXTI_INT0){

		switch(A_u8SenseCtrl)
		{
		case EXTI_LOW      : 	CLR_BIT(MCUCR,1);
							    CLR_BIT(MCUCR,0);
		break;
		case EXTI_ONCHANGE : 	CLR_BIT(MCUCR,1);
								SET_BIT(MCUCR,0);
		break;
		case EXTI_FALLING : 	SET_BIT(MCUCR,1);
								CLR_BIT(MCUCR,0);
		break;
		case EXTI_RISING : 		SET_BIT(MCUCR,1);
								SET_BIT(MCUCR,0);
		break;
		}
	}

	else if (A_u8ExtiIntNo==EXTI_INT1){
		switch(A_u8SenseCtrl)
		{
		case EXTI_LOW      : 	CLR_BIT(MCUCR,3);
							    CLR_BIT(MCUCR,2);
		break;
		case EXTI_ONCHANGE : 	CLR_BIT(MCUCR,3);
								SET_BIT(MCUCR,2);
		break;
		case EXTI_FALLING : 	SET_BIT(MCUCR,3);
								CLR_BIT(MCUCR,2);
		break;
		case EXTI_RISING : 		SET_BIT(MCUCR,3);
								SET_BIT(MCUCR,2);
		break;
		}
	}
	else if (A_u8ExtiIntNo==EXTI_INT2){

		switch(A_u8SenseCtrl)
		{
		case EXTI_FALLING : CLR_BIT(MCUCSR,6);
		break;
		case EXTI_RISING  : SET_BIT(MCUCSR,6);
		}

	}
}


void MEXTI_vEnableInterrupt(u8 A_u8ExtiIntNo ){
	switch(A_u8ExtiIntNo){

	case EXTI_INT0: SET_BIT(GICR,6);
	break;
	case EXTI_INT1: SET_BIT(GICR,7);
	break;
	case EXTI_INT2: SET_BIT(GICR,5);
	break;

	}

}
void MEXTI_vDisableInterrupt(u8 A_u8ExtiIntNo){
	switch(A_u8ExtiIntNo){

	case EXTI_INT0: CLR_BIT(GICR,6);
	break;
	case EXTI_INT1: CLR_BIT(GICR,7);
	break;
	case EXTI_INT2: CLR_BIT(GICR,5);
	break;

	}
}

