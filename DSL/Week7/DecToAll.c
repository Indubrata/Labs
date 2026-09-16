
#include <stdio.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int val) {
    if (s->top == MAX - 1) 
        return;
    s->items[++(s->top)] = val;
}

int pop(Stack* s) {
    if (s->top == -1) 
        return -1;
    return s->items[(s->top)--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void convert(int num, int base) {
    if (num == 0) {
        printf("0\n");
        return;
    }
    
    Stack s;
    init(&s);
    
    while (num > 0) {
        push(&s, num % base);
        num /= base;
    }
    
    while (!isEmpty(&s)) {
        int rem = pop(&s);
        if (rem < 10) {
            printf("%d", rem);
        } else {
            printf("%c", 'A' + (rem - 10));
        }
    }
    printf("\n");
}

int main() {
    int choice, num;
    
    while (1) {
        printf("\n1. Decimal to Binary\n2. Decimal to Octal\n3. Decimal to Hexadecimal\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            case 2:
            case 3:
                printf("Enter a positive decimal number: ");
                scanf("%d", &num);
                if (num < 0) {
                    printf("Invalid input.\n");
                    break;
                }
                printf("Result: ");
                if (choice == 1) convert(num, 2);
                else if (choice == 2) convert(num, 8);
                else convert(num, 16);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}