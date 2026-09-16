#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
int n;
struct Queue {
    int doc_id[MAX_SIZE];
    char name[MAX_SIZE][MAX_SIZE];
    int front;
    int rear;
};

struct Queue q;

void dequeue(struct Queue *qu)
{
    if (qu->front > qu->rear)
    {
        printf("Underflow\n");
        return;
    }
    qu->front++;
    printf("%d\t%s\n", qu->doc_id[qu->front], qu->name[qu->front]);
}
void enqueue(struct Queue *qu, int ele, char *s)
{
    if (qu->rear == n - 1)
    {
        printf("Overflow\n");
        return;
    }
    qu->rear++;
    qu->doc_id[qu->rear] = ele;
    strcpy(qu->name[qu->rear], s);
    printf("Enqueued successfully.\n");
}
int main()
{
    q.front = -1;
    q.rear = -1;
    printf("Enter no. of elements:-\n");
    scanf("%d", &n);
    int c = 1, ele = 0;
    char str[MAX_SIZE];
    while(c)
    {
        printf("Menu:-\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit");
        scanf("%d", &c);
        switch(c)
        {
        case 1:
            printf("Enter document id and task name");
            scanf("%d", &ele);
            scanf("%s", str);
            enqueue(&q, ele, str);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
