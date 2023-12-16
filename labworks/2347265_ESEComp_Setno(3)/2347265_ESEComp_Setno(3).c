#include <stdio.h>

#define MAX_SIZE 100

struct Patient {
    int PatientID;
    char Name[50];
    int Age;
    int SeverityLevel; 
};

struct PriorityQueue {
    struct Patient patients[MAX_SIZE];
    int size;
};

void swap(struct Patient *a, struct Patient *b) {
    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && pq->patients[index].SeverityLevel < pq->patients[parent].SeverityLevel) {
        swap(&pq->patients[index], &pq->patients[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void addPatient(struct PriorityQueue *pq) {
    struct Patient newPatient;

    printf("Enter Patient ID: ");
    scanf("%d", &newPatient.PatientID);

    printf("Enter Name: ");
    scanf("%s", newPatient.Name); 

    printf("Enter Age: ");
    scanf("%d", &newPatient.Age);

    do {
        printf("Enter Severity Level (1 to 5): ");
        scanf("%d", &newPatient.SeverityLevel);

        if (newPatient.SeverityLevel < 1 || newPatient.SeverityLevel > 5) {
            printf("Invalid severity level. It should be between 1 and 5.\n");
        }
    } while (newPatient.SeverityLevel < 1 || newPatient.SeverityLevel > 5);

    if (pq->size == MAX_SIZE) {
        printf("Priority Queue is full. Cannot add more patients.\n");
        return;
    }

    pq->patients[pq->size] = newPatient;
    pq->size++;

    heapifyUp(pq, pq->size - 1);
}

void displayPatients(struct PriorityQueue *pq) {
    int i;
    printf("Patient Records:\n");
    for (i = 0; i < pq->size; i++) {
        printf("PatientID: %d, Name: %s, Age: %d, Severity Level: %d\n",
               pq->patients[i].PatientID, pq->patients[i].Name,
               pq->patients[i].Age, pq->patients[i].SeverityLevel);
    }
}

void displayHighestPriority(struct PriorityQueue *pq) {
    if (pq->size > 0) {
        printf("Patient with Highest Priority:\n");
        printf("PatientID: %d, Name: %s, Age: %d, Severity Level: %d\n",
               pq->patients[0].PatientID, pq->patients[0].Name,
               pq->patients[0].Age, pq->patients[0].SeverityLevel);
    } else {
        printf("Priority Queue is empty.\n");
    }
}

void displayFrequencyCount(struct PriorityQueue *pq) {
    int i;
    int frequency[5] = {0};

    for (i = 0; i < pq->size; i++) {
        frequency[pq->patients[i].SeverityLevel - 1]++;
    }

    printf("Frequency Count of Patients for Each Priority Value:\n");
    for (i = 0; i < 5; i++) {
        printf("Priority %d: %d patients\n", i + 1, frequency[i]);
    }
}

int main() {
    struct PriorityQueue priorityQueue = {0};
    int choice;

    do {
        printf("\n1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Display Highest Priority Patient\n");
        printf("4. Display Frequency Count\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(&priorityQueue);
                break;
            case 2:
                displayPatients(&priorityQueue);
                break;
            case 3:
                displayHighestPriority(&priorityQueue);
                break;
            case 4:
                displayFrequencyCount(&priorityQueue);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
