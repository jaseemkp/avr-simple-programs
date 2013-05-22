#define F_CPU 12000000UL         /* 12 MHz crystal clock */

#include <avr/io.h> 
#define LED_1ON 0x01
#define LED_1OFF 0x11
#define LED_2ON 0x02
#define LED_2OFF 0x1A
#define LED_3ON 0x03
#define LED_3OFF 0x1B
#define LED_4ON 0x04
#define LED_4OFF 0x1C
/**
 *  Initialize the AVR USART
 *
 *  Uses macro helpers for baud rate calculation from
 *  http://www.nongnu.org/avr-libc/user-manual/group__util__setbaud.html
 *  Make sure define BAUD matches baud rate specified in hello.py
 *
 *  The USART frame is not set because the default 8n1 is what we want.
 */
static void USART_init() 
{
    #undef BAUD  
    #define BAUD 9600               
    #include <util/setbaud.h>

    UBRRH = UBRRH_VALUE;
    UBRRL = UBRRL_VALUE;
    #if USE_2X
    UCSRA |= (1 << U2X);
    #else
    UCSRA &= ~(1 << U2X);
    #endif

    /* enable rx and tx */
    UCSRB = (1<<RXEN) | (1<<TXEN);
}

/**
 *  Get a byte from the USART (rx)
 */
uint8_t USART_get_char()
{
    while(!(UCSRA & (1<<RXC))) 
        ;
    
    return UDR;
}


int main (void)
{
    uint8_t command;
    
    USART_init();
    DDRC = 0xFF;
    
    while (1)   /* infinite loop */           
    {
        command = USART_get_char();

        if (command == LED_1ON)
        {
           PORTC |= _BV(PC2); 
        }  
        else if(command == LED_1OFF)
        {
           PORTC &= ~_BV(PC2);
        }
        if(command == LED_2ON)
        {
           PORTC |= _BV(PC3);
        }
        else if(command == LED_2OFF)
        {
           PORTC &= ~_BV(PC3); 
        }
        if (command == LED_3ON)
        {
           PORTC |= _BV(PC4);
        }
        else if (command == LED_3OFF)
        {
           PORTC &= ~_BV(PC4);
        }
        if (command == LED_4ON)
        {
           PORTC |= _BV(PC1);
        }
        else if (command == LED_4OFF)
        {
           PORTC &= ~_BV(PC1);
        }
        
        
}
return(0);
}
