#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node* next;
}Node;

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
    free(temp);
    cur->next = NULL;
    return start;
}

Node* InsBeg(Node* start, int d)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->next = start;
    return temp;
}

Node* DelBeg(Node* start)
{
    if (start != NULL) {
        Node* temp = start;
        start = start->next;
        free(temp);
        return start;
    }
    else
        printf("Can't delete from empty list");
}

Node* InsB4Ele(Node* start, int d, int k)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    if (start == NULL) {
        printf("Can't insert before any element if list is empty!");
        return NULL;
    }
    else if (start->info == k) {
        temp->next = start;
        return temp;
    }
    Node* cur = start;
    for (;cur->next != NULL && cur->next->info != k;cur = cur->next);
    if (cur->next == NULL) {
        printf("Element not found");
        return start;
    }
    temp->next = cur->next;
    cur->next = temp;
    return start;
}

Node* InsAfterEle(Node* start, int d, int k)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    if (start == NULL) {
        printf("Can't insert after any element if list is empty!");
        return NULL;
    }
    Node* cur = start;
    for (;cur != NULL && cur->info != k;cur = cur->next);
    if (cur == NULL) {
        printf("Element not found");
        return start;
    }
    temp->next = cur->next;
    cur->next = temp;
    return start;
}

Node* DelEle(Node* start, int k)
{
    if (start == NULL) {
        printf("Can't delete any element if list is empty!");
        return NULL;
    }
    else if (start->info == k) {
        free(start);
        return NULL;
    }
    Node* cur = start;
    for (;cur->next != NULL && cur->next->info != k;cur = cur->next);
    if (cur->next == NULL) {
        printf("Element not found");
        return start;
    }
    Node* temp = cur->next;
    cur->next = temp->next;
    free(temp);
    return start;
}

Node* Reverse(Node* start)
{
    if (start == NULL || start->next == NULL) {
        printf("Can't reverse");
        return start;
    }
    Node *a = NULL, *b = start, *c = b->next;
    while(c != NULL) {
        b->next = a;
        a = b;
        b = c;
        c = c->next;
    }
    b->next = a;
    start = b;
    return start;
}

Node* BubbleSort(Node* start)
{
    if (start == NULL || start->next == NULL) {
        printf("Nothing to sort");
        return start;
    }
    for (Node* i = start;i->next != NULL;i = i->next)
        for (Node* j = start;j->next != NULL;j = j->next)
            if(j->info > j->next->info) {
                int temp = j->info;
                j->info = j->next->info;
                j->next->info = temp;
            }
    return start;
}

Node* DelAltNode(Node* start)
{
    if (start == NULL || start->next == NULL) {
        printf("Nothing to delete");
        return start;
    }
    Node* cur = start;
    for (;cur != NULL && cur->next != NULL;cur = cur->next) {
        Node* temp = cur->next;
        cur->next = temp->next;
        free(temp);
    }
    return start;
}

Node* SortedInsert(Node* start, int d)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    if (start == NULL || temp->info < start->info) {
        temp->next = start;
        return temp;
    }
    Node* cur = start;
    for (;cur->next != NULL && temp->info > cur->next->info;cur = cur->next);
    if (cur->next == NULL) {
        cur->next = temp;
        temp->next = NULL;
        return start;
    }
    temp->next = cur->next;
    cur->next = temp;
    return start;
}

void display(Node* start) {
    if (start == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    Node* cur = start;
    printf("Linked List: ");
    while (cur != NULL) {
        printf("%d -> ", cur->info);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    Node* start = NULL;
    int choice = 1, ele, key;

    while (choice != 0) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert Before Element\n");
        printf("4. Insert After Element\n");
        printf("5. Sorted Insert\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete Specific Element\n");
        printf("9. Delete Alternate Nodes\n");
        printf("10. Reverse List\n");
        printf("11. Sort List (Bubble Sort)\n");
        printf("12. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            start = InsBeg(start, ele);
            break;
        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            start = insEnd(start, ele);
            break;
        case 3:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            printf("Enter target element (before which to insert): ");
            scanf("%d", &key);
            start = InsB4Ele(start, ele, key);
            break;
        case 4:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            printf("Enter target element (after which to insert): ");
            scanf("%d", &key);
            start = InsAfterEle(start, ele, key);
            break;
        case 5:
            printf("Enter element for sorted insert: ");
            scanf("%d", &ele);
            start = SortedInsert(start, ele);
            break;
        case 6:
            start = DelBeg(start);
            break;
        case 7:
            start = delEnd(start);
            break;
        case 8:
            printf("Enter element to delete: ");
            scanf("%d", &key);
            start = DelEle(start, key);
            break;
        case 9:
            start = DelAltNode(start);
            printf("Alternate nodes deleted.\n");
            break;
        case 10:
            start = Reverse(start);
            printf("List reversed successfully.\n");
            break;
        case 11:
            start = BubbleSort(start);
            printf("List sorted successfully.\n");
            break;
        case 12:
            display(start);
            break;
        case 0:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
