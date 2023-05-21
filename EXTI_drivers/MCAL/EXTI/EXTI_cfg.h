/*
 * EXTI_cfg.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_EXTI_EXTI_CFG_H_
#define MCAL_EXTI_EXTI_CFG_H_

#define ENABLE          1
#define DISABLE         0

#define EXTI_LINE0 		ENABLE
#define EXTI_LINE1 		DISABLE
#define EXTI_LINE2 		DISABLE

#define EXTI_INT0       0
#define EXTI_INT1		1
#define EXTI_INT2		2

/*
 *OPTIONS
 *EXTI_LOW
 *EXTI_ONCHANGE
 *EXTI_FALLING
 *EXTI_RISING
 */
#define EXTI_LOW       0
#define EXTI_ONCHANGE  1
#define EXTI_FALLING   2
#define EXTI_RISING    3

#define EXTI_INT0_SENSE_CTRL EXTI_LOW
#define EXTI_INT1_SENSE_CTRL EXTI_LOW
#define EXTI_INT2_SENSE_CTRL EXTI_RISING


#endif /* MCAL_EXTI_EXTI_CFG_H_ */
