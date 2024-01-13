#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int employeeID;
    char name[50];
    char position[20];
};

struct TreeNode {
    struct Employee data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new employee node
struct TreeNode* createNode(struct Employee data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert an employee into the BST
struct TreeNode* insert(struct TreeNode* root, struct Employee data) {
    if (root == NULL)
        return createNode(data);

    if (data.employeeID < root->data.employeeID)
        root->left = insert(root->left, data);
    else if (data.employeeID > root->data.employeeID)
        root->right = insert(root->right, data);

    return root;
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("[Employee ID: %d, Name: %s, Position: %s]\n", root->data.employeeID, root->data.name, root->data.position);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("[Employee ID: %d, Name: %s, Position: %s]\n", root->data.employeeID, root->data.name, root->data.position);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("[Employee ID: %d, Name: %s, Position: %s]\n", root->data.employeeID, root->data.name, root->data.position);
    }
}

// Function to search for an employee in the BST
struct TreeNode* search(struct TreeNode* root, int employeeID) {
    if (root == NULL || root->data.employeeID == employeeID)
        return root;

    if (employeeID < root->data.employeeID)
        return search(root->left, employeeID);

    return search(root->right, employeeID);
}

// Function to find the node with the minimum value in a BST
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL)
        node = node->left;

    return node;
}

// Function to delete an employee from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int employeeID) {
    if (root == NULL)
        return root;

    if (employeeID < root->data.employeeID)
        root->left = deleteNode(root->left, employeeID);
    else if (employeeID > root->data.employeeID)
        root->right = deleteNode(root->right, employeeID);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.employeeID);
    }
    return root;
}

// Function to calculate the height of the BST
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct TreeNode* root = NULL;
    int choice, employeeID;
    struct Employee data;

    do {
        printf("\n+------------------------ Pharmacy Management System ------------------------+\n");
        printf("| 1. Add Employee                                                              |\n");
        printf("| 2. Remove Employee                                                           |\n");
        printf("| 3. Search for Employee                                                       |\n");
        printf("| 4. Calculate Height of Employee BST                                          |\n");
        printf("| 5. Display Employees (In-order Traversal)                                   |\n");
        printf("| 6. Display Employees (Pre-order Traversal)                                  |\n");
        printf("| 7. Display Employees (Post-order Traversal)                                 |\n");
        printf("| 8. Exit                                                                      |\n");
        printf("+-----------------------------------------------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &data.employeeID);
                printf("Enter employee name: ");
                scanf("%s", data.name);
                printf("Enter employee position: ");
                scanf("%s", data.position);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter employee ID to remove: ");
                scanf("%d", &employeeID);
                root = deleteNode(root, employeeID);
                break;

            case 3:
                printf("Enter employee ID to search: ");
                scanf("%d", &employeeID);
                struct TreeNode* result = search(root, employeeID);
                if (result != NULL)
                    printf("Employee Found! ID: %d, Name: %s, Position: %s\n", result->data.employeeID, result->data.name, result->data.position);
                else
                    printf("Employee Not Found!\n");
                break;

            case 4:
                printf("Height of the Employee BST: %d\n", height(root));
                break;

            case 5:
                printf("Displaying Employees (In-order Traversal):\n");
                inOrderTraversal(root);
                break;

            case 6:
                printf("Displaying Employees (Pre-order Traversal):\n");
                preOrderTraversal(root);
                break;

            case 7:
                printf("Displaying Employees (Post-order Traversal):\n");
                postOrderTraversal(root);
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    return 0;
}
