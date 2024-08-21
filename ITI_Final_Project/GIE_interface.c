#include "MATH.h"
#include "STD_TYPE.h"
#include "GIE_private.h"

void GIE_Vid_Interrupt_Enable(void){
	
	SET_BIT(SREG_REG,7) ;
	// SEI --> set   i    intruction assembly most take one clock cycle
	// __asm volatile("SEI");
}

void GIE_Vid_Interrupt_Disable(void){
	//CLR_BIT(SREG_REG,7) ;
	// CLI --> clear i
	__asm volatile("CLI");
}
