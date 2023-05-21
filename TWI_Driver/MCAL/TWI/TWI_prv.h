/*
 * TWI_prv.h
 *
 *  Created on: Mar 16, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_TWI_TWI_PRV_H_
#define MCAL_TWI_TWI_PRV_H_


#define TWBR   *( ( volatile u8* ) (0x20) )
#define TWCR   *( ( volatile u8* ) (0x56) )
#define TWSR   *( ( volatile u8* ) (0x21) )
#define TWDR   *( ( volatile u8* ) (0x23) )
#define TWAR   *( ( volatile u8* ) (0x22) )



#define TWINT 		7
#define TWEA 		6
#define TWSTA 		5
#define TWSTO 		4
#define TWWC 		3
#define TWEN 		2
#define TWIE 		0

#define TWS7 		7
#define TWS6 		6
#define TWS5 		5
#define TWS4 		4
#define TWS3 		3
#define TWPS1 		1
#define TWPS0 		0


#endif /* MCAL_TWI_TWI_PRV_H_ */
