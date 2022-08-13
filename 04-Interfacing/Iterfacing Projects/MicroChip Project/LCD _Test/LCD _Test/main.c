/*
 * LCD _Test.c
 *
 * Created: 6/27/2022 4:39:58 PM
 * Author : Khalid
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"

void rotateString(char* str, u8 size, u8 direction);

int main(void)
{
	DIO_VoidInit();
	LCD_Init();
	char arr [17] = "     Khalid     ";
	char arr2[17] = "  Sharaf El-din ";
	_delay_ms(1000);
	LCD_Clear();
    while (1) 
    {	
		LCD_Puts(0,0, arr);
		rotateString(arr, 17, 1);
		LCD_Puts(0,1,arr2);
		rotateString(arr2, 17, 0);
		_delay_ms(200);	
    }
}

void rotateString(char* str, u8 size, u8 direction){
	if(direction == 1){
		char c =  str[0];
		for(int i =0; i <size-1; i++){
			str[i]= str[i+1];
		}
		str[size-2] = c ;
		str[size-1] = '\0';
	}else{
		char c= str[size-2];
		for(int i =size-2; i>0; i--){
			str[i]= str[i-1];
		}
		str[0] =c;
		str[16] = '\0';
	}
}

