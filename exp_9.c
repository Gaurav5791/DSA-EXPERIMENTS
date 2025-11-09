#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

// Function to insert an element
void insert() {
    char item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\nQueue Overflow!");
        return;
    }
    printf("\nEnter the element to insert: ");
    scanf(" %c", &item);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = item;
    printf("\n%c inserted into the Circular Queue.", item);
}

// Function to delete an element
void delete() {
    if (front == -1) {
        printf("\nQueue Underflow!");
        return;
    }

    char item = queue[front];
    printf("\nDeleted element: %c", item);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

// Function to display queue elements
void display() {
    if (front == -1) {
        printf("\nQueue is Empty!");
        return;
    }

    printf("\nCircular Queue elements are: ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;
    printf("Circular Queue Operations\n");

    while (1) {
        printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }

    return 0;
}
