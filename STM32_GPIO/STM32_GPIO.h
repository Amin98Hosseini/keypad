/*
------------------------------------------------------------------------------
~ File   : STM32_GPIO.h
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

#ifndef __STM32_GPIO_H_
#define __STM32_GPIO_H_

/* ------------------------------------- Includes ------------------------------------- */

#ifdef USE_HAL_DRIVER  /* Check compiler */

#include "stm32f1xx_hal.h"        /* Import HAL library */

#endif /* USE_HAL_DRIVER */

#include <stdint.h> /* Import standard int */

/* ------------------------------------ Prototypes ------------------------------------ */

uint32_t HAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);
/* Example :
			
			uint32_t port_value;
			
			port_value = HAL_GPIO_ReadPort( GPIOB );

*/

#endif /* __STM32_GPIO_H_ */
