#include <stdbool.h>
#include <stdio.h>

#define MAX 100
#define MAX_QUEUES 10

typedef struct {
    int que[MAX];
    int front[MAX_QUEUES];
    int rear[MAX_QUEUES];
    int bound[MAX_QUEUES + 1];
    int n;
} NQueues;

void init(NQueues* q, int n) {
    q->n = n;
    int len = MAX / n, i;
    
    for (i = 0; i < n; i++) {
        q->front[i] = i * len;
        q->rear[i] = q->front[i];
        q->bound[i] = q->front[i];
    }
    q->bound[i] = MAX;
}

bool QUEUE_FULL(NQueues* q, int i) {
    int len = q->bound[i + 1] - q->bound[i];
    int new_rear = q->bound[i] + ((q->rear[i] - q->bound[i] + 1) % len);
    return new_rear == q->front[i];
}

void ADDQ(NQueues* q, int i, int x) {
    if (QUEUE_FULL(q, i)) {
        printf("Queue %d is Full. Cannot accommodate further insertions.\n", i);
        return;
    }
    int len = q->bound[i + 1] - q->bound[i];
    q->rear[i] = q->bound[i] + ((q->rear[i] - q->bound[i] + 1) % len);
    q->que[q->rear[i]] = x;
    printf("Inserted %d into Queue %d\n", x, i);
}

int DELETEQ(NQueues* q, int i) {
    if (q->front[i] == q->rear[i])
        return -1;
    int len = q->bound[i + 1] - q->bound[i];
    q->front[i] = q->bound[i] + ((q->front[i] - q->bound[i] + 1) % len);
    return q->que[q->front[i]];
}

int main() {
    NQueues nq;
    int n, choice, qi, val, res;

    printf("Enter number of queues: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_QUEUES) {
        printf("Invalid number of queues.\n");
        return 0;
    }

    init(&nq, n);

    while (1) {
        printf("\n1. ADDQ (Add to a queue)\n");
        printf("2. DELETEQ (Delete from a queue)\n");
        printf("3. QUEUE_FULL (Check if a queue is full)\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue index (0 to %d): ", n - 1);
                scanf("%d", &qi);
                if (qi >= 0 && qi < n) {
                    printf("Enter value to insert: ");
                    scanf("%d", &val);
                    ADDQ(&nq, qi, val);
                } 
                else
                    printf("Invalid queue index.\n");
                break;
                
            case 2:
                printf("Enter queue index (0 to %d): ", n - 1);
                scanf("%d", &qi);
                if (qi >= 0 && qi < n) {
                    res = DELETEQ(&nq, qi);
                    if (res == -1) {
                        printf("Queue %d is Empty.\n", qi);
                    } 
                    else 
                        printf("Deleted %d from Queue %d\n", res, qi);
                } 
                else
                    printf("Invalid queue index.\n");
                break;
                
            case 3:
                printf("Enter queue index (0 to %d): ", n - 1);
                scanf("%d", &qi);
                if (qi >= 0 && qi < n) {
                    if (QUEUE_FULL(&nq, qi))
                        printf("Queue %d is FULL.\n", qi);
                    else
                        printf("Queue %d is NOT full\n", qi);
                } 
                else
                    printf("Invalid queue index.\n");
                break;
                
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}