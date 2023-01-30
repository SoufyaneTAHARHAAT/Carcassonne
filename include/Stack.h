#ifndef STACK_H
#define STACK_H

#include "Tile.h"

struct Stack_t{
    unsigned int *number_tiles;
    Tile * list_tiles;
};
typedef Stack_t Stack;


#endif