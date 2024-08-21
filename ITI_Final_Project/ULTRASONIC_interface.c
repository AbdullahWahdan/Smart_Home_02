/*
 * ULTRASONIC_interface.c
 *
 * Created: 10/7/2023 11:59:16 PM
 *  Author: youssef
 */ 

#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "EXT_interface.h"
#include "STD_TYPE.h"
#include "buzzer_config.h"
#include "buzzer_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "STD_TYPE.h"
#define F_CPU 8000000UL
#include <util/delay.h>

u8 pulse_flag=0;
u8 rising_edge=0;
u32 timer_counter=0;
s32 distance;

void  ULTRASONIC_Vid_Init(void){
	/* TRIG PIN ---> OUTPUT */
	DIO_Vid_Set_Pin_Dir(TRIG_PORT,TRIG_PIN,OUTPUT);
	/* ECHO PIN ---> INPUT */
	DIO_Vid_Set_Pin_Dir(ECHO_PORT,ECHO_PIN,INPUT);
	/* ENABLE INTERRUPT(0) ON ---> ANY_LOGIC_CHANGE */
	EXT_Vid_Interrupt_Init();
	EXT_Vid_Enable_Interrupt0();
}

void ULTRASONIC_Vid_Trig(void){
	
	if(pulse_flag == 0){
		DIO_Vid_Set_Pin_Val(TRIG_PORT,TRIG_PIN,HIGH);
		_delay_us(15);
		DIO_Vid_Set_Pin_Val(TRIG_PORT,TRIG_PIN,LOW);
		pulse_flag=1;
	}
} 

void __vector_1(void)__attribute__((signal)) ;
void __vector_1(void){
	
	if(pulse_flag == 1){
		if(rising_edge==0){
			TCNT0_REG=0x00;
			rising_edge=1;
			timer_counter=0;
		}
		else{
			// (F(timer) = 16 MHz) , (T(ticktime) = 0.0625 Us) , (TIMER OVERFLOW COUNT = 2^8 = 256) , (TIMER OVERFLOW TIME = 256 * 0.0625Us = 16 Us = 0.016 Ms)
			distance=((timer_counter*256+TCNT0_REG)/600);
			
			LCD_Vid_GotoXY(COL1,ROW2);
			LCD_Vid_Send_Number(distance);
			_delay_ms(15);
			
			
			if (distance < 30 && distance > 20)
			{
				buzzer_vid_on();
				_delay_ms(250);
				buzzer_vid_off();
			}
			else if (distance<20 && distance>10)
			{
				buzzer_vid_on();
				_delay_ms(100);
				buzzer_vid_off();
			}
			else if (distance<=10)
			{
				buzzer_vid_on();
				
			}
			
			
			
			timer_counter=0;
			rising_edge=0;
		}
	}
}

void __vector_11(void)__attribute__((signal)) ;
void __vector_11(void){
	timer_counter++;
	if(timer_counter == 730){
		TCNT0_REG=0x00;
		pulse_flag=0;
		rising_edge=0;
		timer_counter=0;
	}
}