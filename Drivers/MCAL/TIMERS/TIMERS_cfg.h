/*
 * TIMERS_cfg.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_TIMERS_TIMERS_CFG_H_
#define MCAL_TIMERS_TIMERS_CFG_H_

/*TIMER0 ENABLE OPTIONS:
 *
 * 			TIMER_ENABLE
 * 			TIMER_DISABLE
 * 			*/

#define TIMER0_ENABLE  TIMER_ENABLE


/*TIMER0 MODE OPTIONS:
 *
 * 			TIMER0_OVF
 * 			TIMER0_PHASECORRECT
 * 			TIMER0_CTC
 * 			TIMER0_FASTPWM
 * 			*/

#define TIMER0_MODE		TIMER0_FASTPWM

/*TIMER0 INT OPTIONS:
 *			TIMER0_NO_INT
 * 			TIMER0_OVF_INT
 * 			TIMER0_CTC_INT
 * 			 	*/

#define TIMER0_INT		TIMER0_NO_INT


/*TIMER0 COMPARE OUTPUT MODE OPTIONS:
 *
 *MODES FOR CTC
 *
 * 			NORMAL_OC0_DISCONNECTED
 * 			TOGGLE_OC0_ON_CMP
 * 			CLEAR_OC0_ON_CMP
 * 			SET_OC0_ON_CMP
 *
 *MODES FOR FAST PWM
 *
 *			NORMAL_OC0_DISCONNECTED
 * 			CLEAR_OC0_ON_CMP_SET_OC0_TOP
 * 			SET_OC0_ON_CMP_CLR_OC0_TOP
 *
 *MODES FOR PHASE CORRECT PWM
 *
 * 			NORMAL_OC0_DISCONNECTED
 * 			CLEAR_OC0_ON_CMP_UPCOUNTING_SET_OC0_ON_CMP_DOWNCOUNTING
 * 			SET_OC0_ON_CMP_UPCOUNTING_CLR_OC0_ON_CMP_DOWNCOUNTING
 * */

#define TIMER0_CMP_MATCH_MODE 			CLEAR_OC0_ON_CMP_SET_OC0_TOP


/*TIMER0 PRESCALER OPTIONS:
 *
 * 			TIMER_PS_NO_CLK
 * 			TIMER_PS_1
 * 			TIMER_PS_8
 * 			TIMER_PS_64
 * 			TIMER_PS_256
 * 			TIMER_PS_1024
 * 			TIMERP_PS_EXTERNAL_T0_FALLING
 * 			TIMERP_PS_EXTERNAL_T0_RISING

 * */

#define TIMER0_PRESCALER				TIMER_PS_8


/*************************************************************************************/

#endif /* MCAL_TIMERS_TIMERS_CFG_H_ */
