/************************************************/
/* Title       : USART main file                */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/

#define  F_CPU 16000000Ul
#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_int.h"


// Send code

int main ()
{
 DIO_VoidInit();
 UART_voidInit();
	u8 Data;
 while(1)
 {
	UART_voidSendByte('A');
	_delay_ms(1000);

	UART_voidSendByte('B');
	_delay_ms(1000);
	
	u8 
	
 }

}

/*
volatile uint8 arr[7] = "HELLO !";
volatile uint8 counter = 0;

void func (void)
{
 if(counter < 7)
 {

	UART_voidSendByte(arr[++counter]);

 }


}

int main ()
{
 uint8 Recieve = 0;
 DIO_vid_Init();
 UART_voidInit();
 //UART_void_SetCBSend( func ) ;
 //GIE_voidEnable();

 while(1)
 {
	 Recieve = UART_uint8ReceiveByte();
	switch(Recieve)
	{
	case 'a':
		UART_voidSendByte('A');
		break;

	case 'B':
		UART_voidSendByte('B');
		break;*/
	/*default:
		UART_voidSendByte('2');
		break;
	}


 }

}*/
