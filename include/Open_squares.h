#ifndef OPEN_SQUARES_H
#define OPEN_SQUARES_H


#include "coordinate.h"
#include "Result.h"
#include "Tile.h"




// struct  {
//     Coordinate coor;
//     Edge land *EL;
// } 

// /*
//     [
//     {x0 , y0 , {right = route} }, 
//     {x1 , y1  , {left = free , top = free , right = pre , bottom = free} },
//     {X2 , Y2 , {left = free , top = free , right = route , bottom = free} },
//     {X3 , Y3 , {left = free , top = village , right = route , bottom = pre}  }
//     ];
// */

struct Edge_land_t
{
    Borders border;
    Landscape landscape;
};
typedef struct Edge_land_t Edge_land;


struct Square_info_t {
  Edge_land * edge_land_arr;

  Coordinate coor;
};
typedef struct Square_info_t Square_info;

struct Open_squares_t {
    Square_info  *arr;
    int size;
};
typedef struct Open_squares_t Open_squares;


Open_squares *open_squares_init(); 
void open_squares_push(Open_squares *open_squares, Square_info info_square); 
void open_squares_delete(Open_squares *open_squares, Square_info square);
Result open_squares_search(Open_squares *os, Square_info square);
void open_squares_print(Open_squares *os); 
#endif











