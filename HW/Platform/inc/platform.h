/*
 * platform.h
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 *
 *  This file holds the API for the platform dependant code
 *
 *      Requirements:
 *              A : Send a message to a slave device (slave receive mode)
 *              B : Read a register in a slave device (slave transmit mode)
 *
 *              1 : Bytes are send msb (most significant bit) first
 *
 */

#include <stdint.h>

#ifndef PLATFORM_H_
#define PLATFORM_H_

enum platformErrorCodes { OK, ERROR };

int8_t I2C_init();
int8_t I2C_send();

#endif /* PLATFORM_H_ */
