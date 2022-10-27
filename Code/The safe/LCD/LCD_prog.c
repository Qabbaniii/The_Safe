/*
 * LCD_prog.c
 *
 * Created: 18/10/2022 04:54:44 م
 *  Author: Qabbani
 */ 


#ifndef LCD_PROG_H_
#define LCD_PROG_H_
#include <util/delay.h>

#include "LCD_interface.h"

static void LCD_vSendEnablePulse(void)
{
	DIO_vSetPinValue(LCD_CONTROL_USED_PORT,EN,DIO_u8_PIN_HIGH);
	_delay_ms(2);
	DIO_vSetPinValue(LCD_CONTROL_USED_PORT,EN,DIO_u8_PIN_LOW);
	_delay_ms(2);
}

void LCD_vSendChar(u8 copy_u8Data)
{
	
	#if(configFOUR_BIT_MODE==0)
	{
	DIO_vSetPortValue(LCD_DATA_USED_PORT,copy_u8Data);
	DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_HIGH);
	LCD_vSendEnablePulse();
	}
	#elif(configFOUR_BIT_MODE==1)	
	{
	DIO_vSetLowNibbleValue(LCD_DATA_USED_PORT,copy_u8Data>>4);
	DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_HIGH);
	LCD_vSendEnablePulse();
	DIO_vSetLowNibbleValue(LCD_DATA_USED_PORT,copy_u8Data);
	DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_HIGH);
	LCD_vSendEnablePulse();
	}
	#endif
	_delay_ms(1);
}

void LCD_vSendCmd(u8 copy_u8Cmd)
{
	
	#if(configFOUR_BIT_MODE==0)
	
		DIO_vSetPortValue(LCD_DATA_USED_PORT,copy_u8Cmd);
		DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_LOW);
		LCD_vSendEnablePulse();
		_delay_ms(1);
	
	#elif(configFOUR_BIT_MODE==1)
	
		DIO_vSetLowNibbleValue(LCD_DATA_USED_PORT,copy_u8Cmd>>4);
		DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_LOW);
		LCD_vSendEnablePulse();
		DIO_vSetLowNibbleValue(LCD_DATA_USED_PORT,copy_u8Cmd);
		DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_LOW);
		LCD_vSendEnablePulse();
		
	#endif
	_delay_ms(1);
}	

void LCD_vClearScreen()
{
	LCD_vSendCmd(CLR_SCREEN);
	LCD_vMoveCursor(1,1);
	
}

void LCD_vInit()
{
	_delay_ms(100);	
										  //wait for vdd rises to 4.5v.
	#if (configFOUR_BIT_MODE ==0)                                            
	DIO_vSetPortDirection(LCD_DATA_USED_PORT,0xff);						 /* set PORT output */
	DIO_vSetPinDirection(LCD_CONTROL_USED_PORT,EN,DIO_u8_PIN_OUTPUT);   
	DIO_vSetPinDirection(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_OUTPUT);
	DIO_vSetPinDirection(LCD_CONTROL_USED_PORT,RW,DIO_u8_PIN_OUTPUT);
	
	DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RW,DIO_u8_PIN_LOW);  // Set as write pin 
	
	LCD_vSendCmd(EIGHT_BITS);   // 8_bit mode
	_delay_ms(1);
	LCD_vSendCmd(CURSOR_MODE);   // 8_bit mode
	_delay_ms(1);
	LCD_vSendCmd(CLR_SCREEN);   // clear screen
	_delay_ms(10);
	LCD_vSendCmd(ENTRY_MODE);   // shift cursor to right
	_delay_ms(1);
	
	#elif (configFOUR_BIT_MODE == 1)
	DIO_vSetLowNibbleDirection(LCD_DATA_USED_PORT,DIO_u8_PIN_OUTPUT);

	DIO_vSetPinDirection(LCD_CONTROL_USED_PORT,EN,DIO_u8_PIN_OUTPUT);
	DIO_vSetPinDirection(LCD_CONTROL_USED_PORT,RS,DIO_u8_PIN_OUTPUT);
	DIO_vSetPinDirection(LCD_CONTROL_USED_PORT,RW,DIO_u8_PIN_OUTPUT);
	
	DIO_vSetPinValue(LCD_CONTROL_USED_PORT,RW,DIO_u8_PIN_LOW);  // Set as write pin
	LCD_vSendCmd(RETURN_HOME);  //to set 4_bit mode 
	_delay_ms(10);
	LCD_vSendCmd(FOUR_BITS);   // 4_bit mode
	_delay_ms(1);
	LCD_vSendCmd(CURSOR_MODE);   // 8_bit mode
	_delay_ms(1);
	LCD_vSendCmd(CLR_SCREEN);   // clear screen
	_delay_ms(10);
	LCD_vSendCmd(ENTRY_MODE);   // shift cursor to right
	_delay_ms(1);
	#endif
}

void LCD_vMoveCursor(u8 copy_u8Row,u8 copy_u8Coloumn)
{
	u8 data ;
	if(copy_u8Row>2||copy_u8Row<1||copy_u8Coloumn>16||copy_u8Coloumn<1)
	{
		data=0x80;
	}
	else if(copy_u8Row==1)
	{
		data=0x80+copy_u8Coloumn-1 ;
	}
	else if (copy_u8Row==2)
	{
		data=0xc0+copy_u8Coloumn-1;
	}
	LCD_vSendCmd(data);
	_delay_ms(1);

}
void LCD_vSendString(u8 *copy_u8data)
{
	while((*copy_u8data)!='\0')
	{
		LCD_vSendChar(*copy_u8data);
		copy_u8data++;
	}
}

#endif /* LCD_PROG_H_ */