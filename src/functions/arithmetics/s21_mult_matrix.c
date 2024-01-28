#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if ((s21_is_bad_matrix(A) || s21_is_bad_matrix(B))) return BAD_MATRIX;
  if (A->columns != B->rows)
    return CALC_ERR;  // число столбцов A не равно числу строк B

  result->rows = A->rows;
  result->columns = B->columns;
  s21_create_matrix(result->rows, result->columns,
                    result);  // создаём матрицу-результат

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        // проверка ошибки вычисления
        if (s21_calc_err_check_1(result, i, j) == CALC_ERR) return CALC_ERR;
      }
    }
  }

  return OK;
}
