#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"
#include "matrix_actions.h"

matrix* adding(matrix* a, matrix* b)
{
    if(!a||!b)
    {
        return NULL;
    }

    size_t am=matrix_m(a);
    size_t bm=matrix_m(b);
    size_t an=matrix_n(a);
    size_t bn=matrix_n(b);

    if(am!=bm || an!=bn)
    {
        return NULL;
    }

    for(size_t i = 0; i < am; i++)
    {
        for(size_t j = 0; j < an; j++)
        {
            element_t x = in_index(a, i, j);
            element_t y = in_index(b, i, j);
            change_elem(a, i, j, x + y);
        }
    }
    return a;
}


