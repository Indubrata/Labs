#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    int priority;
} Patient;

typedef struct {
    int front, rear;
    Patient items[MAX];
} PriorityQueue;

void init(PriorityQueue* pq) {
    pq->front = pq->rear = -1;
}

void enqueue(PriorityQueue* pq, char* name, int age, int priority) {
    if (pq->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    Patient pat;
    pat.priority = priority;
    pat.age = age;
    strcpy(pat.name, name);
    pq->items[++pq->rear] = pat;
}

Patient dequeue(PriorityQueue* pq) {
    Patient empty = {"", 0, -1};
    if (pq->rear == pq->front) {
        return empty;
    }
    int k = 0;
    Patient max;
    max.priority = 0;
    for (int i = pq->front + 1;i <= pq->rear;i++)
        if (pq->items[i].priority > max.priority) {
            max = pq->items[i];
            k = i;
        }
    if (k != pq->rear)
        pq->items[k] = pq->items[pq->rear];
    pq->rear--;
    return max;
}

int main() {
    PriorityQueue pq;
    init(&pq);
    int choice, age, priority;
    char name[50];
    Patient p;
    
    while (1) {
        printf("\n1. Enqueue Patient\n2. Dequeue Patient\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Priority (higher number = higher priority): ");
                scanf("%d", &priority);
                enqueue(&pq, name, age, priority);
                break;
            case 2:
                p = dequeue(&pq);
                if (p.priority == -1) {
                    printf("Queue Underflow\n");
                } else {
                    printf("Removed Patient - Name: %s, Age: %d, Priority: %d\n", p.name, p.age, p.priority);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}