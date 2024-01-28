#include "../s21_tests.h"

START_TEST(s21_sum_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  matrix_t B = {0, 0, 0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -2.5;
  B.matrix[1][0] = 2.5;
  B.matrix[1][1] = -6;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(2, 2, &check);
  check.matrix[0][0] = 2;
  check.matrix[0][1] = -0.5;
  check.matrix[1][0] = 5.5;
  check.matrix[1][1] = -2;

  matrix_t result;
  int res_code = s21_sum_matrix(&A, &B, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res_code, 0);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_test_2) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  matrix_t result = {0, 0, 0};
  int res_code = s21_sum_matrix(&A, NULL, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_test_3) {
  matrix_t B = {0, 0, 0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  matrix_t result = {0, 0, 0};
  int res_code = s21_sum_matrix(NULL, &B, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_test_4) {
  matrix_t A = {0, 0, 0};

  matrix_t B = {0, 0, 0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -2.5;
  B.matrix[1][0] = 2.5;
  B.matrix[1][1] = -6;

  matrix_t result = {0, 0, 0};
  int res_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_test_5) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);

  matrix_t B = {0, 0, 0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -2.5;
  B.matrix[1][0] = 2.5;
  B.matrix[1][1] = -6;

  matrix_t result = {0, 0, 0};
  int res_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_test_6) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);

  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -INFINITY;
  B.matrix[1][0] = 2.5;
  B.matrix[1][1] = -6;

  matrix_t result = {0, 0, 0};
  int res_code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sum_test_suite(void) {
  Suite *suite = suite_create("sum_test");
  TCase *test_case = tcase_create("sum_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_sum_test_1);
    tcase_add_test(test_case, s21_sum_test_2);
    tcase_add_test(test_case, s21_sum_test_3);
    tcase_add_test(test_case, s21_sum_test_4);
    tcase_add_test(test_case, s21_sum_test_5);
    tcase_add_test(test_case, s21_sum_test_6);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}