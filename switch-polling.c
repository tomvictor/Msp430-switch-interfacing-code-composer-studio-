// Author : Tomvictor
//Email   : vjtomvictor@gmail.com
//Website : www.buildfromzero.com
//git     : github.com/Tomvictor

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0xff;                            // seting all pins to output direction
  P1OUT = 0x00;                             // seting all pins as active low
  P1REN = 0X00;                             // enables the pull up/pull down functionality(only for i/p pins)
  P1DIR |= BIT0;                            // Set  P1.0 to output direction
  P1DIR &= ~ BIT3;							            // set p1.3 as input ( connect to switch)
  P1REN |= BIT3;                            // pull up/pull down function enabled for pin1.3
  P1OUT |=BIT3;                             // pull up p1.3, there by eliminating the need for external pull up resistor for switch
  while (1)                                 // infinite loop
  {
    if (BIT3 & P1IN)                        // checking p1.3
    	P1OUT &= ~BIT0;                      // if P1.3 not set, p1.3 = 0 (bitwise operator)
    else
    P1OUT |= BIT0;                        // else P1.3  set, p1.3 = 1
  }
}
