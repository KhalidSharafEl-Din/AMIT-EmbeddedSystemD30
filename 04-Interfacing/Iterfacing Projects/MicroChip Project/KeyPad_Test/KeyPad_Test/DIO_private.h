/*************************************************************/
/*      Author  : Khalid Sharaf El-din                       */
/*      Date    : 6-11-2022                                  */
/*      Version : 0.1                                        */
/*      File    : DIO_private.h                              */
/*************************************************************/


// Registers Definitions 

#ifndef __DIO_PRIVATE_H__
#define __DIO_PRIVATE_H__


#define PORTA  *((volatile u8*)0x3B)
#define DDRA   *((volatile u8*)0x3A)
#define PINA   *((volatile u8*)0x39)

#define PORTB  *((volatile u8*)0x38)
#define DDRB   *((volatile u8*)0x37)
#define PINB   *((volatile u8*)0x36)

#define PORTC  *((volatile u8*)0x35)
#define DDRC   *((volatile u8*)0x34)
#define PINC   *((volatile u8*)0x33)

#define PORTD  *((volatile u8*)0x32)
#define DDRD   *((volatile u8*)0x31)
#define PIND   *((volatile u8*)0x30)



#define DIO_u8OUTPUT 1
#define DIO_u8INPUT  0

#define DIO_u8_ERROR 255



#endif