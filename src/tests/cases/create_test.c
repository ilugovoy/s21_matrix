#include "../s21_tests.h"

START_TEST(s21_create_test_1) {
  matrix_t result;
  int res_code = s21_create_matrix(1, 1, &result);
  int res = (result.rows == 1 && result.columns == 1 &&
             (fabs(result.matrix[0][0]) < 1e-7));
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(res_code, 0);

  for (int i = 0; i < result.rows; i++) {
    free(result.matrix[i]);
  }
  free(result.matrix);
  result.matrix = NULL;
}
END_TEST

START_TEST(s21_create_test_2) {
  matrix_t result;
  int res_code = s21_create_matrix(1, 1, &result);
  int res = (result.rows == 1 && result.columns == 1 &&
             (fabs(result.matrix[0][0]) < 1e-7));
  ck_assert_int_eq(res, 1);
  ck_assert_int_eq(res_code, 0);

  for (int i = 0; i < result.rows; i++) {
    free(result.matrix[i]);
  }
  free(result.matrix);
  result.matrix = NULL;
}
END_TEST

START_TEST(s21_create_test_3) {
  matrix_t result;
  int res_code = s21_create_matrix(0, 1, &result);
  ck_assert_int_eq(res_code, 1);
}
END_TEST

START_TEST(s21_create_test_4) {
  matrix_t result;
  int res_code = s21_create_matrix(1, 0, &result);
  ck_assert_int_eq(res_code, 1);
}
END_TEST

Suite *s21_create_test_suite(void) {
  Suite *suite = suite_create("create_test");
  TCase *test_case = tcase_create("create_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_create_test_1);
    tcase_add_test(test_case, s21_create_test_2);
    tcase_add_test(test_case, s21_create_test_3);
    tcase_add_test(test_case, s21_create_test_4);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
