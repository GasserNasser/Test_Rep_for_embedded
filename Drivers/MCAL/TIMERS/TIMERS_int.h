/*
 * TIMERS_int.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_TIMERS_TIMERS_INT_H_
#define MCAL_TIMERS_TIMERS_INT_H_

#define TIM0_CALLBACK_OVF 			0
#define TIM0_CALLBACK_CTC			1

#define 	TIMER0				0
#define 	TIMER1				1
#define 	TIMER2				2
#define 	TIMER_1A			3

#define 	ICU_Rising			1
#define		ICU_Falling			0


void MTIMERS_vInit(void);

void MTIMERS_vSetPreLoadValue(u8 A_u8TimerId, u16 A_u16PreLoad);

void MTIMERS_vSetInterval_OverFlow_Asynch(u16 A_u16IntervalCounts, void (*A_fptr)(void));

void MTIMERS_vSetCompareValue(u8 A_u8TimerId,u16 A_u16CompareValue);

void MTIMERS_vSetInterval_CTC_Asynch(u16 A_u16IntervalCounts,u16 A_u16CompareValue,void (*A_fptr)(void));

u16  MTIMERS_vGetElapsedTime(u8 A_u8TimerId);
u16  MTIMERS_u16GetCapturedValue(void);
void MTIMERS_vSetIcuTrigger(u8 A_u8IcuTrigger);
void MTIMERS_vEnableInterrupt(/* Timer ID*/ u8 A_u8InterruptType);
void MTIMERS_vDisableINterrupt(/* Timer ID*/u8 A_u8InterruptType);
void MTIMERS_vSetCallback(/* Timer ID*/void (*A_fptr)(void));

void MTIMERS_vStartTimer(/* Timer ID*/);

void MTIMERS_vStopTimer(/* Timer ID*/);

#endif /* MCAL_TIMERS_TIMERS_INT_H_ */
