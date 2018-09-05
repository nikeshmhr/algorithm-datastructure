#include <stdio.h>
#include "queue.h"

int main() {
    Node head, tail;
    head = tail = NULL;

    printf("IS QUEUE EMPTY : %d\n", is_empty(&head, &tail));
    for(int i = 0; i <= 20; i++) {
        int value = i * 2;
        enqueue(&head, &tail, value);
    }
    print(&head);
    dequeue(&head, &tail);
    print(&head);
    dequeue(&head, &tail);
    print(&head);
    dequeue(&head, &tail);
    print(&head);

    return 0;
}
