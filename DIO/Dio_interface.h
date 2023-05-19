/*
 * Dio_interface.h
 *
 *  Created on: 12 Aug 2021
 *      Author: omar
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*Port Defines*/

#define DIO_u8PORT_A 			0
#define DIO_u8PORT_B 			1
#define DIO_u8PORT_C 			2
#define DIO_u8PORT_D 			3


/*Pins Defines*/
#define DIO_u8PIN_0 			0
#define DIO_u8PIN_1 			1
#define DIO_u8PIN_2 			2
#define DIO_u8PIN_3 			3
#define DIO_u8PIN_4 			4
#define DIO_u8PIN_5 			5
#define DIO_u8PIN_6 			6
#define DIO_u8PIN_7 			7

/*value*/
#define DIO_u8HIGH 				1
#define DIO_u8LOW 				0
/*Direction of Pin*/
#define DIO_u8OUTPUT			1
#define DIO_u8INPUT				0
/*Upper or Lower Nibble*/
#define DIO_u8UPPER				1
#define DIO_u8LOWER				0



/*IO Pins*/
void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDir);

void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId);

void DIO_u8TogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

/*Port Pins*/

void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PinDir);

void DIO_voidSetPortValue(u8 Copy_u8PortId,u8 Copy_u8PinsValues);

u8 DIO_u8GetPortValue(u8 Copy_u8PortId);



u8 DIO_u8GetNibbleValue(u8 Copy_u8PortId, u8 Copy_u8UpperOrLower);


#endif /* DIO_INTERFACE_H_ */
