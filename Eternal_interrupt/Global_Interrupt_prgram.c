/*
 * Global_Interrupt_prgram.c
 *
 *  Created on: 24 Aug 2021
 *      Author: omar
 */

#include "std_types.h"
#include "BIT_MATH.h"
#include "Global_Interrupt_reg.h"


void GlobalInterrupt_Enable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GlobalInterrupt_Disable(void)
{
	CLR_BIT(SREG,SREG_I);
}
