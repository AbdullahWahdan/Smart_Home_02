/*
 * Tim1_private.h
 *
 * Created: 10/5/2023 7:48:30 PM
 *  Author: user
 */ 


#ifndef TIM1_PRIVATE_H_
#define TIM1_PRIVATE_H_


#define TCCR1A_REG  *((volatile u8*)0x4f)

#define TCCR1B_REG  *((volatile u8*)0x4e)

#define TCNT1_REG  *((volatile u16*)0x4c)

#define OCR1A_REG  *((volatile u16*)0x4a)

#define OCR1B_REG  *((volatile u16*)0x48)

#define ICR1_REG   *((volatile u16*)0x46)

#define TIMSK_REG *((volatile u8*)0x59)

#define TIFR_REG  *((volatile u8*)0x58)

#endif /* TIM1_PRIVATE_H_ */