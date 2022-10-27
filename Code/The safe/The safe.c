/*
 * The_safe.c
 *
 * Created: 27/10/2022 03:28:14 م
 *  Author: mhama
 */ 

#define  F_CPU 8000000UL
#include <util/delay.h>
#include "KEYPAD/KEYPAD_interface.h"
#include "EEPROM/EEPROM_interface.h"
#include "LCD/LCD_interface.h"
#define EEPROM_STATUS_LOCATION    0x20
#define EEPROM_PASS_LOCATION1     0x21
#define EEPROM_PASS_LOCATION2     0x22
#define EEPROM_PASS_LOCATION3     0x23
#define EEPROM_PASS_LOCATION4	  0x24
#define MAX_TRIES 4

u8 arr[4];
int main(void)
{
	u8 LOC_u8Value = NOT_PRESSED;
	u8 LOC_u8CheckFlag=0,i;
	u8 LOC_u8Tries = MAX_TRIES;
	
	LCD_vInit();
	KEYPAD_vInit();
	
    
    
		if(EEPROM_u8Read(EEPROM_STATUS_LOCATION)==NOT_PRESSED)
		{
		LCD_vSendString("Set Pass:");
		for( i=0;i<4;i++)
		{
			do 
			{
				LOC_u8Value = KEYPAD_u8checkPress();
			} while (LOC_u8Value == NOT_PRESSED);
			LCD_vSendChar(LOC_u8Value);
			_delay_ms(300);
			LCD_vMoveCursor(1,10+i);
			LCD_vSendChar('*');
			_delay_ms(100);
			EEPROM_vWrite(EEPROM_PASS_LOCATION1+i,LOC_u8Value);
			}		
        EEPROM_vWrite(EEPROM_STATUS_LOCATION,0x00);
		  }	
		while(LOC_u8CheckFlag==0)
		{
			arr[0]=arr[1]=arr[2]=arr[3]=NOT_PRESSED;
			LCD_vClearScreen();
			LCD_vSendString("check pass:");
			for (i=0;i<=3;i++)
			{
				do
				{
					arr[i]=KEYPAD_u8checkPress();
				}while (arr[i]==NOT_PRESSED);
				LCD_vSendChar(arr[i]);
				_delay_ms(250);
				LCD_vMoveCursor(1,12+i);
				LCD_vSendChar('*');
			}
			
			if(EEPROM_u8Read(EEPROM_PASS_LOCATION1)==arr[0] &&  EEPROM_u8Read(EEPROM_PASS_LOCATION2)==arr[1] && EEPROM_u8Read(EEPROM_PASS_LOCATION3)==arr[2] && EEPROM_u8Read(EEPROM_PASS_LOCATION4)==arr[3])
			{
				LCD_vClearScreen();
				LCD_vSendString("right password");
				LCD_vMoveCursor(2,1);
				LCD_vSendString("safe opened");
				LOC_u8CheckFlag=1;
			}
			else
			{
				LOC_u8Tries=LOC_u8Tries-1;
				if (LOC_u8Tries>0)
				{
					LCD_vClearScreen();
					LCD_vSendString("wrong password");
					_delay_ms(1000);
					LCD_vClearScreen();
					LCD_vSendString("tries left:");
					LCD_vSendChar(LOC_u8Tries+48);
					_delay_ms(1000);
					
				}
				else
				{
					LCD_vClearScreen();
					LCD_vMoveCursor(1,1);
					LCD_vSendString("wrong password");
					LCD_vMoveCursor(2,1);
					LCD_vSendString("safe closed");
					LOC_u8CheckFlag=1;
				}
			}
			}    
			
}