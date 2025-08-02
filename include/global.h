#ifndef global_h_
#define global_h_

#define Set_Bit(reg,bpos) reg|=(1<<bpos)
#define Clr_Bit(reg,bpos) reg&=~(1<<bpos)                                                                                                     

#define Is_Bit_Set(reg,bpos) reg&(1<<bpos)
#define Is_Bit_Clr(reg,bpos) !(reg&(1<<bpos))

#define TRUE 1
#define FALSE 0

typedef unsigned char u8_t;
typedef signed char s8_t;
typedef unsigned int u16_t;
typedef signed int s16_t;
typedef unsigned long int u32_t;
typedef unsigned char bool_t;

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7
#endif





