#include <stdio.h>
#include <stdlib.h> //for memory allocation function

// Define the structure for a node
struct Node {//structure named Node
    int data;//store the value of the node.
    struct Node* next;//pointer "next" to point to the next node in the linked list
};

// Function to traverse the linked list and print its elements
void traverseLinkedList(struct Node* head) {
    // Temporary pointer to traverse the list
    struct Node* current = head;//It initializes current with the address of the head node.

    // Traverse the list until the end (current becomes NULL)
    while (current != NULL) {
        // Print the data of the current node
        printf("%d -> ", current->data);//prints the data field of the current node using printf.

        // Move to the next node
        current = current->next;
    }

    // Print "NULL" to indicate the end of the list
    printf("NULL\n");
}

int main() {
    // Creating nodes for a simple linked list: 1 -> 2 -> 3 -> NULL

    // Creating the first node (head)
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;

    // Creating the second node
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;

    // Creating the third node
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;

    // Linking the nodes together
    head->next = second;
    second->next = third;
    third->next = NULL; // Marking the end of the list

    // Traversing and printing the linked list
    printf("Linked List: ");
    traverseLinkedList(head);

    // Freeing allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
