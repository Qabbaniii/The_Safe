/*
 * DIO_register.h
 *
 *  Created on: Mar 23, 2022
 *      Author: Qabbani
 */


#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_



//Groub A

#define PORTA   *((volatile u8 *) 0x3B)
#define DDRA    *((volatile u8 *) 0x3A)
#define PINA    *((volatile u8 *) 0x39)

//Groub B

#define PORTB   *((volatile u8 *) 0x38)
#define DDRB    *((volatile u8 *) 0x37)
#define PINB    *((volatile u8 *) 0x36)

//Groub C

#define PORTC   *((volatile u8 *) 0x35)
#define DDRC    *((volatile u8 *) 0x34)
#define PINC    *((volatile u8 *) 0x33)

//Groub D

#define PORTD   *((volatile u8 *) 0x32)
#define DDRD    *((volatile u8 *) 0x31)
#define PIND    *((volatile u8 *) 0x30)

#endif /* MCAL_DIO_DIO_REGISTER_H_ */

