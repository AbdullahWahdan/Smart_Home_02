/*
 * LCD_config.h
 *
 * Created: 8/29/2023 4:39:11 PM
 *  Author: youssef
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#if LCD_MODE == EIGHT_BIT_MODE
	#define LCD_DPORT   PORTA 
#elif LCD_MODE == FOUR_BIT_MODE
	#define LCD_DPORT   PORTA
	#define LCD_D4_PIN  PIN4
	#define LCD_D5_PIN  PIN5
	#define LCD_D6_PIN  PIN6
	#define LCD_D7_PIN  PIN7
#endif

#define LCD_CPORT  PORTB

#define LCD_RS_PIN PIN1
#define LCD_RW_PIN PIN2
#define LCD_EN_PIN PIN3


#endif /* LCD_CONFIG_H_ */