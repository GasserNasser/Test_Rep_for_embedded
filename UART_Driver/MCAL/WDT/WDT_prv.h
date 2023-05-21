/*
 * WDT_prv.h
 *
 *  Created on: Mar 12, 2023
 *      Author: Ahmed Ebd ELNasser
 */

#ifndef MCAL_WDT_WDT_PRV_H_
#define MCAL_WDT_WDT_PRV_H_

#define WDTCR   *( ( volatile u8* ) (0x41) )


#define WDTOE	4
#define WDE		3
#define WDP2	2
#define WDP1	1
#define WDP0	0
#endif /* MCAL_WDT_WDT_PRV_H_ */
