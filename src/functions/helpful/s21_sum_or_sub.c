#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления: несовпадающие размеры матриц,
// нельзя провести вычисления и тп

int s21_sum_or_sub(matrix_t *A, matrix_t *B, matrix_t *result) {
  if ((s21_is_bad_matrix(A) || s21_is_bad_matrix(B))) return BAD_MATRIX;
  if (s21_calc_err_check(A, B) == CALC_ERR) return CALC_ERR;

  result->rows = A->rows;
  result->columns = A->columns;
  result->matrix = calloc(result->rows, sizeof(double *));

  for (int i = 0; i < result->rows; i++) {
    result->matrix[i] = calloc(result->columns, sizeof(double));
  }

  return OK;
}
