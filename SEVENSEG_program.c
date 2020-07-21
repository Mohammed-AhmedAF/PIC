#include "Macros.h"
#include "Std_Types.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "SEVENSEG_interface.h"
#include <xc.h>
u8 u8Numbers[11] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00100111, 0b01111111, 0b01101111,0x00};

#define _XTAL_FREQ 4000000

u8 u8State = 0;

void SEVENSEG_vidInit() {
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN4, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN6, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);

    DIO_vidSetPinDirection(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
    DIO_vidSetPinDirection(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);
}

void SEVENSEG_vidWriteDigit(u8 u8Digit, u8 u8Display) {

    SEVENSEG_vidSelectDisplay(u8Display);

    DIO_vidSetPortValue(DIO_PORTD, u8Numbers[u8Digit]);
    
}

void SEVENSEG_vidWriteNumber(u8 u8Number) {
    if (u8Number < 10) {
        SEVENSEG_vidWriteDigit(u8Number, SEVENSEG_DIS4);
    } else {
        SEVENSEG_vidWriteDigit(u8Number / 10, SEVENSEG_DIS3);
        __delay_ms(1);
        SEVENSEG_vidWriteDigit(u8Number % 10, SEVENSEG_DIS4);
        __delay_ms(1);

        
    }
}

u8 SEVENSEG_u8CheckState(void) {
    if (u8State == 0x01) {
        return 1;
    } else {
        return 0;
    }
}

void SEVENSEG_vidSelectDisplay(u8 u8Display) {
    if (u8Display == SEVENSEG_DIS4) {
        DIO_vidSetPinValue(DIO_PORTA, SEVENSEG_DIS3, STD_LOW);

        DIO_vidSetPinValue(DIO_PORTA, SEVENSEG_DIS4, STD_HIGH);
    } else {
        DIO_vidSetPinValue(DIO_PORTA, SEVENSEG_DIS3, STD_HIGH);

        DIO_vidSetPinValue(DIO_PORTA, SEVENSEG_DIS4, STD_LOW);
    }
}

void SEVENSEG_vidDisableSevenSeg(void) {
  SEVENSEG_vidWriteDigit(10, SEVENSEG_DIS3);
        __delay_ms(1);
        SEVENSEG_vidWriteDigit(10, SEVENSEG_DIS4);
        __delay_ms(1);
   
}