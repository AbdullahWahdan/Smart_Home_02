/*
 * EXT_interface.h
 *
 * Created: 9/11/2023 4:21:50 PM
 *  Author: youssef
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_

/* CHOOSING THE STAGE WHICH THE INTERRUPT WILL BE ACTIVATED IN */
#define INT_SENSE_CONTROL      ANY_LOGIC_CHANGE
#define   LOW_LEVEL         0
#define   ANY_LOGIC_CHANGE  1
#define   FALLING_EDGE      2
#define   RISING_EDGE       3

/*****************************************************************************
* Function Name: EXT_Vid_Interrupt_Init
* Purpose      : INITIALIZE THE ITERRUPT WITH THE ACTIVATED STAGE (INT_SENSE_CONTROL)
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Interrupt_Init(void) ;
/*****************************************************************************
* Function Name: EXT_Vid_Enable_Interrupt0
* Purpose      : ENABLE THE INT0
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Enable_Interrupt0(void);
/*****************************************************************************
* Function Name: EXT_Vid_Enable_Interrupt1
* Purpose      : ENABLE THE INT1
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Enable_Interrupt1(void);
/*****************************************************************************
* Function Name: EXT_Vid_Enable_Interrupt2
* Purpose      : ENABLE THE INT2
* Parameters   : void
* Return value : void
*****************************************************************************/
void EXT_Vid_Enable_Interrupt2(void);
/*****************************************************************************
* Function Name: SET_CallBack
* Purpose      : CALL BACK FUNCTION THAT ASSIGN THE FUNCTION ADDRESS TO THE POINTER
* Parameters   : void (*ptr)(void) --> POINTER TO FUNCTION
* Return value : void
*****************************************************************************/
void SET_CallBack(void (*ptr)(void));
/**********************************************************************************************************************/


#endif /* EXT_INTERFACE_H_ */