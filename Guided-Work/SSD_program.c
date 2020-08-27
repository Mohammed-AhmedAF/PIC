#include "Std_Types.h"
#include "Macros.h"
#include "Utilities.h"
#include "SSD_interface.h"
#include "DIO_interface.h"

#define NUMBER_OF_SSD (4)

tSSD_Symbol currentSymbols[NUMBER_OF_SSD] = {SSD_NULL};

static unsigned char ssd_data[] = {
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000
};

void SSD_vidInit(tSSD ssd, tSSD_Symbol symbol,tSSD_State state) {

    DIO_vidSetPortDirection(DIO_PORTD,DIO_OUTPUT);
    
    DIO_vidSetPortValue(DIO_PORTD,ssd_data[SSD_NULL]);
    
    /*Initialize SSD State pins*/
    switch (ssd) {
        case SSD_L:
            DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);
            break;
        case SSD_M:
            DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
            break;
        case SSD_N:
            DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
            break;
        case SSD_R:
            DIO_vidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
            break;
    }
    
    /*Set state*/
    SSD_SetState(ssd,state);
    SSD_SetSymbol(ssd,symbol);
}

void SSD_vidUpdate(void) {

    tSSD current_ssd = SSD_L;
    for (current_ssd = SSD_L; current_ssd <= SSD_R; current_ssd++) {
        /*Turn all SSDs off*/
        SSD_SetState(SSD_L,SSD_OFF);
        SSD_SetState(SSD_M,SSD_OFF);
        SSD_SetState(SSD_N,SSD_OFF);
        SSD_SetState(SSD_R,SSD_OFF);
        
      /*Sending data*/
        DIO_vidSetPortValue(DIO_PORTD,ssd_data[currentSymbols[current_ssd]]);
     
        /*Turn current SSD*/
        SSD_SetState(current_ssd,SSD_ON);
        
        /*Delay*/
        UTIL_DelayMS(20);
    
    }
}

void SSD_SetSymbol(tSSD ssd, tSSD_Symbol symbol) {
    currentSymbols[ssd] = symbol;
}

void SSD_SetState(tSSD ssd, tSSD_State state) {
    switch (ssd) {
        case SSD_L:
            DIO_vidSetPinValue(DIO_PORTB, DIO_PIN7, state);
            break;
        case SSD_M:
            DIO_vidSetPinValue(DIO_PORTB, DIO_PIN6, state);
            break;
        case SSD_N:
            DIO_vidSetPinValue(DIO_PORTB, DIO_PIN5, state);
            break;
        case SSD_R:
            DIO_vidSetPinValue(DIO_PORTB, DIO_PIN4, state);
            break;
        default:
            break;
    }
}

tSSD_State SSD_GetState(tSSD ssd) {
    tSSD_State ret;
    switch (ssd) {
        case SSD_L:
            ret = DIO_u8GetPinValue(DIO_PORTB, DIO_PIN7);
            break;
        case SSD_M:
            ret = DIO_u8GetPinValue(DIO_PORTB, DIO_PIN6);
            break;
        case SSD_N:
            ret = DIO_u8GetPinValue(DIO_PORTB, DIO_PIN5);
            break;
        case SSD_R:
            ret = DIO_u8GetPinValue(DIO_PORTB, DIO_PIN4);
            break;
    }

    return ret;
}

tSSD_Symbol SSD_GetSymbol(tSSD ssd) {
    tSSD_Symbol ret;
    ret = currentSymbols[ssd];
    return ret;
}
