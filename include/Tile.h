#ifndef TILE_H
#define TILE_H

#include <stdbool.h>
#include "coordinate.h"
#include "Meeple.h"

#define MAX_TILES 72


enum State_t
{
    ON_GRID,
    ON_STACK, // STILL IN STACK OF TILES
    ON_HAND, // after stack and before grid 
};
typedef enum State_t Tile_state;

enum Borders_t
{
    TOP,
    RIGHT,
    BOTTOM,
    LEFT,
    CENTER,
};
typedef enum Borders_t Borders;

enum Landscape_t
{
    ROAD, 
    CITY,
    CLOISTER, // THE ONE THAT NEED TO BE SURROUNDED BU 8 TILES PRE
    FIELD,    // ABBAYE
    SHIELD,   // BLASON
    VILLAGE,
};
typedef enum Landscape_t Landscape;

struct Border_land_t

{
    Borders border;
    Landscape landscape;
    bool meepled;
};
typedef struct Border_land_t Border_land;

// create struct for the tiles
struct Tile_t
{
    int id_tile; 
    Border_land borders[5];
    Tile_state tile_state;
};
typedef struct Tile_t Tile;


Tile *tile_create(char arr1[], char arr2[] ,char arr3[],char arr4[], char arr5[]);
Landscape compare(int count , int stop ,  ...);
void tile_print(Tile *t);
void landscape_print(Tile *t, int l);

// number of times to rotate 1..3 
void tile_rotate(Tile *t , int n);
void check_null(void * n , char * msg); 
#endif
