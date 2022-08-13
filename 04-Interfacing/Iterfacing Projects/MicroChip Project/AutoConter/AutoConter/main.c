/*
 * AutoConter.c
 *
 * Created: 6/21/2022 4:38:19 PM
 * Author : Khalid
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define DELAY 100

int num = 0;

int main(void)
{
    DDRC	= 0b01111111;		// 7Seg Pins as OUTPUT
	DDRD	= 0b00000011;		// Enable Pins as OUTPUT
	
	int arr[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F};
	_delay_ms(DELAY);
    while (1) 
    {
		PORTD = 0b00000001;
		PORTC = arr[(num%10)];	// Write the Ones on the first 7Seg
		_delay_ms(50);
		PORTD = 0b00000010;			// Write the Tens on the second 7Seg
		PORTC = arr[(num/10)];
		_delay_ms(50);				// This Delay is set to reduce the interference between them
		
		num++;
		if(num > 99) num=0;
	}
}
	

