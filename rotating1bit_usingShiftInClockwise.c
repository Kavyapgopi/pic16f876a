/*
 * File:   rotating1bit_shiftClockwise.c
 * Author: kavya
 *
 * Created on June 5, 2024, 11:19 AM
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
    int i;
    TRISC =0x00;                                   //Make PortC output using data direction register
    TRISB =0x00;                                   //Make PortB output using data direction register
    TRISA =0x00;                                   //Make PortA output using data direction register
    ADCON1=0x07;                              //make portA pins digital I/O
    PORTB=0x00;                                  //write 0 to all port
    PORTC=0x00;                                  //write 0 to all port
    PORTA=0x00;                                  //write 0 to all port
    while(1)                                           //for repeating code infinitely 
    {                  
        for(i=0;i<8;i++)
        {
            PORTB=1<<i;                           //shift 1 to i position and assign result to the port
            __delay_ms(1000);                      //delay of 1ms
         }
        PORTB=0x00;
        for(i=0;i<8;i++)
        {
            PORTC=1<<i;                           //shift 1 to i position and assign result to the port
            __delay_ms(1000);                      //delay of 1ms

         } 
        PORTC=0x00;
        for(i=0;i<6;i++)                            //rotating clock wise port A is in upward direction 
            
        {
            PORTA=0x20>>i;                      //shift b00100000 to i position and assign result to the port.
            __delay_ms(1000);                      //delay of 1ms

         }
        PORTA=0x00;
                 
    }
}



     
