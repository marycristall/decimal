#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_decimal.h"

int get_sign(s21_decimal val) { return (val.bits[3] & (1 << 31)) > 0; }

void set_sign(s21_decimal *val, int sign) {
  if (sign == 1) {
    (*val).bits[3] = (*val).bits[3] | (1 << 31);
  } else if (sign == 0) {
    (*val).bits[3] = (*val).bits[3] & ~(1 << 31);
  }
}

void print_bit(s21_decimal val, int index, char **res) {
  unsigned tmp = 1 << 31;
  size_t res_index = 0;
  while (tmp != 0) {
    (*res)[res_index++] = '0' + ((val.bits[index] & tmp) > 0);
    tmp >>= 1;
  }
}

void print_bit_val(s21_decimal val, char **res) {
  for (int i = 3; i >= 0; --i) {
    char *tmp = calloc(33, sizeof(unsigned int));
    print_bit(val, i, &tmp);
    tmp[32] = (i != 0) ? ' ' : '\0';
    strncat(*res, tmp, 33);
    free(tmp);
  }
}

int get_bit(s21_decimal val, int index) {
  // start of count from LEFT!!!! sign - 127!
  int tmp = (index) / 32, local_index = index % 32;
  return (val.bits[tmp] & (1 << local_index)) > 0;
}

void set_bit(s21_decimal *val, int index, int bit) {
  int tmp = index / 32, bit_index = index % 32;
  if (bit == 0) {
    (*val).bits[tmp] &= ~(1 << bit_index);
  } else if (bit == 1) {
    (*val).bits[tmp] |= (1 << bit_index);
  }
}

void shift_right(s21_decimal *val, int shift) {
  (*val).bits[0] >>= shift;
  for (int i = 1; i < 3; ++i) {
    int count = 0;
    while (count < shift) {
      if ((*val).bits[i] & (1 << count))
        (*val).bits[i - 1] |= (1 << (31 - shift + count + 1));
      ++count;
    }
    (*val).bits[i] >>= shift;
  }
}

int shift_left(s21_decimal *value, int offset) {
  int res = OK;
  int lastbit = highest_bit(*value);
  if (lastbit + offset > 95) {
    res = INF;
  } else {
    for (int i = 0; i < offset; i++) {
      int bit31 = get_bit(*value, 31);
      int bit63 = get_bit(*value, 63);
      value->bits[0] <<= 1;
      value->bits[1] <<= 1;
      value->bits[2] <<= 1;
      if (bit31) set_bit(value, 32, 1);
      if (bit63) set_bit(value, 64, 1);
    }
  }
  return res;
}

int get_exp(s21_decimal val) {
  unsigned tmp = 0b11111;
  tmp <<= 16;
  return (val.bits[3] & tmp) >> 16;
}

void set_exp(s21_decimal *val, int exp) {
  int cur = 0, start_exp = 112;
  while (cur < 5) {
    int bit = exp & (1 << cur);
    set_bit(val, start_exp + cur, bit > 0);
    ++cur;
  }
}

void init_val(s21_decimal *val, char *str) {
  int space = 0;
  size_t start = strlen(str) - 1;
  for (int i = 0; i < 4; ++i) (*val).bits[i] = 0;
  for (int i = start; i >= 0; --i) {
    if (str[i] == ' ')
      ++space;
    else if (str[i] == '1')
      set_bit(val, start - i - space, 1);
  }
}

void copy_val(s21_decimal *target, s21_decimal src) {
  for (int i = 0; i < 4; ++i) (*target).bits[i] = src.bits[i];
}
//---------------------------------------------------------------------------------------------------------//

void clear_bits(s21_decimal *val) { memset(val->bits, 0, sizeof(val->bits)); }

int is_zero_decimal(s21_decimal val1) {
  int res = FALSE;
  s21_decimal *ptr1 = &val1;
  if (ptr1) {
    if (!val1.bits[0] && !val1.bits[1] && !val1.bits[2]) {
      res = TRUE;
    }
  }
  return res;
}

int highest_bit(s21_decimal number) {
  int highest_bit = 95;
  while (highest_bit >= 0 && get_bit(number, highest_bit) == 0) {
    highest_bit--;
  }
  return highest_bit;
}

int bit_add(s21_decimal val1, s21_decimal val2, s21_decimal *res) {
  clear_bits(res);
  int return_val = OK;
  int buffer = 0;

  for (int i = 0; i < 96; i++) {
    int current_bit1 = get_bit(val1, i);
    int current_bit2 = get_bit(val2, i);

    if (!current_bit1 && !current_bit2) {
      if (buffer) {
        set_bit(res, i, 1);
        buffer = 0;
      } else {
        set_bit(res, i, 0);
      }
    } else if (current_bit1 != current_bit2) {
      if (buffer) {
        set_bit(res, i, 0);
        buffer = 1;
      } else {
        set_bit(res, i, 1);
      }
    } else {
      if (buffer) {
        set_bit(res, i, 1);
        buffer = 1;
      } else {
        set_bit(res, i, 0);
        buffer = 1;
      }
    }
    if (i == 95 && buffer == 1) return_val = INF;
  }
  return return_val;
}
void bit_div(s21_decimal number1, s21_decimal number2, s21_decimal *remainder,
             s21_decimal *res) {
  clear_bits(remainder);
  clear_bits(res);
  int exp = get_exp(number2);
  set_exp(&number2, 0);
  for (int i = highest_bit(number1); i >= 0; i--) {
    if (get_bit(number1, i)) set_bit(remainder, 0, 1);
    if (s21_is_greater_or_equal(*remainder, number2) == TRUE) {
      bit_subtraction(*remainder, number2, remainder);
      if (i != 0) shift_left(remainder, 1);
      if (get_bit(number1, i - 1)) set_bit(remainder, 0, 1);
      shift_left(res, 1);
      set_bit(res, 0, 1);
    } else {
      shift_left(res, 1);
      if (i != 0) shift_left(remainder, 1);
      if ((i - 1) >= 0 && get_bit(number1, i - 1)) set_bit(remainder, 0, 1);
    }
  }
  set_exp(&number2, exp);
}

void bit_subtraction(s21_decimal number_1, s21_decimal number_2,
                     s21_decimal *result) {
  clear_bits(result);
  if (s21_is_not_equal(number_1, number_2) == TRUE) {
    int highestbit_num1 = highest_bit(number_1);
    int mem = 0;
    for (int i = 0; i <= highestbit_num1; i++) {
      int currbit_num1 = get_bit(number_1, i);
      int currbit_num2 = get_bit(number_2, i);
      if (!currbit_num1 && !currbit_num2) {
        if (mem) {
          mem = 1;
          set_bit(result, i, 1);
        } else {
          set_bit(result, i, 0);
        }
      } else if (currbit_num1 && !currbit_num2) {
        if (mem) {
          mem = 0;
          set_bit(result, i, 0);
        } else {
          set_bit(result, i, 1);
        }
      } else if (!currbit_num1 && currbit_num2) {
        if (mem) {
          mem = 1;
          set_bit(result, i, 0);
        } else {
          mem = 1;
          set_bit(result, i, 1);
        }
      } else if (currbit_num1 && currbit_num2) {
        if (mem) {
          mem = 1;
          set_bit(result, i, 1);
        } else {
          set_bit(result, i, 0);
        }
      }
    }
  }
}

void exp_decrease(s21_decimal *a) {
  s21_decimal ten = {{10u, 0, 0, 0}};
  if (highest_bit(*a) < 32 && a->bits[0] < 10) a->bits[0] = 0;
  s21_decimal remainder;
  bit_div(*a, ten, &remainder, a);
}

void normalize_vals(s21_decimal *first, s21_decimal *second) {
  s21_decimal ten = {{10u, 0, 0, 0}};
  if (get_exp(*first) < get_exp(*second)) {
    int difference = get_exp(*second) - get_exp(*first);
    if (highest_bit(*first) + difference <= 95 && highest_bit(*second) <= 95) {
      for (int i = 0; i < difference; i++) {
        s21_mul(*first, ten, first);
      }
      set_exp(first, get_exp(*second));
    } else {
      for (int i = 0; i < difference; i++) {
        exp_decrease(second);
      }
      set_exp(first, get_exp(*first));
    }
  } else {
    int difference = get_exp(*first) - get_exp(*second);
    if (highest_bit(*second) + difference <= 95 && highest_bit(*first) <= 95) {
      for (int i = 0; i < difference; i++) {
        s21_mul(*second, ten, second);
      }
      set_exp(second, get_exp(*first));
    } else {
      for (int i = 0; i < difference; i++) {
        exp_decrease(first);
      }
      set_exp(first, get_exp(*second));
    }
  }
}

int bit_mull(int highest_bit_of_num_1, s21_decimal num_1, s21_decimal num_2,
             s21_decimal tmp, s21_decimal *result, int inf_check) {
  for (int i = 0; i <= highest_bit_of_num_1; i++) {
    clear_bits(&tmp);
    int currbit = get_bit(num_1, i);

    if (currbit) {
      tmp = num_2;
      inf_check = shift_left(&tmp, i);
      inf_check = bit_add(*result, tmp, result);
    }
  }
  return inf_check;
}