#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(s21_from_int_to_decimal_1) {
  int src = 49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  int src = -49135648;
  s21_decimal check = {{49135648, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
  int src = 2147483647;
  s21_decimal check = {{2147483647, 0, 0, 0}};
  s21_decimal result;
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_4) {
  int src = -2147483648;
  s21_decimal check = {{2147483648, 0, 0, 0}};
  set_sign(&check, 1);
  s21_decimal result;
  int return_value = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

Suite *s21_from_int_to_decimal_test_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_int_to_decimal");
  tc = tcase_create("s21_from_int_to_decimal_testcase");

  tcase_add_test(tc, s21_from_int_to_decimal_1);
  tcase_add_test(tc, s21_from_int_to_decimal_2);
  tcase_add_test(tc, s21_from_int_to_decimal_3);
  tcase_add_test(tc, s21_from_int_to_decimal_4);

  suite_add_tcase(s, tc);
  return s;
}
