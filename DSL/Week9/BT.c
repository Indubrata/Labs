#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node{
    int data;
    struct node *left, *right;
} node;


node* newNode(int data)
{
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

node* insNode(node* root, int d)
{
    node *temp, *prev = NULL, *cur;
    char dir[100];
    int i;

    /* Handle empty tree: new node simply becomes the root */
    if (root == NULL)
        return newNode(d);

    temp = newNode(d);
    if (temp == NULL)
        return root;      /* malloc failure */

    printf("Enter direction string (e.g. LRL): ");
    scanf("%99s", dir);

    cur = root;

    for (i = 0; dir[i] != '\0'; i++)
    {
        if (cur == NULL)      /* path goes deeper than the tree */
            break;

        prev = cur;

        if (dir[i] == 'L')
            cur = cur->left;
        else if (dir[i] == 'R')
            cur = cur->right;
        else
        {
            printf("Invalid character '%c' in direction string. Use L or R.\n", dir[i]);
            free(temp);
            return root;
        }
    }

    /*
     * Valid insertion requires:
     *   - the entire string was consumed  (dir[i] == '\0')
     *   - the target slot is empty        (cur == NULL)
     */
    if (dir[i] != '\0' || cur != NULL)
    {
        if (cur != NULL)
            printf("Slot already occupied (value: %d). Insertion aborted.\n", cur->data);
        else
            printf("Path goes beyond existing nodes. Insertion aborted.\n");
        free(temp);
        return root;
    }

    /* Link the new node */
    if (prev == NULL)
    {
        /* direction string was empty — replace root */
        free(temp);
        return root;
    }

    if (dir[i - 1] == 'L')
        prev->left  = temp;
    else
        prev->right = temp;

    printf("Inserted %d at path \"%s\".\n", d, dir);
    return root;
}

void inorder(node *root)
{
    node *stack[MAX];
    int top = -1;
    node *current = root;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

void preorder(node *root)
{
    node *stack[MAX];
    int top = -1;
    node *current;

    stack[++top] = root;

    while (top != -1)
    {
        current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void postorder(node *root)
{
    node *stack1[MAX], *stack2[MAX];
    int top1 = -1, top2 = -1;
    node *current;

    stack1[++top1] = root;

    while (top1 != -1)
    {
        current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;

        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1)
    {
        current = stack2[top2--];
        printf("%d ", current->data);
    }
}

void printParent(node *root, int key)
{
    if (root == NULL)
        return;

    if ((root->left != NULL && root->left->data == key) || (root->right != NULL && root->right->data == key))
    {
        printf("Parent of %d is %d", key, root->data);
        return;
    }

    printParent(root->left, key);
    printParent(root->right, key);
}

int height(node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int printAncestors(node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (printAncestors(root->left, key) ||
        printAncestors(root->right, key))
    {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int countLeaf(node* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    node *root = NULL;
    int choice, key, val;
    char again;

    /* ---- Build the tree from user input using insNode ---- */
    printf("=== Build Binary Tree ===\n");
    printf("Insert nodes one by one. The first node becomes the root.\n");
    printf("For each subsequent node, enter a direction string (e.g. L, RR, LR).\n\n");

    do
    {
        printf("Enter data for new node: ");
        scanf("%d", &val);
        root = insNode(root, val);
        printf("Add another node? (y/n): ");
        scanf("%c", &again);
    } while (again == 'y' || again == 'Y');

    printf("\nTree built successfully!\n");

    do
    {
        printf("\n\n--- BINARY TREE MENU ---\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Print Parent of an Element\n");
        printf("5. Print Height of Tree\n");
        printf("6. Print Ancestors of an Element\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Insert Node (by direction string)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Inorder: ");
                inorder(root);
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                break;

            case 3:
                printf("Postorder: ");
                postorder(root);
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d", &key);
                printParent(root, key);
                break;

            case 5:
                printf("Height of tree = %d", height(root));
                break;

            case 6:
                printf("Enter element: ");
                scanf("%d", &key);
                if (!printAncestors(root, key))
                    printf("Element not found");
                break;

            case 7:
                printf("Number of leaf nodes = %d",
                       countLeaf(root));
                break;

            case 8: {
                int val;
                printf("Enter data for new node: ");
                scanf("%d", &val);
                root = insNode(root, val);
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice);
    return 0;
}
