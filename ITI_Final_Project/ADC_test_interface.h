/*
 * ADC_test_interface.h
 *
 * Created: 9/16/2023 3:53:38 PM
 *  Author: Hima
 */ 


#ifndef ADC_TEST_INTERFACE_H_
#define ADC_TEST_INTERFACE_H_

/*

	1- division_2
	2- division_4
	3- division_8
	4- division_16
	5- division_32
	6- division_64
	7- division_128

*/

#define DIVISION_2		1	// 001
#define DIVISION_4		2   // 010
#define DIVISION_8		3   // 011
#define DIVISION_16		4   // 100
#define DIVISION_32		5   // 101
#define DIVISION_64		6   // 110
#define DIVISION_128	7   // 111

//#define PRESCALER DIVISION_128

void ADC_Vid_Init();

u16 ADC_u16_Read(u8 copy_u8_channel);

#endif /* ADC_TEST_INTERFACE_H_ */