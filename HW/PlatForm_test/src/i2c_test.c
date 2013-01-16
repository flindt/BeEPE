/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

void test_i2c_init()
{

}


void test_i2c( void )
{
        test_fixture_start();               // starts a fixture
        run_test(test_i2c_init);
        test_fixture_end();                 // ends a fixture
}
