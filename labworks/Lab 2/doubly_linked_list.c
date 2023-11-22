#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure representing a medication
struct Medication {
    int id;
    char name[100];
    int quantity;
    float price;
    struct Medication* next; // Pointer to the next node in the linked list
    struct Medication* prev; // Pointer to the previous node in the linked list
};

// Linked list structure for managing medications
struct MedicationList {
    struct Medication* head; // Pointer to the first node in the linked list
    struct Medication* tail; // Pointer to the last node in the linked list
};

// Function to initialize the linked list
void initializeList(struct MedicationList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to insert a new medication at the end of the list
void insertMedication(struct MedicationList* list, int id, const char* name, int quantity, float price) {
    struct Medication* newMedication = (struct Medication*)malloc(sizeof(struct Medication));
    if (newMedication == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newMedication->id = id;
    strncpy(newMedication->name, name, sizeof(newMedication->name) - 1);
    newMedication->quantity = quantity;
    newMedication->price = price;
    newMedication->next = NULL;

    if (list->head == NULL) {
        // If the list is empty, set the new node as both head and tail
        newMedication->prev = NULL;
        list->head = newMedication;
        list->tail = newMedication;
    } else {
        // If the list is not empty, insert the new node at the end
        newMedication->prev = list->tail;
        list->tail->next = newMedication;
        list->tail = newMedication;
    }

    printf("Medication added successfully.\n");
}

// Function to display all medications in the list
void displayMedications(const struct MedicationList* list) {
    struct Medication* current = list->head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: $%.2f\n", current->id, current->name, current->quantity, current->price);
        current = current->next;
    }
}

// Function to search for a medication by ID
struct Medication* searchMedication(const struct MedicationList* list, int id) {
    struct Medication* current = list->head;
    while (current != NULL) {
        if (current->id == id) {
            return current; // Medication found
        }
        current = current->next;
    }
    return NULL; // Medication not found
}

// Function to delete a medication by ID
void deleteMedication(struct MedicationList* list, int id) {
    struct Medication* current = list->head;
    while (current != NULL) {
        if (current->id == id) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            free(current);
            printf("Medication with ID %d deleted successfully.\n", id);
            return;
        }
        current = current->next;
    }

    printf("Medication with ID %d not found.\n", id);
}

// Function to free memory when the linked list is destroyed
void destroyList(struct MedicationList* list) {
    struct Medication* current = list->head;
    while (current != NULL) {
        struct Medication* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct MedicationList medicationList;
    initializeList(&medicationList);

    int choice;
    do {
        printf("\nPharmacy Management System\n");
        printf("1. Insert Medication\n");
        printf("2. Display Medications\n");
        printf("3. Search Medication\n");
        printf("4. Delete Medication\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, quantity;
                char name[100];
                float price;

                printf("Enter Medication ID: ");
                scanf("%d", &id);

                printf("Enter Medication Name: ");
                scanf("%s", name);

                printf("Enter Medication Quantity: ");
                scanf("%d", &quantity);

                printf("Enter Medication Price: ");
                scanf("%f", &price);

                insertMedication(&medicationList, id, name, quantity, price);
                break;
            }
            case 2:
                displayMedications(&medicationList);
                break;
            case 3: {
                int searchId;
                printf("Enter the ID of the medication to search: ");
                scanf("%d", &searchId);

                struct Medication* foundMedication = searchMedication(&medicationList, searchId);
                if (foundMedication != NULL) {
                    printf("Medication with ID %d found: %s\n", searchId, foundMedication->name);
                } else {
                    printf("Medication with ID %d not found.\n", searchId);
                }
                break;
            }
            case 4: {
                int deleteId;
                printf("Enter the ID of the medication to delete: ");
                scanf("%d", &deleteId);
                deleteMedication(&medicationList, deleteId);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    // Free memory when the program exits
    destroyList(&medicationList);

    return 0;
}