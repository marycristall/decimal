#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147745792;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal value = {{0xFFFFFF, 0, 0, 0}};
  float result;
  float check = 16777215;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal value = {{12123, 0, 0, 0}};
  set_exp(&value, 3);
  set_sign(&value, 1);
  float result;
  float check = -12.123;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  float result;
  float check = 0xFFFFFFFFFFFFFFFF;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal value = {{1234, 0, 0, 0}};
  set_sign(&value, 1);
  float result;
  float check = -1234;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

Suite *s21_from_decimal_to_float_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_float");
  tc = tcase_create("s21_from_decimal_to_float_testcase");

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_4);
  tcase_add_test(tc, s21_from_decimal_to_float_5);

  suite_add_tcase(s, tc);
  return s;
}
