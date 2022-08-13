/*
 * ADC_TEST.c
 *
 * Created: 7/5/2022 8:59:35 PM
 * Author : Khalid
 */ 
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC-interface.h"
#include "LCD_interface.h"
#include <stdlib.h>
#include <util/delay.h>

int main(void)
{
   DIO_VoidInit();
   LCD_Init();
   ADC_init();
   u32 digital;
   f32 analog;
   char str[10];
   u8 count=0;
    while (1) 
    {
		  
		analog = (digital*5.0) /1024.0;
		dtostrf(analog, 2,5, str);
		LCD_Puts(0,0, str);
		LCD_Puts(8,0, "Volts");
		
		//dtostrf(count, 2,2, str);
		//LCD_Puts(6,1,str);
		_delay_ms(20);
		//count++;
    }
}

