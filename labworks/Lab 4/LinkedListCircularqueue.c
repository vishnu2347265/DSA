#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[50];
    int quantity;
    struct medicine *next;
};

struct medicine *front = NULL, *last = NULL;

void enqueueMedicine() {
    struct medicine *newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error!!");
        return;
    }

    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);

    printf("Enter Quantity: ");
    scanf("%d", &newptr->quantity);

    newptr->next = NULL;

    if (front == NULL) {
        front = last = newptr;
    } else {
        last->next = newptr;
        last = newptr;
    }

    // Make it circular
    last->next = front;

    printf("\nMedicine Enqueued!\n");
}

void dequeueMedicine() {
    if (front == NULL) {
        printf("\nThere are no Medicines in the Queue!\n");
    } else {
        struct medicine *temp = front;
        if (front == last) {
            front = last = NULL;
        } else {
            front = front->next;
            last->next = front;
        }
        free(temp);
        printf("\nMedicine Dequeued!\n");
    }
}

void peekMedicineQueue() {
    struct medicine *temp = front;

    if (temp == NULL) {
        printf("Medicine Queue is Empty!\n");
        return;
    }

    printf("Medicine Queue: ");
    do {
        printf("[%s, Quantity: %d] <-- ", temp->name, temp->quantity);
        temp = temp->next;
    } while (temp != front);
    printf("NULL\n");
}

void searchMedicineQueue() {
    char searchName[50];
    int pos = 0, foundFlag = 0;
    struct medicine *temp = front;

    if (temp == NULL) {
        printf("\nNo medicines in the queue!\n");
        return;
    }

    printf("\nEnter name of the medicine you want to find: ");
    scanf("%s", searchName);

    do {
        pos++;
        if (strcmpi(searchName, temp->name) == 0) {
            foundFlag = 1;
            printf("\nMedicine Found at Position %d\n", pos);
            printf("Details: [%s - Quantity: %d]\n", temp->name, temp->quantity);
            break;
        }
        temp = temp->next;
    } while (temp != front);

    if (foundFlag == 0) {
        printf("\nNo such medicine found in the queue!\n");
    }
}

void exitProgram() {
    struct medicine *temp = front;
    if (temp != NULL) {
        do {
            struct medicine *nextNode = temp->next;
            free(temp);
            temp = nextNode;
        } while (temp != front);
    }
    exit(0);
}

int main() {
    int opt;

    while (1) {
        printf("\n");
        printf(" +------Pharmacy-Management-Menu------+\n");
        printf(" | 1. Enqueue Medicine                |\n");
        printf(" | 2. Dequeue Medicine                |\n");
        printf(" | 3. Display Medicine Queue          |\n");
        printf(" | 4. Search in Medicine Queue        |\n");
        printf(" | 5. Exit                            |\n");
        printf(" +-----------------------------------+\n");
        printf("Enter your option : ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                enqueueMedicine();
                break;
            case 2:
                dequeueMedicine();
                break;
            case 3:
                peekMedicineQueue();
                break;
            case 4:
                searchMedicineQueue();
                break;
            case 5:
                exitProgram();
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }

    return 0;
}
