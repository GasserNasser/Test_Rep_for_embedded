/*
 * ADC_int.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

void MADC_vInit(void);
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo); //Synchronus Function

/*Interrupt Based APIs*/
void  MADC_vStartConversion(u8 A_u8ChannelNo);

u16 MADC_u16GetADCData(void); //Asynchronus Function

void MADC_vSetCallback(void (*A_fptr) (void));

#endif /* MCAL_ADC_ADC_INT_H_ */
