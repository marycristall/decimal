#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

int s21_add(s21_decimal number_1, s21_decimal number_2, s21_decimal *result) {
  clear_bits(result);
  int return_value = OK;

  if (!get_sign(number_1) && !get_sign(number_2)) {
    if (get_exp(number_1) != get_exp(number_2)) {
      normalize_vals(&number_1, &number_2);
    }

    int bit_additioin_result = OK;
    s21_decimal tmp_res;
    bit_additioin_result = bit_add(number_1, number_2, &tmp_res);

    if (bit_additioin_result == INF) {
      return_value = INF;
    } else {
      *result = tmp_res;
      result->bits[3] = number_1.bits[3];
    }
  } else if (get_sign(number_1) && !get_sign(number_2)) {
    set_sign(&number_1, 0);
    return_value = s21_sub(number_2, number_1, result);
  } else if (!get_sign(number_1) && get_sign(number_2)) {
    set_sign(&number_2, 0);
    return_value = s21_sub(number_1, number_2, result);
  } else {
    set_sign(&number_1, 0);
    set_sign(&number_2, 0);
    return_value = s21_add(number_1, number_2, result);
    if (return_value == INF)
      return_value = NEGATIVE_INF;
    else
      set_sign(result, 1);
  }

  return return_value;
}

int s21_sub(s21_decimal number_1, s21_decimal number_2, s21_decimal *result) {
  clear_bits(result);
  int return_value = OK;

  int sign_1 = get_sign(number_1);
  int sign_2 = get_sign(number_2);
  if (get_exp(number_1) != get_exp(number_2)) {
    normalize_vals(&number_1, &number_2);
  }
  set_sign(&number_1, sign_1);
  set_sign(&number_2, sign_2);

  int resultSign;

  if (get_sign(number_1) != get_sign(number_2)) {
    resultSign = get_sign(number_1);
    set_sign(&number_1, 0);
    set_sign(&number_2, 0);
    return_value = s21_add(number_1, number_2, result);
    if (return_value == INF)
      return_value = NEGATIVE_INF;
    else
      set_sign(result, resultSign);
  } else {
    if (s21_is_equal(number_1, number_2) == TRUE) {
    } else {
      int sign_1 = get_sign(number_1);
      int sign_2 = get_sign(number_2);
      set_sign(&number_1, 0);
      set_sign(&number_2, 0);
      s21_decimal *smallPtr, *bigPtr;

      if (s21_is_less(number_1, number_2) == TRUE) {
        smallPtr = &number_1;
        bigPtr = &number_2;
        resultSign = !sign_2;
      } else {
        smallPtr = &number_2;
        bigPtr = &number_1;
        resultSign = sign_1;
      }

      bit_subtraction(*bigPtr, *smallPtr, result);
      set_exp(result, get_exp(number_1));
      set_sign(result, resultSign);
    }
  }

  return return_value;
}
// 0 - OK
// 1 - big or inf
// 2 - small or -inf
// 3 - div on 0
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clear_bits(result);
  int res = 0, cont = 0, minus_2 = get_sign(value_2);
  int new_exp = get_exp(value_2) - get_exp(value_1);
  set_sign(&value_2, 0);
  s21_decimal rem = {{0u, 0u, 0u, 0u}}, zero = {{0u, 0u, 0u, 0u}}, tmp;
  s21_decimal ten = {{10u, 0u, 0u, 0u}}, tmp_rem, tmp_add;
  if (s21_is_equal(value_2, zero)) {
    res = 3;
    set_exp(result, 0);
    result->bits[0] = 0b11111111111111111111111111111111;
    result->bits[1] = 0b11111111111111111111111111111111;
    result->bits[2] = 0b11111111111111111111111111111111;
  } else {
    bit_div(value_1, value_2, &rem, result);
    if (new_exp < 0 && -new_exp <= 28) {
      set_exp(result, get_exp(*result) - new_exp);
      new_exp = 0;
    }
    while (get_exp(*result) < 28 && !cont && rem.bits[0] != 0) {
      cont |= s21_mul(*result, ten, &tmp);
      if (!cont) *result = tmp;
      cont |= s21_mul(rem, ten, &tmp);
      if (!cont) {
        rem = tmp;
        if (new_exp > 0)
          --new_exp;
        else
          set_exp(result, get_exp(*result) + 1);
        bit_div(rem, value_2, &tmp_rem, &tmp);
        rem = tmp_rem;
        set_exp(&tmp, get_exp(*result));
      }
      cont |= s21_add(*result, tmp, &tmp_add);
      if (!cont) *result = tmp_add;
    }
  }
  if (new_exp > 0 && get_exp(*result) - new_exp >= 0)
    set_exp(result, get_exp(*result) - new_exp);
  if (new_exp > 0) {
    res = (!get_sign(*result)) ? 3 : 2;
    set_exp(result, 0);
    result->bits[0] = 0b11111111111111111111111111111111;
    result->bits[1] = 0b11111111111111111111111111111111;
    result->bits[2] = 0b11111111111111111111111111111111;
  } else if (new_exp < 0 && get_exp(*result) - new_exp <= 28)
    set_exp(result, get_exp(*result) - new_exp);
  if (get_sign(value_1) + minus_2 == 1) set_sign(result, 1);
  return res;
}

int s21_mul(s21_decimal number_1, s21_decimal number_2, s21_decimal *result) {
  clear_bits(result);
  int return_value = OK;
  int res_sign;

  if (get_sign(number_1) != get_sign(number_2)) {
    res_sign = 1;
  } else {
    res_sign = 0;
  }
  int high_bit1 = highest_bit(number_1);
  int high_bit2 = highest_bit(number_2);
  s21_decimal tmp = {{0, 0, 0, 0}};
  int inf_check = OK;
  if (high_bit1 <= high_bit2) {
    bit_mull(high_bit1, number_1, number_2, tmp, result, inf_check);
  }
  if (high_bit1 > high_bit2) {
    bit_mull(high_bit2, number_2, number_1, tmp, result, inf_check);
  }
  if (inf_check == INF) {
    if (res_sign)
      return_value = NEGATIVE_INF;
    else
      return_value = INF;
    clear_bits(result);
  } else {
    int exp = get_exp(number_1) + get_exp(number_2);
    set_exp(result, exp);
    set_sign(result, res_sign);
  }
  return return_value;
}
