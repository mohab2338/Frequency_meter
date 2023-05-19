/*
 * Global_Interrupt_reg.h
 *
 *  Created on: 24 Aug 2021
 *      Author: omar
 */

#ifndef GLOBAL_INTERRUPT_REG_H_
#define GLOBAL_INTERRUPT_REG_H_

#define SREG					*((volatile u8*)0x5F)
/*PINS
 *I:Global Interrupt Enable
 *The Global Interrupt Enable bit must be set for the interrupts to be enabled.*/
/*PINS numbers*/
#define SREG_I						7

#endif /* GLOBAL_INTERRUPT_REG_H_ */
