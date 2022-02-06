/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Interface.h"
#include "GIE_REG.h"

void EXTI_VidEnableOrDisableGIE(u8 Copy_u8EN_DIS)
{
	if (Copy_u8EN_DIS==ENABLE)
		{
			SetBit(SREG_REG,SREG_I_BIT);

		}
	else if( Copy_u8EN_DIS==DISABLE)
		{
		    ClearBit(SREG_REG,SREG_I_BIT);
		}
}
