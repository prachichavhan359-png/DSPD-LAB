#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if(top == MAX-1) {
        printf("Stack Overflow! Cannot push %d\n", item);
    } else {
        stack[++top] = item;
        printf("%d pushed onto stack.\n", item);
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

void display() {
    int i;
    if(top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for(i=top; i>=0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void checkPalindrome() {
    char str[100];
    int i, len, flag=1;
    top=-1;
    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    len = strlen(str);
    for(i=0;i<len;i++) push(str[i]);
    for(i=0;i<len;i++) {
        if(str[i] != stack[top--]) {
            flag=0;
            break;
        }
    }
    if(flag==1) printf("The string is a Palindrome.\n");
    else printf("The string is NOT a Palindrome.\n");
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1.Push\n2.Pop\n3.Check Palindrome\n4.Demo Overflow/Underflow\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                for(int i=0;i<MAX+1;i++) push(i);
                for(int i=0;i<MAX+1;i++) pop();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
