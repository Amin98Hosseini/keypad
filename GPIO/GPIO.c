/*
------------------------------------------------------------------------------
~ File   : GPIO.c
~ Author : Majid Derhambakhsh
~ Version: V0.1.0
~ Created: 06/14/2019 06:50:00 PM
~ Brief  :
~ Support: Majid.do16@gmail.com
------------------------------------------------------------------------------
~ Description:

~ Attention  :		This file is for avr microcontroller
------------------------------------------------------------------------------
*/

#include "GPIO.h"

/* ------------- Functions ------------- */

void GPIO_WritePin(uint8_t *GPIOx , uint8_t GPIO_Pin , uint8_t PinState) /* Function for write data to output */
{
	
	switch (PinState)
	{
		case _GPIO_PIN_RESET:
		{
			*GPIOx &= ~GPIO_Pin; /* Select and set register value */	
		}
		break;
		case _GPIO_PIN_SET:
		{
			*GPIOx |= GPIO_Pin; /* Select and set register value */
		}
		break;
	}

}
/* Example :

 GPIO_WritePin( &PORTA , 0xFF , _GPIO_PIN_SET );
 GPIO_WritePin( &PORTA , 0xFF , _GPIO_PIN_RESET );

*/

/* ------------------------- */

void GPIO_ClearPin(uint8_t *GPIOx , uint8_t GPIO_Pin) /* Function for clear pin */
{
	
	*GPIOx &= ~(1 << GPIO_Pin); /* Select and set register value */

}
/* Example :

 GPIO_ClearPin( &PORTA , 2 );

*/

/* ------------------------- */

uint8_t GPIO_ReadPin(uint8_t *GPIOx , uint8_t GPIO_Pin) /* Function for read pin state */
{
	
	return ( (*GPIOx >> GPIO_Pin) & 1); /* Take and return register value */

}
/* Example :

 GPIO_ReadPin( &PINA , 3 );

*/

/* ------------------------- */

uint8_t GPIO_ReadPort(uint8_t *GPIOx)  /* Function for read port value */
{
	
	return *GPIOx; /* Take and return register value */
	
}
/* Example :
			
			uint8_t port_value;
			
			port_value = GPIO_ReadPort( &PINA );
			
*/

/* ------------------------- */

void GPIO_TogglePin(uint8_t *GPIOx , uint8_t GPIO_Pin) /* Function for toggle pin */
{
	
	*GPIOx ^= (1 << GPIO_Pin); /* Select and set register value */

}
/* Example :

 GPIO_TogglePin( &PORTA , 3 );

*/

/* Program End */