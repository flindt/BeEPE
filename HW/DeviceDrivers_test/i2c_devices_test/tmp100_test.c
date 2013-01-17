/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

void
test_tmp100_readtemp()
{
  assert_true(0);
}


void
test_tmp100(void)
{
  test_fixture_start()
  ;               // starts a fixture
  run_test(test_tmp100_readtemp);

  test_fixture_end()
  ;                 // ends a fixture

}
