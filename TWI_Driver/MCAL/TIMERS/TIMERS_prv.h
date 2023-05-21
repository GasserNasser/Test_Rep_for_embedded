/*
 * TIMERS_prv.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_TIMERS_TIMERS_PRV_H_
#define MCAL_TIMERS_TIMERS_PRV_H_

#define 			NORMAL_OC0_DISCONNECTED										0
#define 			TOGGLE_OC0_ON_CMP											1
#define 			CLEAR_OC0_ON_CMP											2
#define 			SET_OC0_ON_CMP                                              3

#define 			CLEAR_OC0_ON_CMP_SET_OC0_TOP								4
#define 			SET_OC0_ON_CMP_CLR_OC0_TOP									5

#define 			CLEAR_OC0_ON_CMP_UPCOUNTING_SET_OC0_ON_CMP_DOWNCOUNTING		6
#define 			SET_OC0_ON_CMP_UPCOUNTING_CLR_OC0_ON_CMP_DOWNCOUNTING		7

#define		TIMER_PS_NO_CLK					0b000
#define		TIMER_PS_1						0b001
#define		TIMER_PS_8						0b010
#define		TIMER_PS_64						0b011
#define		TIMER_PS_256					0b100
#define		TIMER_PS_1024					0b101
#define		TIMERP_PS_EXTERNAL_T0_FALLING	0b110
#define		TIMERP_PS_EXTERNAL_T0_RISING	0b111


#define TIMER_ENABLE			1
#define TIMER_DISABLE			2

#define	TIMER0_OVF				0
#define TIMER0_PHASECORRECT		1
#define TIMER0_CTC				2
#define TIMER0_FASTPWM			3

#define TIMER0_NO_INT			0
#define TIMER0_OVF_INT			1
#define TIMER0_CTC_INT			2

#define TCCR0   *( ( volatile u8*  ) (0x53) )
#define TCNT0   *( ( volatile u8*  ) (0x52) )
#define OCR0	*( ( volatile u8*  ) (0x5C) )
#define TIMSK	*( ( volatile u8*  ) (0x59) )
#define TIFR	*( ( volatile u8*  ) (0x58) )

#define FOC0   	7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02   	2
#define CS01   	1
#define CS00   	0

#define OCIE0	1
#define TOIE0	0

#define OCF0	1
#define TOV0	0





/*                                         TIMER 1              */

#define TCCR1A  *( ( volatile u8*  ) (0x4F) )
#define TCCR1B  *( ( volatile u8*  ) (0x4E) )
#define TCNT1	*( ( volatile u16* ) (0x4C) )
#define OCR1A	*( ( volatile u16* ) (0x4A) )
#define OCR1B	*( ( volatile u16* ) (0x48) )
#define ICR1	*( ( volatile u16* ) (0x46) )

#define WGM10   	0
#define WGM11   	1
#define FOC1B   	2
#define FOC1A   	3
#define COM1B0   	4
#define COM1B1   	5
#define COM1A0   	6
#define COM1A1   	7

#define CS10   		0
#define CS11   		1
#define CS12   		2
#define WGM12   	3
#define WGM13   	4
#define ICES1   	6
#define ICNC1   	7


#define TOIE1   	2
#define OCIE1B   	3
#define OCIE1A   	4
#define TICIE1   	5


#define TOV1   		2
#define OCF1B   	3
#define OCF1A   	4
#define ICF1   		5

#endif /* MCAL_TIMERS_TIMERS_PRV_H_ */
