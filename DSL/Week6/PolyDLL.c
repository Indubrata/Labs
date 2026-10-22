#include <stdio.h>
#include <stdlib.h>

typedef struct DPolyNode{
    int exp, coeff;
    struct DPolyNode* prev;
    struct DPolyNode* next;
}DPolyNode;


DPolyNode* appendPolyNode(DPolyNode* start, int exp, int coeff)
{
    DPolyNode* temp = (DPolyNode*)malloc(sizeof(DPolyNode));
    temp->exp = exp;
    temp->coeff = coeff;
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
        temp->prev = NULL;
        return start;
    }
    DPolyNode* cur;
    for(cur = start;cur->next != NULL;cur = cur->next);
    cur->next = temp;
    temp->prev = cur;
    return start;
}
DPolyNode* PolyAdd(DPolyNode* a, DPolyNode* b)
{
    DPolyNode *c = NULL;
    int coeff, cmp;
    while(a != NULL && b != NULL) {
        if (a->exp == b->exp)
            cmp = 0;
        else if (a->exp > b->exp)
            cmp = 1;
        else
            cmp = -1;

        switch(cmp) {
            case 0: coeff = a->coeff + b->coeff;
                    if (coeff != 0)
                        c = appendPolyNode(c, a->exp, coeff);
                    b = b->next;
                    a = a->next;
                    break;
            case 1: c = appendPolyNode(c, a->exp, a->coeff);
                    a = a->next;
                    break;
            case -1: c = appendPolyNode(c, b->exp, b->coeff);
                     b = b->next;
                     break;
        }
    }
    while (a != NULL) {
        c = appendPolyNode(c, a->exp, a->coeff);
        a = a->next;
    }
    while (b != NULL) {
        c = appendPolyNode(c, b->exp, b->coeff);
        b = b->next;
    }
    return c;
}

DPolyNode* insertTerm(DPolyNode* start, int exp, int coeff) {
    // If coeff is 0, nothing to insert
    if (coeff == 0) return start;

    DPolyNode* newNode = (DPolyNode*)malloc(sizeof(DPolyNode));
    newNode->exp = exp;
    newNode->coeff = coeff;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Case 1: Empty polynomial
    if (start == NULL) {
        return newNode;
    }

    // Case 2: Insert at the beginning (higher exponent)
    if (exp > start->exp) {
        newNode->next = start;
        start->prev = newNode;
        return newNode;
    }

    // Case 3: Traverse to find correct position
    DPolyNode* current = start;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }

    // Case 4: Duplicate exponent found (add coefficients)
    if (current->next != NULL && current->next->exp == exp) {
        current->next->coeff += coeff;
        free(newNode); // Don't need the new node

        // If sum becomes 0, remove the node
        if (current->next->coeff == 0) {
            DPolyNode* toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete->next != NULL) {
                toDelete->next->prev = current;
            }
            free(toDelete);
        }
        return start;
    }

    // Case 5: Insert in middle or end
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return start;
}

DPolyNode* PolyMult(DPolyNode* a, DPolyNode* b)
{
    DPolyNode* result = NULL;

    for (DPolyNode* ptr1 = a; ptr1 != NULL; ptr1 = ptr1->next) {
        for (DPolyNode* ptr2 = b; ptr2 != NULL; ptr2 = ptr2->next) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int exp = ptr1->exp + ptr2->exp;
            result = insertTerm(result, coeff, exp);
        }
    }
    return result;
}

void display(DPolyNode* start) {
    if (start == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    DPolyNode* cur = start;
    while (cur != NULL) {
        if (cur->coeff > 0 && cur != start)
            printf("+ %d^%d ", cur->coeff, cur->exp);
        else
            printf("%d^%d ", cur->coeff, cur->exp);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    DPolyNode* poly1 = NULL;
    DPolyNode* poly2 = NULL;
    DPolyNode* polySum = NULL;

    int i = 1, exp, coeff;

    printf("Enter the terms of 1st polynomial(coefficient and exponent) in descending order of exponents:\n");
    while(i) {
        printf("Term %d - Coeff and Exp: ", i++);
        scanf("%d%d", &coeff, &exp);
        if (coeff == -999 || exp == -999)
            break;
        poly1 = appendPolyNode(poly1, exp, coeff);
    }

    i = 1;
    printf("Enter the terms of 2nd polynomial(coefficient and exponent) in descending order of exponents:\n");
    while(i) {
        printf("Term %d - Coeff and Exp: ", i++);
        scanf("%d%d", &coeff, &exp);
        if (coeff == -999 || exp == -999)
            break;
        poly2 = appendPolyNode(poly2, exp, coeff);
    }

    polySum = PolyAdd(poly1, poly2);

    printf("\n--- Results ---\n");
    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    printf("Resultant Sum: ");
    display(polySum);

    DPolyNode* polyProd = PolyMult(poly1, poly2);
    printf("Resultant Product: ");
    display(polyProd);

    return 0;
}
