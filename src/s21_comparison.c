#include "s21_decimal.h"

int s21_is_greater(s21_decimal number_1, s21_decimal number_2) {
  int sign1 = get_sign(number_1);
  int sign2 = get_sign(number_2);
  if (get_exp(number_1) != get_exp(number_2)) {
    normalize_vals(&number_1, &number_2);
  }
  set_sign(&number_1, sign1);
  set_sign(&number_2, sign2);
  int result = 1, flag = 1;

  if (get_sign(number_1) && !get_sign(number_2)) {
    result = 0;
  } else if (!get_sign(number_1) && get_sign(number_2)) {
    result = 1;
  } else if (!get_sign(number_1) && !get_sign(number_2)) {
    for (int i = 2; i >= 0 && flag; i--) {
      if (number_1.bits[i] > number_2.bits[i]) {
        result = TRUE;
        flag = 0;
      } else if (number_1.bits[i] < number_2.bits[i]) {
        result = FALSE;
        flag = 0;
      } else if (number_1.bits[i] == number_2.bits[i]) {
        result = FALSE;
      }
    }
  } else if (get_sign(number_1) && get_sign(number_2)) {
    for (int i = 2; i >= 0 && flag; i--) {
      if (number_1.bits[i] > number_2.bits[i]) {
        result = 0;
        flag = 0;
      } else if (number_1.bits[i] < number_2.bits[i]) {
        result = 1;
        flag = 0;
      } else if (number_1.bits[i] == number_2.bits[i]) {
        result = 0;
      }
    }
  }
  if (is_zero(number_1, number_2)) result = FALSE;
  return result;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int is_equal = TRUE;

  if (get_exp(value_1) != get_exp(value_2)) normalize_vals(&value_1, &value_2);
  if (value_1.bits[0] == 0 && value_2.bits[0] == 0 && value_1.bits[1] == 0 &&
      value_2.bits[1] == 0 && value_1.bits[2] == 0 && value_2.bits[2] == 0 &&
      get_exp(value_1) == get_exp(value_2))
    is_equal = TRUE;
  else if (value_1.bits[0] != value_2.bits[0] ||
           value_1.bits[1] != value_2.bits[1] ||
           value_1.bits[2] != value_2.bits[2] ||
           get_exp(value_1) != get_exp(value_2) ||
           get_sign(value_1) != get_sign(value_2)) {
    is_equal = FALSE;
  }

  return is_equal;
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_is_greater(num1, num2) || s21_is_equal(num1, num2));
}

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return !(s21_is_equal(num1, num2));
}

int is_zero(s21_decimal val1, s21_decimal val2) {
  int is_zero = FALSE;
  s21_decimal *ptr1 = &val1;
  s21_decimal *ptr2 = &val2;
  if (ptr1 && ptr2) {
    if (!val1.bits[0] && !val2.bits[0] && !val1.bits[1] && !val2.bits[1] &&
        !val1.bits[2] && !val2.bits[2]) {
      is_zero = TRUE;
    }
  }
  return is_zero;
}

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  return s21_is_greater(num2, num1);
}

int s21_is_less_or_equal(s21_decimal val_1, s21_decimal val_2) {
  return s21_is_less(val_1, val_2) || !s21_is_not_equal(val_1, val_2);
}
