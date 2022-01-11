#include <stdio.h>
#include <stdlib.h>

typedef struct Node;
{
    int id;
    struct Node* next;

} Node;


int main(){
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node15 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));


    node1 -> next = node2;
    node2 -> next = node3;

    node15 -> next = node1 -> next;
    node1 -> next = node15;

    node1 -> next = node15 -> next;
    free(node15);


}