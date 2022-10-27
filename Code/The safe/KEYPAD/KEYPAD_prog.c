/*
 * KEYPAD_prog.c
 *
 * Created: 24/10/2022 09:46:02 م
 *  Author: Qabbani
 */ 
#ifndef KEYPAD_PROG_H_
#define KEYPAD_PROG_H_
#include "KEYPAD_interface.h"

void KEYPAD_vInit(void)
{
	DIO_vSetLowNibbleDirection(KEYPAD_USED_PORT,DIO_u8_PIN_OUTPUT);
	DIO_vSetHighNibbleDirection(KEYPAD_USED_PORT,DIO_u8_PIN_INPUT);
    DIO_vSetHighNibblePullUpEnable(KEYPAD_USED_PORT,DIO_u8_PIN_ENABLE);
}

u8 KEYPAD_u8checkPress(void)
{
	u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	
	u8 row,col,buttonRead;
	u8 returnVal = NOT_PRESSED;
	
	for(row=0 ;row<4;row++)
	{
		
		DIO_vSetLowNibbleValue(KEYPAD_USED_PORT,0x0f);
		DIO_vSetPinValue(KEYPAD_USED_PORT,row,DIO_u8_PIN_LOW);
		
		for ( col=0 ;col<4;col++)
		{
			buttonRead = DIO_u8GetPinValue(KEYPAD_USED_PORT,(col+4));
			if(buttonRead==0)
			{
				returnVal = arr[row][col];
				break;
			}
		}
		if(buttonRead==0)
			break;
	    }
	return returnVal;
}
#endif /* KEYPAD_PROG_H_ */