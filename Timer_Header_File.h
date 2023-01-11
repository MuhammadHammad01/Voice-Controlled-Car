#define TM_BASE   0x40030000

// Peripheral clock enabling for timer and GPIO  
#define RCGC_TIMER_R         *(volatile unsigned long *)0x400FE604
#define RCGC2_GPIO_R         *(volatile unsigned long *)0x400FE108
#define CLOCK_GPIOB          0x00000002    //PortB clock control
#define SYS_CLOCK_FREQUENCY  16000000 

// General purpose timer register definitions
#define GPTM_CONFIG_R          *(volatile long *)(TM_BASE + 0x000)
#define GPTM_TA_MODE_R         *(volatile long *)(TM_BASE + 0x004)
#define GPTM_CONTROL_R         *(volatile long *)(TM_BASE + 0x00C)
#define GPTM_INT_MASK_R        *(volatile long *)(TM_BASE + 0x018)
#define GPTM_INT_CLEAR_R       *(volatile long *)(TM_BASE + 0x024)
#define GPTM_TA_IL_R           *(volatile long *)(TM_BASE + 0x028)
#define GPTM_TA_MATCH_R        *(volatile long *)(TM_BASE + 0x030)

// GPIO PB6 alternate function configuration
#define GPIO_PORTB_AFSEL_R *((volatile unsigned long *)0x40005420)
#define GPIO_PORTB_PCTL_R  *((volatile unsigned long *)0x4000552C)
#define GPIO_PORTB_DEN_R   *((volatile unsigned long *)0x4000551C)

// Timer config and mode bit field definitions  
#define TIM_16_BIT_CONFIG   0x00000004  // 16-bit timer 
#define TIM_PERIODIC_MODE   0x00000002  // Periodic timer mode
#define TIM_A_ENABLE        0x00000001  // Timer A enable control

#define TIM_PWM_MODE        0x0000000A  // Timer in PWM mode 
#define TIM_CAPTURE_MODE    0x00000004  // Timer capture mode


// Timer1 A reload value for 1 kHz PWM frequency
#define TIM_A_INTERVAL      16000    // Timer reload value for
                                     // 1 kHz PWM frequency at
																		 // clock frequency of 16MHz
																		 // 16,000,000/16000 
																		 // = 1 kHz
#define TIM_A_MATCH         4000     // Timer match value for 75%
                                     // duty cycle
