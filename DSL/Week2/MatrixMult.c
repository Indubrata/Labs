#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **mat1, **mat2, **mat3, r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    printf("Enter number of rows and columns for 1st matrix: ");
    scanf("%d%d", &r1, &c1);
    mat1 = (int**)malloc(r1*sizeof(int*));
    for(int i = 0; i < r1; i++)
        *(mat1 + i) = (int*)malloc(c1*sizeof(int));

    printf("Enter number of rows and columns for 2nd matrix: ");
    scanf("%d%d", &r2, &c2);
    mat2 = (int**)malloc(r2*sizeof(int*));
    for(int i = 0; i < r2; i++)
        *(mat2 + i) = (int*)malloc(c2*sizeof(int));

    if (c1 != r2)
    {
        printf("Invalid matrix sizes");
        return 0;
    }

    mat3 = (int**)calloc(r1, sizeof(int*));
    for(int i = 0; i < r1; i++)
        *(mat3 + i) = (int*)calloc(c2, sizeof(int));

    printf("Enter %d elements for 1st matrix:\n", r1 * c1);
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", *(mat1 + i) + j);

    printf("Enter %d elements for 2nd matrix:\n", r2 * c2);
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", *(mat2 + i) + j);

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                *(*(mat3 + i) + j) += *(*(mat1 + i) + k) * *(*(mat2 + k) + j);

    printf("Multiplied matrix:-\n");

    for (int i = 0;i < r1; i++)
    {
        for (int j = 0;j < c2; j++)
            printf("%d ", *(*(mat3 + i) + j));
        printf("\n");
    }

    return 0;
}
