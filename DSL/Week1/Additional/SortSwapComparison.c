#include <stdio.h>

int main()
{
    int arr[100], n = 0, b = 0, in = 0, s = 0, temp = 0, j = 0, k = 0, min = 0;
    printf("Enter the no. of elements:-\n");
    scanf("%d", &n);
    for (int i = 0;i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0;i < n - 1; i++)
        for (int j = 0;j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                b++;
            }

    printf("Bubble Sorted array:-\n");
    for (int i = 0;i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (int i = 1;i < n; i++){
        temp = arr[i];
        for (j = i - 1;j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
        in++;
    }
    printf("Insertion Sorted array:-\n");
    for (int i = 0;i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (int i = 0;i < n - 1; i++){
        k = i, min = arr[i];
        for (j = i + 1;j < n; j++)
            if (arr[j] < arr[k])
                k = j;
        if (arr[k] != min){
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            s++;
        }
    }
    printf("Selection Sorted array:-\n");
    for (int i = 0;i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Swaps in Bubble Sort : %d\n", b);
    printf("Swaps in Selection Sort : %d\n", s);
    printf("Swaps in Insertion Sort : %d\n", in);
    return 0;
}
