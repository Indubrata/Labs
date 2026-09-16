#include <stdio.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

void push(Stack* s, int val) {
    if (s->top == MAX - 1) 
        return;
    s->items[++(s->top)] = val;
}

int pop(Stack* s) {
    if (s->top == -1) 
        return 0;
    return s->items[(s->top)--];
}

int evaluatePostfix(char* exp) {
    Stack s;
    s.top = -1;
    int i = 0;
    
    while (exp[i] != '\0') {
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(&s, exp[i] - '0');
        } else {
            int val1 = pop(&s);
            int val2 = pop(&s);
            switch (exp[i]) {
                case '+': push(&s, val2 + val1); 
                    break;
                case '-': push(&s, val2 - val1); 
                    break;
                case '*': push(&s, val2 * val1); 
                    break;
                case '/': push(&s, val2 / val1); 
                    break;
            }
        }
        i++;
    }
    return pop(&s);
}

int main() {
    char exp[MAX];
    scanf("%s", exp);
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}