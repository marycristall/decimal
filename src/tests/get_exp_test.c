#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(get_exp_test_1) {
  s21_decimal a = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b11111111111101111111111111111111}};
  /////
  int expected = 0b10111;
  int real = get_exp(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(get_exp_test_2) {
  s21_decimal a = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b11111111111001111111111111111111}};
  /////
  int expected = 0b00111;
  int real = get_exp(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(get_exp_test_3) {
  s21_decimal a = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b11111111111101011111111111111111}};
  /////
  int expected = 0b10101;
  int real = get_exp(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(get_exp_test_4) {
  s21_decimal a = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b11111111111100001111111111111111}};
  /////
  int expected = 0b10000;
  int real = get_exp(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(get_exp_test_5) {
  s21_decimal a = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b11111111111111111111111111111111}};
  /////
  int expected = 0b11111;
  int real = get_exp(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

START_TEST(get_exp_test_6) {
  s21_decimal a = {
      {0b01000000000000000000000000001001, 0b10110000000000000000000000000111,
       0b11010001000000100000110000000010, 0b11111111111000001111111111111111}};
  /////
  int expected = 0b00000;
  int real = get_exp(a);
  ck_assert_int_eq(expected, real);
}
END_TEST

Suite *get_exp_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("get_exp");
  tc = tcase_create("get_exp_case");

  tcase_add_test(tc, get_exp_test_1);
  tcase_add_test(tc, get_exp_test_2);
  tcase_add_test(tc, get_exp_test_3);
  tcase_add_test(tc, get_exp_test_4);
  tcase_add_test(tc, get_exp_test_5);
  tcase_add_test(tc, get_exp_test_6);

  suite_add_tcase(s, tc);
  return s;
}
