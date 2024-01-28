#include "../../s21_matrix.h"

void s21_matrix_reset(matrix_t *A) {
  A->matrix = NULL;
  A->columns = 0;
  A->rows = 0;
}
