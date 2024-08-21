/*
 * ADC_test_interface.c
 *
 * Created: 9/16/2023 3:53:18 PM
 *  Author: Hima
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "ADC_test_private.h"
#include "ADC_test_config.h"
#include "ADC_test_interface.h"

void ADC_Vid_Init(){
	#if VOLTAGE_REFERENCE == AREF
	/* Select AREF as reference */
	CLR_BIT(ADMUX_REG,REFS0);
	CLR_BIT(ADMUX_REG,REFS1);
	
	#elif VOLTAGE_REFERENCE == AVCC
	/* Select AVCC as reference */
	SET_BIT(ADMUX_REG,REFS0);
	CLR_BIT(ADMUX_REG,REFS1);
	
	#elif VOLTAGE_REFERENCE == INTERNAL_2_56
	/* Select Internal 2.56V as reference */
	SET_BIT(ADMUX_REG,REFS0);
	SET_BIT(ADMUX_REG,REFS1);
	
	#endif
		/* Another method to select the prescaler */
	//ADCSRA_REG &= 0b11111000;
	//ADCSRA_REG |= PRESCALER;
	
	#if PRESCALER == TWO
	/* Select prescaler --> 2 */
	CLR_BIT(ADCSRA_REG,ADPS0);
	CLR_BIT(ADCSRA_REG,ADPS1);
	CLR_BIT(ADCSRA_REG,ADPS2);
		
	#elif PRESCALER == FOUR
	/* Select prescaler --> 4 */
	CLR_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	CLR_BIT(ADCSRA_REG,ADPS2);
	
	#elif PRESCALER == EIGHT
	/* Select prescaler --> 8 */
	SET_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	CLR_BIT(ADCSRA_REG,ADPS2);	
	
	#elif PRESCALER == SIXTEEN
	/* Select prescaler --> 16 */
	CLR_BIT(ADCSRA_REG,ADPS0);
	CLR_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);	
	
	#elif PRESCALER == THIRTY_TWO
	/* Select prescaler --> 32 */
	SET_BIT(ADCSRA_REG,ADPS0);
	CLR_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);	
	
	#elif PRESCALER == SIXTY_FOUR
	/* Select prescaler --> 64 */
	CLR_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);	
	
	#elif PRESCALER == ONE_TWENTY_EIGHT
	/* Select prescaler --> 128 */  
	SET_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);
	
	#endif
	
	/* ENABLE ADC */
	SET_BIT(ADCSRA_REG,ADEN);
		
}

u16 ADC_u16_Read(u8 copy_u8_channel){
	ADMUX_REG &= 0b11100000;
	ADMUX_REG |= copy_u8_channel;
	
	/* Start conversion */
	SET_BIT(ADCSRA_REG,ADSC);
	/* Busy wait until conversion is complete */
		/* Interrupt with call back function instead of busy wait & polling (task) */
	while(GET_BIT(ADCSRA_REG,ADIF) == LOW);
	/* CLEAR FLAG BY WRITING 1 */
	SET_BIT(ADCSRA_REG,ADIF);
	
	return ADC_REG;
}