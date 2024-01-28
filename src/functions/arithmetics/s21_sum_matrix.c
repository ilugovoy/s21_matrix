#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления: несовпадающие размеры матриц,
// нельзя провести вычисления и тп

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = s21_sum_or_sub(A, B, result);
  if (return_value != OK) return return_value;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      // проверка ошибки вычисления
      if (s21_calc_err_check_1(result, i, j) == CALC_ERR) return CALC_ERR;
    }
  }

  return OK;
}
