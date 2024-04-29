#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** head1_ref, struct Node* head2) {
    if (*head1_ref == NULL) {
        *head1_ref = head2;
        return;
    }
    struct Node* current = *head1_ref;
    while (current->next != NULL)
        current = current->next;
    current->next = head2;
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
    // Initialize two empty linked lists
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Insert nodes into the first linked list
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);

    // Insert nodes into the second linked list
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 5);

    // Concatenate the second linked list to the end of the first linked list
    concatenateLists(&head1, head2);

    // Print the concatenated linked list
    printf("Concatenated Linked List: ");
    printList(head1);

    return 0;
}
