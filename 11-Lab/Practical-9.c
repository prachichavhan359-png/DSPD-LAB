#include<stdio.h>
#define SIZE 7

int main() {
    int hashTable[SIZE];
    int keys[SIZE];
    int n,i,ind;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    for (i = 0; i < n; i++) {
        ind = keys[i] % SIZE;

        while (hashTable[ind] != -1) {
            ind = (ind + 1) % SIZE;
        }

        hashTable[ind] = keys[i];
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Slot %d --> %d\n", i, hashTable[i]);

    return 0;
}