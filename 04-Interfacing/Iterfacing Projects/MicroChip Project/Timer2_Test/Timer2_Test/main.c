/*
 * Timer2_Test.c
 *
 * Created: 8/10/2022 9:19:12 PM
 * Author : Khalid
 */ 
#define F_CPU 16000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "TIMER2_interface.h"
#include "ADC-interface.h"
#include <util/delay.h>

void setServoAngle(u8 angle);
void isr(void){
	TIMER2_SetCompare(150);
}
int main(void)
{
	TIMER2_init();
	DIO_VoidInit();
	ADC_init();
	u8 digital;
    while (1) 
    {	
			TIMER2_SetCompare(ADC_analogRead(1));
	}
}

void setServoAngle(u8 angle){
	// Angle : 0 > 180 
	// Duty cycle : 0 > 100 
	
	u8 dutyCycle = (angle * 5 / 180) + 5;       // Servo Expect 5-10 DutyCycle at 50 HZ
	u8 ocr2Value = 255 - dutyCycle*256/100;		// Calculation on OCR in Fast inverter ed Mode 
	TIMER2_SetCompare(ocr2Value); 
}
