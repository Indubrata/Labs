#include <stdio.h>
#define MAX_SIZE 100
int n;
struct Stack {
    int items[MAX_SIZE];
    int top;
};

struct Stack st;

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
void display(struct Stack *s)
{
    if (s->top == -1)
        printf("Empty");
    for (int i = s->top;i >= 0;i--)
        printf("%d\n", s->items[i]);
}
int main()
{
    st.top = -1;
    printf("Enter no. of elements:-\n");
    scanf("%d", &n);
    int c = 1, ele = 0;
    while(c)
    {
        printf("Menu:-\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit");
        scanf("%d", &c);
        switch(c)
        {
        case 1:
            printf("Enter an element");
            scanf("%d", &ele);
            push(&st, ele);
            break;
        case 2:
            printf("Popped element %d\n", pop(&st));
            break;
        case 3:
            display(&st);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}
