#include "../../s21_matrix.h"

// OK = 0				успех
// BAD_MATRIX = 1		некорректная матрица
// CALC_ERR = 2			ошибка вычисления

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_bad_matrix(A) == BAD_MATRIX) return BAD_MATRIX;
  if (A->columns != A->rows) return CALC_ERR;

  if (A->rows == 1)
    *result = A->matrix[0][0];  // если матрица из одного элемента, то
                                // детерминант равен этому элементу
  else
    *result = s21_calc_determinant(A, A->rows);

  return OK;
}

double s21_calc_determinant(matrix_t *A, int size) {
  if (size == 1)
    return A->matrix[0][0];  // если размер матрицы равен 1, возвращаем элемент
                             // матрицы

  matrix_t aux = {0};  // вспомогательная матрица
  double res = 0;
  s21_create_matrix(size, size, &aux);

  // вычисляем детерминант методом разложения по первой строке
  for (int sign = 1, x = 0; x < size; x += 1, sign *= (-1)) {
    s21_calc_minor(
        A->matrix, aux.matrix, 0, x,
        size);  // рассчитываем минор матрицы A и сохраняем его в матрицу aux
    res +=
        sign * A->matrix[0][x] *
        s21_calc_determinant(
            &aux, size - 1);  // добавляем в результат элемент матрицы A, знак и
                              // рекурсивно рассчитанный определитель минора
  }

  s21_remove_matrix(&aux);
  return res;
}

void s21_calc_minor(double **A, double **aux, int skip_row, int skip_col,
                    int size) {
  for (int row = 0, x = 0; row < size; row += 1) {
    for (int col = 0, y = 0; col < size; col += 1) {
      if (row != skip_row && col != skip_col) {
        aux[x][y++] = A[row][col];  // копируем элементы матрицы A в aux,
                                    // пропуская указанную строку и столбец
        if (y == size - 1) {
          y = 0;
          x++;
        }
      }
    }
  }
}

/*
Определитель (детерминант) - это число, которое ставят в соответствие каждой
квадратной матрице и вычисляют из элементов по специальным формулам Определитель
может быть вычислен только для квадратной матрицы Определитель матрицы равен
сумме произведений элементов строки (столбца) на соответствующие алгебраические
дополнения

Минором называется детерминант (n-1)-го порядка, полученный вычёркиванием из
матрицы i-й строки и j-го столбца
*/
