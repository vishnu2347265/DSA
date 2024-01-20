#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Medication;

int comparisons = 0;
int dataTransfers = 0;

void resetMetrics() {
    comparisons = 0;
    dataTransfers = 0;
}

void printMetrics(const char *operation) {
    printf("\nMetrics for %s:\n", operation);
    printf("Total Element Comparisons: %d\n", comparisons);
    printf("Total Data Transfer Operations: %d\n", dataTransfers);
}

void printMedications(Medication meds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%s (%d)] ", meds[i].name, meds[i].quantity);
    }
    printf("\n");
}

int linearSearch(Medication meds[], int n, const char *target) {
    resetMetrics();

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (strcmp(meds[i].name, target) == 0) {
            return i;
        }
    }

    return -1;
}

int sentinelSearch(Medication meds[], int n, const char *target) {
    resetMetrics();

    // Add a sentinel entry with the target name
    strcpy(meds[n].name, target);

    int i = 0;
    while (strcmp(meds[i].name, target) != 0) {
        comparisons++;
        i++;
    }

    if (i < n) {
        return i;
    } else {
        return -1;
    }
}

int binarySearch(Medication meds[], int n, const char *target) {
    resetMetrics();

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;

        if (strcmp(meds[mid].name, target) == 0) {
            return mid;
        } else if (strcmp(meds[mid].name, target) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void bubbleSort(Medication meds[], int n) {
    resetMetrics();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (strcmp(meds[j].name, meds[j + 1].name) > 0) {
                Medication temp = meds[j];
                meds[j] = meds[j + 1];
                meds[j + 1] = temp;
                dataTransfers++;
            }
        }
    }
}

void insertionSort(Medication meds[], int n) {
    resetMetrics();

    int i, j;
    Medication key;

    for (i = 1; i < n; ++i) {
        key = meds[i];
        j = i - 1;

        while (j >= 0 && strcmp(meds[j].name, key.name) > 0) {
            comparisons++;
            meds[j + 1] = meds[j];
            dataTransfers++;
            --j;
        }

        meds[j + 1] = key;
        dataTransfers++;
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
    int opt;
    char target[50];
    int result;

    while (1) {
        printf("\n");
        printf(" +------------Pharmacy Menu------------+\n");
        printf(" | 1. Linear Search                    |\n");
        printf(" | 2. Sentinel Search                  |\n");
        printf(" | 3. Binary Search                    |\n");
        printf(" | 4. Bubble Sort                      |\n");
        printf(" | 5. Insertion Sort                   |\n");
        printf(" | 6. Display Medications             |\n");
        printf(" | 7. Exit                            |\n");
        printf(" +-----------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the medication name to search: ");
                scanf("%s", target);
                result = linearSearch(medications, size, target);
                if (result != -1) {
                    printf("\nMedication %s found at index %d\n", target, result);
                    printMetrics("Linear Search (Medications)");
                } else {
                    printf("\nMedication %s not found.\n", target);
                }
                break;
            case 2:
                printf("Enter the medication name to search: ");
                scanf("%s", target);
                result = sentinelSearch(medications, size, target);
                if (result != -1) {
                    printf("\nMedication %s found at index %d\n", target, result);
                    printMetrics("Sentinel Search (Medications)");
                } else {
                    printf("\nMedication %s not found.\n", target);
                }
                break;
            case 3:
                printf("Enter the medication name to search: ");
                scanf("%s", target);
                result = binarySearch(medications, size, target);
                if (result != -1) {
                    printf("\nMedication %s found at index %d\n", target, result);
                    printMetrics("Binary Search (Medications)");
                } else {
                    printf("\nMedication %s not found.\n", target);
                }
                break;
            case 4:
                bubbleSort(medications, size);
                printf("\nMedications after Bubble Sort:\n");
                printMedications(medications, size);
                printMetrics("Bubble Sort (Medications)");
                break;
            case 5:
                insertionSort(medications, size);
                printf("\nMedications after Insertion Sort:\n");
                printMedications(medications, size);
                printMetrics("Insertion Sort (Medications)");
                break;
            case 6:
                printf("Medications: ");
                printMedications(medications, size);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid option. Please enter a valid choice.\n");
        }
    }

    return 0;
}