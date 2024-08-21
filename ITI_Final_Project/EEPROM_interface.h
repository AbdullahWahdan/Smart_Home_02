/*
 * EEPROM_interface.c
 *
 * Created: 8/15/2024 10:09:55 PM
 *  Author: wahdan
 */


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

u8 EEPROM_U8_Recive_Data(u16 u16_Loc_Address);

void EEPROM_Vid_Send_Data(u16 u16_Loc_Address, u8 u8_Loc_Data);

/* EEPROM Control Register */
#define EERIE   3
#define EEMWE   2
#define EEWE    1
#define EERE    0

#endif /* EEPROM_INTERFACE_H_ */