/*
 * DIO_LAB_01.c
 *
 * Created: 6/17/2022 1:16:06 PM
 * Author : Khalid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY 500

int main(void)
{
    DDRC	= 0b10000100;
	DDRD	= 0b00001000;
	PORTC	= 0b10000100;
	PORTD	= 0b00001000;
	_delay_ms(5000);
	
    while (1) 
    {
		PORTC	= 0b00000100;
		PORTD	= 0b00000000;
		_delay_ms(DELAY);
		PORTC	= 0b10000000;
		_delay_ms(DELAY);
		PORTC	= 0b00000000;
		PORTD	= 0b00001000;
		_delay_ms(DELAY);
		
    }
}

