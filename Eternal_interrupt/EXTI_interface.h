/*
 * EXTI_interface.h
 *
 *  Created on: 18 Aug 2021
 *      Author: omar
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_INT_PORT 		DIO_u8PORT_D
#define EXTI_INT0_PIN			2
#define EXTI_INT1_PIN			3

#define EXTI2_INT_PORT 		DIO_u8PORT_B
#define EXTI_INT2_PIN			2

#define EXTI_LOW_LEVEL			0
#define EXTI_RISING_EDGE		1
#define EXTI_FALLING_EDGE		2
#define EXTI_ON_CHANGE			3

#define EXTI_ON				1
#define EXTI_OFF			0


#define OK  0
#define NOK  1

/*vector number in page 42 in DATASHEET and the number is less than that in sheet by 1 */
/*Prototype Of PIN INT0*/
void __vector_1(void)__attribute__((signal));
/*Prototype Of PIN INT1*/
void __vector_2(void)__attribute__((signal));
/*Prototype Of PIN INT2*/
void __vector_3(void)__attribute__((signal));

u8 EXTI0_voidInit(u8 Copy_u8SenseLevel);

u8 EXTI1_voidInit(u8 Copy_u8SenseLevel);

u8 EXTI2_voidInit(u8 Copy_u8SenseLevel);


u8 EXTI_u8INT0SetCallback(void (*Copy_pvINTFunction)(void) );
u8 EXTI_u8INT1SetCallback(void (*Copy_pvINTFunction)(void) );
u8 EXTI_u8INT2SetCallback(void (*Copy_pvINTFunction)(void) );

void EXTI_u8INT0DisableOrEnable(u8 Copy_u8State);

#endif /* EXTI_INTERFACE_H_ */
