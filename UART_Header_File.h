// UART registers (UART5)
//*****************************************************************************
#define UART5_DR_R              (*((volatile unsigned long *)0x40011000))  //UART Data Register
#define UART5_FR_R              (*((volatile unsigned long *)0x40011018))  //
#define UART5_IBRD_R            (*((volatile unsigned long *)0x40011024))  //
#define UART5_FBRD_R            (*((volatile unsigned long *)0x40011028)) //
#define UART5_LCRH_R            (*((volatile unsigned long *)0x4001102C)) //
#define UART5_CTL_R             (*((volatile unsigned long *)0x40011030))//
#define UART5_CC_R              (*((volatile unsigned long *)0x40011FC8))//

