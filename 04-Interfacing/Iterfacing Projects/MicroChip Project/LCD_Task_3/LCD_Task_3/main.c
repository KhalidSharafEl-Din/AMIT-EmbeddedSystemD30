/*
 * LCD_Task_3.c
 *
 * Created: 6/28/2022 6:46:09 AM
 * Author : Khalid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"



int main(void)
{
	DIO_VoidInit();
	LCD_Init();
	
	u8 kha2[]		=	{0b00000,0b00100,0b00000,0b00110,0b00001,0b11111,0b00000,0b00000};
	u8 geem[]		=	{0x00,0x00,0x00,0x06,0x01,0x1F,0x00,0x04};
	u8 alef[]		=	{0x04,0x04,0x04,0x04,0x04,0x07,0x00,0x00};
	u8 lamMid[]		=	{0x04,0x04,0x04,0x04,0x04,0x1C,0x00,0x00};
	u8 lamEnd[]		=	{0x01,0x01,0x01,0x01,0x11,0x11,0x0A,0x04};
	u8 dal[]		=	{0x00,0x00,0x02,0x02,0x02,0x1F,0x00,0x00};
	u8 memeMid[]	=	{0x00,0x00,0x00,0x00,0x00,0x1F,0x0A,0x04};
	u8 heart[]		=	{0x00,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00};
	
		
	LCD_CreateChar(0,kha2);
	LCD_CreateChar(1,alef);
	LCD_CreateChar(2,lamMid);
	LCD_CreateChar(3,dal);
	LCD_CreateChar(4, geem);
	LCD_CreateChar(5, memeMid);
	LCD_CreateChar(6, lamEnd);
	LCD_CreateChar(7, heart);
	

	LCD_PutCustom(_LCD_COLS-3,0,0);
	LCD_PutCustom(_LCD_COLS-4,0,1);
	LCD_PutCustom(_LCD_COLS-5,0,2);
	LCD_PutCustom(_LCD_COLS-6,0,3);
	
	LCD_Puts(_LCD_COLS-7, 0, " ");
	
	LCD_PutCustom(_LCD_COLS-8,0,4);
	LCD_PutCustom(_LCD_COLS-9,0,5);
	LCD_PutCustom(_LCD_COLS-10,0,1);
	LCD_PutCustom(_LCD_COLS-11,0,6);
	
	LCD_Puts(_LCD_COLS-12, 0, " ");
	
	LCD_PutCustom(_LCD_COLS-13,0,7);
	
	
	_delay_ms(1000);
    while (1) 
    {	
		LCD_ScrollLeft();
		_delay_ms(250);
    }
}

