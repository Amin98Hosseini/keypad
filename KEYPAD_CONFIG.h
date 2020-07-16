/*
------------------------------------------------------------------------------
~ File   : KEYPAD_CONFIG.h
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

#ifndef __KEYPAD_CONFIG_H_

/* Set your connected port */

#define _KEYPAD_PORT			&PORTB
#define _KEYPAD_PIN 			&PINB
#define _KEYPAD_FIRST_ROW		0
#define _KEYPAD_SCAN_SPEED		1

/*
	Example:
		
		AVR:
			
			#define _KEYPAD_PORT		&PORTB
			#define _KEYPAD_PIN 		&PINB
			#define _KEYPAD_FIRST_ROW	0
			#define _KEYPAD_SCAN_SPEED	1
			
		ARM:
			
			#define _KEYPAD_PORT		GPIOB
			#define _KEYPAD_PIN 		GPIOB
			#define _KEYPAD_FIRST_ROW	14
			#define _KEYPAD_SCAN_SPEED	1
			
*/

#endif /* __KEYPAD_CONFIG_H_ */
