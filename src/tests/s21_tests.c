#include "s21_tests.h"

int main(void) {
  size_t tests_failed = 0;

  Suite *create_test_suite = s21_create_test_suite();
  Suite *remove_test_suite = s21_remove_test_suite();
  Suite *eq_test_suite = s21_eq_test_suite();
  Suite *sum_test_suite = s21_sum_test_suite();
  Suite *sub_test_suite = s21_sub_test_suite();
  Suite *mult_number_test_suite = s21_mult_number_test_suite();
  Suite *mult_matrix_test_suite = s21_mult_matrix_test_suite();
  Suite *calc_test_suite = s21_calc_test_suite();
  Suite *determinant_test_suite = s21_determinant_test_suite();
  Suite *inverse_test_suite = s21_inverse_test_suite();
  Suite *transpose_test_suite = s21_transpose_test_suite();

  SRunner *sr;

  sr = srunner_create(create_test_suite);

  srunner_add_suite(sr, remove_test_suite);
  srunner_add_suite(sr, eq_test_suite);
  srunner_add_suite(sr, sum_test_suite);
  srunner_add_suite(sr, sub_test_suite);
  srunner_add_suite(sr, mult_number_test_suite);
  srunner_add_suite(sr, mult_matrix_test_suite);
  srunner_add_suite(sr, calc_test_suite);
  srunner_add_suite(sr, determinant_test_suite);
  srunner_add_suite(sr, inverse_test_suite);
  srunner_add_suite(sr, transpose_test_suite);

  srunner_run_all(sr, CK_VERBOSE);
  tests_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
