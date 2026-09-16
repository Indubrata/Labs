#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
    if (s->top == -1)  
        return '\0';
    return s->items[s->top];
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverseStr(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    
    reverseStr(infix);

    while (infix[i] != '\0') {
        if (infix[i] >= 'a' && infix[i] <= 'z')
            prefix[j++] = infix[i];
        else if (infix[i] == ')')
            push(&s, infix[i]);
        else if (infix[i] == '(') {
            while (!isEmpty(&s) && peek(&s) != ')')
                prefix[j++] = pop(&s);
            pop(&s);
        }
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(infix[i]))
                prefix[j++] = pop(&s);
            push(&s, infix[i]);
        }
        i++;
    }
    
    while (!isEmpty(&s)) {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    
    reverseStr(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("%s\n", prefix);
    return 0;
}