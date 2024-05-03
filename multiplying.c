#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"
#include "matrix_actions.h"

matrix* matrix_multipl(matrix* a, matrix* b, matrix* c)
{
    size_t ma = matrix_m(a);
    size_t mb = matrix_m(b);
    size_t na = matrix_n(a);
    size_t nb  =matrix_n(b);
    if(na!=mb)
    {
        return NULL;
    }
    if(!c)
    {
        c = matrix_alloc(ma, nb);
    }
    else
    {
        c = matrix_resize(c, ma, nb);
    }
    if(!c)
    {
        return NULL;
    }
    for(size_t i=0; i<ma; i++)
    {
        for(size_t j=0; j<nb; j++)
        {
            change_elem(c, i, j,0);
            for(size_t k=0; k<na; k++)
            {
                element_t xc=in_index(c, i, j);
                element_t xa=in_index(a, i, k);
                element_t xb=in_index(b, k, j);
                change_elem(c, i, j, xa*xb+xc);
            }
        }
    }
    return c;
}

matrix* number_multipl(matrix* a, element_t b)
{
    if(!a)
    {
        return NULL;
    }
    size_t ma = matrix_m(a);
    size_t na = matrix_n(a);
    for(size_t i=0; i<ma; i++)
    {
        for(size_t j=0; j<na; j++)
        {
            element_t x=in_index(a, i, j);
            change_elem(a, i, j, x*b);
        }
    }
    return a;
}
