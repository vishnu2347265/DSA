#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Medication;

int linearSearch(Medication arr[], int size, char* target, int* comparisons) {
    for (int i = 0; i < size; ++i) {
        (*comparisons)++;
        if (strcmp(arr[i].name, target) == 0) {
            return i;
        }
    }
    return -1;
}

int sentinelSearch(Medication arr[], int size, char* target, int* comparisons) {
    strcpy(arr[size].name, target);

    int i = 0;
    while (strcmp(arr[i].name, target) != 0) {
        (*comparisons)++;
        ++i;
    }

    if (i < size) {
        return i;
    } else {
        return -1;
    }
}

int binarySearch(Medication arr[], int size, char* target, int* comparisons) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        (*comparisons)++;
        mid = (low + high) / 2;

        if (strcmp(arr[mid].name, target) == 0) {
            return mid;
        } else if (strcmp(arr[mid].name, target) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void bubbleSort(Medication arr[], int size, int* elementComparisons, int* dataTransfers) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            (*elementComparisons)++;
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                Medication temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*dataTransfers)++;
            }
        }
    }
}

void insertionSort(Medication arr[], int size, int* elementComparisons, int* dataTransfers) {
    int i, j;
    Medication key;

    for (i = 1; i < size; ++i) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && strcmp(arr[j].name, key.name) > 0) {
            (*elementComparisons)++;
            arr[j + 1] = arr[j];
            (*dataTransfers)++;
            --j;
        }

        arr[j + 1] = key;
        (*dataTransfers)++;
    }
}

void displayMedications(Medication arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s (%d)\n", arr[i].name, arr[i].quantity);
    }
}

int main() {
    Medication medications[] = {
        {"Aspirin", 100},
        {"Paracetamol", 50},
        {"Ibuprofen", 75},
        {"Amoxicillin", 30},
    };

    int size = sizeof(medications) / sizeof(medications[0]);

    printf("Original Medications:\n");
    displayMedications(medications, size);

    int bubbleElementComparisons = 0, bubbleDataTransfers = 0;
    bubbleSort(medications, size, &bubbleElementComparisons, &bubbleDataTransfers);

    printf("\nMedications after Bubble Sort:\n");
    displayMedications(medications, size);
    printf("Bubble Sort Comparisons: %d\n", bubbleElementComparisons);
    printf("Bubble Sort Data Transfers: %d\n", bubbleDataTransfers);

    int insertionElementComparisons = 0, insertionDataTransfers = 0;
    insertionSort(medications, size, &insertionElementComparisons, &insertionDataTransfers);

    printf("\nMedications after Insertion Sort:\n");
    displayMedications(medications, size);
    printf("Insertion Sort Comparisons: %d\n", insertionElementComparisons);
    printf("Insertion Sort Data Transfers: %d\n", insertionDataTransfers);

    char linearTarget[] = "Paracetamol";
    int linearComparisons = 0;
    int linearResult = linearSearch(medications, size, linearTarget, &linearComparisons);

    if (linearResult != -1) {
        printf("\nLinear Search: %s found at index %d\n", linearTarget, linearResult);
    } else {
        printf("\nLinear Search: %s not found\n", linearTarget);
    }
    printf("Linear Search Comparisons: %d\n", linearComparisons);

    char sentinelTarget[] = "Ibuprofen";
    int sentinelComparisons = 0;
    int sentinelResult = sentinelSearch(medications, size, sentinelTarget, &sentinelComparisons);

    if (sentinelResult != -1) {
        printf("\nSentinel Search: %s found at index %d\n", sentinelTarget, sentinelResult);
    } else {
        printf("\nSentinel Search: %s not found\n", sentinelTarget);
    }
    printf("Sentinel Search Comparisons: %d\n", sentinelComparisons);

    char binaryTarget[] = "Aspirin";
    int binaryElementComparisons = 0;
    int binaryResult = binarySearch(medications, size, binaryTarget, &binaryElementComparisons);

    if (binaryResult != -1) {
        printf("\nBinary Search: %s found at index %d\n", binaryTarget, binaryResult);
    } else {
        printf("\nBinary Search: %s not found\n", binaryTarget);
    }
    printf("Binary Search Element Comparisons: %d\n", binaryElementComparisons);

    return 0;
}
