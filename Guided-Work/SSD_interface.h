/* 
 * File:   SSD_interface.h
 * Author: Mohammed
 *
 * Created on August 27, 2020, 12:18 PM
 */

#ifndef SSD_INTERFACE_H
#define	SSD_INTERFACE_H

typedef enum {
    SSD_L,
            SSD_M,
            SSD_N,
            SSD_R
}tSSD;

typedef enum {
    SSD_OFF = 0,
            SSD_ON
}tSSD_State;

typedef enum {
    SSD_0,
    SSD_1,
    SSD_2,
    SSD_3,
    SSD_4,
    SSD_5,
    SSD_6,
    SSD_7,
    SSD_8,
    SSD_9,
    SSD_NULL
}tSSD_Symbol;

void SSD_vidInit(tSSD ssd, tSSD_Symbol symbol,tSSD_State state);
void SSD_vidUpdate(void);
void SSD_SetSymbol(tSSD ssd,tSSD_Symbol symbol);
void SSD_SetState(tSSD ssd, tSSD_State State);
tSSD_Symbol SSD_GetSymbol(tSSD ssd);
tSSD_State SSD_GetState(tSSD ssd);


#endif	/* SSD_INTERFACE_H */

