#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node* next;
}Node;
Node node;

Node* insEnd(Node* start, int d)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
        return start;
    }
    Node* cur;
    for(cur = start;cur->next != NULL;cur = cur->next);
    cur->next = temp;
    free(temp);
    return start;
}

Node* delEnd(Node* start)
{
    if (start == NULL) {
        printf("Empty Linked List");
        return start;
    }
    else if(start->next == NULL)
    {
        free(start);
        start = NULL;
        return start;
    }
    Node* cur;
    for(cur = start;cur->next->next != NULL;cur = cur->next);
    Node* temp = cur->next;
    printf("Removed %d", temp->info);
    // free(temp);
    cur->next = NULL;
    return start;
}
void display(Node* start)
{
    if (start == NULL) {
        printf("Empty Linked List");
        return;
    }
    Node* cur;
    for(cur = start;cur != NULL;cur = cur->next)
        printf("%d ", cur->info);
}
void displayTop(Node* cur)
{
    if (cur == NULL) {
        printf("Empty Linked List");
        return;
    }
    else if (cur->next == NULL) {
        printf("%d", cur->info);
        return;
    }
    displayTop(cur->next);
    printf("%d ", cur->info);
}
int main()
{
    Node* start = NULL;
    int c = 1, ele;
    printf("Menu:-");
    printf("1. Insert End, 2. Delete End, 3. Display from top, 4. Display from start, 5. Exit");
    while(c) {
        printf("Enter choice");
        scanf("%d", &c);
        switch(c) {
        case 1:
            printf("Enter element");
            scanf("%d", &ele);
            start = insEnd(start, ele);
            break;
        case 2:
            start = delEnd(start);
            break;
        case 3:
            displayTop(start);
            break;
        case 4:
            display(start);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}

