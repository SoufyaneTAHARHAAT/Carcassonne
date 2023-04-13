#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/Grid.h"
#include "./../include/Player.h"
#include "./../include/Game.h"
#include "./../include/Grid_Validator.h"
Grid *grid_create() {
  Grid *grid = (Grid *)malloc(sizeof(Grid));
  check_null((void *)grid, "could not allocate memory for the grid");
  // create special tile of start
  Tile *t = tile_create("route", "ville", "route", "pre", "route");
  t->tile_state = ON_GRID;
  tile_print(t);
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if ((i == ROWS / 2) && (j == COLS / 2)) {
        grid->tab[i][j].square_state = OCCUPIED;
        grid->tab[i][j].t = t;
      } else {
        grid->tab[i][j].square_state = EMPTY;
        grid->tab[i][j].t = NULL;
      }
    }
  }
  return grid;
}

bool grid_put_tile(Stack * s, Grid *g, Tile *t, Player *p , int x , int y, Open_squares *os) {

  if (grid_validate_put_tile(s , t , g , p , x, y, os)  == OK) {
    print_error(OK);
    g->tab[x][y].square_state = OCCUPIED;
    g->tab[x][y].t = t;
    return true;
  }
  print_error(UNMATCHING_BORDERS);
  return false;
}


void grid_show(Grid *g) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (g->tab[i][j].square_state == EMPTY) {
        printf("E ");
      } else {
        printf("%d ", g->tab[i][j].t->id_tile);
      }
    }
    printf("\n");
  }
}

void grid_cut_show(Grid *g, int row, int col, int dist) {

  printf("    ");
  for (int k = col - dist; k < col + dist; k++)
  {
    printf("%d   " , k);
  }
  printf("\n");
  for (int i = row - dist; i < row + dist; i++) {
    printf("%d ", i);
    for (int j = col - dist; j < col + dist; j++) {
      if (g->tab[i][j].square_state == EMPTY) {
        printf("  E  ");
      } else {
        printf("  %d  ", g->tab[i][j].t->id_tile);
      }
    }
    printf("\n");
  }
}

// void grid_cut_show_v2(Grid *g, int row, int col) {
//   for (int i = 0; i < row + 5; i++)
//   {
//     grid_cut_show_row(g , row , col);
//   }
  
// }


// void grid_cut_show_row(Grid *g, int row, int col) {

//   int i;
//   if (g->tab[row][row].t != NULL) i = 0;

//   printf("------------------------------------------------------------\n");
//   printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col].t->borders[TOP].landscape),
//                     print_landscape_v2(g->tab[row][col + 1].square_state, g->tab[row][col + 1].t->borders[TOP].landscape),
//                     print_landscape_v2(g->tab[row][col + 2].square_state, g->tab[row][col + 2].t->borders[TOP].landscape),
//                     print_landscape_v2(g->tab[row][col + 3].square_state, g->tab[row][col + 3].t->borders[TOP].landscape), 
//                     print_landscape_v2(g->tab[row][col + 4].square_state, g->tab[row][col + 4].t->borders[TOP].landscape));
  
//   printf("%s\t%s\t%s",print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col].t->borders[LEFT].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col].t->borders[CENTER].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col].t->borders[RIGHT].landscape));

//   printf("%s\t%s\t%s",print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 1].t->borders[LEFT].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 1].t->borders[CENTER].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 1].t->borders[RIGHT].landscape));
  
//   printf("%s\t%s\t%s",print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 2].t->borders[LEFT].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 2].t->borders[CENTER].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 2].t->borders[RIGHT].landscape));

//   printf("%s\t%s\t%s",print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 3].t->borders[LEFT].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 3].t->borders[CENTER].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 3].t->borders[RIGHT].landscape));

//   printf("%s\t%s\t%s\n",print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 4].t->borders[LEFT].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 4].t->borders[CENTER].landscape),
//                     print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col + 4].t->borders[RIGHT].landscape));


//   printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", print_landscape_v2(g->tab[row][col].square_state, g->tab[row][col].t->borders[BOTTOM].landscape),
//                     print_landscape_v2(g->tab[row][col + 1].square_state, g->tab[row][col + 1].t->borders[BOTTOM].landscape),
//                     print_landscape_v2(g->tab[row][col + 2].square_state, g->tab[row][col + 2].t->borders[BOTTOM].landscape),
//                     print_landscape_v2(g->tab[row][col + 3].square_state, g->tab[row][col + 3].t->borders[BOTTOM].landscape), 
//                     print_landscape_v2(g->tab[row][col + 4].square_state, g->tab[row][col + 4].t->borders[BOTTOM].landscape));


//   printf("------------------------------------------------------------\n");
  
// }

// char * print_landscape_v2(Square_state empty, Landscape i){
//   if (empty) return "NUL";

//   switch (i) {
//   case CITY:
//     return "CTY";
//     break;
//   case FIELD:
//     return "FLD";
//     break;
//   case CLOISTER:
//     return "CLS";
//     break;
//   case SHIELD:
//     return "SHL";
//     break;
//   case ROAD:
//     return "ROD";
//     break;
//   case VILLAGE:
//     return "VLG";
//     break;
//   default:
//     break;
//   }

// }