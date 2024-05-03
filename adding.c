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

    size_t ma=matrix_m(a);
    size_t mb=matrix_m(b);
    size_t na=matrix_n(a);
    size_t nb=matrix_n(b);

    if(ma!=mb || na!=nb)
    {
        return NULL;
    }

    for(size_t i=0; i<ma; i++)
    {
        for(size_t j=0; j<na; j++)
        {
            element_t x=in_index(a, i, j);
            element_t y=in_index(b, i, j);
            change_elem(a, i, j, x+y);
        }
    }
    return a;
}


