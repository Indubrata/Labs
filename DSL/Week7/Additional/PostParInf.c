#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX][MAX];
} StringStack;

void push(StringStack* s, char* str) {
    if (s->top == MAX - 1) 
        return;
    strcpy(s->items[++(s->top)], str);
}

void pop(StringStack* s, char* res) {
    if (s->top == -1) {
        res[0] = '\0';
        return;
    }
    strcpy(res, s->items[(s->top)--]);
}

void postfixToInfix(char* postfix, char* infix) {
    StringStack s;
    s.top = -1;
    char op1[MAX], op2[MAX], temp[MAX], chStr[2], opStr[2];
    int i = 0;
    
    while (postfix[i] != '\0') {
        if (postfix[i] >= 'a' && postfix[i] <= 'z') {
            chStr[0] = postfix[i];
            chStr[1] = '\0';
            push(&s, chStr);
        } 
        else {
            pop(&s, op1);
            pop(&s, op2);
            
            opStr[0] = postfix[i];
            opStr[1] = '\0';
            
            strcpy(temp, "(");
            strcat(temp, op2);
            strcat(temp, opStr);
            strcat(temp, op1);
            strcat(temp, ")");
            
            push(&s, temp);
        }
        i++;
    }
    pop(&s, infix);
}

int main() {
    char postfix[MAX], infix[MAX];
    scanf("%s", postfix);
    postfixToInfix(postfix, infix);
    printf("%s\n", infix);
    return 0;
}