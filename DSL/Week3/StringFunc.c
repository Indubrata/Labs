#include <stdio.h>
#include <stdlib.h>

int lenStr(char str[])
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}
char* concatStr(char str1[], char str2[])
{
    char *str3;
    str3 = (char*)malloc((lenStr(str1) + lenStr(str2) + 1) * sizeof(char));
    int i = 0;
    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }
    int k = i;
    while(str2[i - k] != '\0') {
        str3[i] = str2[i - k];
        i++;
    }
    str3[i] = '\0';
    return str3;
}
int strCmp(char str1[], char str2[])
{
    int l1 = lenStr(str1), l2 = lenStr(str2);
    if (l1 != l2)
        return l1 - l2;
    int i = 0;
    while (str1[i] != '\0') {
        int diff = (int)str1[i] - (int)str2[i];
        if (diff != 0)
            return diff;
        i++;
    }
    return 0;
}
char* insertSubStr(char str1[], char str2[], int n)
{
    char *str3;
    str3 = (char*)malloc((lenStr(str1) + lenStr(str2) + 1) * sizeof(char));
    int i = 0;
    if (n >= lenStr(str1)) {
        printf("Index exceeds length of 1st string");
        return 0;
    }
    while (i < n) {
        str3[i] = str1[i];
        i++;
    }
    while (str2[i - n] != '\0'){
        str3[i] = str2[i - n];
        i++;
    }
    while (str1[n] != '\0') {
        str3[i] = str1[n];
        n++;
        i++;
    }
    str3[i] = '\0';
    return str3;
}
char* deleteSubStr(char str1[], int start, int end)
{
    char *str3;
    str3 = (char*)malloc((lenStr(str1) - (end - start + 1) + 1) * sizeof(char));
    int i = 0;
    if (start >= lenStr(str1) || end >= lenStr(str1)) {
        printf("Index exceeds length of string");
        return 0;
    }
    while (i < start) {
        str3[i] = str1[i];
        i++;
    }
    while (str1[end + 1] != '\0') {
        str3[i] = str1[end + 1];
        end++;
        i++;
    }
    str3[i] = '\0';
    return str3;
}
int main()
{
    char str1[100], str2[100];
    printf("Enter 2 strings:-\n");
    scanf("%s%s", str1, str2);
    printf("Length of strings are %d and %d\n", lenStr(str1), lenStr(str2));

    int x = strCmp(str1, str2);
    printf("Difference between strings is %d\n", x);

    printf("Concatenated string :-\n");
    int i = 0;
    char* str = concatStr(str1, str2);
    while (str[i] != '\0')
        printf("%c", str[i++]);
    printf("\n");
    i = 0;

    int n = 0;
    printf("Enter index to insert substring:-\n");
    scanf("%d", &n);
    str = insertSubStr(str1, str2, n);
    if (str != NULL) {
        printf("New string after inserting substring:-\n");
        while (str[i] != '\0')
            printf("%c", str[i++]);
    }
    printf("\n");
    i = 0;

    int s = 0, e = 0;
    printf("Enter starting and ending index to delete string:-\n");
    scanf("%d%d", &s, &e);
    str = deleteSubStr(str1, s, e);
    if (str != NULL) {
        printf("New string after deleting substring:-\n");
        while (str[i] != '\0')
            printf("%c", str[i++]);
    }
    return 0;
}
