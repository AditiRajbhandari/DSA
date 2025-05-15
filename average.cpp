#include <stdio.h>

int main() {
    int n, i, num, sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
    }

    average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
    return 0;
}
