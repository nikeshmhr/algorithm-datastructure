#include "maxheap.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// helper functions
// all formulas are for 0 based indices

static int index_of_right_child(int parent_index) {
    return (parent_index * 2) + 2;
}

static int index_of_left_child(int parent_index) {
    return (parent_index * 2) + 1;
}

static int index_of_parent(int child_index) {
    return (child_index - 1) / 2;
}

static int right_child(Heap *heap, int parent_index) {
    int index = index_of_right_child(parent_index);
    assert(heap != NULL);
    assert(index >= 0 && index < heap->size);
    return heap->data[index];
}

static int left_child(Heap *heap, int parent_index) {
    int index = index_of_left_child(parent_index);
    assert(heap != NULL);
    assert(index >= 0 && index < heap->size);
    return heap->data[index];
}

static int parent(Heap *heap, int child_index) {
    int index = index_of_parent(child_index);
    assert(heap != NULL);
    assert(index >= 0 && index < heap->size);
    return heap->data[index];
}

static int has_right_child(Heap *heap, int parent) {
    int i = index_of_right_child(parent);
    return i > 0 && i < heap->size;
}

static int has_left_child(Heap *heap, int parent) {
    int i = index_of_left_child(parent);
    return i > 0 && i < heap->size;
}

// Heap operations implementation
void insert(Heap *heap, int value) {
    // Expand if needed
    expand_heap(heap);

    assert(heap->size < heap->capacity);

    heap->data[heap->size++] = value;

    heapify(heap, HEAPIFY_UP);
}

void init_heap(Heap *heap) {
    heap->capacity = INITIAL_HEAP_CAPACITY;
    heap->size = 0;
    heap->data = (int *) malloc(heap->capacity * sizeof(int));
}

void expand_heap(Heap *heap) {
    if(heap->size >= heap->capacity) {
        heap->capacity *= heap->capacity;
        heap->data = realloc(heap->data, heap->capacity * sizeof(int));
    }
}

void heapify(Heap *heap, int direction) {
    if(direction == HEAPIFY_UP) {
        int index = heap->size - 1; // index of last element

        // Compare with parent and if less than child swap
        while(parent(heap, index) < heap->data[index]) {
            int ip = index_of_parent(index);
            swap(heap, ip, index);
            index = ip;
        }
    } else if(direction == HEAPIFY_DOWN) {
        int index = 0;  // initially index of first element

        // Compare with left and right child and replace with whichever is greater
        while(has_left_child(heap, index) && left_child(heap, index) > heap->data[index]) {
            int higher_index = index_of_left_child(index);

            // If right child is higher than left child
            if(has_right_child(heap, index) && right_child(heap, index) > left_child(heap, index)) {
                // update higher_index to that of right child
                higher_index = index_of_right_child(index);
            }

            // Swap with either right or left index
            swap(heap, index, higher_index);

            // Update the value of index to traverse through inner child
            index = higher_index;
        }
    }
}

void swap(Heap *heap, int i, int j) {
    assert(i < heap->size && i >= 0);
    assert(j < heap->size && j >= 0);
    assert(i != j);

    int tmp = heap->data[i];
    heap->data[i] = heap->data[j];
    heap->data[j] = tmp;
}

int peek(int *a) {
    assert(a != NULL);
    return *a;
}

int poll_item(Heap *heap) {
    int item = heap->data[0];

    swap(heap, 0, heap->size - 1);
    heap->size--;

    heapify(heap, HEAPIFY_DOWN);

    return item;
}

void print_heap(Heap *heap) {
    for(int i = 0; i < heap->size; i++) {
        printf("%d\t", heap->data[i]);
    }
    printf("\n");
}
