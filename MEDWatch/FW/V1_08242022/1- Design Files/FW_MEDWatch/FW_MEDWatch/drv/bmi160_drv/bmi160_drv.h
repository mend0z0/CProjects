/****************************************************************************************************
*					©2022 - 2032 Siavash Taher Parvar All Rights Reserved.
*
*				Project Name:	Medical Watch
*		  @Brief Description:
*				 File Status:	DRAFT
*						(DRAFT , PRILIMINARY, CHECKED, RELEASED)
*	File Name:	bmi160_drv.h
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
#ifndef BMI160_DRV_H_
#define BMI160_DRV_H_
/****************************************************************************************************
****************************       HEADERS DECLARATION       ****************************************
*****************************************************************************************************/
#include "../i2c_drv/i2c_drv.h"

/****************************************************************************************************
****************************   CONST VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

#define BMI160_I2C_ADDR	0X68	//	The default I²C address of the device is 0b1101000 (0x68). It is used if the SDO pin is pulled to ´GND´.

#define	CMD				0X7E	//	Command register triggers operations like soft reset, NVM programming, etc.
#define STEP_CONF_1		0X7B	//	Contains configuration of the step detector
#define STEP_CONF_0		0X7A	//	Contains configuration of the step detector
#define STEP_CNT_1		0X79	//	Contains the number of steps.
#define STEP_CNT_0		0X78	//	Contains the number of steps.
#define OFFSET_6		0X77	//	Contains the offset compensation values for accelerometer and gyroscope
#define OFFSET_5		0X76	//	Contains the offset compensation values for accelerometer and gyroscope
#define OFFSET_4		0X75	//	Contains the offset compensation values for accelerometer and gyroscope
#define OFFSET_3		0X74	//	Contains the offset compensation values for accelerometer and gyroscope
#define OFFSET_2		0X73	//	Contains the offset compensation values for accelerometer and gyroscope
#define OFFSET_1		0X72	//	Contains the offset compensation values for accelerometer and gyroscope
#define OFFSET_0		0X71	//	Contains the offset compensation values for accelerometer and gyroscope
#define NV_CONF			0X70	//	Contains settings for the digital interface.
#define SELF_TEST		0X6D	//	Contains the settings for the sensor self-test configuration and trigger.
#define PMU_TRIGGER		0X6C	//	Used to set the trigger conditions to change the gyro power modes
#define IF_CONF			0X6B	//	Contains settings for the digital interface.
#define CONF			0X6A	//	Configuration of the sensor
#define FOC_CONF		0X69	//	Contains configuration settings for the fast offset compensation for the accelerometer and the gyroscope
#define INT_FLAT_1		0X68	//	Contains the definition of the flat interrupt hold time and flat interrupt hysteresis.
#define INT_FLAT_0		0X67	//	Contains the definition of the flat threshold angle for the flat interrupt.
#define INT_ORIENT_1	0X66	//	contains the definition of the axis orientation, up/down masking, and the theta blocking angle for the orientation interrupt
#define INT_ORIENT_0	0X65	//	contains the definition of hysteresis, blocking, and mode for the orientation interrupt
#define INT_TAP_1		0X64	//	Defines the threshold definition for the single and double tap interrupts.
#define INT_TAP_0		0X63	//	Contains the timing definitions for the single tap and double tap interrupts.
#define INT_MOTION_3	0X62	//	Contains slow / no motion configuration
#define INT_MOTION_2	0X61	//	Contains the threshold definition for the slow/no-motion interrupt.
#define INT_MOTION_1	0X60	//	Contains the threshold definition for the any-motion interrupt
#define INT_MOTION_0	0X5F	//	Contains the configuration for the anymotion and nomotion interrupts
#define INT_LOWHIGH_4	0X5E	//	Contains the delay time definition for the high-g interrupt.
#define INT_LOWHIGH_3	0X5D	//	Contains the delay time definition for the high-g interrupt.
#define INT_LOWHIGH_2	0X5C	//	Contains the low-g interrupt mode selection, the low-g interrupt hysteresis setting, and the high-g interrupt hysteresis setting.
#define INT_LOWHIGH_1	0X5B	//	Contains the configuration for the low g interrupt
#define INT_LOWHIGH_0	0X5A	//	Contains the configuration for the low g interrupt
#define INT_DATA_1		0X59	//	Contains the data source definition for the two interrupt groups.
#define INT_DATA_0		0X58	//	Contains the data source definition for the two interrupt groups.
#define INT_MAP_2		0X57	//	Controls which interrupt signals are mapped to the INT1 and INT2 pin.
#define INT_MAP_1		0X56	//	Controls which interrupt signals are mapped to the INT1 and INT2 pin.
#define INT_MAP_0		0X55	//	Controls which interrupt signals are mapped to the INT1 and INT2 pin.
#define INT_LATCH		0X54	//	Contains the interrupt reset bit and the interrupt mode selection.
#define INT_OUT_CTRL	0X53	//	Contains the behavioral configuration (electrical definition of the interrupt pins.
#define INT_EN_2		0X52	//	Controls which interrupt engines are enabled.
#define INT_EN_1		0X51	//	Controls which interrupt engines are enabled.
#define INT_EN_0		0X50	//	Controls which interrupt engines are enabled.
#define MAG_IF_4		0X4F	//	Register for indirect addressing of the magnetometer connected to the magnetometer interface. This register allows read and write operations on the magnetometer register map.
#define MAG_IF_3		0X4E	//	Register for indirect addressing of the magnetometer connected to the magnetometer interface. This register allows read and write operations on the magnetometer register map.
#define MAG_IF_2		0X4D	//	Register for indirect addressing of the magnetometer connected to the magnetometer interface. This register allows read and write operations on the magnetometer register map.
#define MAG_IF_1		0X4C	//	Register for indirect addressing of the magnetometer connected to the magnetometer interface. This register allows read and write operations on the magnetometer register map.
#define MAG_IF_0		0X4B	//	Register for indirect addressing of the magnetometer connected to the magnetometer interface. This register allows read and write operations on the magnetometer register map.
#define FIFO_CONFIG_1	0X47	//	The Register (0x46-0x47) FIFO_CONFIG is a read/write register and can be used for reading or setting the current FIFO watermark level.
#define FIFO_CONFIG_0	0X46	//	The Register (0x46-0x47) FIFO_CONFIG is a read/write register and can be used for reading or setting the current FIFO watermark level.
#define FIFO_DOWNS		0X45	//	Used to configure the down sampling ratios of the accel and gyro data for FIFO.
#define MAG_CONF		0X44	//	Sets the output data rate of the magnetometer interface in the sensor.
#define GYR_RANGE		0X43	//	Defines the BMI160 angular rate measurement range
#define GYR_CONF		0X42	//	Sets the output data rate, the bandwidth, and the read mode of the gyroscope in the sensor.
#define ACC_RANGE		0X41	//	The register allows the selection of the accelerometer g-range
#define ACC_CONF		0X40	//	Sets the output data rate, the bandwidth, and the read mode of the acceleration sensor.
#define FIFO_DATA		0X24	//	FIFO data readout register.
#define FIFO_LENGTH_1	0X23	//	FIFO data readout register.
#define FIFO_LENGTH_0	0X22	//	FIFO data readout register.
#define TEMPERATURE_1	0X21	//	Contains the temperature of the sensor
#define TEMPERATURE_0	0X20	//	Contains the temperature of the sensor
#define INT_STATUS_3	0X1F	//	The register contains interrupt status flags.
#define INT_STATUS_2	0X1E	//	The register contains interrupt status flags.
#define INT_STATUS_1	0X1D	//	The register contains interrupt status flags.
#define INT_STATUS_0	0X1C	//	The register contains interrupt status flags.
#define STATUS			0X1B	//	Reports sensor status flags.
#define SENSORTIME_2	0X1A	//	Sensortime is a 24 bit counter available in suspend, low power, and normal mode. The value of the register is shadowed when it is read in a burst read with the data register at the beginning of the operation and the shadowed value is returned.
#define SENSORTIME_1	0X19	//	Sensortime is a 24 bit counter available in suspend, low power, and normal mode. The value of the register is shadowed when it is read in a burst read with the data register at the beginning of the operation and the shadowed value is returned.
#define SENSORTIME_0	0X18	//	Sensortime is a 24 bit counter available in suspend, low power, and normal mode. The value of the register is shadowed when it is read in a burst read with the data register at the beginning of the operation and the shadowed value is returned.
#define DATA_19			0X17	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_18			0X16	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_17			0X15	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_16			0X14	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_15			0X13	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_14			0X12	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_13			0X11	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_12			0X10	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_11			0X0F	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_10			0X0E	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_9			0X0D	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_8			0X0C	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_7			0X0B	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_6			0X0A	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_5			0X09	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_4			0X08	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_3			0X07	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_2			0X06	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_1			0X05	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define DATA_0			0X04	//	Register for accelerometer, gyroscope and magnetometer data. DATA[0-19] are treated as atomic update unit with respect to an I2C/SPI operation.
#define PMU_STATUS		0X03	//	Shows the current power mode of the sensor.
#define ERR_REG			0X02	//	Reports sensor error flags. Flags are reset when read.
#define CHIP_ID			0X00	//	The register contains the chip identification code.

/****************************************************************************************************
****************************    EXT. VARIABLES DECLARATION    ***************************************
*****************************************************************************************************/

/****************************************************************************************************
**************************     GLOBAL FUNCTIONS DECLARATION      ************************************
*****************************************************************************************************/

#endif /* BMI160_DRV_H_  */

/****************************************************************************************************
*	Revision History (Description, author, date: mm/dd/yyyy)
*
****************************************************************************************************/

/**************************   (C)SIAVASH TAHER PARVAR ALL RIGHTS RESERVED   ************************/
/************************************     END OF THE FILE      *************************************/
