#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_is_bad_matrix(A)) return BAD_MATRIX;
  if (A->columns != A->rows) return CALC_ERR;

  s21_create_matrix(A->columns, A->rows, result);

  if (A->rows != 1) {  // если количество строк в матрице A не равно 1,
                       // выполняем расчет комплементарной матрицы
    matrix_t aux = {0};
    s21_create_matrix(A->rows, A->rows, &aux);
    for (int sign = 0, x = 0; x < A->rows; x += 1) {
      for (int y = 0; y < A->columns; y += 1) {
        s21_calc_minor(
            A->matrix, aux.matrix, x, y,
            A->rows);  // вычисляем минор для текущего элемента матрицы A
        sign = ((x + y) % 2 == 0)
                   ? 1
                   : (-1);  // вычисляем знак элемента комплементарной матрицы
        result->matrix[x][y] =
            sign *
            s21_calc_determinant(
                &aux, A->rows - 1);  // вычисляем значение комплементарной
                                     // матрицы для текущего элемента
      }
    }
    s21_remove_matrix(&aux);
  } else
    result->matrix[0][0] =
        1;  // Если количество строк в матрице A равно 1, присваивается значение
            // 1 элементу комплементарной матрицы

  return OK;
}
