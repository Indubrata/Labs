#include <stdbool.h>
#include <stdio.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void push(Stack* s, char c) {
    if (s->top == MAX - 1) 
        return;
    s->items[++(s->top)] = c;
}

char pop(Stack* s) {
    if (s->top == -1) 
        return '\0';
    return s->items[(s->top)--];
}

char peek(Stack* s) {
    if (s->top == -1) return '\0';
    return s->items[s->top];
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

int precedence(char c) {
    if (c == '*' || c == '/') 
        return 2;
    if (c == '+' || c == '-') 
        return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z') 
            postfix[j++] = infix[i];
        else if (infix[i] == '(') 
            push(&s, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s);
        } 
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]))
                postfix[j++] = pop(&s);
            push(&s, infix[i]);
        }
        i++;
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}