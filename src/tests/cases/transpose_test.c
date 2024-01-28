#include "../s21_tests.h"

START_TEST(s21_transpose_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[1][1] = 4;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(2, 2, &check);
  check.matrix[0][0] = 1;
  check.matrix[1][0] = 3;
  check.matrix[0][1] = 2;
  check.matrix[1][1] = 4;

  matrix_t result = {0, 0, 0};

  int res_code = s21_transpose(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res_code, 0);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(1, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(3, 1, &check);
  check.matrix[0][0] = 1;
  check.matrix[1][0] = 2;
  check.matrix[2][0] = 3;

  matrix_t result = {0, 0, 0};

  int res_code = s21_transpose(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res_code, 0);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t A = {0, 0, 0};
  matrix_t result = {0, 0, 0};

  int res_code = s21_transpose(&A, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t result = {0, 0, 0};

  int res_code = s21_transpose(NULL, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_test_suite(void) {
  Suite *suite = suite_create("transpose_test");
  TCase *test_case = tcase_create("transpose_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_transpose_test_1);
    tcase_add_test(test_case, s21_transpose_test_2);
    tcase_add_test(test_case, s21_transpose_test_3);
    tcase_add_test(test_case, s21_transpose_test_4);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}