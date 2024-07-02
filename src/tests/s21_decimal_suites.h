#ifndef S21_DECIMAL_SUITES
#define S21_DECIMAL_SUITES

#include <check.h>

#include "../s21_decimal.h"

Suite *get_sign_suite();
Suite *set_sign_suite();
Suite *print_bit_val_suite();
Suite *get_bit_suite();
Suite *set_bit_suite();
Suite *shift_right_suite();
Suite *shift_left_suite();
Suite *get_exp_suite();
Suite *set_exp_suite();
Suite *init_val_suite();
Suite *copy_val_suite();
Suite *s21_is_greater_suite();
Suite *s21_is_equal_suite();
Suite *s21_is_less_suite();
Suite *s21_is_not_equal_suite();
Suite *s21_is_greater_or_equal_suite();
Suite *s21_is_less_or_equal_suite();
Suite *s21_div_suite();
Suite *s21_float_to_decimal_suite();
Suite *s21_from_decimal_to_float_suite();
Suite *s21_add_test_suite();
Suite *s21_sub_test_suite();
Suite *s21_from_int_to_decimal_test_suite();
Suite *s21_from_decimal_to_int_test_suite();
Suite *s21_normalize_test_suite();
Suite *s21_truncate_test_suite();
Suite *s21_negate_test_suite();
Suite *s21_floor_test_suite();
Suite *s21_round_test_suite();

#endif
