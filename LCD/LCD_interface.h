/*
 * LCD_interface.h
 *
 *  Created on: 15 Aug 2021
 *      Author: omar
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);

/*send string to display*/
void LCD_voidSendString(const char* Copy_pcString);

/*move the cursor to position by x and y*/
void LCD_voidGotoxy(u8 Copy_u8xPos, u8 Copy_u8yPos );

/*special characters*/
void LCD_voidwriteSpecialCharacter(u8 Copy_pu8Pattern[], u8 Copy_u8PatternNumber, u8 Copy_u8xPos, u8 Copy_u8yPos );

/*Clear screen*/
void LCD_voidClearScreen();
#endif /* LCD_INTERFACE_H_ */
