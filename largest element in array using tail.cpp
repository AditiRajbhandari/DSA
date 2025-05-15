#include <stdio.h>

// Tail recursive function to find the largest element
int findMax(int arr[], int n, int maxVal) {
    if (n == 0)  
        return maxVal;  // Base case: return maxVal when array is fully traversed

    if (arr[n - 1] > maxVal)  
        maxVal = arr[n - 1];  // Update maxVal if current element is larger

    return findMax(arr, n - 1, maxVal);  // Tail recursive call with smaller array size
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the recursive function starting with the first element as max
    int maxElement = findMax(arr, n, arr[0]);

    printf("Largest element: %d\n", maxElement);
    getchar(); 
    getchar(); 
    return 0;
}

