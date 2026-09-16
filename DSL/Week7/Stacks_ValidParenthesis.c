#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char c)
{
    if (s->top < MAX - 1)
        s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (!isEmpty(s))
        return s->items[(s->top)--];
    return '-1';
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}') || (opening == '[' && closing == ']');
}

bool checkBalancedParentheses(char *expr) {
    Stack s;
    s.top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            push(&s, ch);
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty(&s))
                return false;
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, ch))
                return false;
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checkBalancedParentheses(expr)) {
        printf("Balanced parentheses.\n");
    } else {
        printf("Unbalanced parentheses.\n");
    }
    return 0;
}
