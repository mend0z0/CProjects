
#ifndef	I2C_DRIVER_H
#define I2C_DRIVER_H

//General Constants for I2C peripheral
#define WRITE				0X00
#define READ				0X01
#define START				0X08
#define	RE_START			0X10

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

void _init_I2C( void );
unsigned int SendDataOnI2C( unsigned addr, unsigned int *data, unsigned int buffSize);


#endif