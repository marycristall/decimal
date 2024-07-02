#ifndef DECIMAL_H
#define DECIMAL_H

#define TRUE 1
#define FALSE 0

enum returns { OK, INF, NEGATIVE_INF, DIVISION_BY_ZERO };
enum converts { SUCCESS, CONVERTING_ERROR };

typedef struct {
  unsigned int bits[4];
} s21_decimal;

//------------------ utils

int get_sign(s21_decimal val);
void set_sign(s21_decimal *val, int sign);
void print_bit(s21_decimal val, int index, char **res);
void print_bit_val(s21_decimal, char **res);
int get_bit(s21_decimal val, int index);
void set_bit(s21_decimal *val, int index, int bit);
int get_exp(s21_decimal val);
void set_exp(s21_decimal *val, int exp);
int shift_left(s21_decimal *val, int shift);
void shift_right(s21_decimal *val, int shift);
int highest_bit(s21_decimal number);
void init_val(s21_decimal *val, char *str_val);
void copy_val(s21_decimal *target, s21_decimal src);
void normalize_vals(s21_decimal *first, s21_decimal *second);
void clear_bits(s21_decimal *val);
int bit_add(s21_decimal val1, s21_decimal val2, s21_decimal *res);
int is_zero_decimal(s21_decimal val1);
void bit_div(s21_decimal number1, s21_decimal number2, s21_decimal *remainder,
             s21_decimal *res);
void bit_subtraction(s21_decimal number_1, s21_decimal number_2,
                     s21_decimal *result);
void exp_decrease(s21_decimal *a);
int s21_mul(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);
int bit_mull(int highest_bit_of_num_1, s21_decimal num_1, s21_decimal num_2,
             s21_decimal tmp, s21_decimal *result, int inf_check);

//---------------------comparison

int s21_is_greater(s21_decimal number_1, s21_decimal number_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);
int is_zero(s21_decimal val1, s21_decimal val2);

int s21_is_less(s21_decimal num1, s21_decimal num2);

//-------------------arithmetic
int s21_add(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);
int s21_sub(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);
int s21_mul(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);
int s21_div(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);

//-------------------converters
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//---------------------another-functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
#endif
