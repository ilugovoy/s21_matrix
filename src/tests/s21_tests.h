#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include <check.h>

#include "../s21_matrix.h"

Suite *s21_create_test_suite(void);
Suite *s21_remove_test_suite(void);
Suite *s21_eq_test_suite(void);
Suite *s21_sum_test_suite(void);
Suite *s21_sub_test_suite(void);
Suite *s21_mult_number_test_suite(void);
Suite *s21_mult_matrix_test_suite(void);
Suite *s21_calc_test_suite(void);
Suite *s21_determinant_test_suite(void);
Suite *s21_inverse_test_suite(void);
Suite *s21_transpose_test_suite(void);

#endif
