/****************************************************************************************************
*					©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*				Project Name:	Medical Watch
*		  @Brief Description:	This file is the main file and includes main routine and state machine
*				 File Status:	DRAFT
*						(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	File Name:	main.c
*	Version:	01
*	Revision:	00
*	Date:		08/25/2022
*   Company:    Mend0z0 Co.
*	Client:		----------
*	License:	Private License (Contact for more info.)
*	******************************** Project Description *******************************************
*	@Detailed Description: It's a Medical watch that includes the following features
*	- Heartbeat sensor for observing heartbeats (MAX30102)
*	- MPU  (Gyroscope) sensor for measuring the traveled distance (MPU6050)
*	- OLED Display for displaying the information (SSD1306)
*	- Push buttons for controlling the smart watch manually
*	- RTC for tracking the time (Internal peripheral)
*	- USB-C connector, for transferring data through USB and charging in-built battery (it'll be used as a USB to UART) (CP2021)
*	- Serial Flash to store data in .txt file
*	- Vibrator for vibration and notification
*	- WIFI connection with MQTT protocol to send data in form of wireless connection (
*	- Pressure sensor for measuring the pressure that is applied to hand (SEN0297)
*	The purpose is to collect all the data and finding the body details and displaying on the OLED, also setting alarm and processing the data for medical purposes.
*
*
*	******************************** File Description *******************************************
*	@Detailed Description:
*
*
*
*
*	*********************************  Processor Info **********************************************
*	Processor:			ATmega32		8-Bits
*	Clock Frequency:	8.000			MHz
*	RAM/SRAM Size:		2.00			KBytes
*	Flash Size:			32.00			KBytes
*	EEPROM Size:		1.00			KBytes
*	***********************************  Case Style  ***********************************************
*	Local Variables = camelCase			Global Variables = g_camelCase
*	Headers = SCREAMIN_SNAKE_CASE		Const Variables = SCREAMING_SNAKE_CASE		Macros = SCREAMING_SNAKE_CASE
*	Functions = PascalCase				Initialize Functions = _lower_case
*	Struct = lower_case					Struct.members = camelCase
*	Enum = lower_case					Enum Members = SNAKE_CASE
*	Pointer Variables = p_camelCase
*	*********************************** Contact Info ***********************************************
*	Author:	Siavash Taher Parvar
*	Email:  s.taherparvar@gmail.com
*
*						CONFIDENTIAL DOCUMENT, DO NOT DISTRIBUTE
****************************************************************************************************/

/****************************************************************************************************
****************************       HEADERS DECLARATION       ****************************************
*****************************************************************************************************/
#include "main.h"

/****************************************************************************************************
****************************   GLOB. VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

/****************************************************************************************************
**************************     STATIC FUNCTIONS DECLARATION      ************************************
*****************************************************************************************************/

/****************************************************************************************************
****************************         STATIC FUNTIONS         ****************************************
*****************************************************************************************************/

/****************************************************************************************************
*				©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*		 @Brief Description:
*			Function Status: 	DRAFT
*					(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	************************************************************************************************
*	Author:		Siavash Taher Parvar					Checked By:
*	Date:		mm/dd/yyyy
*	Version:	xx
*	Revision:	xx
*	************************************************************************************************
*	Function Name:
*	Function Scope:			Local(static)
*	Function Parameters:
*	Function Return Type:
*	************************************************************************************************
*	@Detailed Description: (Do numbering and tag the number to each part of code)
*	(1)
*	(2)
*	(3)
*	.
*	.
*	.
*	************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
*	************************************************************************************************
*	License: Private License (Contact for more info.)
*	Email: s.taherparvar@gmail.com
****************************************************************************************************/

/****************************************************************************************************
*				©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*		 @Brief Description:
*			Function Status: 	DRAFT
*					(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	************************************************************************************************
*	Author:		Siavash Taher Parvar					Checked By:
*	Date:		08/25/2022
*	Version:	01
*	Revision:	00
*	************************************************************************************************
*	Function Name:			main
*	Function Scope:			Local(static)
*	Function Parameters:	void
*	Function Return Type:	int
*	************************************************************************************************
*	@Detailed Description: (Do numbering and tag the number to each part of code)
*	(1)
*	(2)
*	(3)
*	.
*	.
*	.
*	************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
*	************************************************************************************************
*	License: Private License (Contact for more info.)
*	Email: s.taherparvar@gmail.com
****************************************************************************************************/
int main(void){
	DDRA |= (1 << 1);
	unsigned int data[100]={0xa1};
	_init_I2C();
	
	PORTA ^= (1 << 1);
	_delay_ms(500);
	PORTA ^= (1 << 1);
	_delay_ms(500);
	PORTA ^= (1 << 1);
	_delay_ms(500);
	PORTA ^= (1 << 1);
	_delay_ms(500);
	PORTA ^= (1 << 1);
	_delay_ms(500);
	PORTA ^= (1 << 1);
	_delay_ms(500);
	PORTA ^= (1 << 1);
	_delay_ms(500);
	PORTA ^= (1 << 1);
	_delay_ms(500);
	/* Replace with your application code */
	while (1){
		SendDataOnI2C( 0x52, data, 2);
		PORTA ^= (1 << 1);
		_delay_ms(500);
	}
	return 0;
}

/**************************   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ************************/
/************************************     END OF THE FILE      *************************************/
