#include "Macros.h"
#include "Std_Types.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "SEVENSEG_interface.h"
#include <xc.h>
u8 u8Numbers[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00100111,0b01111111,0b01101111};

#define _XTAL_FREQ 4000000

void SEVENSEG_vidInit()
{
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN4,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);
    
    DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN4,DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
    
}

void SEVENSEG_vidWriteDigit(u8 u8Digit, u8 u8Display)
{   
    DIO_vidSetPinValue(DIO_PORTA,u8Display,STD_HIGH);
    DIO_vidSetPortValue(DIO_PORTD,u8Numbers[u8Digit]);
    __delay_ms(1);
    DIO_vidSetPinValue(DIO_PORTA,u8Display,STD_LOW);
}

void SEVENSEG_vidWriteNumber(u8 u8Number)
{
    if (u8Number < 10)
    {
        SEVENSEG_vidWriteDigit(u8Number,SEVENSEG_DIS2);
    }
    else 
    {
        SEVENSEG_vidWriteDigit(u8Number%10,SEVENSEG_DIS2);
        SEVENSEG_vidWriteDigit(u8Number/10,SEVENSEG_DIS1);
    }
}