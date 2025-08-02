#include <reg51.h>
#include <global.h>
#include "uart.h"

volatile unsigned char rx_char = 0;
bit rx_flag = 0;

void Config_UART(void) 
{
    TMOD = 0x20;    // Timer1 in Mode 2 (8-bit auto-reload)
    TH1 = 0xFD;      // Baud rate 115200 for 11.0592 MHz
    SCON = 0x50;     // UART Mode 1: 8-bit, REN enabled
    TR1 = 1;         // Start Timer1
    // ES = 1;          // Enable UART interrupt
    // EA = 1;          // Enable global interrupt
}

void Set_UART_Data(unsigned char Dat) 
{
    SBUF = Dat;
    while (TI==0);  //wait for data transmit
    TI = 0; //Ready to send next data

}

void Set_UART_String(unsigned char* str)
{
    while(*str != '\0')
    {
        Set_UART_Data(*str);
        str++;
    }
}

/*
void char Get_UART_Data()
{
    unsigned char RawData = 0;
    while(RI==1)
    {
        RawData = SBUF;
        RI=0;
        return RawData;
    }
}
*/


