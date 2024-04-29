#include <stdio.h>
#include <stdlib.h>

//declaring the double linked list 
struct node {
    int data ;
    struct node *prev ;//ptr storing address of the previous node 
    struct node *next ;//ptr storing address of the next node 

}