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

// 1. Insert at End
void insert_at_end(struct CircularLinkedList* list, int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;

    // If list is empty
    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
        return;
    }

    struct CircularNode* curr = list->head;

    // Find last node
    while (curr->next != list->head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = list->head;
}

// 2. Delete Node with Given Data
void delete_node(struct CircularLinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode *curr = list->head, *prev = NULL;

    // Case 1: Only one node
    if (curr->next == curr && curr->data == data) {
        free(curr);
        list->head = NULL;
        return;
    }

    // Case 2: Deleting head node
    if (curr->data == data) {
        // Find last node
        while (curr->next != list->head) {
            curr = curr->next;
        }

        struct CircularNode* last = curr;
        curr = list->head;

        last->next = curr->next;
        list->head = curr->next;
        free(curr);
        return;
    }

    // Case 3: Deleting non-head node
    curr = list->head;
    prev = NULL;

    do {
        prev = curr;
        curr = curr->next;

        if (curr->data == data) {
            prev->next = curr->next;
            free(curr);
            return;
        }

    } while (curr != list->head);

    printf("Data not found\n");
}

// Helper: Traverse (for testing)
void traverse(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode* curr = list->head;

    printf("Circular List: ");
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

    insert_at_end(&list, 10);
    insert_at_end(&list, 20);
    insert_at_end(&list, 30);
    insert_at_end(&list, 40);

    traverse(&list);

    delete_node(&list, 10); // delete head
    traverse(&list);

    delete_node(&list, 30); // delete middle
    traverse(&list);

    delete_node(&list, 40); // delete end
    traverse(&list);

    return 0;
}