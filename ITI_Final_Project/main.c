/*
 * ITI_Final_Project.c
 *
 * Created: 8/15/2024 11:17:29 PM
 * Author : wahdan
 */ 
#include "DIO_interface.h"
#include "STD_TYPE.h"
#include "MATH.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "EEPROM_interface.h"
#include "uart_interface.h"
#include "Relay_interface.h"
#include "Tim1_interface.h"
#include "ULTRASONIC_interface.h"
#include "buzzer_interface.h"
#include "TIMER0_interface.h"
#include "EXT_interface.h"
#include "GIE_interface.h"
#include "ADC_test_interface.h"

#define F_CPU 8000000
#include <util/delay.h>
static int j ;
int main(void)
{	DIO_Vid_Set_Pin_Dir(PORTC,PIN0,OUTPUT);
	//LCD initializations
	 DIO_Vid_Set_Port_Dir(LCD_DPORT, PORT_OUTPUT);
    DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT);
	LCD_Vid_Init();
	//UART initialization
	DIO_Vid_Set_Pin_Dir(PORTD,PIN0,INPUT);
	UART_Vid_Init();
	//timer1(servo) initialization
	DIO_Vid_Set_Pin_Dir(PORTD,PIN5,OUTPUT);	//OCRA1
	Tim1_Vid_Fast_Pwm_ICR1_Init();
	//relay initialization
	Relay_Vid_Init();
		ADC_Vid_Init();
		DIO_Vid_Set_Pin_Dir(PORTC,PIN1,INPUT);
	
	Tim1_Vid_Set_Compare_Val(1000);
	LCD_Vid_GotoXY(7,0);
	LCD_Vid_Send_String("ITI");
	LCD_Vid_GotoXY(1,1);
	LCD_Vid_Send_String("final project!");
	_delay_ms(2500);
	LCD_Vid_Send_Command(LCD_CLR);
	
	//USERNAMES
 	EEPROM_Vid_Send_Data(0,'a');
 	EEPROM_Vid_Send_Data(1,'b');
 	EEPROM_Vid_Send_Data(2,'c');
	EEPROM_Vid_Send_Data(3,'d');
	EEPROM_Vid_Send_Data(4,'e');
	EEPROM_Vid_Send_Data(5,'f');
	EEPROM_Vid_Send_Data(6,'g');
	EEPROM_Vid_Send_Data(7,'h');
	EEPROM_Vid_Send_Data(8,'i');
	EEPROM_Vid_Send_Data(9,'j');
	//PASSWORDS
	EEPROM_Vid_Send_Data(20,'0');
	EEPROM_Vid_Send_Data(21,'1');
	EEPROM_Vid_Send_Data(22,'2');
	EEPROM_Vid_Send_Data(23,'3');
	EEPROM_Vid_Send_Data(24,'4');
	EEPROM_Vid_Send_Data(25,'5');
	EEPROM_Vid_Send_Data(26,'6');
	EEPROM_Vid_Send_Data(27,'7');
	EEPROM_Vid_Send_Data(28,'8');
	EEPROM_Vid_Send_Data(29,'9');
	
	//USERNAME:a	PASSWORD:0		LOCATION 0X01
	// u8 x=0;
	 u8 user;
	 u8 pass = 0;
	 u8 flag = 0,k = 0;
	 u16 i = 0;
	 u8 choice;
	 j=1;
	 u16 LDR=0;
    while (1) 
    {
		
		
		LCD_Vid_Send_String("username:");
		user = UART_u8_RX();
		LCD_Vid_Send_Data(user);
		_delay_ms(1000);
		LCD_Vid_Send_Command(LCD_CLR);
		for(i=0;i<=19;i++)
		{
			if (user == EEPROM_U8_Recive_Data(i))
			{
				LCD_Vid_Send_String("password:");
				pass = UART_u8_RX();
				LCD_Vid_Send_Data(pass);
				_delay_ms(1000);
				LCD_Vid_Send_Command(LCD_CLR);
				
				if (pass == EEPROM_U8_Recive_Data(i+20))
				{
					flag=1;
					break;
				}
				
			}
		}
			

		if (flag == 1)
		{
			LCD_Vid_Send_String("successful");
			_delay_ms(1000);	
			LCD_Vid_Send_Command(1);
			while(1)
			{
				LCD_Vid_Send_String("1-Door   2-light");
				LCD_Vid_GotoXY(0,1);
				LCD_Vid_Send_String("3-addUser 4-more");
				choice = UART_u8_RX();
				LCD_Vid_GotoXY(8,0);
				LCD_Vid_Send_Data(choice);
				_delay_ms(500);
				LCD_Vid_Send_Command(1);
				if (choice == '1')
				{	
					LCD_Vid_Send_String("1-open");
					LCD_Vid_GotoXY(0,1);
					LCD_Vid_Send_String("2-close");
					choice = UART_u8_RX();
					LCD_Vid_GotoXY(8,0);
					LCD_Vid_Send_Data(choice);
					_delay_ms(500);
					LCD_Vid_Send_Command(1);
				
					if (choice == '1')
					{
						LCD_Vid_Send_String("door opened");
						Tim1_Vid_Set_Compare_Val(2000);
						LCD_Vid_Send_Command(1);
					}
					else if (choice == '2')
					{
						LCD_Vid_Send_String("door closed");
						Tim1_Vid_Set_Compare_Val(1000);
						LCD_Vid_Send_Command(1);
					}
				
				
				}
				else if (choice == '2')
				{
					LCD_Vid_Send_String("1-light on");
					LCD_Vid_GotoXY(0,1);
					LCD_Vid_Send_String("2-light off");
					choice = UART_u8_RX();
					LCD_Vid_GotoXY(8,0);
					LCD_Vid_Send_Data(choice);
					_delay_ms(500);
					LCD_Vid_Send_Command(1);
					
					if (choice == '1')
					{
						LCD_Vid_Send_String("light on");
						Relay_Vid_ON();
						LCD_Vid_Send_Command(1);
					}
					else if (choice == '2')
					{
						LCD_Vid_Send_String("light off");
						Relay_Vid_OFF();
						LCD_Vid_Send_Command(1);
					}
				}
				
				else if (choice=='3')
				{
					LCD_Vid_Send_String("enter username: ");
					user = UART_u8_RX();
					LCD_Vid_Send_Data(user);
					_delay_ms(500);
					LCD_Vid_Send_Command(1);
					LCD_Vid_Send_String("enter password: ");
					pass = UART_u8_RX();
					LCD_Vid_Send_Data(pass);
					_delay_ms(500);
					LCD_Vid_Send_Command(1);
					
					EEPROM_Vid_Send_Data(9+j,user);
					EEPROM_Vid_Send_Data(29+j,pass);
					++j;
				}
				else if (choice == '4')
				{
					LCD_Vid_Send_Command(1);
					LCD_Vid_Send_String("5-Dist  6-Temp");
					LCD_Vid_GotoXY(0,1);
					LCD_Vid_Send_String("8-LDR  7-exit");
					choice = UART_u8_RX();
					LCD_Vid_GotoXY(8,0);
					LCD_Vid_Send_Data(choice);
					_delay_ms(500);
					LCD_Vid_Send_Command(1);
					if(choice=='5')
					{
						GIE_Vid_Interrupt_Enable();
						ULTRASONIC_Vid_Init();
						TIMER0_Vid_Init(OV_MODE);
						buzzer_vid_init();
						LCD_Vid_Send_String("Distance = ");
						_delay_ms(10);
						DIO_Vid_Set_Pin_Val(PORTC,PIN1,HIGH);
						while(1)
						{
							
							ULTRASONIC_Vid_Trig();
							_delay_ms(100);
							LCD_Vid_GotoXY(COL2,ROW2);
							LCD_Vid_Send_Data(' ');
							LCD_Vid_GotoXY(COL3,ROW2);
							LCD_Vid_Send_String(" cm");
							if (DIO_u8_Get_Pin_Val(PORTC,PIN1)==0)
							{
								LCD_Vid_Send_Command(LCD_CLR);
								break;
							}
						
						}
					}
					else if(choice == '6')
					{
						u16 celsius;

						//ADC_Vid_Init();
						DIO_Vid_Set_Pin_Dir(PORTA,PIN0,INPUT); /* initialize ADC*/
						DIO_Vid_Set_Pin_Val(PORTC,PIN1,HIGH);
						while(1)
						{
							LCD_Vid_GotoXY(0,0);
							LCD_Vid_Send_String("TEMP = ");
							celsius = ADC_u16_Read(0);
							celsius *=0.488;
							LCD_Vid_Send_Number(celsius);/* send string data for printing */
							_delay_ms(1000);
							if (DIO_u8_Get_Pin_Val(PORTC,PIN1)==0)
							{
								LCD_Vid_Send_Command(LCD_CLR);
								break;
							}
						}

					}
					else if(choice == '7')
					{
						LCD_Vid_Send_String("exit?");
						LCD_Vid_GotoXY(0,1);
						LCD_Vid_Send_String("1-Yes       2-No");
						choice = UART_u8_RX();
						LCD_Vid_GotoXY(8,0);
						LCD_Vid_Send_Data(choice);
						_delay_ms(500);
						LCD_Vid_Send_Command(1);
						
						if (choice == '1')
						{
							LCD_Vid_Send_String("ThankYou!!");
							
							Relay_Vid_OFF();
							Tim1_Vid_Set_Compare_Val(1000);
							_delay_ms(500);
							LCD_Vid_Send_Command(1);
							flag = 0;
							break;
							
						}
						else if (choice == '2')
						{
							LCD_Vid_Send_Command(1);
						}
					}
					else if (choice == '8')
					{	LCD_Vid_Send_Command(1);
						LCD_Vid_Send_String("LIGHT STATUS");
						_delay_ms(100);
					
						DIO_Vid_Set_Pin_Dir(PORTA,PIN1,INPUT);
						DIO_Vid_Set_Pin_Val(PORTC,PIN1,HIGH);
						while(1){
							LDR=ADC_u16_Read(1);
							LDR=LDR*5/1023;
							if(LDR>=3)
							{	LCD_Vid_Send_Command(1);
								LCD_Vid_Send_String("LED OFF");
								_delay_ms(100);
								DIO_Vid_Set_Pin_Val(PORTC,PIN0,LOW);
							}
							 if(LDR<3){
								LCD_Vid_Send_Command(1);
								LCD_Vid_Send_String("LED ON");
									_delay_ms(100);

								DIO_Vid_Set_Pin_Val(PORTC,PIN0,HIGH);
							}
							
							if (DIO_u8_Get_Pin_Val(PORTC,PIN1)==0)
							{
								LCD_Vid_Send_Command(LCD_CLR);
								break;
							}
						}
					
						
						
					}
				}	
			}
			
		}
		else
		{
			LCD_Vid_Send_String("unsuccessful");
			_delay_ms(1000);
			LCD_Vid_Send_Command(1);
			k++;
		}
		if(k == 3)
		{
			LCD_Vid_Send_String("no more trials!!");
			LCD_Vid_GotoXY(0,1);
			LCD_Vid_Send_String("reset the system");
			break;
		}
		
		
		
    }
}

