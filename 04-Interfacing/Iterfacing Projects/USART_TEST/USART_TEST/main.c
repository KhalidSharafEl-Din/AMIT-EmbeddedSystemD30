/*
 * USART_TEST.c
 *
 * Created: 7/29/2022 10:34:48 PM
 * Author : Khalid
 */ 
#define F_CPU 16000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "USART_interface.h"
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DIO_VoidInit();
	LCD_Init();
	USART_init();
	u8 dataRecived; 
    while (1) 
    {
		u8 arr[50]="";
		USART_reciveString(arr, 50);
		USART_sendString("The String was written to the screen : ");
		USART_sendString(arr);
		
		LCD_Clear();
		LCD_Puts(0,0, arr);
		/*
		dataRecived = USART_reciveByte();
		switch (dataRecived){
			case '1' :
				LCD_Clear(); 
				LCD_Puts(0,0, "Hello, World.   Massage A");
				USART_sendByte('A');
				break;
			case '2':
				LCD_Clear();
				LCD_Puts(0,0, "USART DRIVER BY Khalid Gamal");
				USART_sendByte('B');
				break;
			default: 
					USART_sendString("MEANDNOTYO");
			break;
		}*/

    }
}

