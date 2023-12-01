#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    char expiryDate[15];
    struct medicine *next;
};

struct medicine *front = NULL;

void medicineEnqueue() {
    struct medicine *newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error!!");
        return;
    }

    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);

    printf("Enter Quantity: ");
    scanf("%d", &newptr->quantity);

    printf("Enter Expiry Date (dd-mm-yyyy): ");
    scanf("%s", newptr->expiryDate);

    newptr->next = NULL;

    if (front == NULL || strcmp(newptr->expiryDate, front->expiryDate) < 0) {
        newptr->next = front;
        front = newptr;
    } else {
        struct medicine *temp = front;
        while (temp->next != NULL && strcmp(newptr->expiryDate, temp->next->expiryDate) >= 0) {
            temp = temp->next;
        }
        newptr->next = temp->next;
        temp->next = newptr;
    }

    printf("\nMedicine Enqueued with Expiry Date %s!\n", newptr->expiryDate);
}

void medicineDequeue() {
    if (front == NULL) {
        printf("\nThere are no Medicines in the Expiry Date Queue!\n");
    } else {
        struct medicine *temp = front;
        front = front->next;
        free(temp);
        printf("\nMedicine with earliest Expiry Date Dequeued!\n");
    }
}

void peekExpiryDateQueue() {
    struct medicine *temp = front;

    if (temp == NULL) {
        printf("Expiry Date Queue is Empty!\n");
        return;
    }

    printf("Expiry Date Queue: ");
    while (temp != NULL) {
        printf("[%s, Quantity: %d, Expiry Date: %s] <-- ", temp->name, temp->quantity, temp->expiryDate);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int opt;

    while (1) {
        printf("\n");
        printf(" +---------Pharmacy-Management-Menu---------+\n");
        printf(" | 1. Enqueue Medicine with Expiry Date     |\n");
        printf(" | 2. Dequeue Medicine with Earliest Expiry|\n");
        printf(" | 3. Display Expiry Date Queue            |\n");
        printf(" | 4. Exit                                 |\n");
        printf(" +-----------------------------------------+\n");
        printf("Enter your option : ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                medicineEnqueue();
                break;
            case 2:
                medicineDequeue();
                break;
            case 3:
                peekExpiryDateQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Option! Please try again.\n");
        }
    }

    return 0;
}
