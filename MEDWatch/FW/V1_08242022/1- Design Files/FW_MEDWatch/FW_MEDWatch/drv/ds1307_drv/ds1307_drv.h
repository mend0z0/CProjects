/****************************************************************************************************
*					©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*				Project Name:	Medical Watch
*		  @Brief Description:
*				 File Status:	DRAFT
*						(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	File Name:	ds1307_drv.h
*	Version:	01
*	Revision:	01
*	Date:		09/19/2022
*	Company:	Mend0z0
*	Client:		-----------
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
#ifndef DS1307_DRV_H_
#define DS1307_DRV_H_
/****************************************************************************************************
****************************       HEADERS DECLARATION       ****************************************
*****************************************************************************************************/
#include "../i2c_drv/i2c_drv.h"

/****************************************************************************************************
****************************   CONST VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

#define DS1307_I2C_ADDR		0b11010000

#define DS1307_SECONDS		0X00
#define	DS1307_MINUTES		0X01
#define	DS1307_HOURS		0X02
#define	DS1307_DAY			0X03
#define DS1307_DATE			0X04
#define DS1307_MONTH		0X05
#define DS1307_YEAR			0X06


/****************************************************************************************************
****************************    EXT. VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/
struct {
	volatile unsigned int second;
	volatile unsigned int minute;
	volatile unsigned int hour;
	volatile unsigned int date;
	volatile unsigned int day;
	volatile unsigned int month;
	volatile unsigned int year;
}ds1307;

/****************************************************************************************************
**************************     GLOBAL FUNCTIONS DECLARATION      ************************************
*****************************************************************************************************/
unsigned int _init_DS1307( void );
unsigned int ReadTimeFromDS1307( void );
unsigned int WriteTimeOnDS1307( void );

#endif /* DS1307_DRV_H_  */

/****************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
****************************************************************************************************/

/**************************   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ************************/
/************************************     END OF THE FILE      *************************************/
