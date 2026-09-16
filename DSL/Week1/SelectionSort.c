#include <stdio.h>

int main()
{
    int arr[100], n = 0, k = 0, min = 0, temp = 0, j = 0;
    int flag = 0;
    printf("Enter the no. of elements:-\n");
    scanf("%d", &n);
    printf("Enter array elements:-\n");
    for (int i = 0;i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0;i < n - 1; i++){
        k = i, min = arr[i];
        for (j = i + 1;j < n; j++)
            if (arr[j] < arr[k])
                k = j;
        if (arr[k] != min){
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
    printf("Sorted array:-\n");
    for (int i = 0;i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}


