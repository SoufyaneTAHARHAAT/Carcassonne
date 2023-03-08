#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/Grid.h"
#include "./../include/Open_squares.h"
#include "./../include/Result.h"
#include "./../include/Grid.h"

Open_squares *open_squares_init() {
  Open_squares *os = (Open_squares *)malloc(sizeof(Open_squares));
  check_null((void *)os, "could not allocate memory for Open Squares");
  os->arr = (Square_info *)malloc(sizeof(Square_info) * 4);
  check_null(
      (void *)os->arr,
      "could not allocate arr for open_squares info  in struct Open squares");
  os->size = 4;

  // CONFIGURE THE INFO FOR SQUARE ON THE LEFT TO THE SPECIAL TILE
  os->arr[0].coor.x = ROWS / 2;
  os->arr[0].coor.y = COLS / 2 - 1;
  os->arr[0].edge_land_arr[2].border = RIGHT;
  os->arr[0].edge_land_arr[2].landscape = ROAD;
  os->arr[0].edge_land_arr[0].border = LEFT;
  os->arr[0].edge_land_arr[0].landscape = FREE;
  os->arr[0].edge_land_arr[1].border = TOP;
  os->arr[0].edge_land_arr[1].landscape = FREE;
  os->arr[0].edge_land_arr[3].border = BOTTOM;
  os->arr[0].edge_land_arr[3].landscape = FREE;
  // CONFIGURE THE INFO FOR SQUARE ON THE TOP TO THE SPECIAL TILE
  os->arr[1].coor.x = ROWS / 2 - 1;
  os->arr[1].coor.y = COLS / 2;
  os->arr[1].edge_land_arr[2].border = RIGHT;
  os->arr[1].edge_land_arr[2].landscape = FREE;
  os->arr[1].edge_land_arr[0].border = LEFT;
  os->arr[1].edge_land_arr[0].landscape = FREE;
  os->arr[1].edge_land_arr[1].border = TOP;
  os->arr[1].edge_land_arr[1].landscape = FREE;
  os->arr[1].edge_land_arr[3].border = BOTTOM;
  os->arr[1].edge_land_arr[3].landscape = VILLAGE;

  // CONFIGURE THE INFO FOR SQUARE ON THE RIGHT TO THE SPECIAL TILE
  os->arr[2].coor.x = ROWS / 2;
  os->arr[2].coor.y = COLS / 2 + 1;
  os->arr[2].edge_land_arr[0].border = LEFT;
  os->arr[2].edge_land_arr[0].landscape = ROAD;
  os->arr[2].edge_land_arr[1].border = TOP;
  os->arr[2].edge_land_arr[1].landscape = FREE;
  os->arr[2].edge_land_arr[2].border = RIGHT;
  os->arr[2].edge_land_arr[2].landscape = FREE;
  os->arr[2].edge_land_arr[3].border = BOTTOM;
  os->arr[2].edge_land_arr[3].landscape = FREE;

  // CONFIGURE THE INFO FOR SQUARE ON THE BOTTOM TO THE SPECIAL TILE
  os->arr[3].coor.x = ROWS / 2 + 1;
  os->arr[3].coor.y = COLS / 2;
  os->arr[3].edge_land_arr[1].border = TOP;
  os->arr[3].edge_land_arr[1].landscape = FIELD;
  os->arr[3].edge_land_arr[0].border = LEFT;
  os->arr[3].edge_land_arr[0].landscape = FREE;
  os->arr[3].edge_land_arr[2].border = RIGHT;
  os->arr[3].edge_land_arr[2].landscape = FREE;
  os->arr[3].edge_land_arr[3].border = BOTTOM;
  os->arr[3].edge_land_arr[3].landscape = FREE;
  return os;
}

void open_squares_push(Open_squares *os, Square_info si) {
  os->size++;
  os->arr = (Square_info *)realloc(os->arr, os->size * sizeof(Square_info));
  os->arr[os->size - 1] = si;
}

void square_info_push_edge_land(Open_squares *os, int x, int y, Borders b,
                                Landscape l) {

  for (int i = 0; i < os->size; i++) {

    if (os->arr[i].coor.x == x && os->arr[i].coor.y == y) {

      os->arr[i].edge_land_arr[b].landscape = l;
    }
  }
}

void square_info_delete_edge_land(Open_squares *os, int x, int y, Borders b) {
  for (int i = 0; i < os->size; i++) {

    if (os->arr[i].coor.x == x && os->arr[i].coor.y == y) {

      os->arr[i].edge_land_arr[b].landscape = FREE;
    }
  }
}

void open_squares_delete(Open_squares *open_squares, Square_info square) {
  for (int i = 0; i < open_squares->size; i++) {
    if (open_squares->arr[i].coor.x == square.coor.x &&
        open_squares->arr[i].coor.y == square.coor.y) {
      // Shift all elements after the removed element to the left
      for (int j = i; j < open_squares->size - 1; j++) {
        open_squares->arr[j] = open_squares->arr[j + 1];
      }
      // Decrease the size of the array
      open_squares->size--;
      open_squares->arr = (Square_info *)realloc(
          open_squares->arr, open_squares->size * sizeof(Square_info));
      return;
    }
  }
}

Result open_squares_search(Open_squares *os, Square_info square) {
  for (int i = 0; i < os->size; i++) {
    if (square.coor.x == os->arr[i].coor.x &&
        square.coor.y == os->arr[i].coor.y) {
      return VALID_GRID_POSTION;
    }
  }

  return INVALID_GRID_POSTION;
}




// x and y to the coors of the already putt tile

// once we put the tile on the grid we add new coords and update the conditions of old ones
void open_squares_update(Grid *g ,Open_squares *os , int x , int y) {
  // first we unlock the neighbours of x , y square if they are not occupied already

  // left square

  if (os)
  {
    /* code */
  }
  

  // top square

  // right square

  // bottom square
  

  // we update the conditions

}

void open_squares_print(Open_squares *os) {
  printf("size open squares = %d\n", os->size);
  for (int i = 0; i < os->size; i++) {
    printf(" {%d , %d } ", os->arr[i].coor.x, os->arr[i].coor.y);
    for (int j = 0; j < 4; j++) {
      switch (os->arr[i].edge_land_arr[j].border) {
      case TOP:
        printf("TOP-> ");
        break;
      case BOTTOM:
        printf("BOTTOM-> ");
        break;
      case LEFT:
        printf("LEFT-> ");
        break;
      case RIGHT:
        printf("RIGHT-> ");
        break;
      case CENTER:
        printf("CENTER-> ");
        break;
      }

      switch (os->arr[i].edge_land_arr[j].landscape) {
      case CITY:
        printf("CITY, ");
        break;
      case FIELD:
        printf("FILD, ");
        break;
      case CLOISTER:
        printf("CLST, ");
        break;
      case SHIELD:
        printf("SHLD, ");
        break;
      case ROAD:
        printf("ROAD, ");
        break;
      case VILLAGE:
        printf("VLGE, ");
        break;
      case FREE:
        printf("FREE, ");
        break;
      default:
        break;
      }
    }
    printf(" \n");
  }

  printf("\n");
}
