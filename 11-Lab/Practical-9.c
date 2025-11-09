#include <stdio.h>

#define SIZE 7

int main() {
    int hashTable[SIZE];
    int n, key, index, i;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % SIZE;
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Slot %d : %d\n", i, hashTable[i]);

    return 0;
}

