/* 
 * File:   PB_interface.h
 * Author: Mohammed
 *
 * Created on August 22, 2020, 1:37 PM
 */

#ifndef _PB_INTERFACE_H
#define	_PB_INTERFACE_H

typedef enum {
    PB_PLUS,
    PB_RESET,
            PB_UNUSED_1,
            PB_UNUSED_2
}tPB_Button;


typedef enum{
    PB_PRESSED,
            PB_PRE_RELEASED,
            PB_RELEASED,
            PB_PRE_PRESSED
} tPB_State;


/*Function declaration*/
void PB_vidInit(tPB_Button pb, tPB_State initial_state);
void PB_vidUpdate(void);
void PB_u8GetState(tPB_Button pb);


#endif	/* PB_INTERFACE_H */

