#include "../s21_tests.h"

START_TEST(s21_determinant_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;

  double result;
  double check = 1;
  int res_code = s21_determinant(&A, &result);
  ck_assert_int_eq(res_code, 0);
  ck_assert_double_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  double result;
  double check = -2;
  int res_code = s21_determinant(&A, &result);
  ck_assert_int_eq(res_code, 0);
  ck_assert_double_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  double result = 0;
  double check = -3;
  int res_code = s21_determinant(&A, &result);
  ck_assert_int_eq(res_code, 0);
  ck_assert_double_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 3, &A);

  double result;
  int res_code = s21_determinant(&A, &result);
  ck_assert_int_eq(res_code, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 2, &A);

  double result;
  int res_code = s21_determinant(&A, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  double result;

  int res_code = s21_determinant(NULL, &result);
  ck_assert_int_eq(res_code, 1);
}
END_TEST

START_TEST(s21_determinant_test_7) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 3, &A);

  int res_code = s21_determinant(&A, NULL);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_8) {
  matrix_t A = {0, 0, 0};
  double result;

  int res_code = s21_determinant(&A, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_determinant_test_suite(void) {
  Suite *suite = suite_create("determinant_test");
  TCase *test_case = tcase_create("determinant_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_determinant_test_1);
    tcase_add_test(test_case, s21_determinant_test_2);
    tcase_add_test(test_case, s21_determinant_test_3);
    tcase_add_test(test_case, s21_determinant_test_4);
    tcase_add_test(test_case, s21_determinant_test_5);
    tcase_add_test(test_case, s21_determinant_test_6);
    tcase_add_test(test_case, s21_determinant_test_7);
    tcase_add_test(test_case, s21_determinant_test_8);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
