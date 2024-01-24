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

// Function to insert an employee into the binary tree using level order and depth order
struct TreeNode* insertEmployee(struct employee employees[], int i, int n, int levelOrderIndex) {
    if (i < n) {
        struct TreeNode* temp = createNode(employees[levelOrderIndex]);

        // Insert left child using depth order (pre-order)
        temp->left = insertEmployee(employees, i * 2 + 1, n, levelOrderIndex + 1);

        // Insert right child using depth order (pre-order)
        temp->right = insertEmployee(employees, i * 2 + 2, n, levelOrderIndex + 2);

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

// Pre-order (Depth-order) traversal
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

// Function to calculate the height of the tree
int calculateHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

// Function to calculate the depth of the tree
int calculateDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);

        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
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

    // Create a binary tree using both level order and depth order
    struct TreeNode* root = insertEmployee(employees, 0, n, 0);

    // Perform traversals
    printf("\nIn-order Traversal:\n");
    inOrderTraversal(root);

    printf("\n\nPre-order (Depth-order) Traversal:\n");
    preOrderTraversal(root);

    printf("\n\nPost-order Traversal:\n");
    postOrderTraversal(root);

    // Calculate and print the height and depth of the tree
    int height = calculateHeight(root);
    int depth = calculateDepth(root);

    printf("\nHeight of the tree: %d\n", height);
    printf("Depth of the tree: %d\n", depth);

    return 0;
}
