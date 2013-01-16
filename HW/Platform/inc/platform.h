/*
 * platform.h
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 *
 *  This file holds the API for the platform dependant code
 *
 *      Requirements:
 *              A : Send a message to a slave device
 *              B : Read a register in a slave device
 *              C : Write a register in a slave device (same as A?)
 *
 *
 */

#include <stdint.h>

#ifndef PLATFORM_H_
#define PLATFORM_H_

int8_t I2C_init();

#endif /* PLATFORM_H_ */
