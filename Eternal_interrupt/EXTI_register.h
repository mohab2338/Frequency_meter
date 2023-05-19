/*
 * EXTI_register.h
 *
 *  Created on: 18 Aug 2021
 *      Author: omar
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


/* MCU Control Register
 * MCUCR --> sense Level INT1 INT0*/
#define MCUCR					*((volatile u8*)0x55)
/*PINS*/							/*PINS numbers*/
#define MCUCR_ISC00					0
#define MCUCR_ISC01					1
#define MCUCR_ISC10					2
#define MCUCR_ISC11					3


/*MCU Control and Status Register
 * MCUCSR --> Interrupt Sense Control 2*/
#define MCUCSR					*((volatile u8*)0x54)
/*PINS*/							/*PINS numbers*/
#define MCUCSR_ISC2					6

/*General Interrupt Control Register
 * enable peripheral interrupt
 * GICR**/
#define GICR					*((volatile u8*)0x5B)
/*PINS*/							/*PINS numbers*/
#define GICR_INT0					6
#define GICR_INT1					7
#define GICR_INT2					5

/* General Interrupt Flag Register
 *  GIFR*/
#define GIFR					*((volatile u8*)0x5A)
/*PINS*/							/*PINS numbers*/
#define GIFR_INT0					6
#define GIFR_INT1					7
#define GIFR_INT2					5

/*Status Register
 * SREG*/
#define SREG					*((volatile u8*)0x5F)
/*PINS
 *I:Global Interrupt Enable
 *The Global Interrupt Enable bit must be set for the interrupts to be enabled.*/
								/*PINS numbers*/
#define SREG_I						7


#endif /* EXTI_REGISTER_H_ */
