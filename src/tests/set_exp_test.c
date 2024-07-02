#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(set_exp_test_1) {
  s21_decimal a = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b11111111111101111111111111111111}};
  /////
  int expected, real;
  for (int i = 0; i < 40; ++i) {
    set_exp(&a, i);
    real = get_exp(a);
    expected = i % 32;
    ck_assert_int_eq(expected, real);
  }
}
END_TEST

Suite *set_exp_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("set_exp");
  tc = tcase_create("set_exp_case");

  tcase_add_test(tc, set_exp_test_1);

  suite_add_tcase(s, tc);
  return s;
}
