/*
 * LED1_interface.c
 *
 *  Created on: Sep 19, 2021
 *      Author: dell
 */
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "../../MCAL/DIO_Driver/DIO_REG.h"
#include  "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "LED_Interface.h"

u8 LED_U8ON_OFF(enum PORTS Copy_PortNo,enum LEDs Copy_LedNo,u8 Copy_u8ON_OR_OFF)
{
	u8 Local_Status=RT_OK;
	if((Copy_LedNo<0)||(Copy_LedNo>7)||Copy_PortNo<0||Copy_PortNo>3)
	{
		Local_Status=RT_NOK;
	}
	else
	{
		if( Copy_u8ON_OR_OFF==LED_ON)
			{
			switch(Copy_PortNo)
					{
					case 0:{ SetBit(DDRA_REG,Copy_LedNo);SetBit(PORTA_REG,Copy_LedNo);break;}
					case 1:{ SetBit(DDRB_REG,Copy_LedNo);SetBit(PORTB_REG,Copy_LedNo);break;}
					case 2:{ SetBit(DDRC_REG,Copy_LedNo);SetBit(PORTC_REG,Copy_LedNo);break;}
					case 3:{ SetBit(DDRD_REG,Copy_LedNo); SetBit(PORTD_REG,Copy_LedNo);break;}

			         }

	        }
		else if( Copy_u8ON_OR_OFF==LED_OFF)
					{
					switch(Copy_PortNo)
							{
							case 0:{ ClearBit(PORTA_REG,Copy_LedNo);break;}
							case 1:{ ClearBit(PORTB_REG,Copy_LedNo);break;}
							case 2:{ ClearBit(PORTC_REG,Copy_LedNo);break;}
							case 3:{ ClearBit(PORTD_REG,Copy_LedNo);break;}

					         }

			        }



	}
	return Local_Status;

}
