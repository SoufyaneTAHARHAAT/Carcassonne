#include <stdio.h>
#include <stdlib.h>
#ifndef GRID_H
#define GRID_H

#include "Tile.h"

#define ROWS 72
#define COLS 72

enum Square_state_t
{
    EMPTY,
    OCCUPIED,
};
typedef enum Square_state_t Square_state;

struct Square_t {
    Tile * t;
    Square_state square_state;
};
typedef struct Square_t Square;

struct Grid_t{
    Square tab[ROWS][COLS];
};
typedef struct Grid_t Grid;


Grid * grid_create();
void grid_put_tile(Grid *g , Tile *t , __u_int x , __u_int y);
void grid_show(Grid *g); 

#endif