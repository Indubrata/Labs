#include <stdio.h>

#define MAX 5


typedef struct {
    int ar[MAX];
    int front;
    int rear;
} CQ;
CQ q;


void push(int v) {
    if ((q.rear + 1) % MAX == q.front) {
        printf("Circular queue is full\n");
        return;
    }
    q.rear = (q.rear + 1) % MAX;
    q.ar[q.rear] = v;
    printf("Pushed %d into the queue.\n", v);
}


int pop() {
    if (q.front == q.rear) {
        printf("Circular queue is empty\n");
        return -9999;
    }
    q.front = (q.front + 1) % MAX;
    return q.ar[q.front];
}


void display() {
    if (q.front == q.rear) {
        printf("Circular queue is empty\n");
        return;
    }
    
    printf("Queue elements: \n");
    int i = (q.front + 1) % MAX;
    while (i != (q.rear + 1) % MAX) {
        printf("%d\n", q.ar[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice, value;
    q.front = 0;
    q.rear = 0;
    
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
                
            case 2:
                value = pop();
                if (value != -9999) {
                    printf("Popped value: %d\n", value);
                }
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
        }
    }
    
    return 0;
}