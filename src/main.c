#include <reg51.h>
#include <string.h>
#include "global.h"
#include "delay.h"
#include "lcd.h"
#include "mkeys.h"
#include "uart.h"

// Port 3 I/Os
sbit SW_PIN = P3^2;   // switch (active-low, internal pull-up)
sbit LED    = P3^3;   // LED (active-low)
sbit RELAY  = P3^4;   // relay (active-low)
sbit BUZ    = P3^6;   // buzzer (active-low)

#define MODE_UART   0
#define MODE_KEYPAD 1
#define MODE_SWITCH 2

volatile char uart_rx_char = 0;
volatile bit  uart_flag    = 0;

// Two-line LCD updater
void lcd_update(unsigned char mode, const char* line2) {
    Init_LCD();
    switch (mode) {
        case MODE_UART:   Set_LCD_string("UART MODE");   break;
        case MODE_KEYPAD: Set_LCD_string("KEYPAD MODE"); break;
        case MODE_SWITCH: Set_LCD_string("SWITCH MODE"); break;
        default:          Set_LCD_string("----- MODE");  break;
    }
    Set_LCD_Command(0xC0);
    Set_LCD_string(line2);
}

// UART receive ISR
void uart_isr(void) interrupt 4 {
    if (RI) {
        uart_rx_char = SBUF;
        uart_flag = 1;
        RI = 0;
    }
}

void main(void) {
    char key;
    unsigned char mode;
    char msg[17];

    // — Init UART & Keypad & LCD —
    Config_UART();                   
    Set_UART_String("UART Initialized\r\n");
    Init_LCD();
    Config_mkeys();

    // — Init Port 3 pins —
    SW_PIN = 1;   // switch pull-up
    LED    = 0;   // LED off
    RELAY  = 1;   // relay off
    BUZ    = 1;   // buzzer off

    // — Initial display —
    //lcd_update(MODE_UART, "Press any key");

    while (1) {
        // — 1) KEYPAD (always runs) —
        key = get_key();
        if (key) {
            mode = MODE_KEYPAD;
            switch (key) {
                case '1': RELAY = 0;  strcpy(msg, "KEY:1 Motor ON");   break;
                case '2': RELAY = 1;  strcpy(msg, "KEY:2 Motor OFF");  break;
                case '3': BUZ   = 0;  strcpy(msg, "KEY:3 Buzzer ON");  break;
                case '4': BUZ   = 1;  strcpy(msg, "KEY:4 Buzzer OFF"); break;
                default:  strcpy(msg, "KEY:? Unknown");               break;
            }
            lcd_update(mode, msg);
        }

        // — 2) UART (always runs) —
        if (uart_flag) {
            uart_flag = 0;
            key = uart_rx_char;
            mode = MODE_UART;
            switch (key) {
                case 'M': RELAY = 0;  strcpy(msg, "UART:M Motor ON");   break;
                case 'm': RELAY = 1;  strcpy(msg, "UART:m Motor OFF");  break;
                case 'B': BUZ   = 0;  strcpy(msg, "UART:B Buzzer ON");  break;
                case 'b': BUZ   = 1;  strcpy(msg, "UART:b Buzzer OFF"); break;
                default:  strcpy(msg, "UART:? Unknown");               break;
            }
            lcd_update(mode, msg);
        }

        // — 3) SWITCH (only when pressed) —
        if (!SW_PIN) {
            mode = MODE_SWITCH;
            LED = 0;  // LED ON
            lcd_update(mode, "SWITCH PRESSED");

            // Wait here until release:
            while (!SW_PIN);
            delay(20);  // debounce

            LED = 1;  // LED OFF
            lcd_update(mode, "SWITCH RELEASED");
        }

        // loop back immediately — keypad/UART can fire again
    }
}
