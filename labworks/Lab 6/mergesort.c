#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent medication information
struct Medication {
    char name[50];
    int quantity;
};

// Function to merge two sorted arrays
void merge(struct Medication arr[], int left, int mid, int right, int *comparisons, int *transfers) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    struct Medication L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

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

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        (*transfers)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        (*transfers)++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(struct Medication arr[], int left, int right, int *comparisons, int *transfers) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid, comparisons, transfers);
        mergeSort(arr, mid + 1, right, comparisons, transfers);

        // Merge the sorted halves
        merge(arr, left, mid, right, comparisons, transfers);
    }
}

// Function to print an array of medications
void printMedications(struct Medication arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s - %d\n", arr[i].name, arr[i].quantity);
    }
}

// Function to generate random medication data
void generateRandomData(struct Medication arr[], int size) {
    for (int i = 0; i < size; i++) {
        // Random medication name (for simplicity, using generic names)
        sprintf(arr[i].name, "Medication%d", i + 1);
        // Random quantity (for simplicity, using values between 1 and 100)
        arr[i].quantity = rand() % 100 + 1;
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Number of medications
    int size = 10;

    // Create an array of medications and generate random data
    struct Medication medications[size];
    generateRandomData(medications, size);

    printf("Original Medications:\n");
    printMedications(medications, size);

    int comparisonsMerge = 0, transfersMerge = 0;

    // Sort medications using Merge Sort
    mergeSort(medications, 0, size - 1, &comparisonsMerge, &transfersMerge);

    printf("\nMedications after Merge Sort:\n");
    printMedications(medications, size);
    printf("Merge Sort Comparisons: %d\n", comparisonsMerge);
    printf("Merge Sort Data Transfers: %d\n", transfersMerge);

    return 0;
}
