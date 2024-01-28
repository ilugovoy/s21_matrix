#include "../s21_tests.h"

START_TEST(s21_eq_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);

  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &B);

  int res_code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_test_2) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;

  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1;

  int res_code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_test_3) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 2, &A);

  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &B);

  int res_code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res_code, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_test_4) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;

  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 2;

  int res_code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res_code, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_test_5) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);

  int res_code = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(res_code, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_test_6) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);

  int res_code = s21_eq_matrix(NULL, &A);
  ck_assert_int_eq(res_code, 0);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_eq_test_suite(void) {
  Suite *suite = suite_create("eq_test");
  TCase *test_case = tcase_create("eq_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_eq_test_1);
    tcase_add_test(test_case, s21_eq_test_2);
    tcase_add_test(test_case, s21_eq_test_3);
    tcase_add_test(test_case, s21_eq_test_4);
    tcase_add_test(test_case, s21_eq_test_5);
    tcase_add_test(test_case, s21_eq_test_6);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}