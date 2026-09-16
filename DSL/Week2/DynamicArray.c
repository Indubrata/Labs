#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr, n = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    int min = *(arr);
    for(int i = 0; i < n; i++)
        if (*(arr + i) < min)
            min = *(arr + i);
    printf("Min = %d", min);
    return 0;
}
