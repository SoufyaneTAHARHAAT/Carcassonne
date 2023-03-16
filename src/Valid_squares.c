#include "./../include/Valid_squares.h"
#include "./../include/Grid.h"
#include "./../include/Open_squares.h"
#include "./../include/Result.h"
#include <stdio.h>

Valid_squares *valid_squares_init()
{
  Valid_squares *vs = (Valid_squares *)malloc(sizeof(Valid_squares));
  check_null((void *)vs, "could not allocate memory for Valid_squares struct");
  vs->arr = NULL;
  vs->size = 0;
  return vs;
}

/*
    @vs: pointer to Valid_squares struct
    @os: pointer to Open_sqaures struct
    @t: pointer to Tile struct
    to update valid squares we loop through every open square and compare them
    to the tile popped from the stack if any match is possible we push a new
   Square Oprientation to the vs->arr
*/

void valid_squares_update(Valid_squares *vs, Open_squares *os, Tile *t)
{
  // we loop through the open squares and compare each one to the tile Edges
  bool is_there_one = false;
  for (int i = 0; i < os->size; i++)
  {

    int *arr = (int *)malloc(sizeof(int) * 4);    
    are_borders_matching(arr, os->arr[i].edge_land_arr, t->borders);

    // check if the array contains at least 1 matching possiblity
    for (int k = 0; k < 4; k++)
    {
      if (arr[k] == 1)
      {
        is_there_one = true;
        break;
      }
    }

    // if bordrs matching we push a squar eorietation to Valid Squres;
    if (is_there_one)
    {
      int possible_fits = 0;
      Square_Orientation temp;
      temp.coor.x = os->arr[i].coor.x;
      temp.coor.y = os->arr[i].coor.y;

      for (int m = 0; m < 4; m++)
      {
        if (arr[m] == 1)
          possible_fits++;
      }
      temp.orientation = arr;
      temp.possible_fits = possible_fits;
      valid_squares_push(vs, temp);
      is_there_one = false;
    }
    else
    {
      // free(arr);
      continue;
    }
  }
  // we must free the memory for int * arr; later nchhlhz
}

/*
    @edge_land_arr: array from Open Squres
    @tile_borders: array from Tile
    the function return the number of possible ways the borders can match;
    -1 if no match
    1...3 inclusive if there is a match

    if there is only one condition we look how many squares have that  condition
    if there is only two condtions
*/

void are_borders_matching(int *arr, Edge_land edge_land_arr[4], Border_land tile_borders[5])
{
  bool is_match = true;
  Landscape tile_ladscape_copy[4] = {
      tile_borders[0].landscape, tile_borders[1].landscape,
      tile_borders[2].landscape, tile_borders[3].landscape};
  // conpare all tile positions with orietation
  for (int i = 0; i < 4; i++)
  {
    is_match = true;
    // compare both arrays
    for (int j = 0; j < 4; j++)
    {
      if (edge_land_arr[j].landscape == FREE)
      {
        // continue;
      }
      else
      {
        if (edge_land_arr[j].landscape != tile_ladscape_copy[j])
        {
          is_match = false;
        }
      }
    }

    if (is_match)
    {
      arr[i] = 1;
    }
    else
    {
      arr[i] = 0;
    }

    // shift the array

    shift_array(tile_ladscape_copy, 4);
  }
}

void valid_squares_push(Valid_squares *vs, Square_Orientation so)
{
  vs->size++;
  vs->arr = (Square_Orientation *)realloc(vs->arr, vs->size * sizeof(Square_Orientation));
  vs->arr[vs->size - 1] = so;
}


void valid_square_destory(Valid_squares *vs) {
  free(vs->arr);
  vs->size = 0;
  vs->arr = NULL; 
}

void shift_array(Landscape *arr, int size)
{
  Landscape temp = arr[size - 1];

  for (int i = size - 1; i > 0; i--)
  {
    arr[i] = arr[i - 1];
  }

  arr[0] = temp;
}

void valid_squares_print(Valid_squares *vs)
{
  printf("Valid squares size is %d\n", vs->size);
  for (int i = 0; i < vs->size; i++)
  {
    printf(" {%d , %d } [%d] ", vs->arr[i].coor.x, vs->arr[i].coor.y , vs->arr[i].possible_fits);
    
    for (int j = 0; j < 4; j++)
    {
      printf(" %d ", vs->arr[i].orientation[j]);
    }
    printf("\n");
  }
}

void print_tile_copy(Landscape tile_ladscape_copy[])
{
  for (int i = 0; i < 4; i++)
  {
    switch (tile_ladscape_copy[i])
    {
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
  printf("\n");
}
