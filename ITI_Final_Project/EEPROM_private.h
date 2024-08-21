/*
 * EEPROM_interface.c
 *
 * Created: 8/15/2024 10:09:55 PM
 *  Author: wahdan
 */


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEAR_REG *((volatile u16*)0x3E)
			
#define EEDR_REG *((volatile u8*)0x3D)
		
#define EECR_REG *((volatile u8*)0x3C)

#endif /* EEPROM_PRIVATE_H_ */