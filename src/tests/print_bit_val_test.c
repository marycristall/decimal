#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(print_bit_val_test_1) {
  s21_decimal a = {{0b01010000001000000000000000101011,
                    0b01010001111000000000000000101010,
                    0b01010000000000000011111000101011,
                    0b01010100010001001000100000101011}};  // sing here

  char expected[133] =
      "01010100010001001000100000101011 01010000000000000011111000101011 "
      "01010001111000000000000000101010 01010000001000000000000000101011\0";
  char *real = calloc(4 * 33, 1);
  print_bit_val(a, &real);
  ck_assert_str_eq(expected, real);
  free(real);
}
END_TEST

START_TEST(print_bit_val_test_2) {
  s21_decimal a = {{0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000}};  // sing here
  char expected[133] =
      "00000000000000000000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000000000 00000000000000000000000000000000";
  char *real = calloc(4 * 33, 1);
  print_bit_val(a, &real);
  ck_assert_str_eq(expected, real);
  free(real);
}
END_TEST

START_TEST(print_bit_val_test_3) {
  s21_decimal a = {{0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b00000000000000000000000000000000,
                    0b10000000000000000000000000000000}};  // sing here
  char expected[133] =
      "10000000000000000000000000000000 00000000000000000000000000000000 "
      "00000000000000000000000000000000 00000000000000000000000000000000";
  char *real = calloc(4 * 33, 1);
  print_bit_val(a, &real);
  ck_assert_str_eq(expected, real);
  free(real);
}
END_TEST

START_TEST(print_bit_val_test_4) {
  s21_decimal a = {{0b10011000000000000000000000000000,
                    0b10010100000000000000000000000000,
                    0b10000000000000000000000000000000,
                    0b00000000000000000000000000000000}};  // sing here
  char expected[133] =
      "00000000000000000000000000000000 10000000000000000000000000000000 "
      "10010100000000000000000000000000 10011000000000000000000000000000";
  char *real = calloc(4 * 33, 1);
  print_bit_val(a, &real);
  ck_assert_str_eq(expected, real);
  free(real);
}
END_TEST

START_TEST(print_bit_val_test_5) {
  s21_decimal a = {{0b11111111111111111111111111111111,
                    0b11111111111111111111111111111111,
                    0b11111111111111111111111111111111,
                    0b01111111111111111111111111111111}};  // sing here
  char expected[133] =
      "01111111111111111111111111111111 11111111111111111111111111111111 "
      "11111111111111111111111111111111 11111111111111111111111111111111";
  char *real = calloc(4 * 33, 1);
  print_bit_val(a, &real);
  ck_assert_str_eq(expected, real);
  free(real);
}
END_TEST

Suite *print_bit_val_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("print_bit_val");
  tc = tcase_create("print_bit_val_case");

  tcase_add_test(tc, print_bit_val_test_1);
  tcase_add_test(tc, print_bit_val_test_2);
  tcase_add_test(tc, print_bit_val_test_3);
  tcase_add_test(tc, print_bit_val_test_4);
  tcase_add_test(tc, print_bit_val_test_5);

  suite_add_tcase(s, tc);
  return s;
}
