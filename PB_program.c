#include "Std_Types.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "PB_interface.h"

#define NUMBER_OF_SAMPLES (2)
#define NUMBER_OF_PUSH_BUTTONS (4)

#define PB_PRESSED_VOLTAGE (0)
#define PB_RELEASED_VOLTAGE (1)

typedef struct {
    unsigned char samples[NUMBER_OF_SAMPLES];
    tPB_State state;
}tPB_Info;

static tPB_Info pb_info[NUMBER_OF_PUSH_BUTTONS];

void PB_vidInit(tPB_Button pb, tPB_State initialState)
{
    switch(pb)
    {
        case PB_PLUS:
            DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_INPUT);
            break;
        case PB_RESET:
            DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_INPUT);
            break;
        case PB_UNUSED_1:
            DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);
            break;
        case PB_UNUSED_2:
            DIO_vidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_INPUT);
            break;
    }
    
    /*Setting initial state*/
    pb_info[pb].state = initialState;
    
    switch(initialState)
    {
        case PB_RELEASED_VOLTAGE:
        case PB_PRE_RELEASED:
            pb_info[pb].samples[0] = PB_RELEASED_VOLTAGE;
            pb_info[pb].samples[1] = PB_RELEASED_VOLTAGE;
            break;
        case PB_PRESSED:
        case PB_PRE_PRESSED:
            pb_info[pb].samples[0] = PB_PRESSED_VOLTAGE;
            pb_info[pb].samples[1] = PB_PRESSED_VOLTAGE;
            break;
    }
   
}

void PB_vidUpdate()
{

}

u8 PB_u8GetState(tPB_Button pb)
{
    tPB_State retState = PB_RELEASED_VOLTAGE;
    retState = pb_info[pb].state;
    return retState;
}