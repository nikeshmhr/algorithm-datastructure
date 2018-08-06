#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main()
{

    // Node head;
    // head.next = NULL;

    // push(&head, 1);
    // // push(&head, 2);
    // printStack(&head);
    // printf("NODE VALUE: %d", head.value);

    // Node n = {NULL, 1};
    // Node *tail = malloc(sizeof(Node));
    // Node *head = tail;

    // printf("Address of head %p\n", head);
    // printf("Address of n %p\n", &n);
    // printf("Address of tail %p\n", tail);

    /*
    STACK OPERATIONS
    */
    Node head = NULL;
    for (int i = 0; i < 10; i++)
    {
        push(&head, i);
    }

    printf("\nPrinting stack: \n");
    print(&head);

    printf("\nPopping element: \n");
    for (int i = 0; i < 8; i++)
    {
        pop(&head);
    }

    print(&head);

    return 0;
}