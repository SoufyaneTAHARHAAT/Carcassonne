#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./../../include/Game.h"
#include "./../../include/Player.h"
#include "./../../include/Grid.h"
#include "./../../include/Stack.h"
#include "./../../include/coordinate.h"
#include "./../../include/Result.h"
#include "./../../include/Open_squares.h"
#include "./../../include/Grid_Validator.h"

Result grid_validate_put_tile(Stack *s, Tile *t, Grid *g, Player *p, Coordinate position, Open_squares *os)
{
    // check if stack is empty

    if (s->tiles_number == 0)
    {
        return EMPTY_STACK;
    }

    // check if plyer's turn

    if (!p->turn_to_play)
    {
        return INVALID_TURN;
    }

    // check if positiion is included on open Saquares Array

    if ((Result)open_squares_search(os, position) == INVALID_GRID_POSTION)
    {
        return INVALID_GRID_POSTION;
    }

    // check if all borders are matching

    if ((Result)grid_validate_borders(g , position) == UNMATCHING_BORDERS) {
        return UNMATCHING_BORDERS;
    }

    return OK;
}

/*
    * We need to ckeck some cases later like if we are in the corners
*/

Result grid_validate_borders(Grid *g, Coordinate position)
{
    int x = position.x;
    int y = position.y;
    // LEFT with RIGHT
    if (g->tab[x][y - 1].square_state == OCCUPIED)
    {
        if (g->tab[x][y].t->borders[0].landscape != g->tab[x][y - 1].t->borders[2].landscape)
        {
            return UNMATCHING_BORDERS;
        }
    }
    // TOP with BOTTOM
    if (g->tab[x - 1][y].square_state == OCCUPIED)
    {
        if (g->tab[x][y].t->borders[1].landscape != g->tab[x - 1][y].t->borders[3].landscape)
        {
            return UNMATCHING_BORDERS;
        }
    }
    // RIGHT WITH LEFT
    if (g->tab[x][y + 1].square_state == OCCUPIED)
    {
        if (g->tab[x][y].t->borders[2].landscape != g->tab[x][y + 1].t->borders[0].landscape)
        {
            return UNMATCHING_BORDERS;
        }
    }
    // BOTTOM WITH TOP
    if (g->tab[x + 1][y].square_state == OCCUPIED)
    {
        if (g->tab[x][y].t->borders[3].landscape != g->tab[x + 1][y].t->borders[1].landscape)
        {
            return UNMATCHING_BORDERS;
        }
    }

    return MATCHING_BORDERS;
}
