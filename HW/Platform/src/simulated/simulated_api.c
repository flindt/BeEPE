/*
 * simulated_api.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include <stdint.h>

#include "platform.h"
#include "simulated.h"

int8_t I2C_init()
{
  return ERROR;
}


int8_t I2C_send()
{

  return sim_I2C_send();

}
