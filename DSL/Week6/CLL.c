#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node* next;
}Node;

Node* insEndLPtr(Node* last, int d)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->next = NULL;
    if (last == NULL) {
        last = temp;
        last->next = last;
        return last;
    }
    temp->next = last->next;
    last->next = temp;
    last = temp;
    return last;
}

Node* DelEndLPtr(Node* last)
{
    if (last == NULL) {
        printf("Can't delete from empty list");
        return last;
    }
    else if (last->next == last) {
        free(last);
        return NULL;
    }
    else {
        Node* cur = last->next;
        for (;cur->next != last;cur = cur->next);
        cur->next = last->next;
        free(last);
        last = cur;
        return last;
    }
}
void display(Node* last) {
    if (last == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    Node* cur = last->next;
    printf("Linked List: ");
    while (cur != last) {
        printf("%d -> ", cur->info);
        cur = cur->next;
    }
    printf("%d -> ", cur->info);
    cur = cur->next;
    printf("start");
}
int main() {
    Node* last = NULL;
    int choice = 1, value;

    while(choice) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete Operation\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                last = insEndLPtr(last, value);
                printf("After Insertion:\n");
                display(last);
                break;

            case 2:
                last = DelEndLPtr(last);
                printf("After Deletion:\n");
                display(last);
                break;

            case 3:
                display(last);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
