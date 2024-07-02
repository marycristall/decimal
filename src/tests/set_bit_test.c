#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(set_bit_test_1) {
  s21_decimal a = {{0b11010000001000000000000000100110,
                    0b11010001111000000000000000101011,
                    0b11010000000000000011111000101011,
                    0b11010100010001001000100000100001}};  // sing here

  int expected = 0;
  set_bit(&a, 0, 0);
  int real = get_bit(a, 0);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_2) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 1;
  set_bit(&a, 127, 1);
  int real = get_bit(a, 127);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_3) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 0;
  set_bit(&a, 127, 0);
  int real = get_bit(a, 127);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_4) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 1;
  set_bit(&a, 31, 1);
  int real = get_bit(a, 31);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_5) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 0;
  set_bit(&a, 31, 0);
  int real = get_bit(a, 31);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_6) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 1;
  set_bit(&a, 32, 1);
  int real = get_bit(a, 32);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_7) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 1;
  set_bit(&a, 96, 1);
  int real = get_bit(a, 96);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_8) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 1;
  set_bit(&a, 100, 1);
  int real = get_bit(a, 100);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(set_bit_test_9) {
  s21_decimal a = {{0b01100111010110111100110100010101,
                    0b11110010100000110011001000111001,
                    0b10111010001011000010101100010101,
                    0b10110010000100111111110010110001}};  // sing here

  int expected = 0;
  set_bit(&a, 100, 0);
  int real = get_bit(a, 100);
  ck_assert_int_eq(expected, real);
}
END_TEST

Suite *set_bit_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("set_bit");
  tc = tcase_create("set_bit_case");

  tcase_add_test(tc, set_bit_test_1);
  tcase_add_test(tc, set_bit_test_2);
  tcase_add_test(tc, set_bit_test_3);
  tcase_add_test(tc, set_bit_test_4);
  tcase_add_test(tc, set_bit_test_5);
  tcase_add_test(tc, set_bit_test_6);
  tcase_add_test(tc, set_bit_test_7);
  tcase_add_test(tc, set_bit_test_8);
  tcase_add_test(tc, set_bit_test_9);

  suite_add_tcase(s, tc);
  return s;
}
