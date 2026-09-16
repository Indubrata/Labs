#include <stdio.h>

#define MAX 100
#define MAX_STACKS 10

typedef struct {
    int items[MAX];
    int top[MAX_STACKS];
    int boundary[MAX_STACKS + 1];
    int k;
} KStacks;

void init(KStacks* s, int k) {
    s->k = k;
    int size = MAX / k;
    for (int i = 0; i < k; i++) {
        s->boundary[i] = (i * size) - 1;
        s->top[i] = s->boundary[i];
    }
    s->boundary[k] = MAX - 1;
}

void push(KStacks* s, int sn, int val) {
    if (s->top[sn] == s->boundary[sn + 1]) {
        printf("Overflow\n");
        return;
    }
    s->items[++(s->top[sn])] = val;
}

int pop(KStacks* s, int sn) {
    if (s->top[sn] == s->boundary[sn]) {
        return -1;
    }
    return s->items[(s->top[sn])--];
}

int main() {
    KStacks ks;
    int k, choice, sn, val, res;
    
    printf("Enter number of stacks: ");
    scanf("%d", &k);
    
    if (k <= 0 || k > MAX_STACKS) {
        printf("Invalid number of stacks\n");
        return 0;
    }
    
    init(&ks, k);
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter stack number (0 to %d): ", k - 1);
                scanf("%d", &sn);
                if (sn >= 0 && sn < k) {
                    printf("Enter value to push: ");
                    scanf("%d", &val);
                    push(&ks, sn, val);
                } else {
                    printf("Invalid stack number\n");
                }
                break;
            case 2:
                printf("Enter stack number (0 to %d): ", k - 1);
                scanf("%d", &sn);
                if (sn >= 0 && sn < k) {
                    res = pop(&ks, sn);
                    if (res == -1) {
                        printf("Underflow\n");
                    } else {
                        printf("Popped: %d\n", res);
                    }
                } else {
                    printf("Invalid stack number\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}