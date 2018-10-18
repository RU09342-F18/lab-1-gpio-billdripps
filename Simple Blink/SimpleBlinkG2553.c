/**
 * main.c simple blink
 */
int main()
{
//configure
WDTCTL = WDTPW | WDTHOLD; //turns off watchdog
P1SEL &= ~(BIT0); //sets bits 0 as gpio
P1SEL2 &= ~(BIT0); //
P1DIR |= (BIT0); // sets 0 as output


while(1)
{
    P1OUT ^= (BIT0);
    __delay_cycles(200000); //delay
}
return 0;
}
