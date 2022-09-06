

#include "i2c_driver.h"
#include "avr/io.h"
#include "avr/interrupt.h"

ISR(TWI_vect){
	TWCR |= (1 << TWINT);
}

static void I2CErrorChecker( unsigned int condition){
	
}

void _init_I2C( void ){
	DDRC |= (1 << 0) | (1 << 1);
	
	TWBR = 0X02;			// For 400KHz frequency clock on SCL it should be 8000000/(16+(2 * 2 (TWBR) * 4^0(TWPS)))
	TWCR |= (1 << TWIE);	// TWI Interrupt Enable
	
	sei();
}

unsigned int SendDataOnI2C( unsigned addr, unsigned int *data, unsigned int buffSize){
	TWCR |= (1<<TWINT)|(1<<TWSTA)| (1<<TWEN);	//Send START condition
	while (!(TWCR & (1<<TWINT)));				//Wait for TWINT Flag set. This indicates that the START condition has been transmitted
	TWCR |= (1 << TWINT);
	if ((TWSR & 0xF8) != START){				//Check value of TWI Status Register. Mask prescaler bits. If status different from	START go to ERROR
		I2CErrorChecker( START );
	}
	TWDR = (addr | WRITE);						//Load SLA_W into TWDR Register. Clear TWINT bit in TWCR to start transmission of address
	TWCR |= (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));				//Wait for TWINT Flag set. This indicates that the SLA+W has been transmitted, and ACK/NACK has been received.
	TWCR |= (1 << TWINT);
	if ((TWSR & 0xF8) != MT_SLA_ACK){			//Check value of TWI Status Register. Mask prescaler bits. If status different from	MT_SLA_ACK go to ERROR
		I2CErrorChecker( MT_SLA_ACK );		
	}
	for(unsigned int counter = 0; counter < buffSize; ++counter){
		TWDR = *(data + counter);									//Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data
		TWCR |= (1<<TWINT) | (1<<TWEN);
		while (!(TWCR & (1<<TWINT)));								//Wait for TWINT Flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received.
		TWCR |= (1 << TWINT);
		if ((TWSR & 0xF8) != MT_DATA_ACK){							//Check value of TWI Status Register. Mask prescaler bits. If status different from MT_DATA_ACK go to ERROR
			I2CErrorChecker(MT_DATA_ACK);
			break;
		}
	}
	TWCR |= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);		//Transmit STOP condition
}

unsigned int *ReceiveDataFromI2C( unsigned addr, unsigned int buffSize){
	unsigned int data[255] = {0};
}