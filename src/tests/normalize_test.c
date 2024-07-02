#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(s21_normalize_test_1) {
  s21_decimal first = {
      {0b00000000000000000000000000001111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000011110000000000000000}};
  s21_decimal second = {
      {0b00000000000000000000000000000011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001110000000000000000}};
  normalize_vals(&first, &second);
  int a = get_exp(first);
  int b = get_exp(second);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(b, 15);
}
END_TEST

START_TEST(s21_normalize_test_2) {
  s21_decimal first = {
      {0b00000000000000000000000000001111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000111000000000000000000}};
  s21_decimal second = {
      {0b00000000000000000000000000000011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001110000000000000000}};
  normalize_vals(&first, &second);
  int a = get_exp(first);
  int b = get_exp(second);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(b, 28);
}
END_TEST

START_TEST(s21_normalize_test_3) {
  s21_decimal first = {
      {0b00000000000000000000000000001111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000011110000000000000000}};
  s21_decimal second = {
      {0b00000000000000000000000000000011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  normalize_vals(&first, &second);
  int a = get_exp(first);
  int b = get_exp(second);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(b, 15);
}
END_TEST

START_TEST(s21_normalize_test_4) {
  s21_decimal first = {{~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        0b00000000000010000000000000000000}};
  s21_decimal second = {
      {0b00000000000000000000000000000011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001110000000000000000}};
  normalize_vals(&first, &second);
  int a = get_exp(first);
  int b = get_exp(second);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(b, 8);
}
END_TEST

Suite *s21_normalize_test_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_normalize_test");
  tc = tcase_create("s21_normalize_testcase");

  tcase_add_test(tc, s21_normalize_test_1);
  tcase_add_test(tc, s21_normalize_test_2);
  tcase_add_test(tc, s21_normalize_test_3);
  tcase_add_test(tc, s21_normalize_test_4);
  suite_add_tcase(s, tc);
  return s;
}
