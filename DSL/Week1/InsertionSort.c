#include <stdio.h>

int main()
{
    int arr[100], n = 0, temp = 0, j = 0;
    int flag = 0;
    printf("Enter the no. of elements:-\n");
    scanf("%d", &n);
    printf("Enter array elements:-\n");
    for (int i = 0;i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1;i < n; i++){
        temp = arr[i];
        for (j = i - 1;j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
    printf("Sorted array:-\n");
    for (int i = 0;i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

