#define  F_CPU 16000000UL
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

int main(void)
{ 
	u8 flag = 0;
	DIO_VoidInit();
	
	
	while(1)
	{
		if(DIO_u8GetPinValue(DIO_u8_PORTD , DIO_u8_PIN2) == DIO_u8_HIGH)
		{
			TOGGLE_BIT(flag,0);
			while(DIO_u8GetPinValue(DIO_u8_PORTD , DIO_u8_PIN2) == DIO_u8_HIGH); // polling
		}
		
		if(flag == 0)
		{
			DIO_VoidSetPinValue(DIO_u8_PORTD , DIO_u8_PIN3 , DIO_u8_HIGH);
		}
		else if(flag == 1)
		{
			DIO_VoidSetPinValue(DIO_u8_PORTD , DIO_u8_PIN3 , DIO_u8_LOW);
		444}
	}
	return 0;
}