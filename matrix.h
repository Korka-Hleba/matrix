#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
typedef struct matrix matrix;
typedef double element_t;
struct matrix;

///���������� ����� � �������
size_t matrix_m(matrix* a);

///���������� �������� � �������
size_t matrix_n(matrix* a);

///����� ������� � m �������� � n ���������
matrix* matrix_alloc(size_t M, size_t N);

///����������� �������
matrix* matrix_copy(matrix* a, matrix* b);

///������� ������� � m �������� � n ���������
matrix* null_alloc(size_t M, size_t N);

///��������� ������� � m �������� � n ���������
matrix* e_alloc(size_t M, size_t N);

///��������� �������� � �������� (i,j) � ������� �� �������� x
void change_elem(matrix* a, size_t i, size_t j, element_t x);

///���������� ������� � ������� �� ����� (i,j)
element_t in_index(matrix* a, size_t i, size_t j);

///��������� ������� ������� �� m �����, n ��������
matrix* matrix_resize(matrix* a, size_t m, size_t n);

///����������� ������, ���������� ��� �������
void matrix_free(matrix* a);
#endif // MATRIX_H
