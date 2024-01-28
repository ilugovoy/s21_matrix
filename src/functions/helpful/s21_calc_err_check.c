#include "../../s21_matrix.h"

int s21_calc_err_check(matrix_t *A, matrix_t *B) {
  int return_value = OK;
  if (A->rows != B->rows || A->columns != B->columns) {
    return_value = CALC_ERR;
  }

  return return_value;
}
