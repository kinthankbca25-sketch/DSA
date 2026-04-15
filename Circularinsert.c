#include <stdio.h>
#include <stdlib.h>

// Structure for Circular Node
struct CircularNode {
    int data;
    struct CircularNode* next;
};

// Structure for Circular Linked List
struct CircularLinkedList {
    struct CircularNode* head;
};

// 1. Insert at Beginning
void insert_at_beginning(struct CircularLinkedList* list, int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;

    // If list is empty
    if (list->head == NULL) {
        newNode->next = newNode;  // Points to itself
        list->head = newNode;
        return;
    }

    struct CircularNode* curr = list->head;

    // Find last node
    while (curr->next != list->head) {
        curr = curr->next;
    }

    newNode->next = list->head;
    curr->next = newNode;
    list->head = newNode;
}

// 2. Traverse Circular List
void traverse(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode* curr = list->head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != list->head);

    printf("(back to head)\n");
}

// Main Function
int main() {
    struct CircularLinkedList list;
    list.head = NULL;

    insert_at_beginning(&list, 10);
    insert_at_beginning(&list, 20);
    insert_at_beginning(&list, 30);

    traverse(&list);

    return 0;
}