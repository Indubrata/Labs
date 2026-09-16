#include <stdio.h>
#include <stdlib.h>
void recS_Sort(int *arr, int n, int i)
{
    if (i == n - 1)
        return;
    int min = *(arr + i), k = i;
    for (int j = i + 1;j < n;j++)
        if (*(arr + j) < min)
        {
            min = *(arr + j);
            k = j;
        }
    if (min != *(arr + i))
    {
        int temp = *(arr + k);
        *(arr + k) = *(arr + i);
        *(arr + i) = temp;
    }
    recS_Sort(arr, n, i + 1);
}
int main()
{
    int *arr, n = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    recS_Sort(arr, n, 0);
    printf("Sorted array:-\n");
    for (int i = 0;i < n; i++)
        printf("%d ", *(arr + i));
    return 0;
}
