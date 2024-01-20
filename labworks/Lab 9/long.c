#include <stdio.h>
#include <stdlib.h>

// Definition of a pharmaceutical product node
struct PharmaNode {
    int productID;
    char name[50];
    int quantity;
    float price;
    char expirationDate[20];
    struct PharmaNode* left;
    struct PharmaNode* right;
};

// Function to create a new pharmaceutical product node
struct PharmaNode* newPharmaNode(int id, const char* name, int quantity, float price, const char* expirationDate) {
    struct PharmaNode* node = (struct PharmaNode*)malloc(sizeof(struct PharmaNode));
    node->productID = id;
    snprintf(node->name, sizeof(node->name), "%s", name);
    node->quantity = quantity;
    node->price = price;
    snprintf(node->expirationDate, sizeof(node->expirationDate), "%s", expirationDate);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Breadth-First Traversal (Level Order Traversal) for Pharmacy Inventory
void BFT(struct PharmaNode* root) {
    if (root == NULL)
        return;

    // Create a queue for BFT
    struct PharmaNode* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct PharmaNode* current = queue[++front];
        printf("ID:%d Name:%s Quantity:%d Price:%.2f Expiration:%s\n", current->productID, current->name, current->quantity, current->price, current->expirationDate);

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }
}

// Depth-First Traversal (Inorder) for Pharmacy Inventory
void DFT(struct PharmaNode* root) {
    if (root == NULL)
        return;

    DFT(root->left);
    printf("ID:%d Name:%s Quantity:%d Price:%.2f Expiration:%s\n", root->productID, root->name, root->quantity, root->price, root->expirationDate);
    DFT(root->right);
}

// Function to search for a pharmaceutical product by ID using Breadth-First Traversal (BFT)
struct PharmaNode* searchPharmaBFT(struct PharmaNode* root, int productID) {
    if (root == NULL)
        return NULL;

    // Create a queue for BFT search
    struct PharmaNode* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct PharmaNode* current = queue[++front];

        if (current->productID == productID)
            return current;

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }

    return NULL;
}

// Function to search for a pharmaceutical product by ID using Depth-First Traversal (DFT)
struct PharmaNode* searchPharmaDFT(struct PharmaNode* root, int productID) {
    if (root == NULL || root->productID == productID)
        return root;

    // Check the left subtree
    struct PharmaNode* leftResult = searchPharmaDFT(root->left, productID);
    if (leftResult != NULL)
        return leftResult;

    // Check the right subtree
    return searchPharmaDFT(root->right, productID);
}

// Function to display menu and handle user input
void displayMenu() {
    printf("\nPharmacy Inventory Management Menu:\n");
    printf("1. Add Pharmaceutical Product to Inventory\n");
    printf("2. Display Pharmacy Inventory (BFT)\n");
    printf("3. Display Pharmacy Inventory (DFT)\n");
    printf("4. Search Pharmaceutical Product by ID (BFT)\n");
    printf("5. Search Pharmaceutical Product by ID (DFT)\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct PharmaNode* inventoryRoot = NULL;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int id, quantity;
                    char name[50];
                    float price;
                    char expirationDate[20];

                    printf("Enter Product ID: ");
                    scanf("%d", &id);
                    printf("Enter Name: ");
                    scanf("%s", name);
                    printf("Enter Quantity: ");
                    scanf("%d", &quantity);
                    printf("Enter Price: ");
                    scanf("%f", &price);
                    printf("Enter Expiration Date: ");
                    scanf("%s", expirationDate);

                    struct PharmaNode* newProduct = newPharmaNode(id, name, quantity, price, expirationDate);

                    if (inventoryRoot == NULL)
                        inventoryRoot = newProduct;
                    else {
                        struct PharmaNode* current = inventoryRoot;
                        struct PharmaNode* parent;

                        while (current != NULL) {
                            parent = current;
                            if (id < current->productID)
                                current = current->left;
                            else
                                current = current->right;
                        }

                        if (id < parent->productID)
                            parent->left = newProduct;
                        else
                            parent->right = newProduct;
                    }

                    printf("Pharmaceutical product added to inventory.\n");
                }
                break;

            case 2:
                printf("Pharmacy Inventory (Breadth-First Traversal):\n");
                BFT(inventoryRoot);
                printf("\n");
                break;

            case 3:
                printf("Pharmacy Inventory (Depth-First Traversal):\n");
                DFT(inventoryRoot);
                printf("\n");
                break;

            case 4:
                {
                    int searchID;
                    printf("Enter Product ID to search using BFT: ");
                    scanf("%d", &searchID);
                    struct PharmaNode* result = searchPharmaBFT(inventoryRoot, searchID);
                    if (result != NULL)
                        printf("Pharmaceutical product found in inventory - ID:%d Name:%s Quantity:%d Price:%.2f Expiration:%s\n", result->productID, result->name, result->quantity, result->price, result->expirationDate);
                    else
                        printf("Pharmaceutical product with ID %d not found in the inventory.\n", searchID);
                }
                break;

            case 5:
                {
                    int searchID;
                    printf("Enter Product ID to search using DFT: ");
                    scanf("%d", &searchID);
                    struct PharmaNode* result = searchPharmaDFT(inventoryRoot, searchID);
                    if (result != NULL)
                        printf("Pharmaceutical product found in inventory - ID:%d Name:%s Quantity:%d Price:%.2f Expiration:%s\n", result->productID, result->name, result->quantity, result->price, result->expirationDate);
                    else
                        printf("Pharmaceutical product with ID %d not found in the inventory.\n", searchID);
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
