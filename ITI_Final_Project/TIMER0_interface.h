/*
 * TIMER0_interface.h
 *
 * Created: 9/26/2023 3:40:45 PM
 *  Author: youssef
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "TIMER0_private.h"

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


/*****************************************************************************
* Function Name: TIMER0_Vid_Init
* Purpose      : INITIALIZE TIMER(0)
* Parameters   : VOID
* Return value : VOID
*****************************************************************************/
void TIMER0_Vid_Init(u8 copy_u8_mode);
/*****************************************************************************
* Function Name: TIMER0_Vid_DelayMs
* Purpose      : DELAY IN MILLI SECOND
* Parameters   : u32 copy_u32_delay
* Return value : VOID
*****************************************************************************/
void TIMER0_Vid_DelayMs(u32 copy_u32_delay);
/*****************************************************************************
* Function Name: TIMER0_Vid_DelayUs
* Purpose      : DELAY IN MICRO SECOND
* Parameters   : u32 copy_32_delay
* Return value : VOID
*****************************************************************************/
void TIMER0_Vid_DelayUs(u32 copy_u32_delay);
/*****************************************************************************
* Function Name: TIME0_Vid_FastPWM
* Purpose      : CONTROL THE WIDTH OF THE PULSE 
* Parameters   : u8 copy_u8_duty
* Return value : VOID
*****************************************************************************/
void TIMER0_Vid_FastPWM(u8 copy_u8_duty);
/****************************************************************************************************/

/* SELECT MODE */
#define CTC_MODE   1
#define OV_MODE    2

/* OCR VALUE */
#define OCR0_VAL  250

/* PRESCALER MACROS */
#define TIMER_STOP        0X00
#define NO_PRESCALAR      0X01
#define _2_PRESCALAR      0X02
#define _64_PRESCALAR     0X03
#define _256_PRESCALAR    0X04
#define _1024_PRESCALAR   0X05

/* SELECT PRESCALER */
#define TIMER0_PRESCALER_Ms  NO_PRESCALAR
#define TIMER0_PRESCALER_Us  NO_PRESCALAR

#endif /* TIMER0_INTERFACE_H_ */