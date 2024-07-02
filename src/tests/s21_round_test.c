#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(s21_round_1) {  //-1,5 ->> -2
  s21_decimal first = {
      {0b00000000000000000000000000001111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000010000000000000000}};
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  s21_round(first, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

START_TEST(s21_round_2) {  // 1,5 ->> 2
  s21_decimal first = {
      {0b00000000000000000000000000001111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000010000000000000000}};
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_round(first, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

START_TEST(s21_round_3) {  //-1.001 ->> -1
  s21_decimal first = {
      {0b00000000000000000000001111101001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000110000000000000000}};
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  s21_round(first, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal first = {
      {0b00000000000000000000000000010000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000010000000000000000}};
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_round(first, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

Suite *s21_round_test_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_round");
  tc = tcase_create("s21_round_testcase");

  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);

  suite_add_tcase(s, tc);
  return s;
}