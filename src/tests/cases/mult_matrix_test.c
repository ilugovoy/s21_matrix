#include "../s21_tests.h"

START_TEST(s21_mult_matrix_test_1) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  matrix_t B = {0, 0, 0};
  s21_create_matrix(2, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(3, 3, &check);
  check.matrix[0][0] = 9;
  check.matrix[0][1] = 11;
  check.matrix[0][2] = 17;
  check.matrix[1][0] = 12;
  check.matrix[1][1] = 13;
  check.matrix[1][2] = 22;
  check.matrix[2][0] = 15;
  check.matrix[2][1] = 15;
  check.matrix[2][2] = 27;

  matrix_t result = {0, 0, 0};

  int res_code = s21_mult_matrix(&A, &B, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res_code, 0);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t B = {0, 0, 0};
  s21_create_matrix(2, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  matrix_t result = {0, 0, 0};

  int res_code = s21_mult_matrix(NULL, &B, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(2, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  matrix_t result = {0, 0, 0};

  int res_code = s21_mult_matrix(&A, NULL, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A = {0, 0, 0};
  s21_create_matrix(3, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;
  B.matrix[2][0] = 2;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;

  matrix_t result;

  int res_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t A = {0, 0, 0};

  matrix_t B = {0, 0, 0};
  s21_create_matrix(3, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;
  B.matrix[2][0] = 2;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;
  matrix_t result;

  int res_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res_code, 1);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_test_6) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  matrix_t B;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = -INFINITY;
  B.matrix[0][1] = 1.0;
  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 0.0;

  matrix_t result;
  int res_code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res_code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_mult_matrix_test_suite(void) {
  Suite *suite = suite_create("mult_matrix_test");
  TCase *test_case = tcase_create("mult_matrix_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_mult_matrix_test_1);
    tcase_add_test(test_case, s21_mult_matrix_test_2);
    tcase_add_test(test_case, s21_mult_matrix_test_3);
    tcase_add_test(test_case, s21_mult_matrix_test_4);
    tcase_add_test(test_case, s21_mult_matrix_test_5);
    tcase_add_test(test_case, s21_mult_matrix_test_6);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
