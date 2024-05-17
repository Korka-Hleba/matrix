#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrix.h"
#include "matrix_actions.h"
#include "matrix_structure.h"

void matrix_print(struct matrix* a)
{
    if (a == NULL || a->mat == NULL)
    {
        printf("Matrix is NULL or not allocated\n");
        return;
    }

    if (a->m > a->MAX || a->n > a->MAX)
    {
        printf("Matrix dimensions exceed the maximum size\n");
        return;
    }

    for (size_t i = 0; i < a->m; i++)
    {
        for (size_t j = 0; j < a->n; j++)
        {
            printf("%lf ", a->mat[i * a->n + j]);
        }
        printf("\n");
    }
}
