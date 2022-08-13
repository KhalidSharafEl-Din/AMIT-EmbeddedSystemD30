/*
 * KeyPad_Test.c
 *
 * Created: 6/28/2022 3:39:15 PM
 * Author : Khalid
 */ 
#define F_CPU 16000000UL
#include "util/delay.h"
#include <avr/io.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"


int main(void)
{
    DIO_VoidInit();
	LCD_Init();
	KEYPAD_init();
	LCD_Puts(0,0, ">> ");
	u8 key = '\0';
    while (1) 
    {
		key = KEYPAD_getButton();
		//LCD_CursorSet(3,0);
		if(key != '\0') {
			LCD_Put(key);
			while (key == KEYPAD_getButton());
		}
	}
}

