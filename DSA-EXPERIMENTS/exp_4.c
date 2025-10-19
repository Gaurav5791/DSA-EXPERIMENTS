#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

void deleteNode(Node** head, Node* nodeToDelete) {
    if (*head == nodeToDelete) {
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
        } else {
            Node* temp = *head;
            while (temp->next != *head) temp = temp->next;
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
    } else {
        Node* temp = *head;
        while (temp->next != nodeToDelete && temp->next != *head) temp = temp->next;
        if (temp->next == nodeToDelete) {
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
        }
    }
}

void deleteFromBeginning(Node** head) {
    if (*head != NULL) deleteNode(head, *head);
}

void deleteFromEnd(Node** head) {
    if (*head != NULL) {
        Node* temp = *head;
        while (temp->next->next != *head) temp = temp->next;
        deleteNode(head, temp->next);
    }
}

void deleteElement(Node** head, int data) {
    if (*head != NULL) {
        Node* temp = *head;
        do {
            if (temp->data == data) {
                deleteNode(head, temp);
                return;
            }
            temp = temp->next;
        } while (temp != *head);
    }
}

void displayList(Node* head) {
    if (head != NULL) {
        Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("List elements: ");
    displayList(head);

    deleteFromBeginning(&head);
    printf("List elements after deleting from beginning: ");
    displayList(head);

    deleteFromEnd(&head);
    printf("List elements after deleting from end: ");
    displayList(head);

    deleteElement(&head, 3);
    printf("List elements after deleting 3: ");
    displayList(head);

return 0;
}