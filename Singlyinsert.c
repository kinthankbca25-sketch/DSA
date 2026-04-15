#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// 1. Insert at Beginning
void insert_at_beginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// 2. Insert at End
void insert_at_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = head;

    newNode->data = data;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to last node
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
}

// 3. Insert After Key
void insert_after_key(int key, int data) {
    struct Node* curr = head;

    // Search for key
    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    // If key found
    if (curr != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = curr->next;
        curr->next = newNode;
    } else {
        printf("Key not found!\n");
    }
}

// 4. Traverse List
void traverse() {
    struct Node* curr = head;

    if (curr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
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

    traverse();

    return 0;
}