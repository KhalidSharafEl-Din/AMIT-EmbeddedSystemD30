/*
 * TrafficLight.c
 *
 * Created: 6/21/2022 3:03:11 PM
 * Author : Khalid
 */ 
 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY 500


int main(void)
{
    DDRC = 0b00001111;		// 7Seg Pins as OUTPUT
	DDRD = 0b00000111;		// LED Pins as OUTPUT
	PORTC = 0x00;	
	PORTD = 0x00;	
    while (1) 
    {
		PORTD = 0b00000001;						// RED LED ON
		for(int i=0; i<10; i++){PORTC = i; _delay_ms(DELAY);}	// Count 10 Seconds
		
		PORTD = 0b00000010;						// YELLOW LED ON
		for(int i=0; i<3; i++){PORTC = i; _delay_ms(DELAY);}	// Count 3 Seconds
		
		PORTD = 0b00000100;						// GREEN LED ON
		for(int i=0; i <10; i++){PORTC = i; _delay_ms(DELAY);}	// Count 10 Seconds
		
	}
	return 0;
}

