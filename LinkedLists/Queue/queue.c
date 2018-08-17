#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(Node *head, Node *tail, int value) 
{
    Node node = malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    if(*head == NULL && *tail == NULL) {
        *tail = *head = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
}

void print(Node *head) 
{
    for(Node n = *head; n != NULL; n=n->next)
    {
        printf("%d ", n->value);
    }
    printf("\n");
}

int dequeue(Node *head, Node *tail) 
{
    if(is_empty(head, tail)) {
        return -1;
    }

    Node temp = *head;

    // If head and tail points at same address
    // We know that its the last element
    // So assign null to both head & tail and free the pointer
    if(head == tail) {
        *head = *tail = NULL;
    } else {
        *head = (*head)->next;
    }

    int value = temp->value;
    free(temp);

    return value;
}

int is_empty(Node *head, Node *tail) {
    return *head == NULL && *tail == NULL;
}