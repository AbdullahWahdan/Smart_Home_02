/*
 * ADC_test_private.h
 *
 * Created: 9/16/2023 3:58:44 PM
 *  Author: Hima
 */ 


#ifndef ADC_TEST_PRIVATE_H_
#define ADC_TEST_PRIVATE_H_

#define ADMUX_REG   *((volatile u8*)0x27)
#define ADCSRA_REG  *((volatile u8*)0x26)
#define ADC_REG     *((volatile u16*)0x24) // ADCL + ADCH

#define HIGH  1
#define LOW   0

#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4

#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIF  4
#define ADSC  6
#define ADEN  7


#endif /* ADC_TEST_PRIVATE_H_ */