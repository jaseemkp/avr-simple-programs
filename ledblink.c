/* An LED blinking program */
#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>



void sleep(uint8_t msec)
{  while(msec)
  {
    _delay_ms(1); /* ms delay */
    msec--;
  } 
}

main()
{
   DDRD |= (1<<PD7) | (1<<PD6);
   while(1)
   {
    PORTD &= ~(1<<PD7) & ~(1<<PD6) ; /* PD7 LOW */
    sleep(50);
    
    PORTD |=(1<<PD7) | (1<<PD6); /* PD7 HIGH */
    sleep(50); /*100 ms delay */
   }

}


