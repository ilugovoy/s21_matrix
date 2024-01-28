#include "../../s21_matrix.h"

// SUCCESS 1
// FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = s21_is_bad_eq_matrix(A, B);
  if (return_value != 0) return FAILURE;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        return FAILURE;
      }
    }
  }

  return SUCCESS;
}
