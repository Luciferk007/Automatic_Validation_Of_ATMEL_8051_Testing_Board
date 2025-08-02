#ifndef _LCD_H_
#define _LCD_H_

// Initialize the LCD in 4-bit mode
void Init_LCD(void);

// Send a command byte (e.g. cursor move, clear screen)
void Set_LCD_Command(unsigned char cmd);

// Write a single character to the display
void Set_LCD_Char(unsigned char c);

// Write a null-terminated C-string to the display
void Set_LCD_string(const char *str);

#endif // _LCD_H_
