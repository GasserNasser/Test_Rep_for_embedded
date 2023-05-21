/*
 * ADC_cfg.h
 *
 *  Created on: Feb 26, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_


/*
 * ADC_PRESCALER_OPTIONS:
 *
 * 			ADC_PRESCALER_2
 * 			ADC_PRESCALER_4
 * 			ADC_PRESCALER_8
 * 			ADC_PRESCALER_16
 * 			ADC_PRESCALER_32
 * 			ADC_PRESCALER_64
 * 			ADC_PRESCALER_128*/

#define ADC_PRESCALER ADC_PRESCALER_64


/*
 * REF _VOLT_OPTIONS:
 *
 * 			AVCC
 * 			INTERNAL_REF
 * 			AREF*/

#define ADC_REF_VOLT	AVCC

/*
 * ADC_INTERRUPT_ENABLE_OPTIONS:
 *
 * 			ADC_ENABLE
 * 			ADC_DISABLE
 * 			*/

#define ADC_INTERRUPT_ENABLE ADC_ENALBE


#endif /* MCAL_ADC_ADC_CFG_H_ */
