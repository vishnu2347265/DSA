#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
    struct medicine *next;
} *newptr, *first, *last, *temp, *prev, *next;

int numberOfMedicines = 0;

int create() {
    char ch;
    while (1) {
        newptr = (struct medicine *)malloc(sizeof(struct medicine));
        if (newptr == NULL) {
            printf("Memory allocation error");
            return 0;
        }
        printf("\nEnter Name of the medicine: ");
        scanf("%s", newptr->name);
        printf("Enter Quantity: ");
        scanf("%d", &newptr->quantity);
        printf("Enter Price: ");
        scanf("%f", &newptr->price);

        numberOfMedicines++;
        newptr->next = NULL;

        if (first == NULL)
            first = temp = newptr;
        else {
            temp->next = newptr;
            temp = temp->next;
        }

        printf("Want to add more medicines (Y/N): ");
        ch = getch();
        if (ch == 'n' || ch == 'N') {
            temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
                last = temp;
            }
            last->next = first;  // Circular linked list
            return 0;
        }

        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
            last = temp;
        }
    }
}

void display() {
    temp = first;
    if (temp == NULL) {
        printf("There are no medicines\n");
        return;
    }
    do {
        printf("[%s | Quantity: %d | Price: %.2f]--->", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    } while (temp != first);
    printf("(%s)", last->next->name);
}

void insert_beginning() {
    newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);
    printf("Enter Quantity: ");
    scanf("%d", &newptr->quantity);
    printf("Enter Price: ");
    scanf("%f", &newptr->price);

    numberOfMedicines++;
    newptr->next = NULL;

    if (first == NULL) {
        first = last = newptr;
    } else {
        newptr->next = first;
        first = newptr;
    }
    last->next = first;  // Circular linked list
}

void insert_end() {
    newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);
    printf("Enter Quantity: ");
    scanf("%d", &newptr->quantity);
    printf("Enter Price: ");
    scanf("%f", &newptr->price);

    numberOfMedicines++;
    newptr->next = NULL;

    temp = first;
    while (temp != NULL) {
        last = temp;
        temp = temp->next;
    }
    last->next = newptr;
    newptr->next = first;
}

void insert_middle() {
    int pos, c;
    c = 0;
    newptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (newptr == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("Enter Position for medicine to be inserted: ");
    scanf("%d", &pos);
    printf("\nEnter Name of new Medicine: ");
    scanf("%s", newptr->name);
    printf("Enter Quantity: ");
    scanf("%d", &newptr->quantity);
    printf("Enter Price: ");
    scanf("%f", &newptr->price);

    numberOfMedicines++;
    temp = first;
    while (temp != NULL) {
        c++;
        if (c == pos - 1) {
            next = temp->next;
            newptr->next = next;
            temp->next = newptr;
            break;
        }
        temp = temp->next;
    }
}

void delete_beginning() {
    if (first == NULL) {
        printf("\nThere are no Medicines");
    } else {
        temp = first;
        first = first->next;
        last->next = first;
        free(temp);
        numberOfMedicines--;
        printf("\nFirst Medicine deleted\n");
    }
}

void delete_end() {
    if (first == NULL) {
        printf("\nThere are no Medicines");
        return;
    }
    temp = first;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        last = temp;
    }
    prev->next = NULL;
    last = prev;
    printf("\nLast Medicine deleted\n");
    numberOfMedicines--;
    free(temp);
}

void delete_middle() {
    if (first == NULL) {
        printf("\nThere are no Medicines");
    } else {
        int pos, c;
        c = 0;
        printf("Enter the position of the medicine you want to delete: ");
        scanf("%d", &pos);

        temp = first;
        while (temp->next != NULL) {
            c++;
            if (c == pos - 1) {
                prev = temp;
                next = temp->next->next;
                free(temp->next);
                prev->next = next;
                printf("\nMedicine at position %d deleted\n", pos);
                numberOfMedicines--;
                break;
            }
            temp = temp->next;
        }
    }
}

void search() {
    char search_name[50];
    int pos, foundFlag = 0;
    pos = 0;
    temp = first;
    printf("\nEnter name of the Medicine you want to find: ");
    scanf("%s", search_name);
    do {
        pos++;
        if (strcmpi(search_name, temp->name) == 0) {
            foundFlag = 1;
            printf("\nMedicine Found at %d", pos);
            break;
        }
        temp = temp->next;
    } while (temp != first);
    if (foundFlag == 0) {
        printf("\nNo such Medicine found!");
    }
}

void exit_program() {
    temp = first;
    while (temp != NULL) {
        struct medicine *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    exit(0);
}

int main() {
    int opt;
    opt = 0;
    first = temp = NULL;

    while (1) {
        printf("\n");
        printf(" +---------Pharmacy-Management-Menu---------+\n");
        printf(" | 1. Create Medicines                     |\n");
        printf(" | 2. Display Medicines                    |\n");
        printf(" | 3. Insert Medicine at Beginning         |\n");
        printf(" | 4. Insert Medicine in the Middle        |\n");
        printf(" | 5. Insert Medicine at End               |\n");
        printf(" | 6. Delete Medicine at Beginning         |\n");
        printf(" | 7. Delete Medicine in the Middle        |\n");
        printf(" | 8. Delete Medicine at End               |\n");
        printf(" | 9. Search for Medicine                  |\n");
        printf(" | 10. Exit                                 |\n");
        printf(" +------------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beginning();
            break;
        case 4:
            numberOfMedicines >= 2 ? insert_middle() : printf("\nNeed More Than 1 Medicine\n");
            break;
        case 5:
            insert_end();
            break;
        case 6:
            delete_beginning();
            break;
        case 7:
            numberOfMedicines >= 2 ? delete_middle() : printf("\nNeed More Than 1 Medicine\n");
            break;
        case 8:
            delete_end();
            break;
        case 9:
            search();
            break;
        case 10:
            exit_program();
        }
        getch();
    }

    return 0;
}
