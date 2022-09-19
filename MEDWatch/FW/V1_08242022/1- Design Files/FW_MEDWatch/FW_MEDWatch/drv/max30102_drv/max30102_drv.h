/****************************************************************************************************
*					©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*				Project Name:	Medical Watch
*		  @Brief Description:
*				 File Status:	DRAFT
*						(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	File Name:	xxxx.h
*	Version:	xx
*	Revision:	xx
*	Date:		mm/dd/yyyy
*	Company:	Mend0z0
*	Client:		-----------
*	License:	Private License (Contact for more info.)
*	******************************** Project Description *******************************************
*	@Detailed Description: It's a Medical watch that includes the following features
*	- Heartbeat sensor for observing heartbeats (MAX30102)
*	- MPU  (Gyroscope) sensor for measuring the traveled distance (BMI160)
*	- OLED Display for displaying the information (SSD1306)
*	- Push buttons for controlling the smart watch manually
*	- RTC for tracking the time (DS1307)
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
#ifndef MAX30102_DRV_H_
#define MAX30102_DRV_H_
/****************************************************************************************************
****************************       HEADERS DECLARATION       ****************************************
*****************************************************************************************************/
#include "../i2c_drv/i2c_drv.h"

/****************************************************************************************************
****************************   CONST VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

#define MAX30102_I2C_ADDR	0b10101110	//	

//STATUS
#define INT_STATUS_1		0X00		//	
#define INT_STATUS_2		0X01		//	
#define INT_ENABLE_1		0X02		//	
#define INT_ENABLE_2		0X03		//	
//FIFO
#define FIFO_WRITE_POINTER	0X04		//	
#define OVERFLOW_COUNTER	0X05		//	
#define FIFO_READ_POINTER	0X06		//	
#define FIFO_DATA_REGISTER	0X07		//	
//CONFIGURATION	
#define FIFO_CONFIG			0X08		//	
#define MODE_CONFIG			0X09		//	
#define SPO2_CONFIG			0X0A		//	
#define LED1_PULSE_AMP		0X0C		//	
#define	LED2_PULSE_AMP		0X0D		//	
#define MULTI_LED_CTRL_1	0X11		//	
#define	MULTI_LED_CTRL_2	0X12		//	
//DIE TEMPERATURE
#define DIE_TEMP_INTEG		0X1F		//	
#define DIE_TEMP_FRAC		0X20		//	
#define DIE_TEMP_CONFIG		0X21		//	
//PART ID
#define REVISION_ID			0XFE		//	
#define PART_ID				0XFF		//	

/****************************************************************************************************
****************************    EXT. VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

/****************************************************************************************************
**************************     GLOBAL FUNCTIONS DECLARATION      ************************************
*****************************************************************************************************/

#endif /* MAX30102_DRV_H_  */

/****************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
****************************************************************************************************/

/**************************   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ************************/
/************************************     END OF THE FILE      *************************************/
