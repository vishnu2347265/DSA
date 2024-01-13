#include <stdio.h>
#include <stdlib.h>

struct employee {
    int employeeID;
    char name[50];
    char position[20];
};

struct TreeNode {
    struct employee data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new employee node
struct TreeNode* createNode(struct employee data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert an employee into the binary tree using level order
struct TreeNode* insertLevelOrder(struct employee employees[], int i, int n) {
    if (i < n) {
        struct TreeNode* temp = createNode(employees[i]);

        // Insert left child
        temp->left = insertLevelOrder(employees, 2 * i + 1, n);

        // Insert right child
        temp->right = insertLevelOrder(employees, 2 * i + 2, n);

        return temp;
    }
    return NULL;
}

// In-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Employee ID: %d, Name: %s, Position: %s\n", root->data.employeeID, root->data.name, root->data.position);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("Employee ID: %d, Name: %s, Position: %s\n", root->data.employeeID, root->data.name, root->data.position);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("Employee ID: %d, Name: %s, Position: %s\n", root->data.employeeID, root->data.name, root->data.position);
    }
}

int main() {
    int n;

    // Prompt user for the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct employee employees[n];

    // Input employee information
    for (int i = 0; i < n; ++i) {
        printf("\nEnter the Employee ID of Employee %d: ", i + 1);
        scanf("%d", &employees[i].employeeID);

        printf("Enter the Name of Employee %d: ", i + 1);
        scanf("%s", employees[i].name);

        printf("Enter the Position of Employee %d: ", i + 1);
        scanf("%s", employees[i].position);
    }

    // Create a binary tree using level order
    struct TreeNode* root = insertLevelOrder(employees, 0, n);

    // Perform traversals
    printf("\nIn-order Traversal:\n");
    inOrderTraversal(root);

    printf("\n\nPre-order Traversal:\n");
    preOrderTraversal(root);

    printf("\n\nPost-order Traversal:\n");
    postOrderTraversal(root);

    return 0;
}
