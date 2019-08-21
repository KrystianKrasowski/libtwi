#include <avr/io.h>
#include "twi.h"

void twi_init(uint32_t clock_frequency, uint16_t scl_frequency)
{
	TWSR = 0;
	TWBR = (uint8_t) ((clock_frequency/(scl_frequency * 1000)))/2;
}

uint8_t twi_status(uint8_t status)
{
	uint8_t current = TWSR & 0xF8;
	return status == current;
}

void twi_mode_addressed(uint8_t addr)
{
	TWAR = addr;
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void twi_mode_naddressed()
{
	TWCR = (1 << TWINT) | (TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void twi_start()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	while (!(TWCR & (1 << TWINT)));
}

void twi_write_ack(uint8_t data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

void twi_write(uint8_t data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

uint8_t twi_read_ack()
{
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

uint8_t twi_read_nack()
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

void twi_stop()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	while (TWCR & (1 << TWSTO));
}