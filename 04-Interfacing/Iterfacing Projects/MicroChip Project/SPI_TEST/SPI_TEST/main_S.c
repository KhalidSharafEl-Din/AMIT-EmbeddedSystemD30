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
#define  DUMMY 0xff

int main(void)
{
    DIO_VoidInit();
	SPI_voidInit();
	u8 received;
	
    while (1) 
    {
		received = SPI_u8DataTransfere(DUMMY);
	
	    if(received == 'A')
		{
			DIO_VoidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
			SPI_u8DataTransfere('a');
		}
		else if (received == 'B')
		{
			DIO_VoidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
			SPI_u8DataTransfere('b');
			
		}
    }
}

