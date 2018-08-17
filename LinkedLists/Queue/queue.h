#ifndef QUEUE_H
#define QUEUE_H
#include "../Stack/node.h"

void enqueue(Node *head, Node *tail, int value);
int dequeue(Node *head, Node *tail);
int is_empty(Node *head, Node *tail);
void print(Node *head);

#endif