#include <stdio.h>

int main()
{
    int arr[100], n = 0, k = 0;
    int flag = 0;
    printf("Enter the no. of elements:-\n");
    scanf("%d", &n);
    printf("Enter array elements:-\n");
    for (int i = 0;i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the element to be searched:-\n");
    scanf("%d", &k);
    for (int i = 0;i < n; i++)
        if (arr[i] == k){
            printf("Element found at index %d", i);
            flag = 1;
            break;
        }
    if (flag == 0)
        printf("Element not found");
}
