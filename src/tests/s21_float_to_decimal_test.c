#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(s21_float_to_decimal_test_1) {
  float a = 12345.23456789123456;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  char expected[139] =
      "00000000000000100000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000000000 00000000000100101101011001011011";
  char *str = calloc(139, 1);
  print_bit_val(res, &str);
  ck_assert_int_eq(code, 0);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(s21_float_to_decimal_test_2) {
  float a = 1.23456789123456;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  char expected[139] =
      "00000000000001100000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000000000 00000000000100101101011010001000";
  char *str = calloc(139, 1);
  print_bit_val(res, &str);
  ck_assert_int_eq(code, 0);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(s21_float_to_decimal_test_3) {
  float a = 1234567.89123456;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  char expected[139] =
      "00000000000000000000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000000000 00000000000100101101011010001000";
  char *str = calloc(139, 1);
  print_bit_val(res, &str);
  ck_assert_int_eq(code, 0);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(s21_float_to_decimal_test_4) {
  float a = 123456789123.456;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  char expected[139] =
      "00000000000000000000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000011100 10111110100110010100010100000000";
  char *str = calloc(139, 1);
  print_bit_val(res, &str);
  ck_assert_int_eq(code, 0);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(s21_float_to_decimal_test_5) {
  float a = 0.000123456789123456;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  char expected[139] =
      "00000000000010100000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000000000 00000000000100101101011010001000";
  char *str = calloc(139, 1);
  print_bit_val(res, &str);
  ck_assert_int_eq(code, 0);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(s21_float_to_decimal_test_6) {
  float a = 123456780000000000000000000000.0;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test_7) {
  float a = -987654380000000000000000000000.0;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test_8) {
  float a = 0.000000000000000000000000000012345678;
  s21_decimal res = {{0u, 0u, 0u, 0u}};
  int code = s21_from_float_to_decimal(a, &res);
  char expected[139] =
      "00000000000000000000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000000000 00000000000000000000000000000000";

  char *str = calloc(139, 1);
  print_bit_val(res, &str);
  ck_assert_int_eq(code, 1);
  ck_assert_str_eq(str, expected);
  free(str);
}
END_TEST
Suite *s21_float_to_decimal_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_float_to_decimal");
  tc = tcase_create("s21_float_to_decimal_case");

  tcase_add_test(tc, s21_float_to_decimal_test_1);
  tcase_add_test(tc, s21_float_to_decimal_test_2);
  tcase_add_test(tc, s21_float_to_decimal_test_3);
  tcase_add_test(tc, s21_float_to_decimal_test_4);
  tcase_add_test(tc, s21_float_to_decimal_test_5);
  tcase_add_test(tc, s21_float_to_decimal_test_6);
  tcase_add_test(tc, s21_float_to_decimal_test_7);
  tcase_add_test(tc, s21_float_to_decimal_test_8);

  suite_add_tcase(s, tc);
  return s;
}
