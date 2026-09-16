#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char case_id[15];
    int complexity_score;
    float claim_amount;
}DisputeCase;

typedef struct {
    DisputeCase *cases;
    int front;
    int rear;
    int max_size;
}CaseQueue;

void init(CaseQueue *cq)
{
    cq->front = 0;
    cq->rear = 0;
    cq->max_size = 10;
    cq->cases = (DisputeCase*)malloc(cq->max_size * sizeof(DisputeCase));
}

bool isFull(CaseQueue *cq)
{
    return (cq->rear + 1) % cq->max_size == cq->front;
}

bool isEmpty(CaseQueue *cq)
{
    return cq->front == cq->rear;
}

void enqueue(CaseQueue *cq, DisputeCase dc)
{
    cq->rear = (cq->rear + 1) % cq->max_size;
    cq->cases[cq->rear] = dc;
}

DisputeCase dequeue(CaseQueue *cq)
{
    if (isEmpty(cq))
        return (DisputeCase){"", 0, 0.0f};
    cq->front = (cq->front + 1) % cq->max_size;
    return cq->cases[cq->front];    
}

void priority_inject(CaseQueue *cq, DisputeCase urgent_case)
{
    if (isFull(cq))
        printf("Queue is full");
    else 
    {
        if (urgent_case.claim_amount <= 50000)
            enqueue(cq, urgent_case);
        else
        {
            for (int i = cq->rear; i != cq->front; i = (i - 1 + cq->max_size) % cq->max_size)
            {
                int ind = (i + 1) % cq->max_size;
                cq->cases[ind] = cq->cases[i];
            }
            int new_front = (cq->front + 1) % cq->max_size;
            cq->cases[new_front] = urgent_case;
            cq->rear = (cq->rear + 1) % cq->max_size;
        }
    }
}

void display(CaseQueue *cq)
{
    for (int i = (cq->front + 1) % cq->max_size; i != (cq->rear + 1) % cq->max_size; i = (i + 1) % cq->max_size)
        printf("%d %s %f\n", cq->cases[i].complexity_score, cq->cases[i].case_id, cq->cases[i].claim_amount);
}

int main()
{
    CaseQueue cq;
    init(&cq);
    DisputeCase dc;
    int choice;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                scanf("%s %d %f", dc.case_id, &dc.complexity_score, &dc.claim_amount);
                priority_inject(&cq, dc);
                break;
            case 2:
                dc = dequeue(&cq);
                printf("%d %s %f\n", dc.complexity_score, dc.case_id, dc.claim_amount);
                break;
            case 3:
                display(&cq);
                break;
            case 4:
                exit(0);
                break;
        }
    }
}