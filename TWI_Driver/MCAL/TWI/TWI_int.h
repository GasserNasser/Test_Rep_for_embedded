/*
 * TWI_int.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_

#define TWI_WRITE	0
#define TWI_READ	1

#define TWI_ACk		1
#define TWI_NOT_ACK	0


void MTWI_vInit(void);

u8 MTWI_u8SendStartCondition(void);
u8 MTWI_u8SendRepeatedStartCondition(void);
u8 MTWI_u8SendSlaveAddressRw(u8 A_u8Sla,u8 A_u8Rw);
u8 MTWI_u8SendByte(u8 A_u8Byte);
u8 MTWI_u8RecieveByte(u8* A_pu8Byte,u8 A_u8Ack);
u8 MTWI_u8SendStopCondition(void);
u8 MTWI_u8GetStatus(void);

void MTWI_vSetBitRate(u32 A_u32BitRate);
void MTWI_vSetSlaveAddress(u8 A_u8OwnSla);

#endif /* MCAL_TWI_TWI_INT_H_ */
