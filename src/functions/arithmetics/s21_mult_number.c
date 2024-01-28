#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления: несовпадающие размеры матриц,
// нельзя провести вычисления и тп

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_is_bad_matrix(A)) return BAD_MATRIX;

  result->rows = A->rows;
  result->columns = A->columns;
  s21_create_matrix(result->rows, result->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
      // проверка ошибки вычисления
      if (s21_calc_err_check_1(result, i, j) == CALC_ERR) return CALC_ERR;
    }
  }

  return OK;
}
