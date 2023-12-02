#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
    struct medicine *next;
};

struct medicine *firstMedicine, *lastMedicine, *tempMedicine;

int addMedicine() {
    char ch;
    while(1) {
        tempMedicine = (struct medicine*)malloc(sizeof(struct medicine));
        if(tempMedicine == NULL) {
            printf("Memory allocation error!!");
            return 0;
        }
        printf("\nEnter Name of Medicine: ");
        scanf("%s", tempMedicine->name);
        printf("Enter Quantity: ");
        scanf("%d", &tempMedicine->quantity);
        printf("Enter Price: ");
        scanf("%f", &tempMedicine->price);
        tempMedicine->next = NULL;

        if(firstMedicine == NULL) {
            firstMedicine = tempMedicine;
            lastMedicine = tempMedicine;
        } else {
            lastMedicine->next = tempMedicine;
            lastMedicine = tempMedicine;
        }

        printf("Want to add more medicines to the inventory (Y/N): ");
        ch = getch();
        if(ch == 'n' || ch == 'N')
            return 0;
    }
}

void displayInventory() {
    tempMedicine = firstMedicine;
    if(tempMedicine == NULL) {
        printf("Inventory is empty!!\n");
        return;
    }
    while(tempMedicine != NULL) {
        printf("[%s - Quantity: %d - Price: $%.2f] <---", tempMedicine->name, tempMedicine->quantity, tempMedicine->price);
        tempMedicine = tempMedicine->next;
    }
}

void addNewMedicine() {
    tempMedicine = (struct medicine*)malloc(sizeof(struct medicine));
    if(tempMedicine == NULL) {
        printf("Memory allocation error!!");
        return;
    }
    printf("\nEnter Name of new Medicine: ");
    scanf("%s", tempMedicine->name);
    printf("Enter Quantity: ");
    scanf("%d", &tempMedicine->quantity);
    printf("Enter Price: ");
    scanf("%f", &tempMedicine->price);
    tempMedicine->next = NULL;

    if(firstMedicine == NULL) {
        firstMedicine = tempMedicine;
    } else {
        lastMedicine->next = tempMedicine;
    }
    lastMedicine = tempMedicine;
}

void sellMedicine() {
    if(firstMedicine == NULL) {
        printf("\nInventory is empty. No medicines to sell!\n");
    } else {
        tempMedicine = firstMedicine;
        firstMedicine = firstMedicine->next;
        free(tempMedicine);
        printf("\nMedicine sold and removed from inventory!\n");
    }
}

void searchInInventory() {
    char searchName[50];
    int position = 0, foundFlag = 0;
    tempMedicine = firstMedicine;
    printf("\nEnter name of the medicine you want to find: ");
    scanf("%s", searchName);
    while(tempMedicine != NULL) {
        position++;
        if(strcmpi(searchName, tempMedicine->name) == 0) {
            foundFlag = 1;
            printf("\nMedicine Found at Position %d\n", position);
            printf("Details: [%s - Quantity: %d - Price: $%.2f]\n", tempMedicine->name, tempMedicine->quantity, tempMedicine->price);
        }
        tempMedicine = tempMedicine->next;
    }
    if(foundFlag == 0) {
        printf("\nNo such medicine found in inventory!\n");
    }
}

void exitProgram() {
    tempMedicine = firstMedicine;
    while(tempMedicine != NULL) {
        struct medicine* nextNode = tempMedicine->next;
        free(tempMedicine);
        tempMedicine = nextNode;
    }
    exit(0);
}

int main() {
    int option;
    option = 0;
    firstMedicine = lastMedicine = tempMedicine = NULL;
    
    while(1) {
        printf("\n +------Pharmacy-Management-Menu------+\n");
        printf(" | 1. Add Medicines to Inventory      |\n");
        printf(" | 2. Display Inventory               |\n");
        printf(" | 3. Add New Medicine to Inventory   |\n");
        printf(" | 4. Sell Medicine                   |\n");
        printf(" | 5. Search in Inventory             |\n");
        printf(" | 6. Exit                            |\n");
        printf(" +------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: addMedicine(); break;
            case 2: displayInventory(); break;
            case 3: addNewMedicine(); break;
            case 4: sellMedicine(); break;
            case 5: searchInInventory(); break;
            case 6: exitProgram();
        }
    }
    return 0;
}
