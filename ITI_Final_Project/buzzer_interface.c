/*
 * buzzer_interface.c
 *
 * Created: 10/3/2023 3:03:59 PM
 *  Author: user
 */ 
#include "DIO_interface.h"
#include "DIO_private.h"
#include "MATH.h"
#include "STD_TYPE.h"

void buzzer_vid_init()
{
	DIO_Vid_Set_Pin_Dir(PORTA,PIN3,OUTPUT);
}
void buzzer_vid_on()
{
	DIO_Vid_Set_Pin_Val(PORTA,PIN3,HIGH);
}
void buzzer_vid_off()
{
	DIO_Vid_Set_Pin_Val(PORTA,PIN3,LOW);
}