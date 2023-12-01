#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[50];
    struct medicine *next;
};

struct medicine *front = NULL, *last = NULL;

int numberOfMedicines = 0;

void addMedicine() {
    struct medicine *newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error!!");
        return;
    }

    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);

    newptr->next = NULL;

    if (front == NULL) {
        front = last = newptr;
    } else {
        last->next = newptr;
        last = newptr;
    }

    numberOfMedicines++;
    printf("\nMedicine added to the inventory!\n");
}

void displayInventory() {
    struct medicine *temp = front;

    if (temp == NULL) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Medicine Inventory: ");
    while (temp != NULL) {
        printf("[%s] <-- ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addMedicineToFront() {
    struct medicine *newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error!!");
        return;
    }

    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);

    newptr->next = NULL;

    if (front == NULL) {
        front = last = newptr;
    } else {
        newptr->next = front;
        front = newptr;
    }

    numberOfMedicines++;
    printf("\nMedicine added to the front of the inventory!\n");
}

void addMedicineToRear() {
    struct medicine *newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error!!");
        return;
    }

    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);

    newptr->next = NULL;

    if (front == NULL) {
        front = last = newptr;
    } else {
        last->next = newptr;
        last = newptr;
    }

    numberOfMedicines++;
    printf("\nMedicine added to the rear of the inventory!\n");
}

void removeMedicineFromFront() {
    if (front == NULL) {
        printf("\nInventory is empty. No medicines to remove!\n");
    } else {
        struct medicine *temp = front;
        if (front == last) {
            front = last = NULL;
        } else {
            front = front->next;
        }
        free(temp);
        numberOfMedicines--;
        printf("\nMedicine removed from the front of the inventory!\n");
    }
}

void removeMedicineFromRear() {
    if (front == NULL) {
        printf("\nInventory is empty. No medicines to remove!\n");
    } else {
        struct medicine *temp = front;
        struct medicine *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
            last = prev;
        } else {
            front = last = NULL;
        }

        free(temp);
        numberOfMedicines--;
        printf("\nMedicine removed from the rear of the inventory!\n");
    }
}

void searchMedicine() {
    char searchName[50];
    int position = 0, foundFlag = 0;
    struct medicine *temp = front;

    if (temp == NULL) {
        printf("\nInventory is empty. No medicines to search!\n");
        return;
    }

    printf("\nEnter name of the medicine you want to find: ");
    scanf("%s", searchName);

    while (temp != NULL) {
        position++;
        if (strcmpi(searchName, temp->name) == 0) {
            foundFlag = 1;
            printf("\nMedicine Found at Position %d\n", position);
            printf("Details: [%s]\n", temp->name);
            break;
        }
        temp = temp->next;
    }

    if (foundFlag == 0) {
        printf("\nNo such medicine found in the inventory!\n");
    }
}

void exitProgram() {
    struct medicine *temp = front;
    while (temp != NULL) {
        struct medicine *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    exit(0);
}

int main() {
    int opt;

    while (1) {
        printf("\n");
        printf(" +------Pharmacy-Management-Menu------+\n");
        printf(" | 1. Add Medicine to Inventory        |\n");
        printf(" | 2. Display Inventory               |\n");
        printf(" | 3. Add Medicine to Front           |\n");
        printf(" | 4. Add Medicine to Rear            |\n");
        printf(" | 5. Remove Medicine from Front      |\n");
        printf(" | 6. Remove Medicine from Rear       |\n");
        printf(" | 7. Search for Medicine             |\n");
        printf(" | 8. Exit                            |\n");
        printf(" +-----------------------------------+\n");
        printf("Enter your option : ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addMedicineToFront();
                break;
            case 4:
                addMedicineToRear();
                break;
            case 5:
                removeMedicineFromFront();
                break;
            case 6:
                removeMedicineFromRear();
                break;
            case 7:
                searchMedicine();
                break;
            case 8:
                exitProgram();
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }

    return 0;
}
