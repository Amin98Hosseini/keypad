/*
------------------------------------------------------------------------------
~ File   : KEYPAD.c
~ Author : Majid Derhambakhsh
~ Version: V0.0.0
~ Created: 06/15/2019 07:28:00 PM
~ Brief  :
~ Support: Majid.do16@gmail.com
------------------------------------------------------------------------------
~ Description:

~ Attention  :
------------------------------------------------------------------------------
*/

#include "KEYPAD.h"

/* -------------------------------- Variable -------------------------------- */

uint8_t kbd_scan_status = 0; /* Variable for scan control */
uint8_t kbd_first_value = 0; /* variable for get selected key number */

/* -------------------------------- Functions -------------------------------- */

uint8_t Keypad_GetKey(void) /* Function for get pushed key */
{
	
	uint8_t kbd_port_value = 0; /* Variable for get port value */
	
	/* ^^^^^^^^^^^^^^^^^^^^^^ Scan first column ^^^^^^^^^^^^^^^^^^^^^^ */
	
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (_NIBBLE << _KEYPAD_FIRST_ROW) , _GPIO_PIN_SET); /* Reset port */
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (1 << _KEYPAD_FIRST_ROW) , _GPIO_PIN_RESET); /* Set pin */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	_KEYPAD_DELAY(_KEYPAD_SCAN_SPEED); /* Delay for next scan */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	kbd_port_value = ( _KBD_GPIO_ReadPort(_KEYPAD_PIN) >> ( _KEYPAD_FIRST_ROW + _KEYPAD_ROWS ) ) & _NIBBLE; /* Get port value */
	
	if (kbd_port_value != _NON_PUSHED) /* Check push status */
	{
		
		switch (kbd_port_value) /* Check enable pin */
		{
			case _KEYPAD_FIRST_COLUMN:
			{
				return _KEY_0; /* Return key x value */
			}
			case _KEYPAD_SECOND_COLUMN:
			{
				return _KEY_1; /* Return key x value */
			}
			case _KEYPAD_THIRD_COLUMN:
			{
				return _KEY_2; /* Return key x value */
			}
			case _KEYPAD_FOURTH_COLUMN:
			{
				return _KEY_3; /* Return key x value */
			}
			
			default:
			break;
		}
		
	}
	
	/* ^^^^^^^^^^^^^^^^^^^^^^ Scan second column ^^^^^^^^^^^^^^^^^^^^^^ */
	
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (_NIBBLE << _KEYPAD_FIRST_ROW) , _GPIO_PIN_SET); /* Reset port */
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (1 << _KEYPAD_SECOND_ROW) , _GPIO_PIN_RESET); /* Set pin */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	_KEYPAD_DELAY(_KEYPAD_SCAN_SPEED); /* Delay for next scan */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	kbd_port_value = ( _KBD_GPIO_ReadPort(_KEYPAD_PIN) >> ( _KEYPAD_FIRST_ROW + _KEYPAD_ROWS ) ) & _NIBBLE; /* Get port value */
	
	if (kbd_port_value != _NON_PUSHED) /* Check push status */
	{
		
		switch (kbd_port_value) /* Check enable pin */
		{
			case _KEYPAD_FIRST_COLUMN:
			{
				return _KEY_4; /* Return key x value */
			}
			case _KEYPAD_SECOND_COLUMN:
			{
				return _KEY_5; /* Return key x value */
			}
			case _KEYPAD_THIRD_COLUMN:
			{
				return _KEY_6; /* Return key x value */
			}
			case _KEYPAD_FOURTH_COLUMN:
			{
				return _KEY_7; /* Return key x value */
			}
			
			default:
			break;
		}
		
	}
	/* ^^^^^^^^^^^^^^^^^^^^^^ Scan third column ^^^^^^^^^^^^^^^^^^^^^^ */
	
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (_NIBBLE << _KEYPAD_FIRST_ROW) , _GPIO_PIN_SET); /* Reset port */
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (1 << _KEYPAD_THIRD_ROW) , _GPIO_PIN_RESET); /* Set pin */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	_KEYPAD_DELAY(_KEYPAD_SCAN_SPEED); /* Delay for next scan */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	kbd_port_value = ( _KBD_GPIO_ReadPort(_KEYPAD_PIN) >> ( _KEYPAD_FIRST_ROW + _KEYPAD_ROWS ) ) & _NIBBLE; /* Get port value */
	
	if (kbd_port_value != _NON_PUSHED) /* Check push status */
	{
		
		switch (kbd_port_value) /* Check enable pin */
		{
			case _KEYPAD_FIRST_COLUMN:
			{
				return _KEY_8; /* Return key x value */
			}
			case _KEYPAD_SECOND_COLUMN:
			{
				return _KEY_9; /* Return key x value */
			}
			case _KEYPAD_THIRD_COLUMN:
			{
				return _KEY_10; /* Return key x value */
			}
			case _KEYPAD_FOURTH_COLUMN:
			{
				return _KEY_11; /* Return key x value */
			}
			
			default:
			break;
		}
		
	}
	
	/* ^^^^^^^^^^^^^^^^^^^^^^ Scan fourth column ^^^^^^^^^^^^^^^^^^^^^^ */
	
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (_NIBBLE << _KEYPAD_FIRST_ROW) , _GPIO_PIN_SET); /* Reset port */
	_KBD_GPIO_WritePin(_KEYPAD_PORT , (1 << _KEYPAD_FOURTH_ROW) , _GPIO_PIN_RESET); /* Set pin */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	_KEYPAD_DELAY(_KEYPAD_SCAN_SPEED); /* Delay for next scan */
	
	/* ~~~~~~~~~~~~~~~~~ */
	
	kbd_port_value = ( _KBD_GPIO_ReadPort(_KEYPAD_PIN) >> ( _KEYPAD_FIRST_ROW + _KEYPAD_ROWS ) ) & _NIBBLE; /* Get port value */
	
	if (kbd_port_value != _NON_PUSHED) /* Check push status */
	{
		
		switch (kbd_port_value) /* Check enable pin */
		{
			case _KEYPAD_FIRST_COLUMN:
			{
				return _KEY_12; /* Return key x value */
			}
			case _KEYPAD_SECOND_COLUMN:
			{
				return _KEY_13; /* Return key x value */
			}
			case _KEYPAD_THIRD_COLUMN:
			{
				return _KEY_14; /* Return key x value */
			}
			case _KEYPAD_FOURTH_COLUMN:
			{
				return _KEY_15; /* Return key x value */
			}
			
			default:
			break;
		}
		
	}
	
	return _NON_PUSHED; /* Return non value */
	
	/* Function End */
}
/* 
	Example:
			
			uint8_t my_key = _NON_PUSHED;
			
			my_key = Keypad_GetKey();
			
			my_key data is: 0 ~ 15
			
*/

void Keypad_Read(CommandFunction_T your_function) /* Function for read keypad and run user command */
{
	uint8_t keypad_value = 0; /* Variable for on release check */
	
	/* ~~~~~~~~~~~~~~~~~~~~~~ Get Key ~~~~~~~~~~~~~~~~~~~~~~ */
	
	switch (kbd_scan_status) /* Check status */
	{
		case _NEW_SCAN:
		{
			
			kbd_first_value = Keypad_GetKey(); /* Get key */
			kbd_scan_status = _PUSH_CHECK; /* Change next scan status */
			
		}
		break;
		case _PUSH_CHECK: /* On release check */
		{
			
			keypad_value = Keypad_GetKey(); /* Get key for on release */
			
			/* ----------------------- */
			
			if (keypad_value == _NON_PUSHED) /* Check status */
			{
				kbd_scan_status = _RUN_COMMAND; /* Change next scan status */
			}
			else if (keypad_value == kbd_first_value) /* Check status */
			{
				kbd_scan_status = _PUSH_CHECK; /* Change next scan status */
			}
			else
			{
				kbd_scan_status = _NEW_SCAN; /* Change next scan status */
			}
			
		}
		break;
		case _RUN_COMMAND: /* Run user command */
		{
			
			if (kbd_first_value != _NON_PUSHED) /* Check value */
			{
				
				your_function( kbd_first_value ); /* Run user function */
				
			}
			
			/* ----------------------- */
			
			kbd_scan_status = _NEW_SCAN; /* Change next scan status */
			
		}
		
		default:
		break;
	}
	
	/* Function End */
}
/* 
	Example:
			
			void ShowSelectedKey(int8_t my_key)
			{
				uint8_t my_string[10];
				
				sprintf(my_string , "%u" , my_key);
				Lcd_PutString(my_string);
				
			}
			
			Keypad_Read(ShowSelectedKey);
			
			printed data is: 0 ~ 15
			
*/
