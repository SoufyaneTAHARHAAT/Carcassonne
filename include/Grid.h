#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tile.h"
#include "Meeple.h"
#include "Player.h"
#include "Stack.h"
#include "coordinate.h"
#include "Open_squares.h"

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

struct Open_squares_t; // forward declaration of Grid struct
typedef struct Open_squares_t Open_squares;

typedef struct Player_t Player; // forward declaration of Player struct

Grid *grid_create();
bool grid_put_tile(Stack * s, Grid *g, Tile *t, Player *p, int x, int y, Open_squares *os); 
void grid_show(Grid *g); 
void grid_cut_show(Grid *g , int row , int col , int dist);



void grid_cut_show_row(Grid *g, int row, int col);
// char * print_landscape_v2(Square_state empty, Landscape i);
// void grid_cut_show_v2(Grid *g, int row, int col)
#endif

