/*
 * LCD_interface.h
 *
 * Created: 18/10/2022 04:54:24 م
 *  Author: Qabbani
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../DIO/DIO_interface.h"
#include "LCD_config.h"

/*index of Commands*/
#define CLR_SCREEN 0x01

#define DISPLAY_ON_CURSOR_ON 0x0e
#define DISPLAY_ON_CURSOR_OFF 0x0c
#define DISPLAY_OFF_CURSOR_ON 0x0a
#define DISPLAY_OFF_CURSOR_ON 0x08
#define DISPLAY_ON_CURSOR_BLINKUNG 0x0f

#define SHIFT_CURSOR_LEFT 0x10
#define SHIFT_CURSOR_RIGHT 0x14
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_DISPLAY_RIGHT 0x1c

#define BEDGINNING_1st_LINE 0x80
#define BEDGINNING_2nd_LINE 0xc0

#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
  
#define FOUR_BITS 0x28
#define EIGHT_BITS 0x38
/**/      
#define LCD_DATA_USED_PORT       DIO_u8_PORTA
#define LCD_CONTROL_USED_PORT    DIO_u8_PORTB

#define CURSOR_MODE DISPLAY_ON_CURSOR_OFF

#define EN 0
#define RW 2
#define RS 1


/* Function Prototype */

void LCD_vInit(void);
static void LCD_vSendEnablePulse(void);
void LCD_vSendCmd(u8 copy_u8Cmd);
void LCD_vSendChar(u8 copy_u8Data);
void LCD_vSendString(u8 *copy_u8Data);
void LCD_vClearScreen();
void LCD_vMoveCursor(u8 copy_u8Row,u8 copy_u8Coloumn);





/* custom character*/

/*

LCD_vSendCmd(64);

LCD_vSendChar(0b00000000);//حرف ال ع
LCD_vSendChar(0b00000110);
LCD_vSendChar(0b00001001);
LCD_vSendChar(0b00001000);
LCD_vSendChar(0b00011111);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);

LCD_vSendChar(0b00000000);//حرف ال ب
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000100);
LCD_vSendChar(0b00000100);
LCD_vSendChar(0b00011111);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000100);
LCD_vSendChar(0b00000000);


LCD_vSendChar(0b00000000);//حرف ال د
LCD_vSendChar(0b00001100);
LCD_vSendChar(0b00000010);
LCD_vSendChar(0b00000011);
LCD_vSendChar(0b00011110);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);

LCD_vSendChar(0b00000100);//حرف ال ا
LCD_vSendChar(0b00000100);
LCD_vSendChar(0b00000100);
LCD_vSendChar(0b00000100);
LCD_vSendChar(0b00000100);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);

LCD_vSendChar(0b00000001);//حرف ال ل
LCD_vSendChar(0b00000001);
LCD_vSendChar(0b00000001);
LCD_vSendChar(0b00000001);
LCD_vSendChar(0b00001111);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);

LCD_vSendChar(0b00000001);//حرف ال ل
LCD_vSendChar(0b00000001);
LCD_vSendChar(0b00000001);
LCD_vSendChar(0b00000001);
LCD_vSendChar(0b00001111);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);

LCD_vSendChar(0b00000000);//حرف ال ه
LCD_vSendChar(0b00001110);
LCD_vSendChar(0b00010001);
LCD_vSendChar(0b00010001);
LCD_vSendChar(0b00001111);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);
LCD_vSendChar(0b00000000);

LCD_vMoveCursor(2,15);
LCD_vSendChar(0);
LCD_vMoveCursor(2,14);
LCD_vSendChar(1);
LCD_vMoveCursor(2,13);
LCD_vSendChar(2);
LCD_vMoveCursor(2,12);
LCD_vSendChar(3);
LCD_vMoveCursor(2,11);
LCD_vSendChar(4);
LCD_vMoveCursor(2,10);
LCD_vSendChar(5);
LCD_vMoveCursor(2,9);
LCD_vSendChar(6);
LCD_vMoveCursor(2,8);
LCD_vSendChar(7);
LCD_vMoveCursor(2,7);

*/

#endif /* LCD_INTERFACE_H_ */