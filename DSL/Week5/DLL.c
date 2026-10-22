#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* prev;
    struct Node* next;
} Node;

Node* insRear(Node* start, int d) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        return temp;
    }

    Node* cur;
    for (cur = start; cur->next != NULL; cur = cur->next);
    cur->next = temp;
    temp->prev = cur;
    return start;
}

Node* delRear(Node* start) {
    if (start == NULL) {
        printf("Empty Linked List\n");
        return NULL;
    }
    if (start->next == NULL) {
        printf("Removed %d\n", start->info);
        free(start);
        return NULL;
    }

    Node* cur;
    for (cur = start; cur->next != NULL; cur = cur->next);
    printf("Removed %d\n", cur->info);
    cur->prev->next = NULL;
    free(cur);
    return start;
}

Node* insAtPos(Node* start, int d, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return start;
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->prev = NULL;
    temp->next = NULL;

    if (pos == 1) {
        temp->next = start;
        if (start != NULL) {
            start->prev = temp;
        }
        return temp;
    }

    Node* cur = start;
    for (int i = 1; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Position out of range!\n");
        free(temp);
        return start;
    }

    temp->next = cur->next;
    temp->prev = cur;
    if (cur->next != NULL) {
        cur->next->prev = temp;
    }
    cur->next = temp;
    return start;
}

Node* delAtPos(Node* start, int pos) {
    if (start == NULL) {
        printf("Can't delete from empty list\n");
        return NULL;
    }
    if (pos < 1) {
        printf("Invalid position!\n");
        return start;
    }

    Node* cur = start;

    if (pos == 1) {
        start = start->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        printf("Removed %d\n", cur->info);
        free(cur);
        return start;
    }

    for (int i = 1; i < pos && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Position out of range!\n");
        return start;
    }

    cur->prev->next = cur->next;
    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    }
    printf("Removed %d\n", cur->info);
    free(cur);
    return start;
}

Node* insAfterEle(Node* start, int d, int k) {
    if (start == NULL) {
        printf("Can't insert after any element if list is empty!\n");
        return NULL;
    }

    Node* cur = start;
    for (; cur != NULL && cur->info != k; cur = cur->next);

    if (cur == NULL) {
        printf("Element %d not found\n", k);
        return start;
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->next = cur->next;
    temp->prev = cur;

    if (cur->next != NULL) {
        cur->next->prev = temp;
    }
    cur->next = temp;
    return start;
}

Node* insB4Ele(Node* start, int d, int k) {
    if (start == NULL) {
        printf("Can't insert before any element if list is empty!\n");
        return NULL;
    }

    Node* cur = start;
    for (; cur != NULL && cur->info != k; cur = cur->next);

    if (cur == NULL) {
        printf("Element %d not found\n", k);
        return start;
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->next = cur;
    temp->prev = cur->prev;

    if (cur->prev != NULL) {
        cur->prev->next = temp;
    } else {
        start = temp;
    }
    cur->prev = temp;
    return start;
}

void traverseForward(Node* start) {
    if (start == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    Node* cur = start;
    printf("Forward Traversal: NULL <-> ");
    while (cur != NULL) {
        printf("%d <-> ", cur->info);
        cur = cur->next;
    }
    printf("NULL\n");
}


void traverseReverse(Node* start) {
    if (start == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    Node* cur = start;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    printf("Reverse Traversal: NULL <-> ");
    while (cur != NULL) {
        printf("%d <-> ", cur->info);
        cur = cur->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* start = NULL;
    int choice = 1, ele, key, pos;

    while (choice != 0) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Position\n");
        printf("5. Insert After Element\n");
        printf("6. Insert Before Element\n");
        printf("7. Traverse Forward\n");
        printf("8. Traverse Reverse\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            start = insRear(start, ele);
            break;
        case 2:
            start = delRear(start);
            break;
        case 3:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            printf("Enter position (starts at 1): ");
            scanf("%d", &pos);
            start = insAtPos(start, ele, pos);
            break;
        case 4:
            printf("Enter position to delete (starts at 1): ");
            scanf("%d", &pos);
            start = delAtPos(start, pos);
            break;
        case 5:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            printf("Enter target element (after which to insert): ");
            scanf("%d", &key);
            start = insAfterEle(start, ele, key);
            break;
        case 6:
            printf("Enter element to insert: ");
            scanf("%d", &ele);
            printf("Enter target element (before which to insert): ");
            scanf("%d", &key);
            start = insB4Ele(start, ele, key);
            break;
        case 7:
            traverseForward(start);
            break;
        case 8:
            traverseReverse(start);
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