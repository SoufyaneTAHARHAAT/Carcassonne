#include "./../include/Grid.h"
#include "./../include/Player.h"
#include "./../include/Game.h"
#include "./../include/Grid_Validator.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

bool grid_put_tile(Stack * s, Grid *g, Tile *t, Player *p , Coordinate position , Open_squares *os) {

  if (grid_validate_put_tile(s , t , g , p , position , os)  == OK) {
    print_error(OK);
    g->tab[position.x][position.y].square_state = OCCUPIED;
    g->tab[position.x][position.y].t = t;
    return true;
  }
  print_error(UNMATCHING_BORDERS);
  return false;
}

bool grid_put_meeple(Grid *g, Meeple *mp, Borders cardinal_dir, __u_int x,
                     __u_int y) {
  if (g->tab[x][y].square_state == EMPTY)
    return false; // No need for it;

  switch (cardinal_dir) {
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
