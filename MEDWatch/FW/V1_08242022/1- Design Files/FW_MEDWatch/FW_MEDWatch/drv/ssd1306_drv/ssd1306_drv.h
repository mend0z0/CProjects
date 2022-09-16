/****************************************************************************************************
*					©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*				Project Name:	Medical Watch
*		  @Brief Description:
*				 File Status:	DRAFT
*						(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	File Name:	ssd1306_drv.h
*	Version:	01
*	Revision:	01
*	Date:		09/14/2022
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
#ifndef SSD1306_DRV_H_
#define SSD1306_DRV_H_
/****************************************************************************************************
****************************       HEADERS DECLARATION       ****************************************
*****************************************************************************************************/
#include "../i2c_drv/i2c_drv.h"
#include "D:/Projects/SiavashTP/OSSH/C/MEDWatch/FW/V1_08242022/1- Design Files/FW_MEDWatch/FW_MEDWatch/main.h"

/****************************************************************************************************
****************************   CONST VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/
#define SSD1306_I2C_ADDR    0X78

///////////////////////////////////////////////
//    1. Fundamental Command Table			 //
///////////////////////////////////////////////
#define SET_CONTRAST_CTRL					0X81			//  Double byte command to select 1 out of 256 contrast steps. Contrast increases as the value increases.(RESET = 7Fh )
#define ENT_DIS_ON_RESUME					0XA4			//  A4h, X0=0b: Resume to RAM content display (RESET) Output follows RAM content
#define ENT_DIS_ON							0XA5			//  A5h, X0=1b: Entire display ON Output ignores RAM content
#define SET_NORMAL_DIS						0XA6			//  A6h, X[0]=0b: Normal display (RESET) 0 in RAM: OFF in display panel 1 in RAM: ON in display panel
#define SET_INVERSE_DIS						0XA7			//  A7h, X[0]=1b: Inverse display 0 in RAM: ON in display panel 1 in RAM: OFF in display panel
#define SET_DIS_OFF							0XAE			//  AEh, X[0]=0b:Display OFF (sleep mode)(RESET)
#define SET_DIS_ON							0XAF			//  AFh X[0]=1b:Display ON in normal mode

///////////////////////////////////////////////
//		1. Charge Pump Command Table		 //
///////////////////////////////////////////////
#define CHARGE_PUMP_SETTING					0X8D			//	Charge Pump Setting
#define ENABLE_CHARGE_PUMP					0X14			//	A[2] = 0b, Disable charge pump(RESET)
#define DISABLE_CHARGE_PUMP					0X10			//	A[2] = 1b, Enable charge pump during display on

															//Note: The Charge Pump must be enabled by the following command:
															//		8Dh ; Charge Pump Setting
															//		14h ; Enable Charge Pump
															//		AFh; Display ON

///////////////////////////////////////////////
//	  2. Scrolling Command Table			 //
///////////////////////////////////////////////
#define RIGHT_HORIZ_SCROLL					0X26			//	Continuous horizontal Scroll Setup Right Horizontal Scroll
#define	LEFT_HORIZ_SCROLL					0X27			//	Continuous horizontal Scroll Setup Left Horizontal Scroll
#define	A_SETUP_HORIZ_SCROLL				0X00			//	Continuous horizontal Scroll Setup Dummy byte (Set as 00h)
#define	B_SETUP_HORIZ_SCROLL_S_PG0			0X00			//	Continuous horizontal Scroll Setup Define start page address: Page 0
#define	B_SETUP_HORIZ_SCROLL_S_PG1			0X01			//	Continuous horizontal Scroll Setup Define start page address: Page 1
#define	B_SETUP_HORIZ_SCROLL_S_PG2			0X02			//	Continuous horizontal Scroll Setup Define start page address: Page 2
#define	B_SETUP_HORIZ_SCROLL_S_PG3			0X03			//	Continuous horizontal Scroll Setup Define start page address: Page 3
#define	B_SETUP_HORIZ_SCROLL_S_PG4			0X04			//	Continuous horizontal Scroll Setup Define start page address: Page 4
#define	B_SETUP_HORIZ_SCROLL_S_PG5			0X05			//	Continuous horizontal Scroll Setup Define start page address: Page 5
#define	B_SETUP_HORIZ_SCROLL_S_PG6			0X06			//	Continuous horizontal Scroll Setup Define start page address: Page 6
#define	B_SETUP_HORIZ_SCROLL_S_PG7			0X07			//	Continuous horizontal Scroll Setup Define start page address: Page 7
#define	C_SETUP_HORIZ_SCROLL_5_FRAME		0X00			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 5 Frames
#define	C_SETUP_HORIZ_SCROLL_64_FRAME		0X01			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 64 Frames
#define	C_SETUP_HORIZ_SCROLL_128_FRAME		0X02			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 128 Frames
#define	C_SETUP_HORIZ_SCROLL_256_FRAME		0X03			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 256 Frames
#define	C_SETUP_HORIZ_SCROLL_3_FRAME		0X04			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 3 Frames
#define	C_SETUP_HORIZ_SCROLL_4_FRAME		0X05			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 4 Frames
#define	C_SETUP_HORIZ_SCROLL_25_FRAME		0X06			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 25 Frames
#define	C_SETUP_HORIZ_SCROLL_2_FRAME		0X07			//	Continuous horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 2 Frames
#define	D_SETUP_HORIZ_SCROLL_E_PG0			0X00			//	Continuous horizontal Scroll Setup Define end page address: Page 0 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_HORIZ_SCROLL_E_PG1			0X01			//	Continuous horizontal Scroll Setup Define end page address: Page 1 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_HORIZ_SCROLL_E_PG2			0X02			//	Continuous horizontal Scroll Setup Define end page address: Page 2 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_HORIZ_SCROLL_E_PG3			0X03			//	Continuous horizontal Scroll Setup Define end page address: Page 3 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_HORIZ_SCROLL_E_PG4			0X04			//	Continuous horizontal Scroll Setup Define end page address: Page 4 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_HORIZ_SCROLL_E_PG5			0X05			//	Continuous horizontal Scroll Setup Define end page address: Page 5 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_HORIZ_SCROLL_E_PG6			0X06			//	Continuous horizontal Scroll Setup Define end page address: Page 6 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_HORIZ_SCROLL_E_PG7			0X07			//	Continuous horizontal Scroll Setup Define end page address: Page 7 (The value of D[2:0] must be larger or equal to B[2:0])
#define	E_SETUP_HORIZ_SCROLL				0X00			//	Continuous horizontal Scroll Setup Dummy byte (Set as 00h)
#define	F_SETUP_HORIZ_SCROLL				0XFF			//	Continuous horizontal Scroll Setup Dummy byte (Set as FFh)

#define VERT_RIGHT_HORIZ_SCROLL				0X29			//	Continuous Vertical and Horizontal Scroll Setup Vertical and Right Horizontal Scroll
#define	VERT_LEFT_HORIZ_SCROLL				0X2A			//	Continuous Vertical and Horizontal Scroll Setup Vertical and Left Horizontal Scroll
#define	A_SETUP_VERT_HORIZ_SCROLL			0X00			//	Continuous Vertical and Horizontal Scroll Setup Dummy byte
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG0		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 0
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG1		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 1
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG2		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 2
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG3		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 3
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG4		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 4
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG5		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 5
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG6		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 6
#define	B_SETUP_VERT_HORIZ_SCROLL_S_PG7		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define start page address : Page 7
#define	C_SETUP_VERT_HORIZ_SCROLL_5_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 5 Frames
#define	C_SETUP_VERT_HORIZ_SCROLL_64_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 64 Frames
#define	C_SETUP_VERT_HORIZ_SCROLL_128_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 128 Frames
#define	C_SETUP_VERT_HORIZ_SCROLL_256_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 256 Frames
#define	C_SETUP_VERT_HORIZ_SCROLL_3_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 3 Frames
#define	C_SETUP_VERT_HORIZ_SCROLL_4_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 4 Frames
#define	C_SETUP_VERT_HORIZ_SCROLL_25_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 25 Frames
#define	C_SETUP_VERT_HORIZ_SCROLL_2_FRAME	0X00			//	Continuous Vertical and Horizontal Scroll Setup Set time interval between each scroll step in terms of frame frequency: 2 Frames
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG0		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 0 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG1		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 1 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG2		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 2 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG3		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 3 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG4		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 4 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG5		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 5 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG6		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 6 (The value of D[2:0] must be larger or equal to B[2:0])
#define	D_SETUP_VERT_HORIZ_SCROLL_E_PG7		0X00			//	Continuous Vertical and Horizontal Scroll Setup Define end page address: Page 7 (The value of D[2:0] must be larger or equal to B[2:0])
#define	E_SETUP_VERT_HORIZ_SCROLL_OFFSET	0X00			//	Continuous Vertical and Horizontal Scroll Setup Vertical scrolling offset e.g. E[5:0]= 01h refer to offset =1 row E[5:0] =3Fh refer to offset =63 rows

#define DEACTIVE_SCROLL						0X2E			//  Stop scrolling that is configured by command 26h/27h/29h/2Ah. "After sending 2Eh command to deactivate the scrolling action, the ram data needs to be rewritten. "
#define ACTIVATE_SCROLL						0X2F			//  Start scrolling that is configured by the scrolling setup commands :26h/27h/29h/2Ah with the following valid sequences:

#define SET_VERT_AREA						0XA3
#define SET_VERT_AREA_A						0X00			//	Set No. of rows in top fixed area. The No. of rows in top fixed area is referenced to the top of the GDDRAM (i.e. row 0).[RESET = 0]
#define	SET_VERT_AREA_B						0X20			//	Set No. of rows in scroll area. This is the number of rows to be used for vertical scrolling. The scroll area starts in the first row below the top fixed area. [RESET = 64]
															//	NOTE:
															//	(1) A[5:0]+B[6:0] <= MUX ratio
															//	(2) B[6:0] <= MUX ratio
															//	(3a) Vertical scrolling offset (E[5:0] in 29h/2Ah) < B[6:0]
															//	(3b) Set Display Start Line (X5X4X3X2X1X0 of 40h~7Fh) < B[6:0]
															//	(4) The last row of the scroll area shifts to the first row of the scroll area.
															//	(5) For 64d MUX display
															//							A[5:0] = 0, B[6:0]=64 : whole area scrolls
															//							A[5:0]= 0, B[6:0] < 64 : top area scrolls
															//							A[5:0] + B[6:0] < 64 : central area scrolls
															//							A[5:0] + B[6:0] = 64 : bottom area scrolls

///////////////////////////////////////////////
//    3. Addressing Setting Command Table	 //
///////////////////////////////////////////////
#define SET_MEM_ADDR_MODE					0X20			//	Set Memory Addressing Mode
#define SET_MEM_ADDR_HOR					0X00			//  A[1:0] = 00b, Horizontal Addressing Mode
#define SET_MEM_ADDR_VERT					0X01			//  A[1:0] = 01b, Vertical Addressing Mode
#define SET_MEM_ADDR_PAGE					0X02			//  A[1:0] = 10b, Page Addressing Mode (RESET)

#define SET_COLUMN_ADDR						0X21			//	Set Column Address
#define SET_COLUMN_S_ADDR					0X00			//	A[6:0] : Column start address, range : 0-127d, (RESET=0d)
#define SET_COLUMN_E_ADDR					0X7F			//	B[6:0]: Column end address, range : 0-127d, (RESET =127d)			

#define	SET_PAGE_ADDR						0X22			//	Set Page Address
#define SET_PAGE_S_ADDR						0X00			//	A[2:0] : Page start Address, range : 0-7d, (RESET = 0d)
#define SET_PAGE_E_ADDR						0X07			//	B[2:0] : Page end Address, range : 0-7d, (RESET = 7d)

#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG0	0XB0			//	Set GDDRAM Page Start Address PAGE0 for Page Addressing Mode using X[2:0].
#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG1	0XB1			//	Set GDDRAM Page Start Address PAGE1 for Page Addressing Mode using X[2:0].
#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG2	0XB2			//	Set GDDRAM Page Start Address PAGE2 for Page Addressing Mode using X[2:0].
#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG3	0XB3			//	Set GDDRAM Page Start Address PAGE3 for Page Addressing Mode using X[2:0].
#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG4	0XB4			//	Set GDDRAM Page Start Address PAGE4 for Page Addressing Mode using X[2:0].
#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG5	0XB5			//	Set GDDRAM Page Start Address PAGE5 for Page Addressing Mode using X[2:0].
#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG6	0XB6			//	Set GDDRAM Page Start Address PAGE6 for Page Addressing Mode using X[2:0].
#define SET_PAGE_S_ADDR_FOR_ADDR_MODE_PG7	0XB7			//	Set GDDRAM Page Start Address PAGE7 for Page Addressing Mode using X[2:0].

//////////////////////////////////////////////////////////////////////////////////////
//    4. Hardware Configuration (Panel resolution & layout related) Command Table	//
//////////////////////////////////////////////////////////////////////////////////////
#define SET_DIS_START_LINE					0X40			//	Set display RAM display start line register from 0-63 using X5X3X2X1X0. Display start line register is reset to 000000b during RESET.

#define SET_SEG_REMAP_A0					0XA0			//	A0h, X[0]=0b: column address 0 is mapped to SEG0 (RESET)
#define SET_SEG_REMAP_A1					0XA1			//	A1h, X[0]=1b: column address 127 is mapped to SEG0

#define SET_MULTIPLEX_RATIO					0XA8			//	Set MUX ratio to N+1 MUX 
#define SET_MULTIPLEX_RATIO_A				0X3F			//	N=A[5:0] : from 16MUX to 64MUX, RESET= 111111b (i.e. 63d, 64MUX), A[5:0] from 0 to 14 are invalid entry.

#define SET_COM_OUTPUT_SCAN_DIR_NORM		0XC0			//	C0h, X[3]=0b: normal mode (RESET) Scan from COM0 to COM[N –1]
#define SET_COM_OUTPUT_SCAN_DIR_REMAPPED	0XC8			//	C8h, X[3]=1b: remapped mode. Scan from COM[N-1] to COM0

#define SET_DISPLAY_OFFSET					0XD3			//	Set vertical shift by COM from 0d~63d The value is reset to 00h after RESET.
#define	SET_DISPLAY_OFFSET_A				0X00			//	The value is reset to 00h after RESET.

#define SET_COM_PINS_HARDWARE_CONFIG		0XDA			//	Set COM Pins Hardware Configuration
#define	SET_COM_PINS_HARDWARE_CONFIG_SEQ	0X02			//	Set COM Pins Hardware Configuration: A[4]=0b, Sequential COM pin configuration
#define SET_COM_PINS_HARDWARE_CONFIG_ALTR	0X12			//	Set COM Pins Hardware Configuration: A[4]=1b(RESET), Alternative COM pin configuration
#define SET_COM_PINS_HARDWARE_CONFIG_DIS	0X12			//	Set COM Pins Hardware Configuration: A[5]=0b(RESET), Disable COM Left/Right remap
#define SET_COM_PINS_HARDWARE_CONFIG_EN		0X32			//	Set COM Pins Hardware Configuration: A[5]=1b, Enable COM Left/Right remap

//////////////////////////////////////////////////////////
//   5. Timing & Driving Scheme Setting Command Table	//
//////////////////////////////////////////////////////////
#define SET_CLK_DIV_RATIO					0XD5			//	A[3:0] : Define the divide ratio (D) of the display clocks (DCLK): Divide ratio= A[3:0] + 1, RESET is 0000b (divide ratio = 1)
#define SET_CLK_DIV_RATIO_A					0X08			//	A[7:4] : Set the Oscillator Frequency, FOSC. Oscillator Frequency increases with the value of A[7:4] and vice versa. RESET is 1000b Range:0000b~1111b

#define SET_PRECHARGE_PERIOD				0XD9			//	A[3:0] : Phase 1 period of up to 15 DCLK clocks 0 is invalid entry (RESET=2h)
#define	SET_PRECHARGE_PERIOD_A				0X02			//	A[7:4] : Phase 2 period of up to 15 DCLK clocks 0 is invalid entry (RESET=2h )

#define SET_VCOMH_DESELECT_LVL				0XDB			//	V COMH Deselect level
#define SET_VCOMH_DESELECT_LVL_1			0X00			//	~ 0.65 x VCC
#define SET_VCOMH_DESELECT_LVL_2			0X20			//	~ 0.77 x VCC (RESET)
#define SET_VCOMH_DESELECT_LVL_3			0X30			//	~ 0.83 x VCC

#define NOP									0XE3			//  Command for no operation

/****************************************************************************************************
****************************    EXT. VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

/****************************************************************************************************
**************************     GLOBAL FUNCTIONS DECLARATION      ************************************
*****************************************************************************************************/
void _init_SSD1306( void );
void DisplayImgOnSSD1306( unsigned int *p_data, unsigned int buffSize);

#endif /* SSD1306_DRV_H_  */

/****************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
****************************************************************************************************/

/**************************   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ************************/
/************************************     END OF THE FILE      *************************************/
