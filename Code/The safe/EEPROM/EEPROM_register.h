/*
 * EEPROM_register.h
 *
 * Created: 09/10/2022 04:14:49 م
 *  Author: Qabbani
 */

#ifndef EEPROM_REGISTER_H_
#define EEPROM_REGISTER_H_


#include "../SERVICES/STD_TYPES.h"

#define EEAR *((volatile u16*)0x3E)
#define EEARL *((volatile u8*)0x3E)
#define EEARH *((volatile u8*)0x3F)

#define EEDR *((volatile u8*)0x3D)

#define EECR *((volatile u8*)0x3C)

#endif /* EEPROM_REGISTER_H_ */