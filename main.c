#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"
#include "matrix_actions.h"


int main()
{
    matrix* a;
    matrix* b;
    printf("enter a size\n");
    int n;
    scanf("%d", &n);
    a=null_alloc(n, n);
    printf("enter a\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }
    printf("enter eps\n");
    double y;
    scanf("%lf", &y);
    b=matrix_exp(a, y);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double x=in_index(b, i, j);
            printf("%lf ", x);
        }
        printf("\n");
    }
    matrix_free(b);

    printf("enter a sizes\n");
    int mk;
    scanf("%d%d", &mk, &n);
    matrix_free(a);
    a=matrix_alloc(mk, n);
    printf("enter a\n");
    for(int i=0; i<mk; i++)
    {
        for(int j=0; j<n; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }
    a=self_transpose(a);
    printf("transposed a:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<mk; j++)
        {
            double x=in_index(a, i, j);
            printf("%lf ", x);
        }
        printf("\n");
    }
    matrix_free(a);

    printf("enter a size\n");
    scanf("%d", &n);
    a=matrix_alloc(n, n+1);
    matrix* A=matrix_alloc(n, n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
            if(j!=n)
            {
                change_elem(A, i, j, x);
            }
        }
    }

    b=gauss(a);
    double X = in_index(b, 0, 0);
    if(X != X)
    {
        printf("No solutions\n");
    }
    else
    {
        printf("solution:\n");
        for(int j=0; j<n; j++)
        {
            double x=in_index(b, j, 0);
            printf("%lf ", x);
        }
        printf("\n");
    }

    //multiplying matrices
    matrix* c=matrix_alloc(n, 1);
    c=matrix_multipl(A, b, c);
    printf("result of multiplying:\n");
    for(int j=0; j<n; j++)
    {
        double x=in_index(c, j, 0);
        printf("%lf ", x);
    }

    printf("\n");

    int wk, nk, hk;
    matrix* d = matrix_alloc(mk,wk);
    printf("enter a sizes\n");
    scanf("%d%d", &mk, &nk);
    matrix_free(a);
    a=matrix_alloc(mk, n);
    printf("enter a\n");
    for(int i=0; i<mk; i++)
    {
        for(int j=0; j<n; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }


    printf("enter b sizes\n");
    scanf("%d%d", &hk, &wk);
    matrix_free(b);
    b=matrix_alloc(hk, wk);
    printf("enter a\n");
    for(int i=0; i<hk; i++)
    {
        for(int j=0; j<wk; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }

    d = adding(a, b);
    for(int i=0; i<wk; i++)
    {
        for(int j=0; j<mk; j++)
        {
            double x=in_index(d, i, j);
            printf("%lf ", x);
        }
        printf("\n");
    }


    matrix_free(A);
    matrix_free(c);
    matrix_free(a);
    matrix_free(b);
    matrix_free(d);
    _getch();
    return 0;
}
