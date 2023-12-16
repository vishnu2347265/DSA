#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons);
int sentinelSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons);
int binarySearch(int arr[], int low, int high, int key, int *elementComparisons, int *indexComparisons);
void bubbleSort(int arr[], int n, int *comparisons, int *dataTransfers);
void insertionSort(int arr[], int n, int *comparisons, int *dataTransfers);

int main() {
    int n, key, i;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Linear search
    int linearElementComparisons = 0, linearIndexComparisons = 0;
    int linearResult = linearSearch(arr, n, key, &linearElementComparisons, &linearIndexComparisons);

    if (linearResult != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, linearResult);
    } else {
        printf("Linear Search: Element %d not found\n", key);
    }

    // Sentinel search
    int sentinelElementComparisons = 0, sentinelIndexComparisons = 0;
    int sentinelResult = sentinelSearch(arr, n, key, &sentinelElementComparisons, &sentinelIndexComparisons);

    if (sentinelResult != -1) {
        printf("Sentinel Search: Element %d found at index %d\n", key, sentinelResult);
    } else {
        printf("Sentinel Search: Element %d not found\n", key);
    }

    // Bubble sort
    int bubbleComparisons = 0, bubbleDataTransfers = 0;
    bubbleSort(arr, n, &bubbleComparisons, &bubbleDataTransfers);
    printf("Bubble Sort: Comparisons = %d, Data Transfers = %d\n", bubbleComparisons, bubbleDataTransfers);

    // Insertion sort
    int insertionComparisons = 0, insertionDataTransfers = 0;
    insertionSort(arr, n, &insertionComparisons, &insertionDataTransfers);
    printf("Insertion Sort: Comparisons = %d, Data Transfers = %d\n", insertionComparisons, insertionDataTransfers);

    // Binary search (requires a sorted array)
    int binaryElementComparisons = 0, binaryIndexComparisons = 0;
    int binaryResult = binarySearch(arr, 0, n - 1, key, &binaryElementComparisons, &binaryIndexComparisons);

    if (binaryResult != -1) {
        printf("Binary Search: Element %d found at index %d\n", key, binaryResult);
    } else {
        printf("Binary Search: Element %d not found\n", key);
    }

    return 0;
}

// Linear search function
int linearSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons) {
    for (int i = 0; i < n; i++) {
        (*elementComparisons)++;
        if (arr[i] == key) {
            (*indexComparisons)++;
            return i;
        }
    }
    return -1;
}

// Sentinel search function
int sentinelSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons) {
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;

    while (arr[i] != key) {
        (*elementComparisons)++;
        i++;
    }

    arr[n - 1] = last;

    if (i < n - 1 || arr[n - 1] == key) {
        (*indexComparisons)++;
        return i;
    }

    return -1;
}

// Binary search function
int binarySearch(int arr[], int low, int high, int key, int *elementComparisons, int *indexComparisons) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*elementComparisons)++;
        if (arr[mid] == key) {
            (*indexComparisons)++;
            return mid;
        }

        (*elementComparisons)++;
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Bubble sort function
void bubbleSort(int arr[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*dataTransfers)++;
            }
        }
    }
}

// Insertion sort function
void insertionSort(int arr[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        (*comparisons)++;
        while (j >= 0 && arr[j] > key) {
            // Shift elements greater than key to the right
            arr[j + 1] = arr[j];
            j--;
            (*dataTransfers)++;
            (*comparisons)++;
        }

        // Insert key into the correct position
        arr[j + 1] = key;
        (*dataTransfers)++;
    }
}
