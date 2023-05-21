/*
 * EXTI_prg.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_prv.h"
#include "EXTI_int.h"
#include "EXTI_cfg.h"
/******************************************************************************************/
void MEXTI_vInit(void){

#if EXTI_LINE0 == EXTI_ENABLE
#if EXTI_INT0_SENSE_CTRL == EXTI_LOW

	CLR_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);

#elif EXTI_INT0_SENSE_CTRL == EXTI_ONCHANGE

	CLR_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);

#elif EXTI_INT0_SENSE_CTRL == EXTI_FALLING

	SET_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);

#elif EXTI_INT0_SENSE_CTRL == EXTI_RISING

	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);

#else
#error "Sense Control Must Be Falling,Rising, ..."s
#endif


	SET_BIT(GICR,INT0);

#endif

#if EXTI_LINE1 == EXTI_ENABLE
#if EXTI_INT1_SENSE_CTRL == EXTI_LOW

	CLR_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);

#elif EXTI_INT1_SENSE_CTRL == EXTI_ONCHANGE

	CLR_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);

#elif EXTI_INT1_SENSE_CTRL == EXTI_FALLING

	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);

#elif EXTI_INT1_SENSE_CTRL == EXTI_RISING

	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);

#else
#error "Sense Control Must Be Falling,Rising, ..."s
#endif


	SET_BIT(GICR,INT1);

#endif

#if EXTI_LINE2 == EXTI_ENABLE

#if EXTI_INT2_SENSE_CTRL == EXTI_FALLING

	CLR_BIT(MCUCSR,ISC2);


#elif EXTI_INT2_SENSE_CTRL == EXTI_RISING

	SET_BIT(MCUCSR,ISC2);

#else
#error "Sense Control Must Be Falling,Rising"
#endif


	SET_BIT(GICR,INT2);

#endif

}
/****************************************USIN The TRadition way**************************/

void MEXTI_vSetSenseControl(u8 A_u8ExtiIntNo,u8 A_u8SenseCtrl){

	if(A_u8ExtiIntNo== EXTI_INT0){

		switch(A_u8SenseCtrl)
		{
		case EXTI_LOW      : 	CLR_BIT(MCUCR,ISC01);
							    CLR_BIT(MCUCR,ISC00);
		break;
		case EXTI_ONCHANGE : 	CLR_BIT(MCUCR,ISC01);
								SET_BIT(MCUCR,ISC00);
		break;
		case EXTI_FALLING : 	SET_BIT(MCUCR,ISC01);
								CLR_BIT(MCUCR,ISC00);
		break;
		case EXTI_RISING : 		SET_BIT(MCUCR,ISC01);
								SET_BIT(MCUCR,ISC00);
		break;
		}
	}

	else if (A_u8ExtiIntNo==EXTI_INT1){
		switch(A_u8SenseCtrl)
		{
		case EXTI_LOW      : 	CLR_BIT(MCUCR,ISC11);
							    CLR_BIT(MCUCR,ISC10);
		break;
		case EXTI_ONCHANGE : 	CLR_BIT(MCUCR,ISC11);
								SET_BIT(MCUCR,ISC10);
		break;
		case EXTI_FALLING : 	SET_BIT(MCUCR,ISC11);
								CLR_BIT(MCUCR,ISC10);
		break;
		case EXTI_RISING : 		SET_BIT(MCUCR,ISC11);
								SET_BIT(MCUCR,ISC10);
		break;
		}
	}
	else if (A_u8ExtiIntNo==EXTI_INT2){

		switch(A_u8SenseCtrl)
		{
		case EXTI_FALLING : CLR_BIT(MCUCSR,ISC2);
		break;
		case EXTI_RISING  : SET_BIT(MCUCSR,ISC2);
		}

	}
}


void MEXTI_vEnableInterrupt(u8 A_u8ExtiIntNo ){
	switch(A_u8ExtiIntNo){

	case EXTI_INT0: SET_BIT(GICR,INT0);
	break;
	case EXTI_INT1: SET_BIT(GICR,INT1);
	break;
	case EXTI_INT2: SET_BIT(GICR,INT2);
	break;

	}

}
void MEXTI_vDisableInterrupt(u8 A_u8ExtiIntNo){
	switch(A_u8ExtiIntNo){

	case EXTI_INT0: CLR_BIT(GICR,INT0);
	break;
	case EXTI_INT1: CLR_BIT(GICR,INT1);
	break;
	case EXTI_INT2: CLR_BIT(GICR,INT2);
	break;

	}
}

