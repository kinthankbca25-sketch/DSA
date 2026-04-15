#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Helper: Insert at end (to create list easily)
void insert_at_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = head;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
}

// 1. Delete from Beginning
void delete_from_the_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* curr = head;
    head = head->next;
    free(curr);
}

// 2. Delete End Node
void delete_the_end_node() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // If only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* curr = head;

    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}

// 3. Delete Node with Given Data
void delete_node_with_givenData(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    // If head node has the data
    if (head->data == data) {
        head = head->next;
        free(curr);
        return;
    }

    // Search for the node
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    // If data not found
    if (curr == NULL) {
        printf("Data not found\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
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
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);

    traverse();

    delete_from_the_beginning();
    traverse();

    delete_the_end_node();
    traverse();

    delete_node_with_givenData(20);
    traverse();

    return 0;
}