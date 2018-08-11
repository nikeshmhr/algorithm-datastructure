#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void push(Node *head, int value)
{
    Node node;

    node = malloc(sizeof(Node));
    node->value = value;
    node->next = *head;

    *head = node;
}

void print(const Node *head)
{
    Node node;
    for (node = *head; node->next != NULL; node = node->next)
    {
        printf("%d ", node->value);
    }
}

int empty(const Node *head)
{
    return (*head == 0);
}

int pop(Node *head)
{
    assert(!empty(head));
    int poppedValue = (*head)->value;

    Node top;

    top = *head;
    *head = top->next;

    free(top);

    return poppedValue;
}
