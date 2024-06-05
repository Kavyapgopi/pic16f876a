/*
 * File:   rotating1Bit_usingarrayCloclwise.c
 * Author: kavya
 *
 * Created on June 5, 2024, 2:54 PM
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
    PORTB=0x00;                                  //write 10101010 to all port
    PORTC=0x00;                                  //write 10101010 to all port
    PORTA=0x00;                                  //write 00101010 to all 
    int rotation[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};  //port values as it rotates bit taken as array elements
    while(1)                                           //for repeating code infinitely 
    {                
        
        for(i=0;i<8;i++)                               //PORTB in downward direction
        {
            
            PORTB=rotation[i];                      //assign array elements in position i to the PORTB
            __delay_ms(1000);                      //delay of 1ms
         }
        
         PORTB=0x00;
        
        for(i=0;i<8;i++)                               //PORTC in downward direction
        {
            PORTC=rotation[i];                      //assign array elements in position i to the PORTC
            __delay_ms(1000);                      //delay of 1ms
         }
         
         PORTC=0X00;

        for(i=5;i>=0;i--)                              //PORTA in upward direction
        {
            PORTA=rotation[i];                       //assign array elements in position i to the PORTA
            __delay_ms(1000);                      //delay of 1ms
         }
         PORTA=0X00;
            
    }
    
}
