#include <stdio.h>
#include "queue.h"

void main() {
    Node head, tail;
    head = tail = NULL;

    printf("IS QUEUE EMPTY : %d\n", is_empty(&head, &tail));
    enqueue(&head, &tail, 10);
    enqueue(&head, &tail, 20);
    enqueue(&head, &tail, 35);
    print(&head);
    dequeue(&head, &tail);
    print(&head);
    dequeue(&head, &tail);
    print(&head);
    dequeue(&head, &tail);
    print(&head);
}