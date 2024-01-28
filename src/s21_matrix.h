#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 0.0000001  // Сравнение с точностью 7 знаков после запятой

// Возвращаемые значения для сравнения матриц
#define SUCCESS 1
#define FAILURE 0

// Прочие операции возвращают
enum { OK = 0, BAD_MATRIX = 1, CALC_ERR = 2, MEM_FAIL = 3 };

// Структура матрицы
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание и удаление матрицы
void s21_remove_matrix(matrix_t *A);  // очистка матрицы
int s21_create_matrix(int rows, int columns,
                      matrix_t *result);  // создание матрицы

// Арифметические операции с матрицами и сравнение
int s21_eq_matrix(matrix_t *A,
                  matrix_t *B);  // сравнение матриц до седьмого знака после
                                 // запятой включительно
int s21_sum_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // сложение матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // вычитание матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result);  // умножение двух матриц
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  // умножение матрицы на число

// Расчет дополнительных параметров и характеристик матриц
int s21_determinant(matrix_t *A, double *result);  // определитель матрицы
int s21_transpose(matrix_t *A, matrix_t *result);  // транспонирование матрицы
int s21_inverse_matrix(matrix_t *A,
                       matrix_t *result);  // инвертирование матрицы
int s21_calc_complements(
    matrix_t *A,
    matrix_t *result);  // минор матрицы и матрица алгебраических дополнений

// Вспомогательные функции
void s21_matrix_reset(matrix_t *A);  // сброс полей матрицы
int s21_is_bad_matrix(matrix_t *A);  // проверка на возврат единицы
int s21_calc_err_check(matrix_t *A, matrix_t *B);  // проверка ошибки вычисления
int s21_is_bad_eq_matrix(
    matrix_t *A, matrix_t *B);  // проверка двух матриц на возврат единицы
int s21_calc_err_check_1(matrix_t *result, int i, int j);  // проверка nan и inf
int s21_sum_or_sub(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // для перевода в сложение или вычитание

double s21_calc_determinant(
    matrix_t *A, int size);  // рекурсивно вычисляет детерминант матрицы
// Если размер матрицы равен 1, она возвращает элемент матрицы
// eсли размер матрицы > 1 используется метод разложения определителя по первой
// строке где для каждого элемента первой строки рекурсивно вычисляется
// детерминант соответствующего минора

void s21_calc_minor(double **A, double **aux, int skip_row, int skip_col,
                    int size);  // создает минор матрицы
// Удаляет указанную строку и столбец исходной матрицы
// сохраняет результат в новую матрицу aux

// Тесты ошибок выделения памяти в функции s21_create_matrix
int mem_fail_check_columns(matrix_t *result, int x);
int mem_fail_check_rows(matrix_t *result);

#endif
