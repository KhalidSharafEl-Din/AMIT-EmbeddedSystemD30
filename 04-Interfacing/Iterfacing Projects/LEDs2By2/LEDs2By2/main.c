/*
 * LEDs2By2.c
 *
 * Created: 6/21/2022 2:51:01 PM
 * Author : Khalid
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY 250


int main(void)
{
    DDRC = 0xFF;	DDRD = 0xFF;	// Set PORTC & PORTD as OUTPUT
	PORTC = 0x00;	PORTD = 0x00;	// Init PORTC & PORTD to LOW
    while (1) 
    {
		//Close the Curtain
		for(int i =0; i<8; i+=2){			
			PORTD |= (128 >> i);
			PORTD |= (128 >> (i+1));
			PORTC |= (1 << i);
			PORTC |= (1 << (i+1));
			_delay_ms(DELAY);
		}
		
		//Open the Curtain
		for(int i =0; i<8; i+=2){
			PORTD &= ~(1 << i);
			PORTD &= ~(1 << (i+1));
			PORTC &= ~(128 >> i);
			PORTC &= ~(128 >> (i+1));
			_delay_ms(DELAY);
		}
		
	}
	return 0;
}

