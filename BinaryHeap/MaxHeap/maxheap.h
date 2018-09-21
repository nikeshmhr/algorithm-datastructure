#ifndef MAXHEAP_H
#define MAXHEAP_H
#define HEAPIFY_UP (0)
#define HEAPIFY_DOWN (1)
#define INITIAL_HEAP_CAPACITY (2)

struct heap {
    int *data;
    int size;   // size currently in use
    int capacity; // total capacity
};

typedef struct heap Heap;

// Returns root element and deletes it from the tree
int poll_item(Heap *heap);

// Returns root element
int peek(int *a);

// Restore the structure of given heap
// Either heapyfies from top or bottom
void heapify(Heap *, int t_or_b);

// Insert into tree
void insert(Heap *heap, int value);

// Initializes heap
void init_heap(Heap *heap);

// Expands heap size
void expand_heap(Heap *heap);

// Swaps values of given two indices
void swap(Heap *heap, int i, int j);

// prints heap
void print_heap(Heap *heap);

#endif
