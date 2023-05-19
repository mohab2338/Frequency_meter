/*************************************************
*  FILE  DESCRIPTION
*------------------------------------------------
*     File: main.c
*     Description: Application of Frequency meter
*
****************************************************/

#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_types.h"
#include "BIT_MATH.h"
#include "Dio_interface.h"
#include "EXTI_interface.h"
#include "Timer1_interface.h"
#include "LCD_interface.h"

#define REESOLUTION    15 /*Any number depends on the resolution of the meter*/
u16 Result_Array[REESOLUTION] = {0};
u32 Edges ; /*Number of edges in time period*/
u32 Freq;   /* Frequency */

void edge();
void Freq_Calculate();
void Display_result(u32 Displayed_Value);
void Initializations();


int main(void)
{
	Initializations();
	while(1);
}
void edge(void)
{
	Edges++;
}

void Freq_Calculate()
{

	LCD_voidClearScreen();
	Freq = Edges/1;
	_delay_us(500);
	if( (Freq < 1000) ){
		Display_result(Edges);
	}
	else if( (Freq>=1000)&&(Freq < 10000 ) )
	{
		Display_result(Freq/1000);
		LCD_voidSendString("K");
	}
	else if( (Freq>=10000)&&(Freq < 100000 ) )
	{
		Display_result(Freq/1000);
	    LCD_voidSendString("K");

	}
	else if( (Freq>=100000)&&(Freq < 1000000 ) )
	{
		Display_result(Freq/1000);
		LCD_voidSendData('k');

	}
	LCD_voidSendString(" Hz");
		Edges = 0;
		Timer1_SetTimer1value(34286);
}

void Display_result(u32 Displayed_Value){
	u32 Local_resolution = 0;
	u32 temp = Displayed_Value;
	while(temp != 0 )
	{
		if( (temp = temp/10)==0)  break;
		Local_resolution = Local_resolution + 1;
	}

	temp = Local_resolution;
	Local_resolution = 0;

	while(Local_resolution <= temp )
	{

		Result_Array[temp - Local_resolution] = (  Displayed_Value - ( (Displayed_Value/10 )*10 )  );
		Displayed_Value = (Displayed_Value/10 );
		Local_resolution = Local_resolution + 1;
	}

	Local_resolution = 0;

	for(int i = 0; i <= temp ;i++)
	{
		LCD_voidSendData(Result_Array[i] + '0');
	}
}
void Initializations()
{
	LCD_voidInit();
    EXTI0_voidInit( EXTI_RISING_EDGE );
    EXTI_u8INT0SetCallback(edge);

    Timer1_SetTimer1value(34286);/*this number to trigger interrupt after exactly 1 sec*/
	Timer1CTCA_u8CTCtimerCallback(Freq_Calculate);
	Timer1_voidInit();

}
/*
 * This meter measures frequency up to 59k Hz
 */

