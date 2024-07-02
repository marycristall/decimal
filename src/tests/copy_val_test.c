#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(copy_val_test_1) {
  s21_decimal first = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b00000000000101111111111111111111}};

  char *str1 = calloc(133, 1);
  char *str2 = calloc(133, 1);
  print_bit_val(first, &str1);
  s21_decimal second;
  copy_val(&second, first);
  print_bit_val(second, &str2);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(copy_val_test_2) {
  s21_decimal first = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};

  char *str1 = calloc(133, 1);
  char *str2 = calloc(133, 1);
  print_bit_val(first, &str1);
  s21_decimal second;
  copy_val(&second, first);
  print_bit_val(second, &str2);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(copy_val_test_3) {
  s21_decimal first = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b11111111111111111111111111111111}};

  char *str1 = calloc(133, 1);
  char *str2 = calloc(133, 1);
  print_bit_val(first, &str1);
  s21_decimal second;
  copy_val(&second, first);
  print_bit_val(second, &str2);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(copy_val_test_4) {
  s21_decimal first = {
      {0b01010000001000000000000000101011, 0b01010001111000000000000000101010,
       0b01010000000000000011111000101011, 0b01010100010001001000100000101011}};

  char *str1 = calloc(133, 1);
  char *str2 = calloc(133, 1);
  print_bit_val(first, &str1);
  s21_decimal second;
  copy_val(&second, first);
  print_bit_val(second, &str2);
  ck_assert_str_eq(str1, str2);
  free(str1);
  free(str2);
}
END_TEST

Suite *copy_val_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("copy_val");
  tc = tcase_create("copy_val_case");

  tcase_add_test(tc, copy_val_test_1);
  tcase_add_test(tc, copy_val_test_2);
  tcase_add_test(tc, copy_val_test_3);
  tcase_add_test(tc, copy_val_test_4);

  suite_add_tcase(s, tc);
  return s;
}