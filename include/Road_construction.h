#ifndef ROAD_CONSTRUCTION_H
#define ROAD_CONSTRUCTION_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/Grid.h"
#include "./../include/Tile.h"
#include "./../include/Player.h"
#include "./../include/Open_squares.h"
#include "./../include/Result.h"
#include "./../include/coordinate.h"

struct Node_t {
    Borders border;
    Coordinate pos;
};
struct struct Node_t Node;

struct road_double_list_t {
    Node *node;
};
typedef struct road_double_list_t road_double_list;

struct Road_t
{
    road_double_list *origine; // pointer to double linked liset
    bool conquered; // true means road is takes can not put a meeple
    Player * owners; // array of players
    int *num_meeples; // array for num_meeples for every player
};


struct Road_construction_t {
    Road * arr;
};
typedef struct Road_construction_t Road_construction;

#endif