#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal_suites.h"

START_TEST(init_val_test_1) {
  s21_decimal a;
  char expected[133] =
      "10110010000100111111110010110001 10111010001011000010101100010101 "
      "11110010100000110011001000111001 01100111010110111100110100010101";
  init_val(&a, expected);
  char *str = calloc(133, 1);
  print_bit_val(a, &str);
  ck_assert_str_eq(expected, str);
  free(str);
}
END_TEST

START_TEST(init_val_test_2) {
  s21_decimal a;
  char expected[129] =
      "101100100001001111111100101100011011101000101100001010110001010111110010"
      "10000011001100100011100101100111010110111100110100010101";
  init_val(&a, expected);
  char *str = calloc(133, 1);
  char res[133];
  int index = 0;
  print_bit_val(a, &str);
  for (int i = 0; i < 133; ++i) {
    if (str[i] != ' ') res[index++] = str[i];
  }

  ck_assert_str_eq(expected, res);
  free(str);
}
END_TEST

Suite *init_val_suite() {
  Suite *s;
  TCase *tc;
  s = suite_create("init_val");
  tc = tcase_create("init_val_case");

  tcase_add_test(tc, init_val_test_1);
  tcase_add_test(tc, init_val_test_2);

  suite_add_tcase(s, tc);
  return s;
}
