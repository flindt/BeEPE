/*
 * platform.h
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 *
 *  This file holds the API for the platform dependent code
 *
 *      Requirements:
 *              A : Send a message to a slave device (slave receive mode)
 *                      slave address | W | internal slave register | byte 1 | bytes 2 | ... | byte N
 *              B : Read a register in a slave device (slave transmit mode)
 *                      slave address | R | internal slave register | byte 1 | bytes 2 | ... | byte N
 *              1 : Bytes are send msb (most significant bit) first
 *
 *              C : Support for more than one I2C bus
 *
 */

#include <stdint.h>

#ifndef PLATFORM_H_
#define PLATFORM_H_

enum platformErrorCodes { I2C_OK, I2C_ERROR };

// Define a HWBUS pointer - this is the reference to the bus to be used
struct bus_struct;
typedef struct bus_struct *HWBUS;

// HWBUS functions -----------------------------------------------------------------------------------
HWBUS I2C_bus_open(int8_t busNumber);

// I2C functions -------------------------------------------------------------------------------------
int8_t I2C_init();
int8_t I2C_send( HWBUS hwBus, int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToSend, int8_t *dataBytes);
int8_t I2C_read( HWBUS hwBus, int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToRead, int8_t *dataBytes);


#endif /* PLATFORM_H_ */
