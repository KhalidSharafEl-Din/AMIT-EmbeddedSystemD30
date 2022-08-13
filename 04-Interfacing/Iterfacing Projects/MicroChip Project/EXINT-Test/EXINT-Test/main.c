/*
 * EXINT-Test.c
 *
 * Created: 7/3/2022 10:12:13 PM
 * Author : Khalid
 */ 

#define F_CPU 1600000;
#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EINT_interface.h"
#include "GIE_config.h"

ISR(INT0_vect){
	TOGGLE_BIT(PORTD, 3);
}

int main(void)
{
	DIO_VoidInit();
	INT_init();
	
	INT_enbaleInterrupt(EXT_INT_0);
	INT_SenseControlMode(EXT_INT_0, FALLING_EDGE);
	GIE_enable();
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

