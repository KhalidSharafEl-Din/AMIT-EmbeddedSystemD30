/*
 * LEDSeq_1.c
 *
 * Created: 6/17/2022 5:34:55 PM
 * Author : Khalid
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY 500

int main(void)
{
    DDRC	= 0b10000100;			// Set LED_0 and LED_1 as OUTPUT
	DDRD	= 0b00001000;			// Set LED_2 as OUTPUT
	
    while (1) 
    {
		PORTC	= 0b00000100;		// ON:LED_0  OFF: LED_1 LED_2  >>>> 001
		PORTD	= 0b00000000;
		_delay_ms(DELAY);
		PORTC	= 0b10000000;		// ON:LED_1  OFF: LED_0 LED_2  >>>> 010
		_delay_ms(DELAY);
		PORTC	= 0b00000000;		// ON:LED_2  OFF: LED_0 LED_1  >>>> 100
		PORTD	= 0b00001000;
		_delay_ms(DELAY);
		PORTC	= 0b10000000;		// ON:LED_1  OFF: LED_0 LED_2  >>>> 010
		PORTD	= 0b00000000;
		_delay_ms(DELAY);
		
    }
}


