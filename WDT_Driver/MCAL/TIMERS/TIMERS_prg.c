/*
 * TIMERS_prg.c
 *
 *  Created on: Mar 1, 2023
 *      Author: Ahmed Ebd ELNasser
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_int.h"
#include "TIMERS_prv.h"
#include "TIMERS_cfg.h"

//static void (*G_TIM0_OVF_Callback)(void);
//static void (*G_TIM0_CTC_Callback)(void);

static void (*G_TIM0_Callback[2])(void);
static void (*G_TIM1_ICU_Callback)(void);
u32 G_32IntervalCount;


void MTIMERS_vInit(void){

#if TIMER0_ENABLE == TIMER_ENABLE
	/*1- Wave Generation Mode*/ 	/*2- Compare Match Mode*/
	CLR_BIT(TCCR0,FOC0);
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);

	#if TIMER0_MODE == TIMER0_OVF

		CLR_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,COM01);
		CLR_BIT(TCCR0,COM01);


	#elif TIMER0_MODE == TIMER0_PHASECORRECT

		CLR_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);


		#if TIMER0_CMP_MATCH_MODE == NORMAL_OC0_DISCONNECTED

			CLR_BIT(TCCR0,COM01);
			CLR_BIT(TCCR0,COM00);

		#elif TIMER0_CMP_MATCH_MODE == CLEAR_OC0_ON_CMP_UPCOUNTING_SET_OC0_ON_CMP_DOWNCOUNTING

			SET_BIT(TCCR0,COM01);
			CLR_BIT(TCCR0,COM00);

		#elif TIMER0_CMP_MATCH_MODE == SET_OC0_ON_CMP_UPCOUNTING_CLR_OC0_ON_CMP_DOWNCOUNTING

			SET_BIT(TCCR0,COM01);
			SET_BIT(TCCR0,COM00);

		#else

		#error "PLEASE SELECT A VALID COMPARE MATCH MODE WITH PHASE CORRECT"

		#endif

	#elif TIMER0_MODE ==  TIMER0_CTC

		SET_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);

		#if TIMER0_CMP_MATCH_MODE == NORMAL_OC0_DISCONNECTED
			CLR_BIT(TCCR0,COM01);
			CLR_BIT(TCCR0,COM00);

		#elif TIMER0_CMP_MATCH_MODE == TOGGLE_OC0_ON_CMP
			CLR_BIT(TCCR0,COM01);
			SET_BIT(TCCR0,COM00);
		#elif TIMER0_CMP_MATCH_MODE == CLEAR_OC0_ON_CMP
			SET_BIT(TCCR0,COM01);
			CLR_BIT(TCCR0,COM00);
		#elif TIMER0_CMP_MATCH_MODE == SET_OC0_ON_CMP
			SET_BIT(TCCR0,COM01);
			SET_BIT(TCCR0,COM00);
		#else

		#error "PLEASE SELECT A VALID COMPARE MATCH MODE WITH CTC"

		#endif

	#elif TIMER0_MODE == TIMER0_FASTPWM

		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);

		#if TIMER0_CMP_MATCH_MODE == NORMAL_OC0_DISCONNECTED

			CLR_BIT(TCCR0,COM01);
			CLR_BIT(TCCR0,COM00);

		#elif TIMER0_CMP_MATCH_MODE == CLEAR_OC0_ON_CMP_SET_OC0_TOP

			SET_BIT(TCCR0,COM01);
			CLR_BIT(TCCR0,COM00);

		#elif TIMER0_CMP_MATCH_MODE == SET_OC0_ON_CMP_CLR_OC0_TOP

			SET_BIT(TCCR0,COM01);
			SET_BIT(TCCR0,COM00);

		#else
		#error "PLEASE SELECT A VALID COMPARE MATCH MODE WITH FAST PWM"
		#endif

	#else
	#error "PLEASE SELECT A VALID TIMER MODE"

	#endif


		/*3- Interrupt Enable*/
	#if TIMER0_INT == TIMER0_NO_INT

			CLR_BIT(TIMSK,TOIE0);
			CLR_BIT(TIMSK,OCIE0);

	#elif TIMER0_INT == TIMER0_OVF_INT

			SET_BIT(TIMSK,TOIE0);

	#elif TIMER0_INT == TIMER0_CTC_INT
			SET_BIT(TIMSK,OCIE0);

	#else
	#error "PLEASE SELECT A VALID TIMER0 INTERRUPT"
	#endif



#endif

			//STepper Motor MODE
//			TCCR1A=0b10000010;
//			TCCR1B=0b00011010;
//			ICR1=19999;// 20ms

			TCCR1A = 0b10000000 ;
			TCCR1B = 0b01000010 ;
}

void MTIMERS_vSetPreLoadValue(u8 A_u8TimerId, u16 A_u16PreLoad){
	switch(A_u8TimerId){
	case TIMER0:
		TCNT0 = A_u16PreLoad;
		break;
	}


}

void MTIMERS_vSetCompareValue(u8 A_u8TimerId,u16 A_u16CompareValue){
	switch(A_u8TimerId){
	case TIMER0:
		OCR0 = A_u16CompareValue;
		break;
	case TIMER_1A:
		OCR1A=A_u16CompareValue;
		break;
	}



}

void MTIMERS_vSetInterval_OverFlow_Asynch(u16 A_u16IntervalCounts, void (*A_fptr)(void)){

	G_32IntervalCount = A_u16IntervalCounts;

	G_TIM0_Callback[TIM0_CALLBACK_OVF] = A_fptr;

	// Start Timer
	MTIMERS_vStartTimer();
}

void MTIMERS_vSetInterval_CTC_Asynch(u16 A_u16IntervalCounts,u16 A_u16CompareValue,void (*A_fptr)(void)){

	G_32IntervalCount = A_u16IntervalCounts;


	G_TIM0_Callback[TIM0_CALLBACK_CTC] = A_fptr;
	MTIMERS_vSetCompareValue(TIMER0,A_u16CompareValue);
	// Start Timer
	MTIMERS_vStartTimer();
}

void MTIMERS_vStartTimer(/* Timer ID*/){

	TCCR0= ( TCCR0 & 0xF8 ) | (TIMER0_PRESCALER); /*Select the First 3 Bits and then or them with clk prescaler*/

}

void MTIMERS_vStopTimer(/* Timer ID*/){

	TCCR0= ( TCCR0 & 0xF8 ) | (TIMER_PS_NO_CLK);
}


u16  MTIMERS_vGetElapsedTime(u8 A_u8TimerId){

	u16 L_u16ElapsedTime = 0;

	switch(A_u8TimerId){

	case TIMER0:

		L_u16ElapsedTime=TCNT0;
		break;

	case TIMER1:

		L_u16ElapsedTime=TCNT1;
		break;
	}

	return L_u16ElapsedTime;

}
u16  MTIMERS_u16GetCapturedValue(void){

	return ICR1;


}

void MTIMERS_vSetIcuTrigger(u8 A_u8IcuTrigger){

	switch(A_u8IcuTrigger){
	case ICU_Rising:

		SET_BIT(TCCR1B,ICES1);
		break;

	case ICU_Falling:

		CLR_BIT(TCCR1B,ICES1);
		break;

	}


}
void MTIMERS_vEnableInterrupt(/* Timer ID*/u8 A_u8InterruptType){

	SET_BIT(TIMSK,TICIE1);

}
void MTIMERS_vDisableINterrupt(/* Timer ID*/u8 A_u8InterruptType){
	CLR_BIT(TIMSK,TICIE1);

}
void MTIMERS_vSetCallback(/* Timer ID*/void (*A_fptr)(void)){
	G_TIM1_ICU_Callback=A_fptr;

}

/*                                                 Timer 0 OverFlow ISR                                                      */
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){

	static u32 LS_u32Counter = 0;
	LS_u32Counter++;

	if(LS_u32Counter == G_32IntervalCount){

		if(G_TIM0_Callback[TIM0_CALLBACK_OVF]!=NULL){

			G_TIM0_Callback[TIM0_CALLBACK_OVF]();
			LS_u32Counter = 0;

		}
	}
}

/*                                                     Timer 0 CTC ISR                                                  */

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){

	static u32 LS_u32Counter = 0;
	LS_u32Counter++;

	if(LS_u32Counter == G_32IntervalCount){

		if(G_TIM0_Callback[TIM0_CALLBACK_CTC]!=NULL){

			G_TIM0_Callback[TIM0_CALLBACK_CTC]();
			LS_u32Counter = 0;

		}
	}
}


/*                                                     Timer 1 ICU ISR                                                  */

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void){

	G_TIM1_ICU_Callback();

}
