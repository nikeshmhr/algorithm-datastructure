#include <stdio.h>
#include "minheap.h"

int main() {
    Heap heap;

    init_heap(&heap);
    insert(&heap, 35);
    insert(&heap, 33);
    insert(&heap, 42);
    insert(&heap, 10);
    insert(&heap, 14);
    insert(&heap, 19);
    insert(&heap, 27);
    insert(&heap, 44);
    insert(&heap, 26);
    insert(&heap, 31);
    
    print_heap(&heap);
    
    int poll = poll_item(&heap);
    printf("POLLED %d\n", poll);
    
    print_heap(&heap);
    
    int peeked = peek(heap.data);
    printf("PEEKED %d\n", peeked);
    
    print_heap(&heap);
    
    return 0;
}
