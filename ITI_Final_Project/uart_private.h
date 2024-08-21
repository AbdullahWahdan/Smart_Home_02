/*
 * uart_private.h
 *
 * Created: 10/15/2023 1:08:44 PM
 *  Author: user
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

 #define UDR_REG		*((volatile u8*)0x2C)
 #define UCSRA_REG		*((volatile u8*)0x2B)
 #define UCSRB_REG		*((volatile u8*)0x2A)
 #define UCSRC_REG		*((volatile u8*)0x40)
 #define UBRRL_REG		*((volatile u8*)0x29)



#endif /* UART_PRIVATE_H_ */