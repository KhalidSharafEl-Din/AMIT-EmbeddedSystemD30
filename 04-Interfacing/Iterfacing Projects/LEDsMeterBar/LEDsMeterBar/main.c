/*
 * LEDsMeterBar.c
 *
 * Created: 6/21/2022 2:33:09 PM
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
		// Light LEDs in one Direction 
		for(int i =0; i<8; i++){			// PORTD
			PORTD |= (128 >> i);
			_delay_ms(DELAY);
		}
		for(int i =0; i<8; i++){			// PORTC
			PORTC |= (128 >> i);
			_delay_ms(DELAY);
		}
		// Die Down
		for(int i =0; i<8; i++){			// PORTC 
			PORTC &= ~( 1 << i);
			_delay_ms(DELAY);
		}
		for(int i =0; i<8; i++){			// PORTD
			PORTD &= ~( 1 << i);
			_delay_ms(DELAY);
		}
    }
	
	return 0;
}

