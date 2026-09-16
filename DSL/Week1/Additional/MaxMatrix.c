#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **mat1, **mat2, **mat3, r = 0, c = 0;

    printf("Enter number of rows and columns for 1st matrix: ");
    scanf("%d%d", &r, &c);
    mat1 = (int**)malloc(r*sizeof(int*));
    for(int i = 0; i < r; i++)
        *(mat1 + i) = (int*)malloc(c*sizeof(int));

    mat2 = (int**)malloc(r*sizeof(int*));
    for(int i = 0; i < r; i++)
        *(mat2 + i) = (int*)malloc(c*sizeof(int));

    mat3 = (int**)calloc(r, sizeof(int*));
    for(int i = 0; i < r; i++)
        *(mat3 + i) = (int*)calloc(c, sizeof(int));

    printf("Enter %d elements for 1st matrix:\n", r * c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", *(mat1 + i) + j);

    printf("Enter %d elements for 2nd matrix:\n", r * c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", *(mat2 + i) + j);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            *(*(mat3 + i) + j) = (*(*(mat1 + i) + j) > *(*(mat2 + i) + j)) ? *(*(mat1 + i) + j) : *(*(mat2 + i) + j);

    printf("Maximum matrix:-\n");
    for (int i = 0;i < r; i++)
    {
        for (int j = 0;j < c; j++)
            printf("%d ", *(*(mat3 + i) + j));
        printf("\n");
    }

    return 0;
}
