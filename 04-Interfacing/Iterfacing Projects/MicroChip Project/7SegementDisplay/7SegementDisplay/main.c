/*
 * 7SegementDisplay.c
 *
 * Created: 6/17/2022 2:34:22 PM
 * Author : Khalid Sharaf El-Din
 */ 

#include <avr/io.h>
#define F_CPU	16000000UL
#include <util/delay.h>


int main(void)
{
	DDRA	= 0b11110000;				// Set PA4-PA7 As OUTPUT, A B C D on the Seven Segment Module
	DDRB	= 0b00001110;				// Set PB1-PB3 As OUTPUT, EN_2 EN_1 DP
	PORTB	= 0b00000010;				// Set PB1 to HIGH, Enable the first 7Segment.
    while (1) 
    {
		// For loop to go from 0 to 9 
		for(int i =0; i<10; i++){
			PORTA = (i << 4);				// Shifting the index by 4 place to write to the upper 4 bytes 
											//Ex: i=5 (0000 0101) >> (0101 0000)
			_delay_ms(500);					
		}
		
    }
}

