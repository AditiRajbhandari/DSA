#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a; // Base case
    return gcd(b, a % b); // Recursive case
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    getchar(); 
    getchar(); 
    return 0;
}

