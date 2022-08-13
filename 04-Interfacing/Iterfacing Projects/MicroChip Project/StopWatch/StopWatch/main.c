/*
 * StopWatch.c
 *
 * Created: 6/21/2022 8:22:59 PM
 * Author : Khalid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY 100

#define CHECK_BIT(Var, BitNo) ( 1  &  (Var >> BitNo))
long int counter=0, HOURS=0, MINS=0, SECS=0;
int HoursTens=0, HoursOnes=0, MinsTens=0, MinsOnes=0, SecTens=0, SecOnes=0;
char startFlag=0, pauseFlag=0, stopFlag=1; 

int main(void)
{	
	DDRA    = 0b00000000;		// The Buttons as INPUT
    DDRC	= 0b01111111;		// 7Seg Pins as OUTPUT
	DDRD	= 0b00111111;		// Enable Pins as OUTPUT
	PORTA	= 0b00000111;		// Set The PULLUP for the Buttons
	
	int arr[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F};
	_delay_ms(DELAY);
    while (1) 
    {	// Display the data
		PORTD = 0b00000001;			// Switch to 7Seg_2
		PORTC = arr[HoursOnes];				// Write the Ones on the first 7Seg
		PORTC |= (1<<7);
		_delay_ms(5);
		
		PORTD = 0b000000010;		// Switch to 7Seg_3
		PORTC = arr[MinsTens];								// Write the Tens on the second 7Seg
		_delay_ms(5);				// This Delay is set to reduce the interference between them
		
		PORTD = 0b00000100;			// Switch to 7Seg_4
		PORTC = arr[MinsOnes];								// Write the Tens on the second 7Seg
		PORTC |= (1<<7);
		_delay_ms(5);				// This Delay is set to reduce the interference between them
		
		PORTD = 0b00001000;			// Switch to 7Seg_5
		PORTC = arr[SecTens];								// Write the Tens on the second 7Seg
		_delay_ms(5);				// This Delay is set to reduce the interference between them
		
		PORTD = 0b00010000;			// Switch to 7Seg_6
		PORTC = arr[SecOnes];								// Write the Tens on the second 7Seg
		PORTC |= (1<<7);
		_delay_ms(5);				// This Delay is set to reduce the interference between them
		
		PORTD = 0b00100000;			// Switch to 7Seg_1
		PORTC = arr[HoursTens];								// Write the Tens on the second 7Seg
		_delay_ms(5);				// This Delay is set to reduce the interference between them
		
		// User input handling 
		if(CHECK_BIT(PINA, 0) == 0){				// Start
			startFlag = 1;		pauseFlag = 0;		stopFlag = 0;
			while(CHECK_BIT(PINA, 0) == 0);
		}
		if(CHECK_BIT(PINA, 1) == 0){				// Pause
			startFlag = 0;		pauseFlag = 1;		stopFlag = 0;
			while(CHECK_BIT(PINA, 1) == 0);
		}
		if(CHECK_BIT(PINA, 2) == 0){				// STOP
			startFlag = 0;		pauseFlag = 0;		stopFlag = 1;
			while(CHECK_BIT(PINA, 2) == 0);
		}
		// Flow Control 
		if (pauseFlag == 1){startFlag=0;  stopFlag=0;}
		if (stopFlag == 1){startFlag=0;  stopFlag=0; counter =0;}
		if (startFlag == 1){counter++;  pauseFlag=0;  stopFlag=0;}
		// Extract the data to be displayed
		SECS  =  counter % 60;				SecOnes = SECS%10;		SecTens = SECS/10;
		MINS  = (counter / 60)%60;			MinsOnes= MINS%10;		MinsTens = MINS/10;
		HOURS = (counter / 3600)%60;		HoursOnes = HOURS%10;	HoursTens = HOURS/10;
		
	}
}
	

