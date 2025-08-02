#include "global.h"
#include <reg51.h>
#include "delay.h"
#include "lcd.h"

#define LCD_PORT P2
#define Set_LCD_Command_mode()  Clr_Bit(P3, BIT5)
#define Set_LCD_Data_mode()     Set_Bit(P3, BIT5)

static void Set_LCD_Clock(void)
{ 
    Clr_Bit(P3, BIT7);
    delay(1000);
    Set_Bit(P3, BIT7);
}

static void Write_LCD_PORT(unsigned char value)
{
    LCD_PORT = value;
}

void Set_LCD_Command(unsigned char command)
{
    Write_LCD_PORT(command);
    Set_LCD_Command_mode();
    Set_LCD_Clock();
}

void Set_LCD_Char(unsigned char character)
{
    Write_LCD_PORT(character);
    Set_LCD_Data_mode();
    Set_LCD_Clock();
}

void Set_LCD_string(const char *str)
{
    while (*str != '\0') {
        Set_LCD_Char(*str);
        str++;
    }
}

void Init_LCD(void)
{
    Set_LCD_Command(0x38);  // Function set: 8-bit, 2 line, 5x8 dots
    Set_LCD_Command(0x0E);  // Display on, cursor on
    Set_LCD_Command(0x06);  // Entry mode: increment
}
