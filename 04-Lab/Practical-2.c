#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n"); } 
else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}


void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}


void display() {
int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void checkpali() {
    #define Size 100
    char Cstack[Size];
    int sTop = -1;
    char str1[100];
    char rev[100];
    int i;

    printf("Enter String To Check Palindrome: ");
    scanf("%s", str1);

    for (i = 0; i < strlen(str1); i++) {
        if (sTop < Size - 1) {
            Cstack[++sTop] = str1[i];
        }
    }

    for (i = 0; i < strlen(str1); i++) {
        rev[i] = Cstack[sTop--];
    }
    rev[i] = '\0';

    if (strcmp(str1, rev) == 0)
        printf("'%s' is a Palindrome.\n", str1);
    else
        printf("'%s' is not a Palindrome.\n", str1);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check Palindrome\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Element to Push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                    checkpali();
                    break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}