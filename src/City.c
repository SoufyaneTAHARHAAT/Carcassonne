#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/Tile.h"
#include "./../include/Grid.h"
#include "./../include/Player.h"
#include "./../include/Game.h"
#include "./../include/Grid_Validator.h"



bool is_visited(Coordinate visited_arr[], int x, int y) {
    for (int i = 0; i < MAX_TILES; i++) {
        if (visited_arr[i].x == x && visited_arr[i].y == y) {
            return true;
        }
    }
    return false;
}

bool is_city_complete(Grid *g, int x, int y, Coordinate visited_arr[]) {

    printf("calling is_city_complete with x = %d, y = %d\n", x, y);
    if (is_visited(visited_arr, x, y)) {
        printf("tile with %d %d is_visited \n", x, y);
        return true;
    }

    int temp_x = -1;
    int temp_y = -1;

    for (int i = 0 ; i< MAX_TILES; i++) {
        if (visited_arr[i].x == -1 && visited_arr[i].y == -1) {
            visited_arr[i].x = x;
            visited_arr[i].y = y;
            break;
        }   
    }

    for (int i = 0 ; i < 4 ; i++) {
        printf("checking border %d on tile x = %d y = %d\n", i, x, y);
        if (g->tab[x][y].t->borders[i].landscape == CITY) {
         
            switch (i)
                {
                    case 0:
                    // if(g->tab[x][y - 1].t == NULL) return false;
                     if((g->tab[x][y - 1].t != NULL) && (g->tab[x][y - 1].t->borders[2].landscape == CITY)) {
                        temp_x = x;
                        temp_y = y - 1;
                     }

                    break;

                    case 1:
                    // if(g->tab[x - 1][y].t == NULL) return false;
                     if((g->tab[x - 1][y].t != NULL) && (g->tab[x - 1][y].t->borders[3].landscape == CITY)) {
                        temp_x = x - 1;
                        temp_y = y;
                     }

                    break;

                    case 2:
                    // if(g->tab[x][y + 1].t == NULL) return false;
                     if((g->tab[x][y + 1].t != NULL) && (g->tab[x][y + 1].t->borders[0].landscape == CITY)) {
                        temp_x = x;
                        temp_y = y + 1;
                     }

                    break;

                    case 3:
                    // if(g->tab[x + 1][y].t == NULL) return false;
                     if((g->tab[x + 1][y].t != NULL) && (g->tab[x + 1][y].t->borders[1].landscape == CITY)) {
                        temp_x = x + 1; 
                        temp_y = y;
                     }

                    break;
             }
            
            
            if (!is_city_complete(g, temp_x, temp_y, visited_arr)) {
                return false;
            }
        }
    }

    return true;

}

