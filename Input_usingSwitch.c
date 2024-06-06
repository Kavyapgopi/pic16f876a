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
    TRISA =0x0F;                                   //Make PortA put using data direction register
    TRISB =0x00;                                   //Make PortB output using data direction register
    ADCON1=0x07;                              //make portA pins digital I/O
    PORTB=0x00;                                  //write 0 to all port
    while(1)                                           //for repeating code infinitely 
    {   
        PORTB=0x00;                              //making port low when unused time
        if(RA0==0)                                  //pull up resistor is connected so if switch is closed pin value become zero
        {
             PORTB=0x01;                         //PORTB moving downward when switch connected in RA0 is closed
             for(i=0;i<8;i++)
             {
                  __delay_ms(100);                      //delay of 1ms
                   PORTB=PORTB<<1;
            }
         
            
        }
         if(RA1==1)                                  //pull down resistor is connected so if switch is closed pin value become high
        {
            PORTB=0x80;                           //PORTB moving upward when switch connected in RA1 is closed
            for(i=8;i>0;i--)
            {
                  __delay_ms(100);                      //delay of 1ms
                  PORTB=PORTB>>1;
            }
         }
    }
}