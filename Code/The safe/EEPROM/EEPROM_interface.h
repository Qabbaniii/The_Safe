/*
 * EEPROM_interface.h
 *
 * Created: 09/10/2022 04:15:18 م
 *  Author: Qabbani
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

//EEPROM Control Register

#define EERE     0
#define EEWE     1
#define EEMWE    2
#define EERIE    3 



void EEPROM_vWrite(const u16 copy_u16Address,u8 copy_u8Data);
void EEPROM_vWriteBlock(const u16 copy_u16Address,u8 copy_u8Data);

u8 EEPROM_u8Read(const u16 copy_u16Address);
#endif /* EEPROM_INTERFACE_H_ */