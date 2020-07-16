/*
------------------------------------------------------------------------------
~ File   : KEYPAD.h
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

#ifndef __KEYPAD_H_
#define __KEYPAD_H_

/* ------------------------------------- Includes ------------------------------------- */

/*----------------------------------------------------------*/

#ifdef __CODEVISIONAVR__  /* Check compiler */

#include <io.h> /* Import AVR IO library */
#include <delay.h> /* Import delay lib */
#include "GPIO/GPIO.h"        /* Import AVR GPIO control library */

/*----------------------------------------------------------*/

#elif defined(__GNUC__)  /* Check compiler */

#include <avr/io.h>
#include <util/delay.h> /* Import delay lib */
#include "GPIO/GPIO.h"        /* Import AVR GPIO control library */

/*----------------------------------------------------------*/

#elif defined(USE_HAL_DRIVER)  /* Check compiler */

#include "STM32_GPIO/STM32_GPIO.h"        /* Import HAL library */

/*----------------------------------------------------------*/

#else                     /* Compiler not found */

#error Chip or GPIO Library not supported  /* Send error */

#endif /* __CODEVISIONAVR__ */

/*----------------------------------------------------------*/

#include <stdint.h> /* Import standard integer lib */
#include "KEYPAD_CONFIG.h" /* Import config file */

/* -------------------------------------- Define -------------------------------------- */

/* ------------------------- Keypad ------------------------- */

#define _KEYPAD_ROWS   4 /* Number of keypad rows */

#define _KEYPAD_FIRST_COLUMN   0x0E /* Column x value */
#define _KEYPAD_SECOND_COLUMN  0x0D /* Column x value */
#define _KEYPAD_THIRD_COLUMN   0x0B /* Column x value */
#define _KEYPAD_FOURTH_COLUMN  0x07 /* Column x value */

#define _KEYPAD_SECOND_ROW  _KEYPAD_FIRST_ROW + 1 /* Row x value */
#define _KEYPAD_THIRD_ROW   _KEYPAD_FIRST_ROW + 2 /* Row x value */
#define _KEYPAD_FOURTH_ROW  _KEYPAD_FIRST_ROW + 3 /* Row x value */

/* ^^^^^^^^^^^^^^^ Key number ^^^^^^^^^^^^^^^ */

#define _KEY_0      0  /* Key x number */
#define _KEY_1      1  /* Key x number */
#define _KEY_2      2  /* Key x number */
#define _KEY_3      3  /* Key x number */
#define _KEY_4      4  /* Key x number */
#define _KEY_5      5  /* Key x number */
#define _KEY_6      6  /* Key x number */
#define _KEY_7      7  /* Key x number */
#define _KEY_8      8  /* Key x number */
#define _KEY_9      9  /* Key x number */
#define _KEY_10     10 /* Key x number */
#define _KEY_11     11 /* Key x number */
#define _KEY_12     12 /* Key x number */
#define _KEY_13     13 /* Key x number */
#define _KEY_14     14 /* Key x number */
#define _KEY_15     15 /* Key x number */
#define _NON_PUSHED 16 /* Key x number */

/* ------------------------ Control ------------------------- */

#define _NEW_SCAN     0 /* Value for change scan status */
#define _PUSH_CHECK   1 /* Value for change scan status */
#define _RUN_COMMAND  2 /* Value for change scan status */

/* ------------------------- Global ------------------------- */

#define _NIBBLE 0xF /* Nibble value */

/* -------------------- By user library --------------------- */

#ifdef __CODEVISIONAVR__  /* Check compiler */

#define _KBD_GPIO_WritePin(port , pin , state)    GPIO_WritePin(port , pin , state) /* Change function */
#define _KBD_GPIO_ReadPort( port )                GPIO_ReadPort( port ) /* Change function */
#define _KEYPAD_DELAY(t)					  delay_ms(t) /* Change function */

/* ---------------------------------------------------------- */

#elif defined(__GNUC__)  /* Check compiler */

#define _KBD_GPIO_WritePin(port , pin , state)    GPIO_WritePin(port , pin , state) /* Change function */
#define _KBD_GPIO_ReadPort( port )                GPIO_ReadPort( port ) /* Change function */
#define _KEYPAD_DELAY(t)					  _delay_ms(t) /* Change function */

/* ---------------------------------------------------------- */

#elif defined(USE_HAL_DRIVER)  /* Check compiler */

#define _KBD_GPIO_WritePin(port , pin , state)    HAL_GPIO_WritePin(port , pin , state) /* Change function */
#define _KBD_GPIO_ReadPort( port )                HAL_GPIO_ReadPort( port ) /* Change function */
#define _GPIO_PIN_RESET                       GPIO_PIN_RESET /* Select GPIO reset instruction */
#define _GPIO_PIN_SET                         GPIO_PIN_SET /* Select GPIO set instruction */
#define _KEYPAD_DELAY(t)					  HAL_Delay(t) /* Change function */

/* ---------------------------------------------------------- */

#else                     /* Compiler not found */

#error Chip or GPIO Library not supported  /* Send error */

#endif /* __CODEVISIONAVR__ */

/* -------------------------------------- Types --------------------------------------- */

typedef void (*CommandFunction_T)(int8_t keypad_character); /* Function pointer for run user command */

/* ----------------------------------- Prototypes ------------------------------------- */

uint8_t Keypad_GetKey(void); /* Function for get pushed key */
/* 
	Example:
			
			uint8_t my_key = _NON_PUSHED;
			
			my_key = Keypad_GetKey();
			
			my_key data is: 0 ~ 15
			
*/

void Keypad_Read(CommandFunction_T your_function); /* Function for read keypad and run user command */
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

#endif /* __KEYPAD_H_ */
