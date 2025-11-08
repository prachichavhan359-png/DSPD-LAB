#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

void insert(char item) {
    if(rear == MAX-1) {
        printf("Queue Overflow! Cannot insert %c\n", item);
    } else {
        if(front == -1) front = 0;
        queue[++rear] = item;
        printf("%c inserted into queue.\n", item);
    }
}

void delete() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to delete.\n");
    } else {
        printf("%c deleted from queue.\n", queue[front++]);
    }
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for(int i=front; i<=rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char value;
    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Demo Overflow/Underflow\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                for(int i=0; i<MAX+1; i++) insert('A'+(i%26));
                for(int i=0; i<MAX+1; i++) delete();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
