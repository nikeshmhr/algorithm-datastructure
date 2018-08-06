#ifndef NODE_H
#define NODE_H
struct s
{
    struct s *next;
    int value;
};

typedef struct s *Node;
#endif