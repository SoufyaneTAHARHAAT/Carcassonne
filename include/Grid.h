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

    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_YELLOW  "\x1b[33m"
    #define ANSI_COLOR_BLUE    "\x1b[34m"
    #define ANSI_COLOR_MAGENTA "\x1b[35m"
    #define ANSI_COLOR_CYAN    "\x1b[36m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

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
    bool isRoadComplete(Grid *g, int x, int y, bool isStart, bool isEnd);

    void grid_show(Grid *g); 
    void grid_cut_show(Grid *g , int row , int col , int dist);



    void grid_cut_show_v2(Grid *g, int row, int col);
    char * print_landscape_v2(Landscape i);
    void grid_cut_show_v3(Grid *g, int row, int col, int dist);
    #endif

