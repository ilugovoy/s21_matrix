#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления: несовпадающие размеры матриц,
// нельзя провести вычисления и тп

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = s21_is_bad_matrix(A);

  if (return_value == 0) {
    return_value = s21_create_matrix(A->columns, A->rows, result);
    if (return_value == OK) {
      for (int x = 0; x < A->rows; x++) {
        for (int y = 0; y < A->columns; y++) {
          result->matrix[y][x] = A->matrix[x][y];
        }
      }
    }
  }

  return return_value;
}
