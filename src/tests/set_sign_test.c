#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(set_sign_test_1) {
  s21_decimal a = {{0b01010000001000000000000000101011,
                    0b01010001111000000000000000101010,
                    0b01010000000000000011111000101011,
                    0b01010100010001001000100000101011}};  // sing here
  int expected = 1;
  set_sign(&a, 1);
  int real = get_sign(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_sign_test_2) {
  s21_decimal a = {{0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000}};  // sing here
  int expected = 0;
  set_sign(&a, 0);
  int real = get_sign(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_sign_test_3) {
  s21_decimal a = {{0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b10000000000000000000000000000000}};  // sing here
  int expected = 0;
  set_sign(&a, 0);
  int real = get_sign(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_sign_test_4) {
  s21_decimal a = {{0b10011000000000000000000000000000,
                    0b10010100000000000000000000000000,
                    0b10000000000000000000000000000000,
                    0b10000000000000000000000000000000}};  // sing here
  int expected = 1;
  set_sign(&a, 1);
  int real = get_sign(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

Suite *set_sign_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("set_sign");
  tc = tcase_create("set_sign_case");

  tcase_add_test(tc, set_sign_test_1);
  tcase_add_test(tc, set_sign_test_2);
  tcase_add_test(tc, set_sign_test_3);
  tcase_add_test(tc, set_sign_test_4);

  suite_add_tcase(s, tc);
  return s;
}
