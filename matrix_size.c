#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"

struct matrix
{
    size_t MAX;
    size_t m;
    size_t n;
    element_t* mat;
};

size_t matrix_m(matrix* matrix)
{
    return matrix->m;
}

size_t matrix_n(matrix* matrix)
{
    return matrix->n;
}

matrix* matrix_resize(matrix* matr, size_t given_m, size_t given_n)
{
    if(given_m * given_n > matr -> MAX)
    {
        size_t x=given_m * given_n;
        if(x<2*matr -> MAX)
        {
            x=2*matr->MAX;
        }
        matr -> mat=realloc(matr->mat, x*sizeof(element_t));
        matr -> MAX=x;
    }
    matr -> m = given_m;
    matr -> n = given_n;
    return matr;
}
