#include <stdio.h>

int main() {
    int n, i;
    int arr[100]; 
    int oddSum = 0, evenSum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)   
            evenSum += arr[i];
        else                    
            oddSum += arr[i];
    }

    printf("Sum of numbers at odd positions = %d\n", oddSum);
    printf("Sum of numbers at even positions = %d\n", evenSum);

    return 0;
}
