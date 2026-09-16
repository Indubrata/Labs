#include <stdio.h>

int n = 0; 
struct Student
{
    int roll;
    char grade;
    char name[50];
}stud[100];

void read(struct Student stud[])
{
    printf("Enter no. of students:-\n");
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        printf("Enter student %d roll no., grade and name:-\n", i + 1);
        scanf("%d", &stud[i].roll);
        getchar();
        scanf("%c", &stud[i].grade);
        getchar();
        scanf("%s", stud[i].name);
    }
}

void display(struct Student stud[])
{
    for (int i = 0;i < n;i++) {
        printf("Student %d details:-\n", i + 1);
        printf("%d\t%c\t%s", stud[i].roll, stud[i].grade, stud[i].name);
        printf("\n");
    }
}

void sort(struct Student stud[])
{
    for (int i = 0;i < n - 1; i++)
        for (int j = 0;j < n - i - 1; j++)
            if (stud[j].roll > stud[j + 1].roll) {
                struct Student temp = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = temp;
            }
}

int main()
{
    read(stud);
    display(stud);
    sort(stud);
    display(stud);
    return 0;
}
