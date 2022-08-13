/*
 * SPI_lab1_M.c
 *
 * Created: 7/30/2022 1:23:24 PM
 * Author : Astrolabe
 */ 

#define  F_CPU 1000000UL
#include <util/delay.h>
#include "STD_types.h"
#include "SPI_int.h"
#include "DIO_interface.h"


int main(void)
{
    DIO_VoidInit();
	SPI_voidInit();
	DIO_VoidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_LOW);
	u8 data;
    while (1) 
    {
		data = SPI_u8DataTransfere('A');
		if(data == 'a'){
			DIO_VoidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		}
		_delay_ms(1000);
		data = SPI_u8DataTransfere('B');
		if(data == 'b'){
			DIO_VoidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		_delay_ms(1000);
    }
}

