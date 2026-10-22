#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

/* ── Node creation ─────────────────────────────────────────── */

node *newNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data  = data;
    n->left  = n->right = NULL;
    return n;
}

/* ── BST Insert ────────────────────────────────────────────── */

node *insert(node *root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left  = insert(root->left,  data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate value %d not inserted.\n", data);

    return root;
}

/* ── Traversals ─────────────────────────────────────────────── */

void inorder(node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* ── Main ───────────────────────────────────────────────────── */

int main()
{
    node *root = NULL;
    int choice, value;

    do {
        printf("\n\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal   (Left -> Root -> Right)\n");
        printf("3. Preorder Traversal  (Root -> Left -> Right)\n");
        printf("4. Postorder Traversal (Left -> Right -> Root)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted.\n", value);
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Inorder:   ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Preorder:  ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
