/*
 * 8BitNumberOnLEDs.c
 *
 * Created: 6/21/2022 1:19:31 PM
 * Author : Khalid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
    DDRC = 0xFF;
	PORTC = 0x00;
    while (1) 
    {
		for(int i =0; i < 256; i++){
			PORTC = i;
			_delay_ms(20);
		}
    }
	
	return 0;
}

