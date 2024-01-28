#include "../s21_tests.h"

START_TEST(s21_calc_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 3, &A);
  matrix_t result = {0, 0, 0};

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(3, 3, &check);
  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  int res_code = s21_calc_complements(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res_code, 0);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_calc_test_2) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 3, &A);
  matrix_t result = {0, 0, 0};

  int res_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_test_3) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 2, &A);
  matrix_t result = {0, 0, 0};

  int res_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_test_4) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 2, &A);

  int res_code = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_test_5) {
  matrix_t result = {0, 0, 0};

  int res_code = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_test_6) {
  matrix_t A = {0, 0, 0};
  matrix_t result;

  int res_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res_code, 1);
}
END_TEST

START_TEST(s21_calc_test_7) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(1, 1, &A);
  matrix_t result = {0, 0, 0};

  int res_code = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res_code, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_calc_test_suite(void) {
  Suite *suite = suite_create("calc_test");
  TCase *test_case = tcase_create("calc_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_calc_test_1);
    tcase_add_test(test_case, s21_calc_test_2);
    tcase_add_test(test_case, s21_calc_test_3);
    tcase_add_test(test_case, s21_calc_test_4);
    tcase_add_test(test_case, s21_calc_test_5);
    tcase_add_test(test_case, s21_calc_test_6);
    tcase_add_test(test_case, s21_calc_test_7);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
