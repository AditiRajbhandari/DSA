#include <stdio.h>

// Function to find the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1)
        return n;  // Base case: Fibonacci(0) = 0, Fibonacci(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the term (n): ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        printf("The %d-th Fibonacci number is: %d\n", n, fibonacci(n));
    }
    getchar();  // Consume leftover newline character from scanf
    getchar(); 

    return 0;
}

