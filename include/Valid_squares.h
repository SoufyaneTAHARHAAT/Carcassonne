#ifndef VALID_SQUARES_H
#define VALID_SQUARES_H

#include "Open_squares.h"
#include "coordinate.h"



// typedef struct Borders_state_t Borders_state;


struct Square_Orientation_t {
    Coordinate coor;
    int possible_fits;
    int *orientation; 
};
// [1 , 0 , 1 , 0] means that the first index of 1 is 0 so no ortientation
// second index of 1 is 2 so means two orientations

typedef struct Square_Orientation_t  Square_Orientation;

struct Valid_squares_t
{
    Square_Orientation* arr;
    int size;   
};
typedef struct Valid_squares_t Valid_squares;



Valid_squares *valid_squares_init();

void valid_squares_update(Valid_squares *vs, Open_squares *os , Tile *t);
int  *are_borders_matching(Edge_land edge_land_arr[4] , Border_land tile_borders[5]);

void valid_squares_print(Valid_squares *vs); 
void valid_squares_push(Valid_squares *vs, Square_Orientation so);
void shift_array(Landscape arr[] , int size);

#endif
