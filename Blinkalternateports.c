/*
 * File:   Blinkalternateports.c
 * Author: kavya
 *
 * Created on June 5, 2024, 11:03 AM
 */
// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000          //select oscillator freqency as 4MHZ
#include <xc.h>                

void main(void) 
{
    TRISC =0x00;                                   //Make PortC output using data direction register
    PORTC=0xAA;                                  //write 10101010 to all port
    TRISB =0x00;                                   //Make PortB output using data direction register
    PORTB=0xAA;                                  //write 10101010 to all port
    TRISA =0x00;                                   //Make PortA output using data direction register
    PORTA=0x2A;                                  //write 00101010 to all port
    ADCON1=0x07;                              //make portA pins digital I/O

    while(1)                                           //for repeating code infinitely 
    {
        PORTC=0xAA;                             //10101010=0XAA makes alternate pins on and off
        PORTB=0xAA;                              //10101010=0XAA makes alternate pins on and off
        PORTA=0x2A;                              //00101010=0X2A makes alternate pins on and off PortA have only 6 pin so 6and 7 bits are 0
        __delay_ms(1000);                      //delay of 1ms
        PORTC=0x55;                             //01010101=0X55 makes alternate pins on and  off
        PORTB=0x55;                              //01010101=0X55 makes alternate pins on and off
        PORTA=0x15;                            //00010101=0X15 makes alternate pins on and off
        __delay_ms(1000);
    }
    return;
}
