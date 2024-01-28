#include "../../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return BAD_MATRIX;
  }

  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (mem_fail_check_rows(result) == MEM_FAIL) return MEM_FAIL;

  for (int x = 0; x < rows; x += 1) {
    result->matrix[x] = (double *)calloc(columns, sizeof(double));
    if (mem_fail_check_columns(result, x) == MEM_FAIL) return MEM_FAIL;
  }

  return OK;
}
