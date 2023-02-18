#ifndef STACK_H
#define STACK_H

#include "./../include/Tile.h"

struct Node_t
{
    Tile *t;
    struct Node_t * next;
};typedef struct Node_t Node;

struct Stack_t{
    __u_int tiles_number;
    Node * head; // lined_list
};
typedef struct Stack_t Stack;

// We decided after a long discussion with the vice president
// and members of community to name the var s not stack for the following reasons 
void read_tiles_file(char *filename, Stack *s);
Stack * stack_create();
void stack_push(Stack *s , Tile *t);
Tile * stack_pop(Stack *s);
void stack_shuffle(Stack *s);
void stack_swap_nodes(Node * n1, Node *n2);
Node *stack_nth_node( Node *head ,__u_int n); 
void stack_summary(Stack *s);   

void stack_show(Stack *s);

#endif