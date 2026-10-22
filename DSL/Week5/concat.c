#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

/* Insert at rear of singly linked list */
Node* insRear(Node* start, int d) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->info = d;
    temp->next = NULL;

    if (start == NULL)
        return temp;

    Node* cur;
    for (cur = start; cur->next != NULL; cur = cur->next);
    cur->next = temp;
    return start;
}

/* Display a singly linked list */
void display(Node* start) {
    if (start == NULL) {
        printf("NULL\n");
        return;
    }
    Node* cur;
    for (cur = start; cur != NULL; cur = cur->next)
        printf("%d -> ", cur->info);
    printf("NULL\n");
}

/* Build a list by inserting n elements at rear */
Node* buildList(int n) {
    Node* start = NULL;
    int d, i;
    for (i = 0; i < n; i++) {
        printf("  Enter element %d: ", i + 1);
        scanf("%d", &d);
        start = insRear(start, d);
    }
    return start;
}

/* Concatenate list2 at the rear of list1 */
Node* concat(Node* list1, Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node* cur;
    for (cur = list1; cur->next != NULL; cur = cur->next);
    cur->next = list2;   /* link tail of list1 to head of list2 */
    return list1;
}

int main() {
    Node *list1 = NULL, *list2 = NULL, *result = NULL;
    int n1, n2;

    printf("=== Concatenation of Two Linked Lists ===\n\n");

    /* Build List 1 */
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    list1 = buildList(n1);

    /* Build List 2 */
    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    list2 = buildList(n2);

    printf("\nList 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    /* Concatenate */
    result = concat(list1, list2);

    printf("\nConcatenated List: ");
    display(result);

    return 0;
}
