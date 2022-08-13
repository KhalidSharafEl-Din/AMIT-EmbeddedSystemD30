/*
 * TraficLight-Emergency.c
 *
 * Created: 6/21/2022 3:28:54 PM
 * Author : Khalid
 */ 
 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define DELAY 100

int emergency = 0;

ISR (INT1_vect){
	emergency =1;
}

int main(void)
{
    DDRC	= 0b00001111;		// 7Seg Pins as OUTPUT
	DDRD	= 0b00000111;		// LED Pins as OUTPUT
	PORTC	= 0x00;	
	PORTD	= 0b0001000;		// Setting the LEDs To LOW and the Button To PULLUP	
	
	GICR =0x80;					// Enable External interrupt INT1
	MCUCR =0x08;				// INT1 Falling Edge interrupt
	sei();						// Enable Global interrupts
	_delay_ms(DELAY);
    while (1) 
    {
		PORTD |= (1 << 0); 	PORTD &= ~(1 << 2);					// RED LED ON
		for(int i=0; i<10; i++){
			if(emergency !=0) {break;}							
			PORTC = i; _delay_ms(DELAY);
			}	// Count 10 Seconds
		
		PORTD |= (1 << 1); 	PORTD &= ~(1 << 0);				  // YELLOW LED ON
		for(int i=0; i<3; i++){
			if(emergency != 0) {break;}
			PORTC = i; _delay_ms(DELAY);
			}	// Count 3 Seconds
		
		PORTD |= (1 << 2); 	PORTD &= ~(1 << 1);				    // GREEN LED ON
		for(int i=0; i <10; i++){PORTC = i; _delay_ms(DELAY);}	// Count 10 Seconds
		emergency=0;
		
	}
	return 0;
}

