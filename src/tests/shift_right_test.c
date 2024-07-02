#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(shift_right_test_1) {
  s21_decimal a = {{0b11010000001000000000000000100110,
                    0b11010001111000000000000000101011,
                    0b11010000000000000011111000101011,
                    0b11010100010001001000100000100001}};  // sing here

  char expected[133] =
      "11010100010001001000100000100001 11010000000000000011111000101011 "
      "11010001111000000000000000101011 11010000001000000000000000100110";
  shift_right(&a, 0);
  char *str = calloc(133, 1);
  print_bit_val(a, &str);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(shift_right_test_2) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  char expected[133] =
      "10110010000100111111110010110001 00000101110100010110000101011000 "
      "10101111100101000001100110010001 11001011001110101101111001101000";

  shift_right(&a, 5);
  char *str = calloc(133, 1);
  print_bit_val(a, &str);

  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

Suite *shift_right_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("shift_right");
  tc = tcase_create("shift_right_case");

  tcase_add_test(tc, shift_right_test_1);
  tcase_add_test(tc, shift_right_test_2);

  suite_add_tcase(s, tc);
  return s;
}
