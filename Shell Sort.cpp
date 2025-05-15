#include <stdio.h>

// Function to print the array with space between elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Added space for better readability
    }
    printf("\n");
}

// Function to implement Shell Sort
void ShellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                printArray(arr, n); // Print intermediate steps
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 56, 23, 7}; // Elements separated by spaces
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    ShellSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}

