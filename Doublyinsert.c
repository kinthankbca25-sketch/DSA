#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Node
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

// Head pointer
struct DoublyNode* head = NULL;

// 1. Insert at Beginning
void insert_at_beginning(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// 2. Insert After Key
void insert_after_key(int key, int data) {
    struct DoublyNode* curr = head;

    // Search for key
    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Key not found!\n");
        return;
    }

    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));

    newNode->data = data;
    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = newNode;
    }

    curr->next = newNode;
}

// 3. Insert at End
void insert_at_end(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    struct DoublyNode* curr = head;

    newNode->data = data;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    // Traverse to last node
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;
}

// 4. Traverse Forward
void traverse_forward() {
    struct DoublyNode* curr = head;

    if (curr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List (Forward): ");
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// 5. Traverse Backward
void traverse_backward() {
    struct DoublyNode* curr = head;

    if (curr == NULL) {
        printf("List is empty\n");
        return;
    }

    // Find the last node
    while (curr->next != NULL) {
        curr = curr->next;
    }

    printf("Doubly Linked List (Backward): ");
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}

// Main Function
int main() {
    insert_at_beginning(10);
    insert_at_beginning(5);
    insert_at_end(20);
    insert_at_end(30);

    insert_after_key(20, 25);

    traverse_forward();

    traverse_backward();

    return 0;
}