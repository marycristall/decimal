#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  int sign = get_sign(value);
  if (sign) {
    set_sign(result, 0);
  } else {
    set_sign(result, 1);
  }
  return OK;
}

int s21_truncate(s21_decimal src, s21_decimal *result) {
  int res = OK;
  s21_decimal ten = {
      {0b00000000000000000000000000001010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int src_exp = get_exp(src);
  int src_sign = get_sign(src);

  while (src_exp > 0) {
    s21_decimal buffer = {{0, 0, 0, 0}};
    bit_div(src, ten, &buffer, result);
    src = *result;
    src_exp--;
  }
  if (src_sign) {
    set_sign(result, src_sign);
  }
  set_exp(&src, 0);
  //
  return res;
}

int s21_floor(s21_decimal value, s21_decimal *result) {  // оттестить -1.000
  s21_decimal one = {{1, 0, 0, 0}};
  int sign = get_sign(value);
  s21_truncate(value, result);

  if (sign == 1 && !s21_is_equal(value, *result)) {
    set_sign(result, 0);
    s21_add(*result, one, result);
  }
  set_sign(result, sign);
  return OK;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = OK;
  if (result != 0) {
    int exp = get_exp(value);
    int sign = get_sign(value);
    if (sign) {
      set_bit(&value, 127, 0);
    }
    s21_truncate(value, result);
    s21_decimal part_after_dot;
    s21_sub(value, *result, &part_after_dot);
    set_exp(&part_after_dot, 0);
    s21_decimal ten = {{10, 0, 0, 0}};
    while ((exp - 1 > 0) && !is_zero_decimal(part_after_dot)) {
      s21_decimal reminder = {{0, 0, 0, 0}};
      bit_div(part_after_dot, ten, &reminder, &part_after_dot);
      exp--;
    }
    s21_decimal five = {{5, 0, 0, 0}};
    int comp_res = s21_is_greater_or_equal(part_after_dot, five);
    if (comp_res) {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_add(*result, one, result);
    }
    if (sign) {
      set_sign(result, sign);
    }
  } else {
    res = 1;
  }
  return res;
}