#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include "Meeple.h"
#include "Player.h"
#include "Open_squares.h"
#include "Grid.h"
#include "Stack.h"
#include "coordinate.h"

#define ROWS 143
#define COLS 143

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


Grid *grid_create();
bool grid_put_tile(Stack * s, Grid *g, Tile *t, Player *p, Coordinate position , Open_squares *os); 
bool grid_put_meeple(Grid *g , Meeple * mp , Borders cardinal_dir, __u_int x, __u_int y);
void grid_show(Grid *g); 
void grid_cut_show(Grid *g , int row , int col , int dist);
#endif
