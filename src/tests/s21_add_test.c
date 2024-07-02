#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(s21_add_test_1) {  // два положительных целых числа
  s21_decimal first = {
      {0b00000000000000000000000000000011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal second = {
      {0b00000000000000000000000000000111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};

  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000001010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_add(first, second, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

START_TEST(s21_add_test_2) {  // отрицательное и положительное целые
  s21_decimal first = {
      {0b00000000000000000000000000001010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal second = {
      {0b00000000000000000000000000001111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};

  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000000101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  s21_add(first, second, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

START_TEST(s21_add_test_3) {  // целое и дробное положительные
  s21_decimal first = {
      {0b00000000000000000000000000000100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal second = {
      {0b00000000000000000000000000001111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000110000000000000000}};

  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000111110101111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000110000000000000000}};
  s21_add(first, second, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

START_TEST(s21_add_test_4) {  // переполнение положительное
  s21_decimal first = {{~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000}};
  s21_decimal second = {{~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};

  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_add(first, second, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST
START_TEST(s21_add_test_5) {  // переполнение положительное, возвращаемый код
  s21_decimal first = {{~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000}};
  s21_decimal second = {{~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         0b00000000000000000000000000000000}};

  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int i = s21_add(first, second, &result);
  ck_assert_int_eq(1, i);
}
END_TEST

START_TEST(s21_add_test_6) {  // переполнение отрицательное
  s21_decimal first = {{~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        0b10000000000000000000000000000000}};
  s21_decimal second = {{~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         0b10000000000000000000000000000000}};

  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal expected = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_add(first, second, &result);
  char *str_result = calloc(133, 1);
  char *str_expected = calloc(133, 1);
  print_bit_val(result, &str_result);
  print_bit_val(expected, &str_expected);
  ck_assert_str_eq(str_expected, str_result);
  free(str_result);
  free(str_expected);
}
END_TEST

START_TEST(s21_add_test_7) {  // переполнение отрицательное, возвращаемый код
  s21_decimal first = {{~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        ~0b00000000000000000000000000000000,
                        0b10000000000000000000000000000000}};
  s21_decimal second = {{~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         ~0b00000000000000000000000000000000,
                         0b10000000000000000000000000000000}};

  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};

  int i = s21_add(first, second, &result);
  ck_assert_int_eq(2, i);
}
END_TEST

Suite *s21_add_test_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_add_test");
  tc = tcase_create("s21_add_testcase");

  tcase_add_test(tc, s21_add_test_1);
  tcase_add_test(tc, s21_add_test_2);
  tcase_add_test(tc, s21_add_test_3);
  tcase_add_test(tc, s21_add_test_4);
  tcase_add_test(tc, s21_add_test_5);
  tcase_add_test(tc, s21_add_test_6);
  tcase_add_test(tc, s21_add_test_7);

  suite_add_tcase(s, tc);
  return s;
}