#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 4

// Define a structure for the pharmacy
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Define an array of medicines
struct Medicine pharmacy[100];
int medicineCount = 0;

// Function to enter sales values for a matrix
void enterSalesMatrix(int mat[ROWS][COLS], char *matrixName) {
    printf("Enter sales values for %s (3x4 matrix):\n", matrixName);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter sales value for Day %d, Product %d: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add a new medicine to the pharmacy
void addMedicine() {
    printf("Enter the ID of the Medicine: ");
    scanf("%d", &pharmacy[medicineCount].id);

    printf("Enter the Name of the Medicine: ");
    scanf("%s", pharmacy[medicineCount].name);

    printf("Enter the Price of the Medicine: ");
    scanf("%f", &pharmacy[medicineCount].price);

    printf("Enter the Quantity of the Medicine: ");
    scanf("%d", &pharmacy[medicineCount].quantity);

    medicineCount++;

    printf("Medicine added successfully!\n");
}

// Function to delete a medicine based on ID
void deleteMedicine(int id) {
    int i, j;
    int deleteIndex = -1;

    for (i = 0; i < medicineCount; i++) {
        if (pharmacy[i].id == id) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex == -1) {
        printf("Medicine with ID %d not found.\n", id);
        return;
    }

    for (j = deleteIndex; j < medicineCount - 1; j++) {
        pharmacy[j] = pharmacy[j + 1];
    }

    medicineCount--;

    printf("Medicine with ID %d has been deleted.\n", id);
}

// Function to search for a medicine by name
void searchMedicine(char *searchName) {
    int i;
    int found = 0;

    for (i = 0; i < medicineCount; i++) {
        if (strcmp(pharmacy[i].name, searchName) == 0) {
            printf("Medicine Found!\n");
            printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", pharmacy[i].id, pharmacy[i].name, pharmacy[i].price, pharmacy[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found with the name: %s\n", searchName);
    }
}

int main() {
    int choice;

    // Define matrices for sales data
    int salesMatrix1[ROWS][COLS] = {0};
    int salesMatrix2[ROWS][COLS] = {0};
    int resultMatrix[ROWS][COLS];

    do {
        // Menu for pharmacy and matrix operations
        printf("\nPharmacy Management System & Matrix Operations \n");
        printf(" 1. Add Medicine                                           \n");
        printf(" 2. Show All Medicines                                     \n");
        printf(" 3. Delete Medicine                                       \n");
        printf(" 4. Search Medicine by Name                                \n");
        printf(" 5. Enter Sales Data (Matrix 1)                            \n");
        printf(" 6. Enter Sales Data (Matrix 2)                            \n");
        printf(" 7. Perform Matrix Addition                                \n");
        printf(" 8. Perform Matrix Subtraction                             \n");
        printf(" 9. Exit Program                                          \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                if (medicineCount == 0) {
                    printf("No medicines in the pharmacy.\n");
                } else {
                    printf("Medicine Inventory:\n");
                    for (int i = 0; i < medicineCount; i++) {
                        printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n\n", pharmacy[i].id, pharmacy[i].name, pharmacy[i].price, pharmacy[i].quantity);
                    }
                }
                break;
            case 3:
                if (medicineCount == 0) {
                    printf("No medicines to delete.\n");
                } else {
                    int delId;
                    printf("Enter the ID of the medicine to delete: ");
                    scanf("%d", &delId);
                    deleteMedicine(delId);
                }
                break;
            case 4:
                if (medicineCount == 0) {
                    printf("No medicines to search.\n");
                } else {
                    char searchName[50];
                    printf("Enter the name of the medicine you want to search: ");
                    scanf("%s", searchName);
                    searchMedicine(searchName);
                }
                break;
            case 5:
                enterSalesMatrix(salesMatrix1, "Matrix 1");
                break;
            case 6:
                enterSalesMatrix(salesMatrix2, "Matrix 2");
                break;
            case 7:
                // Perform matrix addition
                for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLS; j++) {
                        resultMatrix[i][j] = salesMatrix1[i][j] + salesMatrix2[i][j];
                    }
                }
                printf("Matrix Addition Result:\n");
                displayMatrix(resultMatrix);
                break;
            case 8:
                // Perform matrix subtraction
                for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLS; j++) {
                        resultMatrix[i][j] = salesMatrix1[i][j] - salesMatrix2[i][j];
                    }
                }
                printf("Matrix Subtraction Result:\n");
                displayMatrix(resultMatrix);
                break;

            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 10);

    return 0;
}
