#include "GPIO_Header_File.h"
#include "UART_Header_File.h"
#include "Timer_Header_File.h"

void SystemInit(){}
void Delay(unsigned long counter); // used to add delay
void HC05_init(void); // Initialize UART5 module for HC-05
char Bluetooth_Read(void); //Read data from Rx5 pin of TM4C123
void Bluetooth_Write(unsigned char data); // Transmit a character to HC-05 over Tx5 pin 
void Bluetooth_Write_String(char *str); // Transmit a string to HC-05 over Tx5 pin 
void Init_GPIO(void);
void Timer1A_Init(void);
void car(void);
void Forward(void);
void Backward(void);
void Right(void);
void Left(void);
void Move_Faster(void);
void Go_Slower(void);
void Stop(void);
int main(void)
{
	Timer1A_Init();  
	HC05_init(); // call HC05_init() to initialze UART5 of TM4C123GH6PM
	Init_GPIO();
	Delay(10);  
	while(1)
	{
		char c = Bluetooth_Read();          /* get a character from UART5 */
		
/* Check the received character and take action to control onboard LEDs of TM4C123 */
/* Send status string to Andriod app after turning on/off LEDs */
		if( c=='f'|| c=='F'){
			Forward();
		}
		
		 else if( c=='B'||c=='b'){
			Backward();
		}
		 else if( c=='R'||c=='r'){
		  Right();
}
		else if (c=='L'||c=='l'){
			Left();
		}
			
     else if (c =='S'||c=='s'){
			 Stop();
					} 
		else if(c=='M'||c=='m')
		{
		 Move_Faster();	
    }
		else if(c=='G'||c=='g')
		{
			Go_Slower();
    }
}
}

void HC05_init(void)
{
		SYSCTL_RCGCUART_R |= 0x20;  /* enable clock to UART5 */
    SYSCTL_RCGC_GPIO_R |= 0x10;  /* enable clock to PORTE for PE4/Rx and RE5/Tx */
    Delay(10);
    /* UART0 initialization */
    UART5_CTL_R = 0;         /* UART5 module disbable */
    UART5_IBRD_R = 104;      /* for 9600 baud rate, integer = 104 */
    UART5_FBRD_R = 11;       /* for 9600 baud rate, fractional = 11*/
    UART5_CC_R = 0;          /*select system clock*/
    UART5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */

    /* UART5 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    GPIO_PORTE_DEN_R = 0x30;      /* set PE4 and PE5 as digital */
    GPIO_PORTE_AFSEL_R = 0x30;    /* Use PE4,PE5 alternate function */
    GPIO_PORTE_AMSEL_R = 0;    /* Turn off analg function*/
    GPIO_PORTE_PCTL_R= 0x00110000;     /* configure PE4 and PE5 for UART */
}
char Bluetooth_Read(void)  
{
    char data;
	  while((UART5_FR_R  & (1<<4)) != 0); /* wait until Rx buffer is not full */
    data = UART5_DR_R ;  	/* before giving it another byte */
    return (unsigned char) data; 
}

void Bluetooth_Write(unsigned char data)  
{
    while((UART5_FR_R & (1<<5)) != 0); /* wait until Tx buffer not full */
    UART5_DR_R = data;                  /* before giving it another byte */
}

void Bluetooth_Write_String(char *str)
{
  while(*str)
	{
		Bluetooth_Write(*(str++));
	}
}
void Init_GPIO(void)
{
	  SYSCTL_RCGC_GPIO_R |= 0x21;   /* enable clock to GPIOA and F*/
    GPIO_PORTA_DIR_R |= 0x5C;         //set PA2,PA3 , PA4 And PA6 as digital output pin
    GPIO_PORTA_DEN_R |= 0x5C;         // CON PA2,PA3 ,PA4 And PA6 as digital GPIO pins
    GPIO_PORTF_DEN_R |= 0x0E;         //ENABLE Port F pins for LED configuration as OUTPUT
    GPIO_PORTF_DIR_R |= 0x0E;         //set Port F pins for LED configuration as OUTPUT
    
}
// Timer and GPIO intialization and configuration
void Timer1A_Init(void)
{		
  // Enable the clock for portB and Timer1
    RCGC2_GPIO_R |= CLOCK_GPIOB;
	RCGC_TIMER_R |= 0x01; 
	
	// Configure PORTB pin 6 as Timer0 A output
	GPIO_PORTB_AFSEL_R |= 0x00000040;
    GPIO_PORTB_PCTL_R  |= 0x07000000;  // Configure as timer CCP0 pin
	GPIO_PORTB_DEN_R   |= 0x00000040;
	
	// Enable the clock for Timer 1 
	GPTM_CONTROL_R &= ~(TIM_A_ENABLE);		// disable timer 0 A
	
	// Timer0 A configured as 16-bit timer
	GPTM_CONFIG_R |= TIM_16_BIT_CONFIG;		
	
	// Timer0 A in periodic timer, edge count and PWM mode
	GPTM_TA_MODE_R |= TIM_PWM_MODE;
    GPTM_TA_MODE_R &= ~(TIM_CAPTURE_MODE);	
	
	// Make PWM frequency 1 kHz using reload value of 16000
	GPTM_TA_IL_R = TIM_A_INTERVAL;  
	
	// Configure PWM duty cycle value (should be less than 16000)
	GPTM_TA_MATCH_R = TIM_A_MATCH;	
	
	// Enable timer0 A	
	GPTM_CONTROL_R |= TIM_A_ENABLE;				
}

void Forward(void)
{
	    Delay(10000);				  
	    GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
	    Delay(10000);				  
	    GPIO_PORTF_DATA_R &=(0x00);
			Bluetooth_Write_String("Car Move Forward\n");
			{
			GPIO_PORTA_DATA_R |=((1<<3) | (1<<4));
	    GPIO_PORTF_DATA_R|=0x08;
				
			}
}
void Backward(void)
{

	    Delay(10000);				  
	    GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
	    Delay(10000);				  
	    GPIO_PORTF_DATA_R &=(0x00);
	    GPIO_PORTA_DATA_R |= ((1<<2)| (1<<6));
	    Bluetooth_Write_String("Car Moves Back\n");
	    GPIO_PORTF_DATA_R|=0x02;
}
void Right(void)
{
	      Delay(10000);				  
	      GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
        Delay(10000);				  
				GPIO_PORTF_DATA_R &=(0x00);
				GPIO_PORTA_DATA_R |=(1<<3);
        Delay(2500000);			  
				GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
				Delay(1000000);
				GPIO_PORTA_DATA_R =((1<<3) | (1<<4));
				Bluetooth_Write_String("BLUE LED OFF\n");
        GPIO_PORTF_DATA_R|=0x06;
}
void Left(void)
{
	      Delay(10000);				  
	      GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
        Delay(10000);				    
	      GPIO_PORTF_DATA_R &=(0x00);
				GPIO_PORTA_DATA_R |=(1<<4);
        Delay(2500000);				  
				GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
				Delay(1000000);
				GPIO_PORTA_DATA_R =((1<<3) | (1<<4));
				Bluetooth_Write_String("BLUE LED OFF\n");
        GPIO_PORTF_DATA_R|=0x0E;
}
void Move_Faster(void)
{
	    Delay(10000);				  
	    GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
      Delay(10000);				  
	    GPIO_PORTF_DATA_R &=(0x00);
			Bluetooth_Write_String("Car Moves Faster\n");
			{
			GPTM_TA_MATCH_R =25;
			GPIO_PORTA_DATA_R |=(0x18);
			GPIO_PORTF_DATA_R|=0x0C;
			
      }
}
void Go_Slower(void)
{
	    Delay(10000);				  
	    GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
      Delay(10000);				  
	    GPIO_PORTF_DATA_R &=(0x00);
			Bluetooth_Write_String("Car Moves Slower\n");
			{
			GPIO_PORTA_DATA_R |=(0x18);
			GPTM_TA_MATCH_R =7000;
			GPIO_PORTF_DATA_R|=0x0A;
      }
}
void Stop(void)
{
		    Delay(10000);				  
	      GPIO_PORTA_DATA_R &=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
        Delay(10000);				  
	      GPIO_PORTF_DATA_R &=(0x00);
	      GPIO_PORTA_DATA_R&=~((1<<2)| (1<<3) | (1<<4) | (1<<6));
	      Bluetooth_Write_String("Car Stops Completely\n");

}
void Delay(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter; i++);
}
