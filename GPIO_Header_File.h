#define	SYSCTL_RCGCUART_R 				(*((volatile unsigned long*) 0x400FE618 ))  //UART Clock 5.4(pg # 234)
#define	SYSCTL_RCGC_GPIO_R 					(*((volatile unsigned long*) 0x400FE608 ))

//*****************************************************************************

//PORT-F Configuration
#define 	GPIO_PORTF_DATA_R			(*((volatile unsigned long*)0x400253FC))
#define 	GPIO_PORTF_DIR_R			(*((volatile unsigned long*)0x40025400))
#define 	GPIO_PORTF_DEN_R			(*((volatile unsigned long*)0x4002551C))
//PORT-A Configuration 
#define 	GPIO_PORTA_DATA_R			(*((volatile unsigned long*)0x400043FC))
#define 	GPIO_PORTA_DIR_R			(*((volatile unsigned long*)0x40004400))
#define 	GPIO_PORTA_DEN_R			(*((volatile unsigned long*)0x4000451C))
//PORT-E Configuration
#define 	GPIO_PORTE_DATA_R			(*((volatile unsigned long*)0x400243FC))
#define 	GPIO_PORTE_DEN_R			(*((volatile unsigned long*)0x4002451C))
#define 	GPIO_PORTE_AMSEL_R		(*((volatile unsigned long*)0x40024528))
#define 	GPIO_PORTE_PCTL_R			(*((volatile unsigned long*)0x4002452C))
#define 	GPIO_PORTE_AFSEL_R		(*((volatile unsigned long*)0x40024420))

