#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node after a specific node in the linked list
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert nodes into the linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    // Insert more nodes into the linked list
    insertAfter(head, 2);  // Insert 2 after head
    insertAfter(head->next, 3);  // Insert 3 after node with data 2

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    return 0;
}
