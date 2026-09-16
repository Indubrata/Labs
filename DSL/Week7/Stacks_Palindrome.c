#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

bool isFull(Stack *s)
{
    return s->top == MAX - 1;
}
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char c)
{
    if (!isFull(s))
        s->items[++(s->top)] = c;
    else
        printf("Overflow");
}

char pop(Stack *s) {
    if (!isEmpty(s))
        return s->items[(s->top)--];
    return '-1';
}

bool isPalindrome(char *str) {
    Stack s;
    s.top = -1;
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
        push(&s, str[i]);
    int start = (len % 2 == 0) ? (len / 2) : (len / 2 + 1);
    for (int i = start; i < len; i++)
        if (str[i] != pop(&s))
            return false;
    return true;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    return 0;
}
