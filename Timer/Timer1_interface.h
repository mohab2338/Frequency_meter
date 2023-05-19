/*
 * Timer1_interface.h
 *
 *  Created on: Feb 20, 2022
 *      Author: mhy
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define OK    0
#define NOK	  1
#define OVERFLOW		0
#define CTC_A			1
#define FAST_PWM		2




void Timer1_voidInit(void);

u8 Timer1OV_u8OVtimerCallback(void (*Copy_pvOVTimer1Function)(void));
u8 Timer1CTCA_u8CTCtimerCallback(void (*Copy_CTCTimer1Function)(void));

void Timer1_SetCompareMatchA_Value(u16 Copy_CompareValue);
void Timer1_SetTimer1value(u16 Copy_TimerValue);
void Timer1PWM_A_OC1A(u8 Copy_BitValue);
void __vector_7(void)__attribute__((signal));
void __vector_9(void)__attribute__((signal));

#endif /* TIMER1_INTERFACE_H_ */
