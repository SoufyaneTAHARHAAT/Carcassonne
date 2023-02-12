#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "./../include/Grid.h"

Grid * grid_create() {
    Grid * grid = (Grid *)malloc(sizeof(Grid));
    check_null((void *)grid , "could not allocate memory for the grid");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid->tab[i][j].square_state = EMPTY;
            grid->tab[i][j].t = NULL;
        }
    }
    return grid;
}

void grid_put_tile(Grid *g , Tile *t, int x , int y){
    g->tab[x][y].square_state = OCCUPIED;
    g->tab[x][y].t = t;
}



void grid_show(Grid *g) {
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {

            if (g->tab[i][j].square_state == EMPTY) {
                printf("E ");
            }
            else {
                printf("%d " , g->tab[i][j].t->id_tile);
            }
        }
        
        printf("\n");
    }
    
}
