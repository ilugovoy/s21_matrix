#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_is_bad_matrix(A)) return BAD_MATRIX;
  if (A->columns != A->rows) return CALC_ERR;

  double determinant = 0;  // вычисление определителя матрицы A
  int check_calc_err = s21_determinant(A, &determinant);
  if (fabs(determinant) < 1e-6 || check_calc_err) return CALC_ERR;

  matrix_t aux = {0}, aux_transpose = {0};
  s21_calc_complements(A, &aux);  // вычисление комплементарной матрицы для
                                  // матрицы A и сохранение ее в aux
  s21_transpose(
      &aux,
      &aux_transpose);  // вычисление транспонированной комплементарной матрицы
  s21_create_matrix(A->rows, A->rows, result);

  // вычисление значений обратной матрицы через отношение элементов
  // транспонированной комплементарной матрицы к определителю
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->rows; y += 1) {
      result->matrix[x][y] = aux_transpose.matrix[x][y] / determinant;
    }
  }

  s21_remove_matrix(&aux_transpose);
  s21_remove_matrix(&aux);

  return OK;
}
