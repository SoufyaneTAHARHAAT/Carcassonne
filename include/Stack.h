#ifndef STACK_H
#define STACK_H

#include "Tile.h"

struct Stack_t{
    unsigned int *tiles_number;
    Tile * list_tiles;
};
typedef Stack_t Stack;


// We decided after a long discussion with the vice president
// and members of community to name the var s not stack for the following reasons 
void read_tiles_file(char *filename, Stack s);


#endif