/*
 * LEDOneDir.c
 *
 * Created: 6/21/2022 1:54:38 PM
 * Author : Khalid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY 100


int main(void)
{
    DDRC = 0xFF;	DDRD = 0xFF;	// Set PORTC & PORTD as OUTPUT
	PORTC = 0x00;	PORTD = 0x00;	// Init PORTC & PORTD to LOW
    while (1) 
    {
		PORTC = 1;					// First LED in PORTC and Wait 
		for(int i= 0; i <8; i++){	// Shift the ONE through the register
			_delay_ms(DELAY	);
			PORTC = PORTC << 1;		// to light every led in PORTC in sequence
		}
		PORTD = 1;					// The same thing but for PORTD
		for(int i= 0; i <8; i++){
			_delay_ms(DELAY);
			PORTD = PORTD << 1;
		}
		
    }
	
	return 0;
}

