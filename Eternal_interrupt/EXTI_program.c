/*
 * EXTI_program.c
 *
 *  Created on: 18 Aug 2021
 *      Author: omar
 */

#include "std_types.h"
#include "BIT_MATH.h"

#include "Dio_interface.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"

#define NULL (void*)0

void (*EXTI_pvINT0Function)(void) = NULL; // this is a pointer to function
void (*EXTI_pvINT1Function)(void) = NULL;
void (*EXTI_pvINT2Function)(void) = NULL;

//void *(EXTI_pvINTFunction)(void)[2]={NULL,NULL};

u8 EXTI0_voidInit(u8 Copy_u8SenseLevel)
{
	u8 Local_u8check = OK ;
	/*1-Set Direction Pin --> Input*/
	DIO_voidSetPinDirection(EXTI_INT_PORT, EXTI_INT0_PIN, DIO_u8INPUT);

	/*2-Enable Pull up Resistor*/
	DIO_voidSetPinValue(EXTI_INT_PORT, EXTI_INT0_PIN, DIO_u8HIGH);

	/*3-Enable PIE of INT0*/
	SET_BIT(GICR,GICR_INT0);

	/*4-Enable GIE Global Interrupt*/
	SET_BIT(SREG ,SREG_I);

	/*5-Choose Sense Level*/
	switch(Copy_u8SenseLevel)
	{
		case EXTI_LOW_LEVEL	 :  	CLR_BIT(MCUCR,MCUCR_ISC00)	;
									CLR_BIT(MCUCR,MCUCR_ISC01)	;
														break;
		case EXTI_RISING_EDGE:	   	SET_BIT(MCUCR,MCUCR_ISC00)	;
									SET_BIT(MCUCR,MCUCR_ISC01)	;
														break;
		case EXTI_FALLING_EDGE:		CLR_BIT(MCUCR,MCUCR_ISC00)	;
									SET_BIT(MCUCR,MCUCR_ISC01)	;
														break;
		case EXTI_ON_CHANGE:		SET_BIT(MCUCR,MCUCR_ISC00)	;
									CLR_BIT(MCUCR,MCUCR_ISC01)	;
														break;
		default:	return NOK;							break;
	}
	return Local_u8check;
}

u8 EXTI1_voidInit(u8 Copy_u8SenseLevel)
{
	u8 Local_u8check = OK ;

		/*1-Set Direction Pin --> Input*/
		DIO_voidSetPinDirection(EXTI_INT_PORT, EXTI_INT1_PIN, DIO_u8INPUT);

		/*2-Enable Pull up Resistor*/
		DIO_voidSetPinValue(EXTI_INT_PORT, EXTI_INT1_PIN, DIO_u8HIGH);

		/*3-Enable PIE of INT1*/
		SET_BIT(GICR,GICR_INT1);

		/*4-Enable GIE Global Interrupt*/
		SET_BIT(SREG ,SREG_I);

		/*5-Choose Sense Level*/
		switch(Copy_u8SenseLevel)
		{
			case EXTI_LOW_LEVEL	 :  	CLR_BIT(MCUCR,MCUCR_ISC00)	;
										CLR_BIT(MCUCR,MCUCR_ISC01)	;
															break;
			case EXTI_RISING_EDGE:	   	SET_BIT(MCUCR,MCUCR_ISC00)	;
										SET_BIT(MCUCR,MCUCR_ISC01)	;
															break;
			case EXTI_FALLING_EDGE:		CLR_BIT(MCUCR,MCUCR_ISC00)	;
										SET_BIT(MCUCR,MCUCR_ISC01)	;
															break;
			case EXTI_ON_CHANGE:		SET_BIT(MCUCR,MCUCR_ISC00)	;
										CLR_BIT(MCUCR,MCUCR_ISC01)	;
															break;
			default:	return NOK;							break;
		}
		return Local_u8check;
}

u8 EXTI2_voidInit(u8 Copy_u8SenseLevel)
{
	u8 Local_u8check = OK ;

		/*1-Set Direction Pin --> Input*/
		DIO_voidSetPinDirection(EXTI2_INT_PORT, EXTI_INT2_PIN, DIO_u8INPUT);

		/*2-Enable Pull up Resistor*/
		DIO_voidSetPinValue(EXTI2_INT_PORT, EXTI_INT2_PIN, DIO_u8HIGH);

		/*3-Enable PIE of INT2*/
		SET_BIT(GICR,GICR_INT2);

		/*4-Enable GIE Global Interrupt*/
		SET_BIT(SREG ,SREG_I);

		/*5-Choose Sense Level*/
		switch(Copy_u8SenseLevel)
		{
			case EXTI_RISING_EDGE:	   	SET_BIT(MCUCSR,MCUCSR_ISC2)	;
															break;
			case EXTI_FALLING_EDGE:		CLR_BIT(MCUCSR,MCUCSR_ISC2)	;
															break;
			default:	return NOK;							break;
		}
		return Local_u8check;
}

/*
 *  function (to change sense level of any interrupt)  take --> Interrupt Number , Sense level
 *  function to (Enable of PIE of any interrupt i.e any peripheral takes --> interrupt number)
 *  function to (Disable of PIE of any interrupt i.e any peripheral takes --> interrupt number)
 *  function to Disable/ Enable Global INT SREG
 *  ----------------------------------------------------------------
 *   (SREG is an INT shared with all interrupts so it is better to make new files of it  )
 *   Enable/Disable Global INT
 *   GlobalINT_program.c
 *   GlobalINT_interface.h
 *   GlobalInt_register.h
 *  */


/*pointer --->type --> pointer function
 * returnType (*pointerName)(type inputArgument) ;*/
u8 EXTI_u8INT0SetCallback(void (*Copy_pvINTFunction)(void) )
{
	u8 Local_u8ReturnStatus = OK;
	if(Copy_pvINTFunction != NULL)
	{
		EXTI_pvINT0Function = Copy_pvINTFunction;
	}
	else
	{
		Local_u8ReturnStatus = NOK;
	}
	return Local_u8ReturnStatus;
}
u8 EXTI_u8INT1SetCallback(void (*Copy_pvINTFunction)(void) )
{
	u8 Local_u8ReturnStatus = OK;
	if(Copy_pvINTFunction != NULL)
	{
		EXTI_pvINT1Function = Copy_pvINTFunction;
	}
	else
	{
		Local_u8ReturnStatus = NOK;
	}
	return Local_u8ReturnStatus;
}
u8 EXTI_u8INT2SetCallback(void (*Copy_pvINTFunction)(void) )
{
	u8 Local_u8ReturnStatus = OK;
	if(Copy_pvINTFunction != NULL)
	{
		EXTI_pvINT2Function = Copy_pvINTFunction;
	}
	else
	{
		Local_u8ReturnStatus = NOK;
	}
	return Local_u8ReturnStatus;
}
void EXTI_u8INT0DisableOrEnable(u8 Copy_u8State)
{

	if(Copy_u8State == EXTI_ON)
	{/*Enable PIE of INT0*/
		SET_BIT(GICR,GICR_INT0);
	}
	else if(Copy_u8State == EXTI_OFF)
	{
	/*Disable PIE of INT0*/
		CLR_BIT(GICR,GICR_INT0);
	}
}
void __vector_1(void)
{
	if( EXTI_pvINT0Function != NULL)
	{
		EXTI_pvINT0Function();
	//ADDRESS func in app --> &INTISR0
	}
}
void __vector_2(void)
{
	if( EXTI_pvINT1Function != NULL)
	{
		EXTI_pvINT1Function();  //calling pointer to func is the same as calling a func
	}
}
void __vector_3(void)
{
	if( EXTI_pvINT2Function != NULL)
	{
		EXTI_pvINT2Function();  //calling pointer to func is the same as calling a func
	}
}


