/*
 * uart_interface.h
 *
 * Created: 10/15/2023 1:08:23 PM
 *  Author: user
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Vid_Init();
void UART_Vid_TX(u8 copy_u8_data);
u8 UART_u8_RX();




#endif /* UART_INTERFACE_H_ */