/*
 * Relay_interface.c
 *
 * Created: 9/12/2023 9:52:16 PM
 * Author : Hima
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "Relay_config.h"
#include "Relay_interface.h"

void Relay_Vid_Init(){
	DIO_Vid_Set_Pin_Dir(RELAY_PORT,RELAY_PIN,OUTPUT);
}

void Relay_Vid_ON(){
	DIO_Vid_Set_Pin_Val(RELAY_PORT,RELAY_PIN,HIGH);
}

void Relay_Vid_OFF(){
	DIO_Vid_Set_Pin_Val(RELAY_PORT,RELAY_PIN,LOW);
}