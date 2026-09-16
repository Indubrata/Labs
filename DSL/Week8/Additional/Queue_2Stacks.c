#include <stdio.h>
#define MAX_SIZE 100
int n;
struct Stack {
    int items[MAX_SIZE];
    int top;
};

struct Stack s1, s2;

int pop(struct Stack *s)
{
    if (s->top == -1)
        return -1;
    return s->items[s->top--];
}
void push(struct Stack *s, int ele)
{
    if (s->top == n - 1)
    {
        printf("Overflow");
        return;
    }
    s->items[++s->top] = ele;
}
int main()
{
    s1.top = -1;
    s2.top = -1;
    printf("Enter no. of elements:-\n");
    scanf("%d", &n);
    int c = 1, ele = 0;
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
            printf("Enter an element");
            scanf("%d", &ele);
            push(&s1, ele);
            break;
        case 2:
            while(s1.top != -1)
            {
                ele = pop(&s1);
                push(&s2, ele);
            }
            printf("Dequeued element %d\n", pop(&s2));
            while(s2.top != -1)
            {
                ele = pop(&s2);
                push(&s1, ele);
            }
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
