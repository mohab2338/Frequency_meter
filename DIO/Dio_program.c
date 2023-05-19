/*
 * Dio_program.c
 *
 *  Created on: 12 Aug 2021
 *      Author: omar
 */
#include "std_types.h"
#include "BIT_MATH.h"


#include "Dio_interface.h"
#include "Dio_reg.h"

//--------------------------------------------------------------------------------------------


// PIN Direction
void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDir)
{
	if( ( (Copy_u8PortId <= DIO_u8PORT_D)&&(Copy_u8PortId >= DIO_u8PORT_A ) ) && ( (Copy_u8PinId <= DIO_u8PIN_7)&&(Copy_u8PinId <= DIO_u8PIN_7) ) )
	{
		if(Copy_u8PinDir == DIO_u8OUTPUT)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A :		SET_BIT(DDRA,Copy_u8PinId); break;
			case DIO_u8PORT_B :		SET_BIT(DDRB,Copy_u8PinId); break;
			case DIO_u8PORT_C :		SET_BIT(DDRC,Copy_u8PinId); break;
			case DIO_u8PORT_D :		SET_BIT(DDRD,Copy_u8PinId); break;

			}
		}
		else if(Copy_u8PinDir == DIO_u8INPUT )
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A:		CLR_BIT(DDRA,Copy_u8PinId); break;
			case DIO_u8PORT_B:		CLR_BIT(DDRB,Copy_u8PinId); break;
			case DIO_u8PORT_C:		CLR_BIT(DDRC,Copy_u8PinId); break;
			case DIO_u8PORT_D:		CLR_BIT(DDRD,Copy_u8PinId); break;

			}
		}
		else
		{
			//Nothing error
		}
	}
}
//--------------------------------------------------------------------------------------------

//set PIN Value
void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue)
{
	if( ( (Copy_u8PortId <= DIO_u8PORT_D)&&(Copy_u8PortId >= DIO_u8PORT_A ) ) && ( (Copy_u8PinId <= DIO_u8PIN_7)&&(Copy_u8PinId <= DIO_u8PIN_7) ) )
	{
		if(Copy_u8PinValue == DIO_u8HIGH)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A :		SET_BIT(PORTA,Copy_u8PinId); break;
			case DIO_u8PORT_B :		SET_BIT(PORTB,Copy_u8PinId); break;
			case DIO_u8PORT_C :		SET_BIT(PORTC,Copy_u8PinId); break;
			case DIO_u8PORT_D :		SET_BIT(PORTD,Copy_u8PinId); break;
			}
		}
		else if(Copy_u8PinValue == DIO_u8LOW )
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8PORT_A:		CLR_BIT(PORTA,Copy_u8PinId); break;
			case DIO_u8PORT_B:		CLR_BIT(PORTB,Copy_u8PinId); break;
			case DIO_u8PORT_C:		CLR_BIT(PORTC,Copy_u8PinId); break;
			case DIO_u8PORT_D:		CLR_BIT(PORTD,Copy_u8PinId); break;
			}
		}
		else
		{
			//Nothing error
		}
	}
}
//--------------------------------------------------------------------------------------------

// check the value in pins
u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId)
{
	u8 Local_u8ReadPinVal = 0; //local variable to

	if( ( (Copy_u8PortId <= DIO_u8PORT_D)&&(Copy_u8PortId >= DIO_u8PORT_A ) ) && ( (Copy_u8PinId <= DIO_u8PIN_7)&&(Copy_u8PinId <= DIO_u8PIN_7) ) )
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8PORT_A :		Local_u8ReadPinVal = GET_BIT(PINA,Copy_u8PinId); break;
		case DIO_u8PORT_B :		Local_u8ReadPinVal = GET_BIT(PINB,Copy_u8PinId); break;
		case DIO_u8PORT_C :		Local_u8ReadPinVal = GET_BIT(PINC,Copy_u8PinId); break;
		case DIO_u8PORT_D :		Local_u8ReadPinVal = GET_BIT(PIND,Copy_u8PinId); break;
		}
	}
	else
	{
		Local_u8ReadPinVal = 0xff;
	}
	return Local_u8ReadPinVal;
}


void DIO_u8TogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	if( ( (Copy_u8PortId <= DIO_u8PORT_D)&&(Copy_u8PortId >= DIO_u8PORT_A ) ) && ( (Copy_u8PinId <= DIO_u8PIN_7)&&(Copy_u8PinId <= DIO_u8PIN_7) ) )
	{

		switch(Copy_u8PortId)
		{
		case DIO_u8PORT_A :		TGL_BIT(PORTA,Copy_u8PinId); break;
		case DIO_u8PORT_B :		TGL_BIT(PORTB,Copy_u8PinId); break;
		case DIO_u8PORT_C :		TGL_BIT(PORTC,Copy_u8PinId); break;
		case DIO_u8PORT_D :		TGL_BIT(PORTD,Copy_u8PinId); break;
		}
	}
}

//--------------------------------------------------------------------------------------------

u8 DIO_u8GetPortValue(u8 Copy_u8PortId)
{
	u8 Local_u8ReadPinVal[8] = {0};
	u8 Local_u8PortValue;
	if( ( (Copy_u8PortId <= DIO_u8PORT_D)&&(Copy_u8PortId >= DIO_u8PORT_A )  ) )
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8PORT_A :
			Local_u8ReadPinVal[0] = GET_BIT(PINA,DIO_u8PIN_0);
			Local_u8ReadPinVal[1] = GET_BIT(PINA,DIO_u8PIN_1);
			Local_u8ReadPinVal[2] = GET_BIT(PINA,DIO_u8PIN_2);
			Local_u8ReadPinVal[3] = GET_BIT(PINA,DIO_u8PIN_3);
			Local_u8ReadPinVal[4] = GET_BIT(PINA,DIO_u8PIN_4);
			Local_u8ReadPinVal[5] = GET_BIT(PINA,DIO_u8PIN_5);
			Local_u8ReadPinVal[6] = GET_BIT(PINA,DIO_u8PIN_6);
			Local_u8ReadPinVal[7] = GET_BIT(PINA,DIO_u8PIN_7);
			break;

		case DIO_u8PORT_B :
			Local_u8ReadPinVal[0] = GET_BIT(PINB,DIO_u8PIN_0);
			Local_u8ReadPinVal[1] = GET_BIT(PINB,DIO_u8PIN_1);
			Local_u8ReadPinVal[2] = GET_BIT(PINB,DIO_u8PIN_2);
			Local_u8ReadPinVal[3] = GET_BIT(PINB,DIO_u8PIN_3);
			Local_u8ReadPinVal[4] = GET_BIT(PINB,DIO_u8PIN_4);
			Local_u8ReadPinVal[5] = GET_BIT(PINB,DIO_u8PIN_5);
			Local_u8ReadPinVal[6] = GET_BIT(PINB,DIO_u8PIN_6);
			Local_u8ReadPinVal[7] = GET_BIT(PINB,DIO_u8PIN_7);
			break;

		case DIO_u8PORT_C :
			Local_u8ReadPinVal[0] = GET_BIT(PINC,DIO_u8PIN_0);
			Local_u8ReadPinVal[1] = GET_BIT(PINC,DIO_u8PIN_1);
			Local_u8ReadPinVal[2] = GET_BIT(PINC,DIO_u8PIN_2);
			Local_u8ReadPinVal[3] = GET_BIT(PINC,DIO_u8PIN_3);
			Local_u8ReadPinVal[4] = GET_BIT(PINC,DIO_u8PIN_4);
			Local_u8ReadPinVal[5] = GET_BIT(PINC,DIO_u8PIN_5);
			Local_u8ReadPinVal[6] = GET_BIT(PINC,DIO_u8PIN_6);
			Local_u8ReadPinVal[7] = GET_BIT(PINC,DIO_u8PIN_7);
			break;

		case DIO_u8PORT_D :
			Local_u8ReadPinVal[0] = GET_BIT(PIND,DIO_u8PIN_0);
			Local_u8ReadPinVal[1] = GET_BIT(PIND,DIO_u8PIN_1);
			Local_u8ReadPinVal[2] = GET_BIT(PIND,DIO_u8PIN_2);
			Local_u8ReadPinVal[3] = GET_BIT(PIND,DIO_u8PIN_3);
			Local_u8ReadPinVal[4] = GET_BIT(PIND,DIO_u8PIN_4);
			Local_u8ReadPinVal[5] = GET_BIT(PIND,DIO_u8PIN_5);
			Local_u8ReadPinVal[6] = GET_BIT(PIND,DIO_u8PIN_6);
			Local_u8ReadPinVal[7] = GET_BIT(PIND,DIO_u8PIN_7);


			break;
		}
		Local_u8PortValue = 1*Local_u8ReadPinVal[0] + 2*Local_u8ReadPinVal[1] + 4*Local_u8ReadPinVal[2]
						   +8*Local_u8ReadPinVal[3] + 16*Local_u8ReadPinVal[4] + 32*Local_u8ReadPinVal[5]
		                   +64*Local_u8ReadPinVal[6]+128*Local_u8ReadPinVal[7] ;
	}
	else
	{
		Local_u8PortValue = 0xff;
	}


	return Local_u8PortValue;

}
//--------------------------------------------------------------------------------------------

u8 DIO_u8GetNibbleValue(u8 Copy_u8PortId, u8 Copy_u8UpperOrLower)
{
	u8 Local_u8ReadPinVal[8] = {0};
	u8 Local_u8PortValue;
	if( ( (Copy_u8PortId <= DIO_u8PORT_D)&&(Copy_u8PortId >= DIO_u8PORT_A )  ) )
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8PORT_A :
			Local_u8ReadPinVal[0 ] = GET_BIT(PINA,DIO_u8PIN_0 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[1 ] = GET_BIT(PINA,DIO_u8PIN_1 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[2 ] = GET_BIT(PINA,DIO_u8PIN_2 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[3 ] = GET_BIT(PINA,DIO_u8PIN_3 + 4*Copy_u8UpperOrLower);
			break;

		case DIO_u8PORT_B :
			Local_u8ReadPinVal[0 ] = GET_BIT(PINB,DIO_u8PIN_0 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[1 ] = GET_BIT(PINB,DIO_u8PIN_1 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[2 ] = GET_BIT(PINB,DIO_u8PIN_2 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[3 ] = GET_BIT(PINB,DIO_u8PIN_3 + 4*Copy_u8UpperOrLower);
			break;

		case DIO_u8PORT_C :
			Local_u8ReadPinVal[0 ] = GET_BIT(PINC,DIO_u8PIN_0 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[1 ] = GET_BIT(PINC,DIO_u8PIN_1 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[2 ] = GET_BIT(PINC,DIO_u8PIN_2 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[3 ] = GET_BIT(PINC,DIO_u8PIN_3 + 4*Copy_u8UpperOrLower);
			break;

		case DIO_u8PORT_D :
			Local_u8ReadPinVal[0 ] = GET_BIT(PIND,DIO_u8PIN_0 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[1 ] = GET_BIT(PIND,DIO_u8PIN_1 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[2 ] = GET_BIT(PIND,DIO_u8PIN_2 + 4*Copy_u8UpperOrLower);
			Local_u8ReadPinVal[3 ] = GET_BIT(PIND,DIO_u8PIN_3 + 4*Copy_u8UpperOrLower);
			break;

		}
		Local_u8PortValue = 1*Local_u8ReadPinVal[0] + 2*Local_u8ReadPinVal[1]
						    + 4*Local_u8ReadPinVal[2] +8*Local_u8ReadPinVal[3] ;

	}
	else
	{
		Local_u8PortValue = 0xff;
	}


	return Local_u8PortValue;

}
//--------------------------------------------------------------------------------------------

void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PinDir)
{

	switch(Copy_u8PortId)
	{
	case DIO_u8PORT_A :		DDRA = Copy_u8PinDir;  break;
	case DIO_u8PORT_B :		DDRB = Copy_u8PinDir;  break;
	case DIO_u8PORT_C :		DDRC = Copy_u8PinDir;  break;
	case DIO_u8PORT_D :		DDRD = Copy_u8PinDir;  break;
	default : /*Wrong port*/ break;
	}
}

//--------------------------------------------------------------------------------------------

void DIO_voidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8PinsValues)
{

	switch(Copy_u8PortId)
	{
	case  DIO_u8PORT_A : PORTA = Copy_u8PinsValues ; break;
	case  DIO_u8PORT_B : PORTB = Copy_u8PinsValues ; break;
	case  DIO_u8PORT_C : PORTC = Copy_u8PinsValues ; break;
	case  DIO_u8PORT_D : PORTD = Copy_u8PinsValues ; break;


	}
}

