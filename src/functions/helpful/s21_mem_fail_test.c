#include "../../s21_matrix.h"

int mem_fail_check_rows(matrix_t *result) {
  int return_value = OK;

  if (result->matrix == NULL) {
    s21_matrix_reset(result);
    return_value = MEM_FAIL;
  }
  return return_value;
}

int mem_fail_check_columns(matrix_t *result, int x) {
  int return_value = OK;

  if (result->matrix[x] == NULL) {
    for (int q = 0; q < x; q += 1) {
      free(result->matrix[q]);
    }
    free(result->matrix);
    s21_matrix_reset(result);
    return_value = MEM_FAIL;
  }
  return return_value;
}