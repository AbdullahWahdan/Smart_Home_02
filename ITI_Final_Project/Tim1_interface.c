/*
 * Tim1_interface.c
 *
 * Created: 10/5/2023 7:48:56 PM
 *  Author: user
 */ 
#include "DIO_interface.h"
#include "DIO_private.h"
#include "EXT_interface.h"
#include "EXT_private.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "intrupt_vector.h"
#include "MATH.h"
#include "STD_TYPE.h"
#include "Tim1_interface.h"
#include "Tim1_private.h"

void Tim1_Vid_Fast_Pwm_ICR1_Init()
{
	/*Fast PWM non inverting*/
	SET_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);
	
	/*fast PWM icr1 MODE*/
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
	
	/*SET ICR register Top value*/
	ICR1_REG = 20000;
	
	/*set OCR*/
	//OCR1A_REG = 2000;
	
	/*Select PRESCALER VALUE*/
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
	
}

void Tim1_Vid_Set_Compare_Val(u32 copy_u32_val)
{
	OCR1A_REG = copy_u32_val;
}