#include "../s21_tests.h"

START_TEST(s21_inverse_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(3, 3, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;

  matrix_t result = {0, 0, 0};

  int res_code = s21_inverse_matrix(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res_code, 0);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_inverse_test_2) {
  matrix_t result = {0, 0, 0};

  int res_code = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_test_3) {
  matrix_t A = {0, 0, 0};
  matrix_t result;

  int res_code = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_inverse_test_suite(void) {
  Suite *suite = suite_create("inverse_test");
  TCase *test_case = tcase_create("inverse_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_inverse_test_1);
    tcase_add_test(test_case, s21_inverse_test_2);
    tcase_add_test(test_case, s21_inverse_test_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
