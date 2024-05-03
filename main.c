#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"
#include "matrix_actions.h"


int main()
{
    matrix* a;
    matrix* b;

    //entering matrices size(n*n)
    printf("Write a size\n");
    int n;
    scanf("%d", &n);

    a=null_alloc(n, n);

    //entering elements
    printf("Write a\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }

    //eps for exp
    printf("Write eps\n");
    double eps;
    scanf("%lf", &eps);

    //calculate the exponent of matrix a and store the result in b
    b=matrix_exp(a, eps);

    // print b exp
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

    printf("Write a sizes\n");
    int mk;
    scanf("%d%d", &mk, &n);

    //freeing memory allocated for old matrix a
    matrix_free(a);

    //new matrix a
    a=matrix_alloc(mk, n);
    printf("Write a\n");
    for(int i=0; i<mk; i++)
    {
        for(int j=0; j<n; j++)
        {
            double x;
            scanf("%lf", &x);
            change_elem(a, i, j, x);
        }
    }

    //transposing a
    a=self_transpose(a);
    printf("transposed matrix a:\n");
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


    printf("Write a size\n");
    scanf("%d", &n);
    a = matrix_alloc(n, n+1);
    matrix* A = matrix_alloc(n, n);

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

    b = gauss(a);

    //check if the system has solutions
    double X=in_index(b, 0, 0);
    if(X!=X)
    {
        printf("No solutions\n");
    }
    else
    {
        printf("solutions:\n");
        for(int j=0; j<n; j++)
        {
            double x=in_index(b, j, 0);
            printf("%lf ", x);
        }
        printf("\n");
    }

    //calculating matrix c = A * b
    matrix* c=matrix_alloc(n, 1);
    c=matrix_multipl(A, b, c);
    for(int j=0; j<n; j++)
    {
        double x=in_index(c, j, 0);
        printf("%lf ", x);
    }
    matrix_free(A);
    matrix_free(c);
    matrix_free(a);
    matrix_free(b);
    _getch();
    return 0;
}
