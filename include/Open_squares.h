#ifndef OPEN_SQUARES_H
#define OPEN_SQUARES_H


#include "coordinate.h"
#include "Result.h"
#include "Tile.h"

struct Edge_land_t
{
    Borders border;
    Landscape landscape;
};
typedef struct Edge_land_t Edge_land;


struct Square_info_t {
  Edge_land  edge_land_arr[4];
  Coordinate coor;
};
typedef struct Square_info_t Square_info;

struct Open_squares_t {
    Square_info  *arr;
    int size;
};
typedef struct Open_squares_t Open_squares;


Open_squares *open_squares_init(); 

void open_squares_push(Open_squares *os, Square_info si);

void square_info_push_edge_land(Open_squares *os , int x , int y , Borders b , Landscape l); 

void square_info_delete_edge_land(Open_squares *os , int x , int y, Borders b); 

void open_squares_delete(Open_squares *open_squares, Square_info square);

Result open_squares_search(Open_squares *os, Square_info square);

void open_squares_print(Open_squares *os); 
#endif











