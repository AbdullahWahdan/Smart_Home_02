/*
 * EXT_interface.c
 *
 * Created: 9/11/2023 4:22:07 PM
 *  Author: youssef
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "EXT_private.h"
#include "EXT_interface.h"
#include "DIO_interface.h"


void EXT_Vid_Interrupt_Init(void){
	
	#if INT_SENSE_CONTROL == LOW_LEVEL
	/* FROM HTE TABLE CHOSSING THE LOW LEVEL OF (INT1, INT0) INT2 DOESN'T HAVE ACTIVATED (LOW LEVEL) STAGE */
	/* INT1 */
	CLR_BIT(MCUCR_REG,ISC11) ;
	CLR_BIT(MCUCR_REG,ISC10) ;
	/* INT0 */
	CLR_BIT(MCUCR_REG,ISC01) ;
	CLR_BIT(MCUCR_REG,ISC00) ;
	
	
	#elif INT_SENSE_CONTROL == ANY_LOGIC_CHANGE
	/* FROM HTE TABLE CHOSSING THE ANY_LOGIC_CHANGE OF (INT1, INT0) INT2 DOESN'T HAVE ACTIVATED (ANY_LOGIC_CHANGE) STAGE */
	/* INT1 */
	CLR_BIT(MCUCR_REG,ISC11) ;
	SET_BIT(MCUCR_REG,ISC10) ;
	/* INT0 */
	CLR_BIT(MCUCR_REG,ISC01) ;
	SET_BIT(MCUCR_REG,ISC00) ;
	
	
	#elif   INT_SENSE_CONTROL == FALLING_EDGE
	/* FROM HTE TABLE CHOSSING THE FALLING_EDGE OF (INT1, INT0, INT2) */
	/* INT1 */
	SET_BIT(MCUCR_REG,ISC11) ;
	CLR_BIT(MCUCR_REG,ISC10) ;
	/* INT0 */
	SET_BIT(MCUCR_REG,ISC01) ;
	CLR_BIT(MCUCR_REG,ISC00) ;
	/* INT2*/
	CLR_BIT(MCUCSR_REG,ISC2) ;
	
	
	#elif    INT_SENSE_CONTROL == RISING_EDGE
	/* FROM HTE TABLE CHOSSING THE RISING_EDGE OF (INT1, INT0, INT2) */
	/* INT1 */
	SET_BIT(MCUCR_REG,ISC11) ;
	SET_BIT(MCUCR_REG,ISC10) ;
	/* INT0 */
	SET_BIT(MCUCR_REG,ISC01) ;
	SET_BIT(MCUCR_REG,ISC00) ;
	/* INT2*/
	SET_BIT(MCUCSR_REG,ISC2) ;
	
	
	#endif
}

void EXT_Vid_Enable_Interrupt0(void){
	
	/* enable interrupt (PIE)*/
	SET_BIT(GICR_REG,INT_0) ;
}

void EXT_Vid_Enable_Interrupt1(void){
	
	/* enable interrupt (PIE)*/
	SET_BIT(GICR_REG,INT_1) ;
}

void EXT_Vid_Enable_Interrupt2(void){
	
	/* enable interrupt (PIE)*/
	SET_BIT(GICR_REG,INT_2) ;
}

/* POINTER TO FUNCTION */
void (*ptr_set)(void) = 0;
/* CALL BACK FUNCTION THAT ASSIGN THE FUNCTION ADDRESS TO THE POINTER */ 
void SET_CallBack( void (*ptr)(void) ){
	ptr_set = ptr;
}

/* THIS IS ISR() FUNCTION IN WHICH WHEN INT2 IS HAPPEN IT AUTOMATICALLY JUMP TO THIS FUNCTION TO DO IT */
void __vector_3(void)__attribute__((signal)) ;
void __vector_3(void){
	
}