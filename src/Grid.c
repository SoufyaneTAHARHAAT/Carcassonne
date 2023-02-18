#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "./../include/Grid.h"

Grid *grid_create()
{
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    check_null((void *)grid, "could not allocate memory for the grid");
    // create special tile of start
    Tile *t = tile_create("route", "ville", "route", "pre", "route");
    tile_print(t);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if ((i == 35) && (j == 35))
            {
                grid->tab[i][j].square_state = OCCUPIED;
                grid->tab[i][j].t = t;
            }
            else
            {
                grid->tab[i][j].square_state = EMPTY;
                grid->tab[i][j].t = NULL;
            }
        }
    }
    return grid;
}

bool grid_put_tile(Grid *g, Tile *t, __u_int x, __u_int y)
{
    
    if (g->tab[x][y].square_state == EMPTY)
    {
        g->tab[x][y].square_state = OCCUPIED;
        g->tab[x][y].t = t;
        return true;
    }
    printf("square %d %d is already occupied\n", x, y);
    return false;
}

bool grid_put_meeple(Grid *g, Meeple *mp, Borders cardinal_dir, __u_int x, __u_int y)
{
    if (g->tab[x][y].square_state == EMPTY)
        return false; // No need for it;

    switch (cardinal_dir)
    {
        case LEFT:
            g->tab[x][y].t->borders[0].meepled = true;
            break;
        case TOP:
            g->tab[x][y].t->borders[1].meepled = true;
            break;
        case RIGHT:
            g->tab[x][y].t->borders[2].meepled = true;
            break;
        case BOTTOM:
            g->tab[x][y].t->borders[3].meepled = true;
            break;
        case CENTER:
            g->tab[x][y].t->borders[4].meepled = true;
            break;
        default:
            break;
    }

    mp->position.x = x;
    mp->position.y = y;
    mp->state = IN_GRID;
    return true;
}
void grid_show(Grid *g)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (g->tab[i][j].square_state == EMPTY)
            {
                printf("E ");
            }
            else
            {
                printf("%d ", g->tab[i][j].t->id_tile);
            }
        }
        printf("\n");
    }
}
