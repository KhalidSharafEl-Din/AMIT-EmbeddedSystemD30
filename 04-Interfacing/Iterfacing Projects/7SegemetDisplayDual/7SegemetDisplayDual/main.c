/*
 * 7SegemetDisplayDual.c
 *
 * Created: 6/17/2022 3:40:32 PM
 * Author : Khalid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int num = 0;

ISR (TIMER1_OVF_vect)		// Timer1 ISR
{
	num++;
	if(num > 99) num=0;		// Increment the number 
	TCNT1 = 57723;			// for 0.5 sec at 16 MHz >> TCNT1 = 65536 -(Delay_Seconds * F_CPU)/ scaler
}

int main(void)
{
	DDRA  = 0b11110000;					// Set PA4-PA7 As OUTPUT, A B C D on the Seven Segment Module
	DDRB  = 0b00001110;					// Set PB1-PB3 As OUTPUT, EN_2 EN_1 DP

	TCNT1 = 57723;						// for 0.5 sec at 16 MHz
	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);;	// Timer mode with 1024 pre-scaler
	TIMSK = (1 << TOIE1) ;				// Enable timer1 overflow interrupt(TOIE1)
	sei();								// Enable global interrupts by setting global interrupt enable bit in SREG
    
	
    while (1) 
    {
			PORTB = 0b00000010;
			PORTA = ((num%10) << 4);	// Write the Ones on the first 7Seg
			_delay_ms(10);
			PORTB = 0b00000100;			// Write the Tens on the second 7Seg
			PORTA = ((num/10) << 4);	
			_delay_ms(10);				// This Delay is set to reduce the interference between them 
	}

}


