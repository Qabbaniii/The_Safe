/*
 * EEPROM_proj.c
 *
 * Created: 09/10/2022 04:15:36 م
 *  Author: Qabbani
 */ 
#include "EEPROM_register.h"
#include "EEPROM_interface.h"
#include "../SERVICES/BIT_MATH.h"


void EEPROM_vWrite(const u16 copy_u16Address,u8 copy_u8Data){
	
	/*Setup address Register*/
	EEARL =(char)copy_u16Address;
	EEARH =(char)(copy_u16Address>>8);
	
	/*Setup data Register*/
	EEDR =copy_u8Data;
	
	/*write logic one to EEMWE*/
	SET_BIT(EECR,EEMWE);
	/*write logic one to EEWE*/
	SET_BIT(EECR,EEWE);
	
	/*wait for completion of write operation*/
	while(GET_BIT(EECR,EEWE)==1);
	
}

void EEPROM_vWriteBlock(const u16 copy_u16Address,u8 copy_u8Data){}

u8 EEPROM_u8Read(const u16 copy_u16Address)
{
	/*Setup Address Register*/
	EEAR = copy_u16Address;
	
	/*Start EEPROM Read*/
	SET_BIT(EECR,EERE);
	
	/*Return Data From Data Register*/
	return EEDR;
}