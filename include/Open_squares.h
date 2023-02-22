#ifndef OPEN_SQUARES_H
#define OPEN_SQUARES_H


#include "coordinate.h"


struct Open_squares_t {
    Coordinate *arr;
    int size;
};
typedef struct Open_squares_t Open_squares;


// taks the position of the first special Tile
Open_squares * open_squres_init();
void open_squares_push(Open_squares *open_squares, Coordinate coordinate);
void open_squares_delete(Open_squares *open_squares, Coordinate coordinate);

#endif