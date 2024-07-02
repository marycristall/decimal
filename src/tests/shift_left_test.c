#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(shift_left_test_1) {
  s21_decimal a = {{0b11010000001000000000000000100110,
                    0b11010001111000000000000000101011,
                    0b11010000000000000011111000101011,
                    0b11010100010001001000100000100001}};  // sing here

  char expected[133] =
      "11010100010001001000100000100001 11010000000000000011111000101011 "
      "11010001111000000000000000101011 11010000001000000000000000100110";
  shift_left(&a, 0);
  char *str = calloc(133, 1);
  print_bit_val(a, &str);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(shift_left_test_2) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int code = shift_left(&a, 5);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *shift_left_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("shift_left");
  tc = tcase_create("shift_left_case");

  tcase_add_test(tc, shift_left_test_1);
  tcase_add_test(tc, shift_left_test_2);

  suite_add_tcase(s, tc);
  return s;
}
