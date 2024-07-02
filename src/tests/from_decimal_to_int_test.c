#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(s21_from_decimal_to_int_1) {
  s21_decimal value = {{49135648, 0, 0, 0}};
  set_sign(&value, 1);
  set_exp(&value, 0);
  int dst;
  int check = -49135648;
  int return_value = s21_from_decimal_to_int(value, &dst);
  ck_assert_int_eq(dst, check);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  s21_decimal value = {{49135648, 0, 0, 0}};
  set_exp(&value, 1);
  int dst;
  int check = 49135648;
  int return_value = s21_from_decimal_to_int(value, &dst);
  ck_assert_int_eq(dst, check);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  s21_decimal value = {{2, 3, 0, 0}};
  int dst;
  int return_value = s21_from_decimal_to_int(value, &dst);
  ck_assert_int_eq(return_value, CONVERTING_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  s21_decimal value = {{2, 3, 7, 0}};
  int dst;
  int return_value = s21_from_decimal_to_int(value, &dst);
  ck_assert_int_eq(return_value, CONVERTING_ERROR);
}
END_TEST
Suite *s21_from_decimal_to_int_test_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_int_test");
  tc = tcase_create("s21_from_decimal_to_int_testcase");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  suite_add_tcase(s, tc);
  return s;
}
