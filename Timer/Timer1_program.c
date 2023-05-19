/*
 * Timer1_program.c
 *
 *  Created on: Dec 25, 2021
 *      Author: Omar
 */


#include "util/delay.h"

#include "std_types.h"
#include "BIT_MATH.h"

#include "Dio_interface.h"
#include "Global_Interrupt_interface.h"
#include "Timer1_reg.h"
#include "Timer1_interface.h"
#include "Timer1_config.h"


#define NULL 		(void*)0

void (*OVTimer1_pvOVtimerfunction)(void) = NULL; // this is a pointer to function

void (*CTCATimer1_pvCTCtimerfunction)(void) = NULL;

void Timer1_voidInit(void)
{

#if(TIMER_MODE == OVERFLOW)

	/*enable Timer overflow interrupt*/
	SET_BIT(TIMSK,TIMSK_TOIE1);
	/**choose OverFlow Mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1A,TCCR1B_WGM12);
	CLR_BIT(TCCR1A,TCCR1B_WGM13);
	/*prescaler*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

#elif(TIMER_MODE == CTC_A)
	/*enable Timer CTC compare match A interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE1A);
	/**choose OverFlow Mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1A,TCCR1B_WGM12);
	CLR_BIT(TCCR1A,TCCR1B_WGM13);
	/*OC1A activation*/
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/*prescaler*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);

#elif(TIMER_MODE == FAST_PWM)
	/**choose FAST_PWM TOP OCR1A Mode*/
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	/*Enable o/p compare match A interrupt */
	//SET_BIT(TIMSK,TIMSK_OCIE1A);
	/*enable Timer overflow interrupt*/
	//SET_BIT(TIMSK,TIMSK_TOIE1);
	/*OC1A activation*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	/*prescaler*/
	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);


#endif
	GlobalInterrupt_Enable();
}

u8 Timer1OV_u8OVtimerCallback(void (*Copy_pvOVTimer1Function)(void))
{
	u8 Local_u8ReturnStatus = OK;

	if(Copy_pvOVTimer1Function != NULL)
	{
		OVTimer1_pvOVtimerfunction = Copy_pvOVTimer1Function;
	}
	else
	{
		Local_u8ReturnStatus = NOK;
	}
	return Local_u8ReturnStatus;
}

void __vector_9(void)
{
	//static f32 counter = 0;
	//counter++;
	//if(counter >= 3906) // this is a condition for one sec overflow
	//if(counter >= 16)
	//{
		if( OVTimer1_pvOVtimerfunction != NULL)
		{
			OVTimer1_pvOVtimerfunction();
		}
		//counter = 0;
	//	CLR_BIT(TIFR, TIFR_TOV1);
	//}
}

u8 Timer1CTCA_u8CTCtimerCallback(void (*Copy_CTCTimer1Function)(void))
{
	u8 Local_u8ReturnStatus = OK;

	if(Copy_CTCTimer1Function != NULL)
	{
		CTCATimer1_pvCTCtimerfunction = Copy_CTCTimer1Function;
	}
	else
	{
		Local_u8ReturnStatus = NOK;
	}
	return Local_u8ReturnStatus;
}
void __vector_7(void)
{
	//static f32 counter = 0;
	//counter++;
	//if(counter >= 468.75)
	//{
		if( CTCATimer1_pvCTCtimerfunction != NULL)
		{
			CTCATimer1_pvCTCtimerfunction();
		}
	//	counter = 0;
	//}
}
void Timer1_SetCompareMatchA_Value(u16 Copy_CompareValue)
{
	OCR1AL_H = Copy_CompareValue;

}
void Timer1_SetTimer1value(u16 Copy_TimerValue)
{
	TCNT1L_H = Copy_TimerValue;
}

void Timer1PWM_A_OC1A(u8 Copy_BitValue)
{
	if(Copy_BitValue == 1)
	{
		SET_BIT(TCCR1A,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	}
	else if(Copy_BitValue == 0)
	{
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	}
}
