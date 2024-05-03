#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
typedef struct matrix matrix;
typedef double element_t;
struct matrix;

///количество строк в матрице
size_t matrix_m(matrix* a);

///количество столбцов в матрице
size_t matrix_n(matrix* a);

///новая матрица с m строками и n столбцами
matrix* matrix_alloc(size_t M, size_t N);

///копирование матрицы
matrix* matrix_copy(matrix* a, matrix* b);

///нулевая матрица с m строками и n столбцами
matrix* null_alloc(size_t M, size_t N);

///единичная матрица с m строками и n столбцами
matrix* e_alloc(size_t M, size_t N);

///изменение элемента с индексом (i,j) в матрице на значение x
void change_elem(matrix* a, size_t i, size_t j, element_t x);

///возвращает элемент в матрице на месте (i,j)
element_t in_index(matrix* a, size_t i, size_t j);

///изменение размера матрицы на m строк, n столбцов
matrix* matrix_resize(matrix* a, size_t m, size_t n);

///освобождает память, выделенную под матрицу
void matrix_free(matrix* a);
#endif // MATRIX_H
