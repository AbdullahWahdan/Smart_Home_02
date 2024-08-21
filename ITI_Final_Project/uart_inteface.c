/*
 * uart_inteface.c
 *
 * Created: 10/15/2023 1:09:01 PM
 *  Author: user
 */ 
#include "DIO_interface.h"
#include "DIO_private.h"
#include "MATH.h"
#include "STD_TYPE.h"
#include "uart_private.h"
#include "uart_interface.h"

void UART_Vid_Init()
{
	
	/*enable TX and RX*/
	SET_BIT(UCSRB_REG,4);
	SET_BIT(UCSRB_REG,3);
	
	/*send 8 bit data mode*/
	u8 loc_u8_temp = 0;
	SET_BIT(loc_u8_temp,7);
	SET_BIT(loc_u8_temp,2);
	SET_BIT(loc_u8_temp,1);
	UCSRC_REG = loc_u8_temp;
	
	/*set baud rate 9600 16MHZ*/
	UBRRL_REG = 51;
	
}
void UART_Vid_TX(u8 copy_u8_data)
{
	UDR_REG = copy_u8_data;
	while(GET_BIT(UCSRA_REG,5)==0);
}

u8 UART_u8_RX()
{
	while(GET_BIT(UCSRA_REG,7)==0);
	return UDR_REG;
}