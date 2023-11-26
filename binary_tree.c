#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // In Order
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);

    // Pre Order
    // printf("%d ", root->data);
    // printTree(root->left);
    // printTree(root->right);

    // Post Order
    // printTree(root->left);
    // printTree(root->right);
    // printf("%d ", root->data);
}

int main()
{
    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Binary Tree (In-order Traversal): ");
    printTree(root);
    printf("\n");
}