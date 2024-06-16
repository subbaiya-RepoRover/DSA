#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for Inorder Traversal
void inorderTraversal(struct Node* node) {
    if (node == NULL) return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}
// Function for Preorder Traversal
void preorderTraversal(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Function for Postorder Traversal
void postorderTraversal(struct Node* node) {
    if (node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}
// Main function to demonstrate the tree traversals
int main() {
    // Creating a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Performing Inorder Traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Performing Preorder Traversal
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Performing Postorder Traversal
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
