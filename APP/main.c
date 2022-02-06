/*
 * main.c
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */
#include"util/delay.h"
#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
#include "../MCAL/PORT_Driver/PORT_Private.h"
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../MCAL/ADC_Driver/ADC_Interface.h"
#include "../MCAL/ADC_Driver/ADC_Config.h"
#include "../MCAL/ADC_Driver/ADC_Private.h"
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../HAL/LM35_Module/LM35_Interface.h"


/*void __vector_1 (void) __attribute__((signal));*/

const f32 step=4.8828125;
u32 AVO_Meter(u16 Copy_u16DigitalReading,u32*Copy_pu32Rest_Float);

u32 Global_u32Rest_Flaot=0;
int main(void)
{
	PORT_VoidInit();
	LCD_VoidInit();
	LM35_VoidInit();
     u16 LDR;


	while(1)
	{


	LCD_VoidClearDisplay();
	ADC_u8GetDigitalValChannel(SINGLE_ENDED_CHANNEL_ADC1,&LDR);
	LCD_VoidSendString("Res=");

if(AVO_Meter(LDR,&Global_u32Rest_Flaot)<1000)
{
	LCD_VoidSendNumber(AVO_Meter(LDR,&Global_u32Rest_Flaot));
	LCD_VoidSendString(" Ohm");
}
else if (AVO_Meter(LDR, &Global_u32Rest_Flaot)>=1000||AVO_Meter(LDR, &Global_u32Rest_Flaot)<=1000000)
{
	LCD_VoidSendNumber(AVO_Meter(LDR,&Global_u32Rest_Flaot)/1000);
	LCD_VoidSendData('.');
	LCD_VoidSendNumber(Global_u32Rest_Flaot);
		LCD_VoidSendString(" K Ohm");
}
else
{
	LCD_VoidSendNumber(AVO_Meter(LDR,&Global_u32Rest_Flaot)/1000000);
		LCD_VoidSendString(" M Ohm");
}

	}

	return 0;

}








u32 AVO_Meter(u16 Copy_u16DigitalReading,u32*Copy_pu32Rest_Float)
{
	u32 Resistance_Measure=(Copy_u16DigitalReading*step*220)/(5000-Copy_u16DigitalReading*step);
	if(Resistance_Measure>1000&&Resistance_Measure<2000)
	{
		*Copy_pu32Rest_Float=Resistance_Measure-1000;
	}
	else if(Resistance_Measure>2000&&Resistance_Measure<3000)
	{
		*Copy_pu32Rest_Float=Resistance_Measure-2000;
	}
	else if(Resistance_Measure>3000&&Resistance_Measure<4000)
		{
			*Copy_pu32Rest_Float=Resistance_Measure-3000;
		}
	else if(Resistance_Measure>4000&&Resistance_Measure<5000)
		{
			*Copy_pu32Rest_Float=Resistance_Measure-4000;
		}
	else if(Resistance_Measure>5000&&Resistance_Measure<6000)
		{
			*Copy_pu32Rest_Float=Resistance_Measure-5000;
		}
	else if(Resistance_Measure>6000&&Resistance_Measure<7000)
		{
			*Copy_pu32Rest_Float=Resistance_Measure-6000;
		}
	else if(Resistance_Measure>7000&&Resistance_Measure<8000)
		{
			*Copy_pu32Rest_Float=Resistance_Measure-7000;
		}
	else if(Resistance_Measure>8000&&Resistance_Measure<9000)
		{
			*Copy_pu32Rest_Float=Resistance_Measure-9000;
		}
	return Resistance_Measure;

}
