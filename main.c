#include <msp430.h> 


/*main.c single blink

int main()
{
//configure
WDTCTL = WDTPW | WDTHOLD; //turns off watchdog
P1SEL &= ~BIT0; //sets p1.0 as gpio
P1SEL2 &= ~BIT0; //
P1DIR |= BIT0; //sets p1.0 as an output

while(1)
{
P1OUT ^= BIT0;
__delay_cycles(100000);
}
return 0;
}
*/
/**
 * main.c multiblink
 *
int main()
{
//configure
WDTCTL = WDTPW | WDTHOLD; //turns off watchdog
volatile unsigned int count; //big counter for the delay
P1SEL &= ~(BIT0 | BIT6); //
P1SEL2 &= ~(BIT0 | BIT6); //
P1DIR |= (BIT0 | BIT6); //

while(1)
{
P1OUT ^= (BIT0 | BIT6);
__delay_cycles(200000); //delay
//for( count = 0 ; count < 10000 ; count++ ); //delay

}
return 0;
}
*/
/**
 * main.c buttonblink
 */
int main()
{
//configure
WDTCTL = WDTPW | WDTHOLD; //turns off watchdog
volatile unsigned int count; //big counter for the delay
P1SEL &= ~(BIT0 | BIT6 | BIT3); //sets bits 0 3 6 as gpio
P1SEL2 &= ~(BIT0 | BIT6 | BIT3); //
P1DIR |= (BIT0 | BIT6); // sets 0 6 as outputs
P1DIR &= (~BIT3); //sets 3 as input

while(1)
{
if(P1IN & BIT3)
    P1OUT ^= (BIT0 | BIT6);
__delay_cycles(200000); //delay
//for( count = 0 ; count < 10000 ; count++ ); //delay

}
return 0;
}
