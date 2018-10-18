/**
 * main.c buttonblink
 */
int main()
{
//configure
WDTCTL = WDTPW | WDTHOLD; //turns off watchdog
P1SEL &= ~(BIT0 | BIT3); //sets bits 0 3 as gpio
P1SEL2 &= ~(BIT0 | BIT3); //
P1DIR |= (BIT0); // sets 0 as outputs
P1DIR &= (~BIT3); //sets 3 as input

while(1)
{
if(P1IN & BIT3)
    P1OUT ^= (BIT0); //flips p1.0 state when the button is pressed
}
return 0;
}
