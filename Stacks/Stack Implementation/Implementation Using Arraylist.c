#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int* array;
    int size;
    int capacity;
} ArrayList;

// Function to create a new ArrayList
ArrayList* createArrayList() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (list->array == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

// Function to check if the ArrayList is empty
int isEmpty(ArrayList* list) {
    return (list->size == 0);
}

// Function to add an element to the end of the ArrayList
void add(ArrayList* list, int value) {
    if (list->size == list->capacity) {
        // Resize the array if it's full
        list->capacity *= 2;
        list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
        if (list->array == NULL) {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    list->array[list->size++] = value;
}

// Function to remove the last element from the ArrayList
void removeLast(ArrayList* list) {
    if (!isEmpty(list)) {
        list->size--;
    }
}

// Function to get the last element of the ArrayList without removing it
int getLast(ArrayList* list) {
    if (!isEmpty(list)) {
        return list->array[list->size - 1];
    }
    printf("ArrayList is empty\n");
    exit(EXIT_FAILURE);
}

// Function to free the memory allocated for the ArrayList
void freeArrayList(ArrayList* list) {
    free(list->array);
    free(list);
}

int main() {
    ArrayList* list = createArrayList();

    add(list, 10);
    add(list, 20);
    add(list, 30);

    printf("Last element: %d\n", getLast(list));

    removeLast(list);
    printf("Last element removed\n");

    printf("Last element: %d\n", getLast(list));

    freeArrayList(list);

    return 0;
}
