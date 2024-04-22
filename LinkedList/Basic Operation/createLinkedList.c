#include <stdio.h> // standard input and output
#include <stdlib.h> //for malloc and exit function

// Define the structure for each node in the linked list
struct Node {
    int data;//value of the node to be stored
    struct Node* next; //to store a pointer to the next node in the list
};

// Function to create a new node
struct Node* createNode(int data) {
    //dyanmically allocating memory for a new node 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the linked list implementation
int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtBeginning(&head, 77);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    return 0;
}
