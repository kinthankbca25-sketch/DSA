#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Node
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

// Structure for Doubly Linked List
struct DoublyLinkedList {
    struct DoublyNode* head;
};

// Helper: Insert at end (to build list)
void insert_at_end(struct DoublyLinkedList* list, int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }

    struct DoublyNode* curr = list->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;
}

// 1. Delete first node with given data
void delete_node(struct DoublyLinkedList* list, int data) {
    struct DoublyNode* curr = list->head;

    while (curr != NULL && curr->data != data) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Data not found\n");
        return;
    }

    // If node is head
    if (curr->prev == NULL) {
        list->head = curr->next;
        if (list->head != NULL)
            list->head->prev = NULL;
    } else {
        curr->prev->next = curr->next;
    }

    // If node is not last
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }

    free(curr);
}

// 2. Delete end node
void delete_the_end_node(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct DoublyNode* curr = list->head;

    // If only one node
    if (curr->next == NULL) {
        free(curr);
        list->head = NULL;
        return;
    }

    // Traverse to last node
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->prev->next = NULL;
    free(curr);
}

// 3. Delete node with given data (same as delete_node)
void delete_node_with_givenData(struct DoublyLinkedList* list, int data) {
    delete_node(list, data);
}

// 4. Traverse Backward
void traverse_backward(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct DoublyNode* curr = list->head;

    // Move to last node
    while (curr->next != NULL) {
        curr = curr->next;
    }

    printf("Backward Traversal: ");
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}

// Main Function
int main() {
    struct DoublyLinkedList list;
    list.head = NULL;

    insert_at_end(&list, 10);
    insert_at_end(&list, 20);
    insert_at_end(&list, 30);
    insert_at_end(&list, 40);

    traverse_backward(&list);

    delete_node(&list, 20);
    traverse_backward(&list);

    delete_the_end_node(&list);
    traverse_backward(&list);

    delete_node_with_givenData(&list, 10);
    traverse_backward(&list);

    return 0;
}