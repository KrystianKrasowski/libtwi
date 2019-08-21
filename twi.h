#ifndef TWIMASTER_H_
#define TWIMASTER_H_


void twi_init(uint32_t clock_frequency, uint16_t scl_frequency);
uint8_t twi_status(uint8_t status);
void twi_mode_addressed(uint8_t addr);
void twi_mode_naddressed();
void twi_start();
void twi_write(uint8_t data);
void twi_write_ack(uint8_t data);
uint8_t twi_read_ack();
uint8_t twi_read_nack();
void twi_stop();
void twi_transmit(uint8_t addr, uint8_t message[], uint8_t size);
void twi_receive(uint8_t address, uint8_t message[], uint8_t size);


#endif /* TWIMASTER_H_ */