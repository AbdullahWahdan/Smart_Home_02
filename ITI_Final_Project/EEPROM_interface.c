/*
 * EEPROM_interface.c
 *
 * Created: 8/15/2024 10:09:55 PM
 *  Author: wahdan
 */
 #include "MATH.h"
 #include "STD_TYPE.h"
 #include "EEPROM_interface.h"
 #include "EEPROM_private.h"
 
void EEPROM_Vid_Send_Data(u16 u16_Loc_Address, u8 u8_Loc_Data)
{
	/* Wait for completion of previous write */
	while(EECR_REG & (1<<EEWE));
	/* Set up address and data registers */
	EEAR_REG = u16_Loc_Address;
	EEDR_REG = u8_Loc_Data;
	/* Write logical one to EEMWE */
	SET_BIT(EECR_REG,EEMWE);
	/* Start eeprom write by setting EEWE */
	SET_BIT(EECR_REG,EEWE);
}

u8 EEPROM_U8_Recive_Data(u16 u16_Loc_Address)
{
	/* Wait for completion of previous write */
	while(EECR_REG & (1<<EEWE));
	/* Set up address register */
	EEAR_REG = u16_Loc_Address;
	/* Start eeprom read by writing EERE */
	SET_BIT(EECR_REG,EERE);
	/* Return data from data register */
	return EEDR_REG;
}