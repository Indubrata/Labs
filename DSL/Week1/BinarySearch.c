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
    int l = 0, u = n - 1, m = 0;
    while(1) {
        m = (l + u)/2;
        if(arr[m] == k) {
            printf("Element found at index %d", m);
            flag = 1;
            break;
        }
        else if (l >= n || u <= 0)
            break;
        else if (arr[m] < k)
            l = m + 1;
        else
            u = m - 1;
    }
    if (flag == 0)
        printf("Element not found");
}
