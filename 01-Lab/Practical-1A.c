#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int sumOdd = 0, sumEven = 0;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)
            sumEven += arr[i];
        else
            sumOdd += arr[i];
    }

    printf("Sum of numbers at odd positions = %d\n", sumOdd);
    printf("Sum of numbers at even positions = %d\n", sumEven);

    return 0;
}
