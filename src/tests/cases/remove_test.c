#include "../s21_tests.h"

START_TEST(s21_remove_test_1) {
  matrix_t result;
  s21_create_matrix(1, 1, &result);
  s21_remove_matrix(&result);
  ck_assert_ptr_null(result.matrix);
}
END_TEST

START_TEST(s21_remove_test_2) {
  matrix_t result = {0, 0, 0};
  s21_remove_matrix(&result);
  ck_assert_ptr_null(result.matrix);
}
END_TEST

START_TEST(s21_remove_test_3) { s21_remove_matrix(NULL); }
END_TEST

Suite *s21_remove_test_suite(void) {
  Suite *suite = suite_create("remove_test");
  TCase *test_case = tcase_create("remove_test");

  if (suite != NULL && test_case != NULL) {
    tcase_add_test(test_case, s21_remove_test_1);
    tcase_add_test(test_case, s21_remove_test_2);
    tcase_add_test(test_case, s21_remove_test_3);
    suite_add_tcase(suite, test_case);
  }

  return suite;
}
