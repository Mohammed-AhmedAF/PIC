/* 
 * File:   SEVENSEG_interface.h
 * Author: Mohammed
 *
 * Created on July 6, 2020, 7:10 PM
 */

#ifndef SEVENSEG_INTERFACE_H
#define	SEVENSEG_INTERFACE_H

void SEVENSEG_vidInit(void);
void SEVENSEG_vidWriteDigit(u8 u8Number, u8 u8Display);
void SEVENSEG_vidWriteNumber(u8);

#define SEVENSEG_DIS1 2
#define SEVENSEG_DIS2 3
#define SEVENSEG_DIS3 4
#define SEVENSEG_DIS4 5



#endif	/* SEVENSEG_INTERFACE_H */

