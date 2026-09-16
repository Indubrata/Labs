#include <stdio.h>

int n = 0;
struct Student
{
    int roll;
    float marks;
    char name[50];
}stud[100];

void read(struct Student stud[])
{
    printf("Enter no. of students:-\n");
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        printf("Enter student %d roll no., marks and name:-\n", i + 1);
        scanf("%d", &(stud+i)->roll);
        getchar();
        scanf("%f", &(stud+i)->marks);
        getchar();
        scanf("%s", (stud+i)->name);
    }
}

void display(struct Student stud[])
{
    for (int i = 0;i < n;i++) {
        printf("Student %d details:-\n", i + 1);
        printf("%d\t%f\t%s", (stud+i)->roll, (stud+i)->marks, (stud+i)->name);
        printf("\n");
    }
}

void highest(struct Student stud[])
{
    int max = 0;
    for (int i = 0;i < n; i++)
        if ((stud+i)->marks > (stud+max)->marks)
            max = i;
    printf("Student %d has highest marks:-\n", max + 1);
    printf("%d\t%f\t%s", (stud+max)->roll, (stud+max)->marks, (stud+max)->name);
}

int main()
{
    read(stud);
    display(stud);
    highest(stud);
    return 0;
}
