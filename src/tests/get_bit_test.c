#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(get_bit_test_1) {
  s21_decimal a = {{0b11010000001000000000000000100110,
                    0b11010001111000000000000000101011,
                    0b11010000000000000011111000101011,
                    0b11010100010001001000100000100001}};  // sing here

  char expected[128] =
      "110101000100010010001000001000011101000000000000001111100010101111010001"
      "11100000000000000010101111010000001000000000000000100110";
  int real;
  for (int i = 127; i >= 0; --i) {
    real = get_bit(a, i);
    ck_assert_int_eq(expected[127 - i] - '0', real);
  }
}
END_TEST

START_TEST(get_bit_test_2) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  char expected[128] =
      "101100100001001111111100101100011011101000101100001010110001010111110010"
      "10000011001100100011100101100111010110111100110100010101";
  int real;
  for (int i = 127; i >= 0; --i) {
    real = get_bit(a, i);
    ck_assert_int_eq(expected[127 - i] - '0', real);
  }
}
END_TEST

Suite *get_bit_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("get_bit");
  tc = tcase_create("get_bit_case");

  tcase_add_test(tc, get_bit_test_1);
  tcase_add_test(tc, get_bit_test_2);

  suite_add_tcase(s, tc);
  return s;
}
