#ifndef STACK_H
#define STACK_H
#include "node.h"

void push(Node *, int);
void print(const Node *);
int empty(const Node *);
int pop(Node *);

#endif