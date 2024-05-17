#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"
#include "matrix_actions.h"
#include "matrix_structure.h"

void element_swap(element_t* a, element_t* b)
{
    element_t c=*a;
    *a=*b;
    *b=c;
}

matrix* transpose(matrix* a, matrix* b)
{
    size_t ma = matrix_m(a);
    size_t na = matrix_n(a);

    if(!b)
    {
        b = matrix_alloc(na, ma);
        if (!b)
        {
            return NULL;
        }

    }
    else
    {
        if (b->m != na || b->n != ma)
        {
            b = matrix_resize(b, na, ma);
            if (!b)
            {
                return NULL;
            }
        }
    }

    for(size_t i = 0; i < ma; i++)
    {
        for(size_t j = 0; j < na; j++)
        {
            element_t x = in_index(a, i, j);
            change_elem(b, j, i, x);
        }
    }
    return b;
}

matrix* self_transpose(matrix* a)
{
    if(!a)
    {
        return NULL;
    }
    size_t ma = matrix_m(a);
    size_t na = matrix_n(a);
    matrix* b = null_alloc(na, ma);
    b=transpose(a, b);
    if(!b)
    {
        return NULL;
    }
    matrix* c = a;
    a = b;
    matrix_free(c);
    return a;
}
