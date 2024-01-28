#include "../s21_tests.h"

START_TEST(s21_mult_number_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 3.3;
  A.matrix[1][1] = -4.3;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(2, 2, &check);
  check.matrix[0][0] = 3;
  check.matrix[0][1] = -6;
  check.matrix[1][0] = 9.9;
  check.matrix[1][1] = -12.9;

  matrix_t result = {0, 0, 0};
  double multiplier = 3;

  int res_code = s21_mult_number(&A, multiplier, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res_code, 0);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t result = {0, 0, 0};
  double multiplier = 3;

  int res_code = s21_mult_number(NULL, multiplier, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t A = {0, 0, 0};

  double multiplier = 3;

  int res_code = s21_mult_number(&A, multiplier, NULL);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  double multiplier = -INFINITY;

  matrix_t result;
  int res_code = s21_mult_number(&A, multiplier, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_mult_number_test_suite(void) {
  Suite *suite = suite_create("mult_number_test");
  TCase *test_case = tcase_create("mult_number_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_mult_number_test_1);
    tcase_add_test(test_case, s21_mult_number_test_2);
    tcase_add_test(test_case, s21_mult_number_test_3);
    tcase_add_test(test_case, s21_mult_number_test_4);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
