/*
------------------------------------------------------------------------------
~ File   : STM32_GPIO.c
~ Author : Majid Derhambakhsh
~ Version: V0.0.0
~ Created: 06/14/2019 06:24:00 PM
~ Brief  :
~ Support: Majid.do16@gmail.com
------------------------------------------------------------------------------
~ Description:

~ Attention  :
------------------------------------------------------------------------------
*/

#include "STM32_GPIO.h"

uint32_t HAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	
	return (GPIOx -> IDR); /* Return Pin state*/
	
}
/* Example :
			
			uint32_t port_value;
			
			port_value = HAL_GPIO_ReadPort( GPIOB );

*/
