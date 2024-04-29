#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to new node
    new_node->data = new_data;
    // Set the next of new node as current head
    new_node->next = *head_ref;
    // Move the head to point to the new node
    *head_ref = new_node;
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

    // Insert nodes at the beginning of the linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    return 0;
}
