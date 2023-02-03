#ifndef STACK_H
#define STACK_H

#include "./../include/Tile.h"

struct Stack_t{
    unsigned int *tiles_number;
    Tile * list_tiles; // lined_list
};
typedef struct Stack_t Stack;


// We decided after a long discussion with the vice president
// and members of community to name the var s not stack for the following reasons 
void read_tiles_file(char *filename, Stack *s);
Stack * create_stack();


#endif