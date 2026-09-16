#include <stdio.h>

#define MAX 100
#define MAX_QUEUES 10

typedef struct {
    int que[MAX];
    int front[MAX_QUEUES];
    int rear[MAX_QUEUES];
    int bound[MAX_QUEUES + 1]; 
    int k;
} KQueues;

void init(KQueues* q, int k) {
    q->k = k;
    int len = MAX / k;
    int i;
    
    for (i = 0; i < k; i++) {
        q->bound[i] = i * len;
        q->front[i] = q->bound[i] - 1;
        q->rear[i] = q->bound[i] - 1; 
    }
    q->bound[k] = MAX; 
}

int QUEUE_FULL(KQueues* q, int i) {
    return q->rear[i] == q->bound[i + 1] - 1;
}

int QUEUE_EMPTY(KQueues* q, int i) {
    return q->front[i] == q->rear[i];
}

void ADDQ(KQueues* q, int i, int x) {
    if (QUEUE_FULL(q, i)) {
        printf("Queue %d is Full. Cannot accommodate further insertions.\n", i);
        return;
    }
    q->que[++(q->rear[i])] = x;
    printf("Inserted %d into Queue %d\n", x, i);
}

int DELETEQ(KQueues* q, int i) {
    if (QUEUE_EMPTY(q, i))
        return -1;
    return q->que[++(q->front[i])];
}

int main() {
    KQueues kq;
    int k, choice, qi, val, res; 

    printf("Enter number of queues: ");
    scanf("%d", &k);
    
    if (k <= 0 || k > MAX_QUEUES) { 
        printf("Invalid number of queues.\n");
        return 0;
    }

    init(&kq, k);

    while (1) {
        printf("\n1. ADDQ (Add to a simple queue)\n");
        printf("2. DELETEQ (Delete from a simple queue)\n");
        printf("3. QUEUE_FULL (Check if a queue is full)\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter queue index (0 to %d): ", k - 1);
                scanf("%d", &qi);
                if (qi >= 0 && qi < k) {
                    printf("Enter value to insert: ");
                    scanf("%d", &val);
                    ADDQ(&kq, qi, val);
                } 
                else
                    printf("Invalid queue index.\n");
                break;
                
            case 2:
                printf("Enter queue index (0 to %d): ", k - 1);
                scanf("%d", &qi);
                if (qi >= 0 && qi < k) {
                    res = DELETEQ(&kq, qi);
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
                printf("Enter queue index (0 to %d): ", k - 1);
                scanf("%d", &qi);
                if (qi >= 0 && qi < k) {
                    if (QUEUE_FULL(&kq, qi))
                        printf("Queue %d is FULL.\n", qi);
                    else
                        printf("Queue %d is NOT full.\n", qi);
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