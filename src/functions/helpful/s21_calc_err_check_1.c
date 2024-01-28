#include "../../s21_matrix.h"

int s21_calc_err_check_1(matrix_t *result, int i, int j) {
  int return_value = OK;

  if (isnan(result->matrix[i][j]) || isinf(result->matrix[i][j])) {
    return_value = CALC_ERR;
  }

  return return_value;
}
