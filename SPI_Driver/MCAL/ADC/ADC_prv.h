/*
 * ADC_prv.h
 *
 *  Created on: Feb 26, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

#define ADC_ENALBE 			1
#define ADC_DISABLE			2

#define AVCC			1
#define INTERNAL_REF	2
#define AREF			3

#define ADC_PRESCALER_2   0b000
#define ADC_PRESCALER_4   0b010
#define ADC_PRESCALER_8   0b011
#define ADC_PRESCALER_16  0b100
#define ADC_PRESCALER_32  0b101
#define ADC_PRESCALER_64  0b110
#define ADC_PRESCALER_128 0b111



#define ADMUX   *( ( volatile u8*  ) (0x27) )
#define ADCSRA  *( ( volatile u8*  ) (0x26) )
#define ADCL	*( ( volatile u8*  ) (0x24) )
#define ADCH	*( ( volatile u8*  ) (0x25) )
#define SFIOR	*( ( volatile u8*  ) (0x50) )
#define ADC 	*( ( volatile u16* ) (0x24) )

#define REFS1   7
#define REFS0   6
#define ADLAR  	5
#define	ADEN 	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3

#endif /* MCAL_ADC_ADC_PRV_H_ */
