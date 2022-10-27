/*
 * DIO_prog.h
 *
 *  Created on: Mar 23, 2022
 *      Author: Qabbani
 */



/* include services */

#include <stdio.h>

#include "../SERVICES/BIT_MATH.h"
#include "../SERVICES/STD_TYPES.h"

//include lower layer

//include peripheral header

#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_register.h"

//Body of function which there prototype is in interface

void DIO_vSetPortDirection (u8 copy_u8PortName ,u8 copy_u8Direction){
	if(copy_u8PortName <=0 && copy_u8PortName >=3 && (copy_u8Direction==1||copy_u8Direction==0) ){

	switch (copy_u8Direction){
	default : break;
	case DIO_u8_PORT_OUTPUT :{

	switch(copy_u8PortName){
		default:break;
		case DIO_u8_PORTA: DDRA = 0xff; break;
		case DIO_u8_PORTB: DDRB = 0xff; break;
		case DIO_u8_PORTC: DDRC = 0xff; break;
		case DIO_u8_PORTD: DDRD = 0xff; break;

	}}break;
	case DIO_u8_PORT_INPUT: {

	 switch(copy_u8PortName){
	   default:break;
	   case DIO_u8_PORTA: DDRA = 0x00; break;
	   case DIO_u8_PORTB: DDRB = 0x00; break;
	   case DIO_u8_PORTC: DDRC = 0x00; break;
	   case DIO_u8_PORTD: DDRD = 0x00; break;
	}}break;


}}}
void DIO_vSetPortValue (u8 copy_u8PortName,u8 copy_u8Value         ){
	switch(copy_u8PortName){
			default:break;
			case DIO_u8_PORTA: PORTA = copy_u8Value; break;
			case DIO_u8_PORTB: PORTB = copy_u8Value; break;
			case DIO_u8_PORTC: PORTC = copy_u8Value; break;
			case DIO_u8_PORTD: PORTD = copy_u8Value; break;
	}
}
u8 DIO_u8GetPortValue (u8 copy_u8PortName                                 ){
	u8 LOC_u8Value = 0;
	switch(copy_u8PortName){
				default:break;
				case DIO_u8_PORTA: LOC_u8Value = PORTA; break;
				case DIO_u8_PORTB: LOC_u8Value = PORTB; break;
				case DIO_u8_PORTC: LOC_u8Value = PORTC; break;
				case DIO_u8_PORTD: LOC_u8Value = PORTD; break;}
				return LOC_u8Value;
}


void DIO_vSetPinDirection (u8 copy_u8PortName,u8 copy_u8PinNumber,u8 copy_u8Direction){
	switch (copy_u8Direction){
		default : break;
		case DIO_u8_PORT_INPUT : {
			switch(copy_u8PortName){
			default:break;
			case DIO_u8_PORTA: CLR_BIT(DDRA,copy_u8PinNumber); break;
			case DIO_u8_PORTB: CLR_BIT(DDRB,copy_u8PinNumber); break;
			case DIO_u8_PORTC: CLR_BIT(DDRC,copy_u8PinNumber); break;
			case DIO_u8_PORTD: CLR_BIT(DDRD,copy_u8PinNumber); break;

			}}break;
		case DIO_u8_PORT_OUTPUT: {
			switch(copy_u8PortName){
			default:break;
			case DIO_u8_PORTA: SET_BIT(DDRA,copy_u8PinNumber); break;
			case DIO_u8_PORTB: SET_BIT(DDRB,copy_u8PinNumber); break;
			case DIO_u8_PORTC: SET_BIT(DDRC,copy_u8PinNumber); break;
			case DIO_u8_PORTD: SET_BIT(DDRD,copy_u8PinNumber); break;
			}}break;


	}
}
void DIO_vSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8Value		){
	switch (Copy_u8Value){
	default : break;

	case DIO_u8_PIN_HIGH:{
		switch (Copy_u8PortName){
		default :break;
		case DIO_u8_PORTA: SET_BIT(PORTA, Copy_u8PinNumber);	break;
		case DIO_u8_PORTB: SET_BIT(PORTB, Copy_u8PinNumber);	break;
		case DIO_u8_PORTC: SET_BIT(PORTC, Copy_u8PinNumber);	break;
		case DIO_u8_PORTD: SET_BIT(PORTD, Copy_u8PinNumber);	break;
		}
	}break;


	case DIO_u8_PIN_LOW:{
		switch (Copy_u8PortName){
		default :break;
		case DIO_u8_PORTA: CLR_BIT(PORTA, Copy_u8PinNumber);	break;
		case DIO_u8_PORTB: CLR_BIT(PORTB, Copy_u8PinNumber);	break;
		case DIO_u8_PORTC: CLR_BIT(PORTC, Copy_u8PinNumber);	break;
		case DIO_u8_PORTD: CLR_BIT(PORTD, Copy_u8PinNumber);	break;
		}
	}break;
	}
}

u8 DIO_u8GetPinValue (u8 copy_u8PortName,u8 copy_u8PinNumber                                ){

	u8 LOC_u8Value = 0;
		switch(copy_u8PortName){
					default:break;
					case DIO_u8_PORTA: LOC_u8Value = GET_BIT(PINA,copy_u8PinNumber); break;
					case DIO_u8_PORTB: LOC_u8Value = GET_BIT(PINB,copy_u8PinNumber); break;
					case DIO_u8_PORTC: LOC_u8Value = GET_BIT(PINC,copy_u8PinNumber); break;
					case DIO_u8_PORTD: LOC_u8Value = GET_BIT(PIND,copy_u8PinNumber); break;
					}
					return LOC_u8Value;
}

void DIO_vTogglePin(u8 copy_u8PortName,u8 copy_u8PinNumber){
	switch(copy_u8PortName){
						default:break;
						case DIO_u8_PORTA: TOG_BIT(PORTA,copy_u8PinNumber); break;
						case DIO_u8_PORTB: TOG_BIT(PORTB,copy_u8PinNumber); break;
						case DIO_u8_PORTC: TOG_BIT(PORTC,copy_u8PinNumber); break;
						case DIO_u8_PORTD: TOG_BIT(PORTD,copy_u8PinNumber); break;

	}}




void DIO_vPullUpEnable (u8 copy_u8PortName,u8 copy_u8PinNumber,u8 copy_u8Enable)
{
	// default of PUD is 0
	
	switch (copy_u8Enable){
		default : break;
			case DIO_u8_PIN_ENABLE: {
				switch(copy_u8PortName){
					default:break;
					case DIO_u8_PORTA: SET_BIT(PORTA,copy_u8PinNumber); break;
					case DIO_u8_PORTB: SET_BIT(PORTB,copy_u8PinNumber); break;
					case DIO_u8_PORTC: SET_BIT(PORTC,copy_u8PinNumber); break;
					case DIO_u8_PORTD: SET_BIT(PORTD,copy_u8PinNumber); break;
				}}break;
			case DIO_u8_PIN_DISABLE: {
				switch(copy_u8PortName){
					default:break;
					case DIO_u8_PORTA: CLR_BIT(PORTA,copy_u8PinNumber); break;
					case DIO_u8_PORTB: CLR_BIT(PORTB,copy_u8PinNumber); break;
					case DIO_u8_PORTC: CLR_BIT(PORTC,copy_u8PinNumber); break;						
					case DIO_u8_PORTD: CLR_BIT(PORTD,copy_u8PinNumber); break;

				}}break;
			}
		}

void DIO_vSetLowNibblePullUpEnable (u8 copy_u8PortName,u8 copy_u8Enable)
{
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN0,copy_u8Enable);
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN1,copy_u8Enable);
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN2,copy_u8Enable);
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN3,copy_u8Enable);
}

void DIO_vSetHighNibblePullUpEnable (u8 copy_u8PortName,u8 copy_u8Enable)
{
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN4,copy_u8Enable);
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN5,copy_u8Enable);
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN6,copy_u8Enable);
	DIO_vPullUpEnable(copy_u8PortName,DIO_u8_PIN7,copy_u8Enable);
}

void DIO_vSetLowNibbleValue(u8 copy_u8PortName,u8 Copy_u8Value)
{
	
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN0,GET_BIT(Copy_u8Value,0));
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN1,GET_BIT(Copy_u8Value,1));
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN2,GET_BIT(Copy_u8Value,2));
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN3,GET_BIT(Copy_u8Value,3));
}

void DIO_vSetHighNibbleValue(u8 copy_u8PortName,u8 Copy_u8Value)
{
	Copy_u8Value<<=4;
	
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN4,GET_BIT(Copy_u8Value,4));
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN5,GET_BIT(Copy_u8Value,5));
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN6,GET_BIT(Copy_u8Value,6));
	DIO_vSetPinValue(copy_u8PortName,DIO_u8_PIN7,GET_BIT(Copy_u8Value,7));
}

void DIO_vSetLowNibbleDirection(u8 copy_u8PortName,u8 copy_u8Direction)
{
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN0,copy_u8Direction);
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN1,copy_u8Direction);
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN2,copy_u8Direction);
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN3,copy_u8Direction);
}

void DIO_vSetHighNibbleDirection(u8 copy_u8PortName,u8 copy_u8Direction)
{
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN4,copy_u8Direction);
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN5,copy_u8Direction);
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN6,copy_u8Direction);
	DIO_vSetPinDirection(copy_u8PortName,DIO_u8_PIN7,copy_u8Direction);
}