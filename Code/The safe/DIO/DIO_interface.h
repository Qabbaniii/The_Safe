/*
 * DIO_inteface.h
 *
 *  Created on: Mar 23, 2022
 *      Author: Qabbani
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../Services/STD_TYPES.h"
//all defines

#define DIO_u8_PORTA   0
#define DIO_u8_PORTB   1
#define DIO_u8_PORTC   2
#define DIO_u8_PORTD   3

#define DIO_u8_PIN0 		0
#define DIO_u8_PIN1		    1
#define DIO_u8_PIN2 		2
#define DIO_u8_PIN3	     	3
#define DIO_u8_PIN4 		4
#define DIO_u8_PIN5 		5
#define DIO_u8_PIN6 		6
#define DIO_u8_PIN7 		7

#define DIO_u8_PORT_HIGH    1
#define DIO_u8_PORT_LOW     0

#define DIO_u8_PORT_OUTPUT  1
#define DIO_u8_PORT_INPUT   0

#define DIO_u8_PIN_HIGH     1
#define DIO_u8_PIN_LOW      0

#define DIO_u8_PIN_OUTPUT   1
#define DIO_u8_PIN_INPUT    0

#define DIO_u8_PIN_ENABLE   1
#define DIO_u8_PIN_DISABLE  0


// prototype of function

void DIO_vSetPortDirection		 (u8 copy_u8PortName ,u8 copy_u8Direction					     );
void DIO_vSetPortValue 			 (u8 copy_u8PortName,u8 copy_u8Value						     );
u8 DIO_u8GetPortValue 			 (u8 copy_u8PortName										     );

void DIO_vSetPinDirection		 (u8 copy_u8PortName,u8 copy_u8PinNumber,u8 copy_u8Direction	);
void DIO_vSetPinValue 			 (u8 copy_u8PortName,u8 copy_u8PinNumber,u8 copy_u8Value		);
void DIO_vTogglePin				 (u8 copy_u8PortName,u8 copy_u8PinNumber						);
u8 DIO_u8GetPinValue 			 (u8 copy_u8PortName,u8 copy_u8PinNumber						);

void DIO_vPullUpEnable			 (u8 copy_u8PortName,u8 copy_u8PinNumber,u8 copy_u8Enable	    );

void DIO_vSetLowNibbleDirection	 (u8 copy_u8PortName,u8 copy_u8Direction						);
void DIO_vSetLowNibbleValue		 (u8 copy_u8PortName,u8 Copy_u8Value							);
void DIO_vSetLowNibblePullUpEnable  (u8 copy_u8PortName,u8 copy_u8Enable						);

void DIO_vSetHighNibbleDirection (u8 copy_u8PortName,u8 copy_u8Direction						);
void DIO_vSetHighNibbleValue	 (u8 copy_u8PortName,u8 Copy_u8Value							);
void DIO_vSetHighNibblePullUpEnable (u8 copy_u8PortName,u8 copy_u8Enable						);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
