#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int start = 0, end = n - 1, mid;

    if (arr == NULL || n == 0) {
        return -1;
    }

    while (start <= end) {
        mid = (start + end) / 2;

        printf("Middle value = %d at index %d\n", arr[mid], mid);

        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            printf("Value is greater, new start index = %d\n", mid + 1);
            start = mid + 1;
        } else {
            printf("Value is smaller, new end index = %d\n", mid - 1);
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, key, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty.\n");
        return 0;
    }

    printf("Enter %d sorted numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Value found at index %d\n", result);
    else
        printf("Value not found.\n");

    return 0;
}
