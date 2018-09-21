#include <stdio.h>
#include "maxheap.h"

int main() {
    Heap heap;

    init_heap(&heap);
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 33);
    insert(&heap, 4);
    insert(&heap, 55);
    insert(&heap, 33);
    
    print_heap(&heap);
    
    int poll = poll_item(&heap);
    printf("POLLED %d\n", poll);
    
    print_heap(&heap);
    
    int peeked = peek(heap.data);
    printf("PEEKED %d\n", peeked);
    
    print_heap(&heap);
    
    return 0;
}
