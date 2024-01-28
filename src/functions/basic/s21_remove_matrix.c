#include "../../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int x = 0; x < A->rows; x += 1) {
      free(A->matrix[x]);
    }
    free(A->matrix);
    s21_matrix_reset(A);
  }
}
