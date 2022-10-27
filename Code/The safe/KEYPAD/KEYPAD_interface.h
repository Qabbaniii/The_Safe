/*
 * KEYPAD_interface.h
 *
 * Created: 24/10/2022 09:45:33 م
 *  Author: Qabbani
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_
#include "../DIO/DIO_interface.h"
#define KEYPAD_USED_PORT DIO_u8_PORTD
#define NOT_PRESSED 0xff

/* Function prototype */

void KEYPAD_vInit(void);
u8 KEYPAD_u8checkPress(void);

#endif /* KEYPAD_INTERFACE_H_ */