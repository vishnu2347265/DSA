#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Medication {
    char name[50];
    int quantity;
};

void merge(struct Medication arr[], int left, int mid, int right, int *comparisons, int *transfers) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Medication L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i].quantity <= R[j].quantity) {
            (*transfers)++;
            arr[k] = L[i];
            i++;
        } else {
            (*transfers)++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        (*transfers)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        (*transfers)++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Medication arr[], int left, int right, int *comparisons, int *transfers) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons, transfers);
        mergeSort(arr, mid + 1, right, comparisons, transfers);

        merge(arr, left, mid, right, comparisons, transfers);
    }
}

void printMedications(struct Medication arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%-20s - %d\n", arr[i].name, arr[i].quantity);
    }
}

void generateRandomData(struct Medication arr[], int size) {
    char medicationNames[][50] = {
        "Aspirin", "Ibuprofen", "Paracetamol", "Antibiotic", "Vitamin C",
        "Cough Syrup", "Painkiller", "Antacid", "Allergy Medication", "Insulin"
    };

    for (int i = 0; i < size; i++) {
        sprintf(arr[i].name, "%s", medicationNames[i]);
        arr[i].quantity = rand() % 50 + 10; // Quantity range: 10 to 59
    }
}

int main() {
    srand(time(NULL));

    int size = 10;
    struct Medication medications[size];

    int option;
    do {
        printf("\n +-------------------------------+\n");
        printf(" | 1. Generate Random Data       |\n");
        printf(" | 2. Sort Medications (Merge)   |\n");
        printf(" | 3. Display Medications        |\n");
        printf(" | 4. Exit                       |\n");
        printf(" +-------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                generateRandomData(medications, size);
                printf("Random data generated.\n");
                break;
            case 2: {
                int comparisonsMerge = 0, transfersMerge = 0;
                mergeSort(medications, 0, size - 1, &comparisonsMerge, &transfersMerge);
                printf("\nMedications after Merge Sort:\n");
                printMedications(medications, size);
                printf("Merge Sort Comparisons: %d\n", comparisonsMerge);
                printf("Merge Sort Data Transfers: %d\n", transfersMerge);
                break;
            }
            case 3:
                printf("Medications:\n");
                printMedications(medications, size);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please enter a valid choice.\n");
        }

    } while (option != 5);

    return 0;
}
