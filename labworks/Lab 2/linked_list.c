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
};

// Linked list structure for managing medications
struct MedicationList {
    struct Medication* head; // Pointer to the first node in the linked list
};

// Function to initialize the linked list
void initializeList(struct MedicationList* [__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2) {
    list->head = NULL;
}

// Function to insert a new medication at the beginning of the list
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
    newMedication->next = list->head;
    list->head = newMedication;
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
    struct Medication* prev = NULL;

    // Search for the medication to delete
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    // If medication is found, delete it
    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            list->head = current->next;
        }
        free(current);
        printf("Medication with ID %d deleted.\n", id);
    } else {
        printf("Medication with ID %d not found.\n", id);
    }
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
    // Create a linked list for medications
    struct MedicationList medicationList;
    initializeList(&medicationList);

    // Insert some medications
    insertMedication(&medicationList, 1, "Aspirin", 100, 5.99);
    insertMedication(&medicationList, 2, "Ibuprofen", 50, 8.99);
    insertMedication(&medicationList, 3, "Paracetamol", 75, 4.99);

    // Display all medications
    printf("Medications in the Pharmacy:\n");
    displayMedications(&medicationList);

    // Search for a medication by ID
    int searchId;
    printf("Enter the ID of the medication to search: ");
    scanf("%d", &searchId);

    struct Medication* foundMedication = searchMedication(&medicationList, searchId);
    if (foundMedication != NULL) {
        printf("Medication with ID %d found: %s\n", searchId, foundMedication->name);
    } else {
        printf("Medication with ID %d not found.\n", searchId);
    }

    // Delete a medication by ID
    int deleteId;
    printf("Enter the ID of the medication to delete: ");
    scanf("%d", &deleteId);
    deleteMedication(&medicationList, deleteId);

    // Display the updated list of medications
    printf("Updated Medications in the Pharmacy:\n");
    displayMedications(&medicationList);

    // Free memory when the program exits
    destroyList(&medicationList);

    return 0;
}
