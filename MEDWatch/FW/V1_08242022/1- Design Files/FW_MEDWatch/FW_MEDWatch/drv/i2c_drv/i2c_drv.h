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
*	- MPU  (Gyroscope) sensor for measuring the traveled distance (MPU6050)
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
#ifndef I2C_DRV_H_
#define I2C_DRV_H_
/****************************************************************************************************
****************************       HEADERS DECLARATION       ****************************************
*****************************************************************************************************/
#include "avr/interrupt.h"
#include "avr/io.h"
#include "D:/Projects/SiavashTP/OSSH/C/MEDWatch/FW/V1_08242022/1- Design Files/FW_MEDWatch/FW_MEDWatch/main.h"

/****************************************************************************************************
****************************   CONST VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/
//General Constants for I2C peripheral
#define WRITE				0X00
#define READ				0X01
#define START				0X08
#define	RE_START			0X10
#define I2C_100KHZ			32
#define I2C_400KHZ			2

//Status Codes for Master Transmitter Mode
#define MT_SLA_ACK			0X18
#define MT_SLA_NOT_ACK		0X20
#define MT_DATA_ACK			0X28
#define	MT_DATA_NOT_ACK		0X30

//Status Codes for Master Receiver Mode
#define	MR_SLA_ACK			0X40
#define MR_SLA_NOT_ACK		0X48
#define MR_DATA_ACK			0X50
#define MR_DATA_NOT_ACK		0X58

/****************************************************************************************************
****************************    EXT. VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

/****************************************************************************************************
**************************     GLOBAL FUNCTIONS DECLARATION      ************************************
*****************************************************************************************************/
void _init_I2C( unsigned int frequency );
unsigned int SendDataOnI2C( unsigned addr, unsigned int *data, unsigned int buffSize);
unsigned int ReceiveDataFromI2C( unsigned int i2cAddr, unsigned regAddr, unsigned int *data, unsigned int buffSize);

#endif /* I2C_DRV_H_  */

/****************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
****************************************************************************************************/

/**************************   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ************************/
/************************************     END OF THE FILE      *************************************/
