/*
 * SPI_prv.h
 *
 *  Created on: Mar 15, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_

#define SPI_MASTER 	0
#define SPI_SLAVE 	1



#define SPCR   *( ( volatile u8* ) (0x2D) )
#define SPSR   *( ( volatile u8* ) (0x2E) )
#define SPDR   *( ( volatile u8* ) (0x2F) )


#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

#define SPIF	7
#define WCOL	6
#define SPI2X	0

#define MSB		7
#define LSB		0

#endif /* MCAL_SPI_SPI_PRV_H_ */
