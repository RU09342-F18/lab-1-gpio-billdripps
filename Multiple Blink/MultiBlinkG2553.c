/**
 * main.c multiblink
 */
int main()
{
//configure
WDTCTL = WDTPW | WDTHOLD; //turns off watchdog
P1SEL &= ~(BIT0 | BIT6); //sets bits 0 6 as gpio
P1SEL2 &= ~(BIT0 | BIT6); //
P1DIR |= (BIT0 | BIT6); // sets 0 6 as outputs


while(1)
{
if(P1IN & BIT3)
    P1OUT ^= (BIT0 | BIT6);
    __delay_cycles(200000); //delay
    P1OUT ^= (BIT6);
    __delay_cycles(100000); //delay
}
return 0;
}
