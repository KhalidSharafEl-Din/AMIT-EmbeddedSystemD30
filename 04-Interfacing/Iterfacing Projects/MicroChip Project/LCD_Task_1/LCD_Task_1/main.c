/*
 * LCD_Task_1.c
 *
 * Created: 6/28/2022 4:58:31 AM
 * Author : Khalid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"

void bounceString(char* str, u8 size, u8* direction);

int main(void)
{
	DIO_VoidInit();
	LCD_Init();
	char str1 [17] = "Khalid";				u8 flag1 =0;
	char str2[17] = "           Gamal";		u8 flag2 =0;
	_delay_ms(1000);
	LCD_Clear();
    while (1) 
    {	
		LCD_Puts(0,0, str1);
		LCD_Puts(0,1, str2);
		bounceString(str1, strlen(str1), &flag1);
		bounceString(str2, strlen(str2), &flag2);
		_delay_ms(100);
		LCD_Clear();
    }
}

void bounceString(char* str, u8 size, u8* direction){
	if (*direction == 0){
		if(size<16){
			// Add spaces to the beginning  if the length of string is less than the screen
			for(int i=16; i>0; i--){str[i] =str[i-1];}
			str[0]=' ';
			}else{*direction = 1;} // When you reach the edge, reverse direction			
		}
	
		if(*direction == 1){
			if(str[0] == ' '){
				// Delete space from the beginning if there's a one
				for(int i =0; i<17; i++){str[i] = str[i+1];}
			}else{*direction =0;} // When you reach the edge, reverse direction
		}
}

