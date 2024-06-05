
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

void main(void) {
    TRISA =0x00;                                   //Make PortA output using data direction register
    PORTA=0x00;                                  //write 0 to all port
    ADCON1=0x07;                              //make portA pins digital I/O

    while(1)                                           //for repeating code infinitely 
    {
        PORTA=0x00;
        __delay_ms(1000);                      //delay of 1ms
        PORTA=0xFF;
        __delay_ms(1000);
    }
    return;
}
