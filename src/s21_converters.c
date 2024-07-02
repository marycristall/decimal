#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  clear_bits(dst);
  int result = 0, index = 0, i = 0, sign = 0, cont = 0;
  char s[14];
  if (src > 0)
    snprintf(s, 13, "%.6e", src);
  else {
    snprintf(s, 14, "%.6e", src);
    sign = 1;
    i = 1;
    while (s[i] != '\0') {
      s[i - 1] = s[i];
      ++i;
    }
    s[12] = '\0';
    i = 0;
  }
  while (s[i] != '\0' && index == 0) {
    if (s[i] == '.') index = i;
    ++i;
  }
  int exp = (s[10] - '0') * 10 + s[11] - '0', mantissa = 0;
  i = 0;
  while (s[i] != 'e') {
    if (s[i] != '.') mantissa = mantissa * 10 + s[i] - '0';
    ++i;
  }
  (*dst).bits[0] = mantissa;
  s21_decimal ten = {{10u, 0u, 0u, 0u}}, tmp = {{0u, 0u, 0u, 0u}};
  if (s[9] == '-') exp = -exp;
  if (exp > 28 || -exp > 27) result = 1;
  exp -= 6;
  if (exp < 0)
    set_exp(dst, -exp);
  else {
    while (exp > 0 && !cont) {
      cont = s21_mul(*dst, ten, &tmp);
      --exp;
      if (!cont) *dst = tmp;
    }
    if (exp != 0)
      set_exp(dst, -exp);
    else
      set_exp(dst, exp);
  }
  if (!result)
    set_sign(dst, sign);
  else
    clear_bits(dst);
  return result;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int return_value = OK;
  if (dst) {
    clear_bits(dst);
    if (src < 0) {
      set_sign(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;
  } else {
    return_value = CONVERTING_ERROR;
  }
  return return_value;
}
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int return_value = OK;
  if (src.bits[1] || src.bits[2]) {
    return_value = CONVERTING_ERROR;
  }
  if (dst && !return_value) {
    *dst = src.bits[0];
    if (get_bit(src, 127)) {
      *dst *= -1;
    }
  } else {
    return_value = CONVERTING_ERROR;
  }
  return return_value;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double tmp = 0;
  int exp = 0;
  for (int i = 0; i < 96; i++)
    if (((src.bits[i / 32]) & (1 << i % 32)) != 0) tmp += pow(2, i);
  if ((exp = (src.bits[3] & ~0x80000000) >> 16) > 0) {
    for (int i = exp; i > 0; i--) tmp /= 10;
  }
  *dst = (float)tmp;
  *dst *= src.bits[3] >> 31 ? -1 : 1;
  return OK;
}
