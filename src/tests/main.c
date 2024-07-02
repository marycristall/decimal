#include "s21_decimal_suites.h"

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests() {
  Suite *test_cases[] = {s21_add_test_suite(),
                         s21_sub_test_suite(),
                         s21_from_decimal_to_int_test_suite(),
                         get_sign_suite(),
                         set_sign_suite(),
                         print_bit_val_suite(),
                         get_bit_suite(),
                         set_bit_suite(),
                         shift_right_suite(),
                         shift_left_suite(),
                         get_exp_suite(),
                         set_exp_suite(),
                         init_val_suite(),
                         copy_val_suite(),
                         s21_add_test_suite(),
                         s21_sub_test_suite(),
                         s21_div_suite(),
                         s21_is_less_suite(),
                         s21_is_less_or_equal_suite(),
                         s21_is_equal_suite(),
                         s21_is_not_equal_suite(),
                         s21_is_greater_or_equal_suite(),
                         s21_is_greater_suite(),

                         s21_from_decimal_to_float_suite(),
                         s21_from_decimal_to_int_test_suite(),
                         s21_normalize_test_suite(),
                         s21_truncate_test_suite(),
                         s21_negate_test_suite(),
                         s21_round_test_suite(),
                         s21_floor_test_suite(),
                         s21_from_int_to_decimal_test_suite(),
                         s21_float_to_decimal_suite(),
                         NULL};
  // Suite *test_cases[] = { s21_div_suite(), NULL};
  // Suite *test_cases[] = { s21_float_to_decimal_suite(), NULL};
  // Suite *test_cases[] = { shift_left_suite(), NULL };
  /*
  Suite *test_cases[] = {get_sign_suite(),
                   set_sign_suite(),
                   print_bit_val_suite(),
                   get_bit_suite(),
                   set_bit_suite(),
                   shift_right_suite(),
                   shift_left_suite(),
                   get_exp_suite(),
                   set_exp_suite(),
                   init_val_suite(),
                   copy_val_suite(),
                   s21_add_test_suite(),
                   s21_sub_test_suite(),
s21_round_test_suite(),
                   s21_from_decimal_to_int_test_suite(),
                   s21_normalize_test_suite(),
                   s21_truncate_test_suite(),  s21_negate_test_suite(),
  s21_from_int_to_decimal_test_suite(),

                   NULL};
  */
  for (Suite **current_testcase = test_cases; *current_testcase != NULL;
       current_testcase++)
    run_testcase(*current_testcase);
}

int main() {
  run_tests();
  return 0;
}
