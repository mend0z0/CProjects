/****************************************************************************************************
*					©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*				Project Name:	Medical Watch
*		  @Brief Description:
*				 File Status:	DRAFT
*						(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	File Name:	ssd1306_drv.c
*	Version:	01
*	Revision:	01
*	Date:		09/14/2022
*   Company:    Mend0z0
*	Client:		----------
*	License:	Private License (Contact for more info.)
*	******************************** Project Description *******************************************
*	@Detailed Description: It's a Medical watch that includes the following features
*	- Heartbeat sensor for observing heartbeats (MAX30102)
*	- MPU  (Gyroscope) sensor for measuring the traveled distance (MPU6050)
*	- OLED Display for displaying the information (SSD1306)
*	- Push buttons for controlling the smart watch manually
*	- RTC for tracking the time (DS... peripheral)
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
#include "../ssd1306_drv/ssd1306_drv.h"

/****************************************************************************************************
****************************   GLOB. VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

/****************************************************************************************************
**************************     STATIC FUNCTIONS DECLARATION      ************************************
*****************************************************************************************************/
static void SendDataToSSD1306( unsigned int data );
static void SendCommandToSSD1306( unsigned int *command, unsigned int buffSize);

/****************************************************************************************************
****************************         GLOBAL FUNTIONS         ****************************************
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
*	Function Scope:			Global
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
*	Date:		mm/dd/yyyy
*	Version:	xx
*	Revision:	xx
*	************************************************************************************************
*	Function Name:
*	Function Scope:			Global
*	Function Parameters:
*	Function Return Type:
*	************************************************************************************************
*	@Detailed Description: (Do numbering and tag the number to each part of code)
*	(1)	Set MUX Ratio A8h, 3Fh
*	(2)	Set Display Offset D3h, 00h
*	(3)	Set Display Start Line 40h
*	(4)	Set Segment re-map A0h/A1h
*	(5)	Set COM Output Scan Direction C0h/C8h
*	(6)	Set COM Pins hardware configuration DAh, 02
*	(7)	Set Contrast Control 81h, 7Fh
*	(8)	Disable Entire Display On A4h
*	(9)	Set Normal Display A6h
*	(10)	Set Osc Frequency D5h, 80h
*	(11)	Enable charge pump regulator 8Dh, 14h
*	(12)	Display On AFh
*	************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
*	************************************************************************************************
*	License: Private License (Contact for more info.)
*	Email: s.taherparvar@gmail.com
****************************************************************************************************/
void _init_SSD1306( void ){
	unsigned int cmdChargePump[] = {0X8D, 0X14};
	unsigned int setDisOn = SET_DIS_ON;
	//enable Charge pump
	SendCommandToSSD1306( cmdChargePump, 2);
	SendCommandToSSD1306( &setDisOn, 1 ); // 12
}

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
*	Function Scope:			Global
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
void DisplayImgOnSSD1306( unsigned int *p_data, unsigned int buffSize){
	for(unsigned int counter = 0; counter < buffSize; ++counter){
		SendDataToSSD1306( p_data[counter] );
	}
}


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
static void SendDataToSSD1306( unsigned int data ){
	unsigned int controlByte = 0b01000000;						//0b	C0	D/C	0	0	0	0	0	0 if C0 set to zero it means the next data is data and if D/C set to 1 it means the next data byte is data
	unsigned int str_data[2] = {controlByte, data};
	while(SendDataOnI2C( SSD1306_I2C_ADDR, str_data, 2) != OK);
}

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
static void SendCommandToSSD1306( unsigned int *command, unsigned int buffSize){
	unsigned int controlByte = 0b10000000;						//0b	C0	D/C	0	0	0	0	0	0 if C0 set to one it means the next data is command and if D/C set to zero it means the next data byte is command
	unsigned int data[14];
	
	buffSize *= 2;
	
	if(buffSize > 13){
		return ;
	}
	
	for(unsigned int counter = 0; counter < buffSize; ++counter){
		data[counter] = controlByte;
		counter += 1;
		data[counter] = *command;
		command++;
	}
	
	while( SendDataOnI2C( SSD1306_I2C_ADDR, data, buffSize) != OK);
}


/**************************   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ************************/
/************************************     END OF THE FILE      *************************************/
