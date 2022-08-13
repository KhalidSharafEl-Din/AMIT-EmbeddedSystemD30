/*
 * DigitalCounter.c
 *
 * Created: 6/21/2022 5:32:08 PM
 * Author : Khalid
 */ 
 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY 100

#define CHECK_BIT(Var, BitNo) ( 1  &  (Var >> BitNo))

int num = 55;

int main(void)
{
    DDRC	= 0b01111111;		// 7Seg Pins as OUTPUT
	DDRD	= 0b00000011;		// Enable Pins as OUTPUT
	PORTD	= 0b00011100;		// Setting 3 Buttons as PULLUP
	int arr[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F};
	_delay_ms(DELAY);
    while (1) 
    {
		PORTD |= (1<<0);		PORTD &= ~(1<<1);			// Switch to 7Seg_1
		PORTC = arr[(num%10)];								// Write the Ones on the first 7Seg
		_delay_ms(50);
		PORTD |= (1<<1);		PORTD &= ~(1<<0);			// Switch to 7Seg_2
		PORTC = arr[(num/10)];								// Write the Tens on the second 7Seg
		_delay_ms(50);				// This Delay is set to reduce the interference between them
		
		if(CHECK_BIT(PIND, 2) == 0){
			num++;
			while(CHECK_BIT(PIND, 2) == 0);
		}
		if(CHECK_BIT(PIND, 3) == 0){
			num--;
			while(CHECK_BIT(PIND, 3) == 0);
		}
		if(CHECK_BIT(PIND, 4) == 0){
			num=0;
			while(CHECK_BIT(PIND, 4) == 0);
		}
	}
}
	

