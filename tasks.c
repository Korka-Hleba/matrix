#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"
#include "matrix_actions.h"

matrix* gauss (matrix* a)
{
    size_t ma = matrix_m(a);
    size_t na = matrix_n(a);
    matrix* b = matrix_alloc(ma, 1);
    for(size_t i=0; i<ma; i++)
    {
        if(in_index(a, i, i)==0.0)
        {
            for(size_t j=i; j<ma; j++)
            {
                if(in_index(a, j, i)!=0.0)
                {
                    swap_strings(a, i, j);
                    break;
                }
            }
        }
        if(in_index(a, i, i)==0.0)
        {
            change_elem(b, 0, 0, 0.0/0.0);
            return b;
        }
        element_t k=in_index(a, i, i);
        for(size_t j=i+1; j<ma; j++)
        {
            element_t l=in_index(a, j, i);
            minus_str(a, j, i, l/k);
        }
    }
    if(in_index(a, ma-1, ma-1)==0.0)
    {

        change_elem(b, 0, 0, 0.0/0.0);
        return b;
    }
    for(size_t j=ma; j>0; j--)
    {
        size_t i=j-1;
        element_t x=in_index(a, i, na-1);
        for(size_t j=ma-1; j>i; j--)
        {
            x-=in_index(b, j, 0)*in_index(a, i, j);
        }
        element_t u=in_index(a, i, i);
        change_elem(b, i, 0, x/u);
    }
    return b;
}

matrix* matrix_exp(matrix* a, element_t eps)
{
    if(eps!=eps)
    {
        return NULL;
    }
    size_t ma = matrix_m(a);
    size_t na = matrix_n(a);
    if(ma!= na)
    {
        return NULL;
    }
    element_t A=1.0/0.0;
    if(A == eps)
    {
        return NULL;
    }
    matrix* deg = e_alloc(ma, na);
    matrix* cur = null_alloc(ma, na);
    double N=1;
    while(matrix_norm(deg)>= eps)
    {
        matrix* x = null_alloc(ma, na);
        cur = adding(cur, deg);
        x=matrix_multipl(deg, a, x);
        x=number_multipl(x, 1/N);
        N++;
        matrix* y=deg;
        deg=x;
        matrix_free(y);
    }
    cur=adding(cur, deg);
    matrix_free(deg);
    return cur;
}

element_t matrix_norm(matrix* a)
{
    size_t ma = matrix_m(a);
    size_t na = matrix_n(a);
    element_t norm = 0;
    for(size_t i=0; i<na; i++)
    {
        element_t cur_norm = 0;
        for(size_t j = 0; j<ma; j++)
        {
            cur_norm+=fabs(in_index(a, j, i));
        }
        if(cur_norm>norm)
        {
            norm=cur_norm;
        }
    }
    return norm;
}
