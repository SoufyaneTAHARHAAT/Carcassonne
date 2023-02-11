#ifndef TILE_H
#define TILE_H

#include "coordinate.h"
#include "Meeple.h"

enum State_t
{
    PLAYED,
    ON_HOLD, // STILL IN STACK OF TILES
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
    CLOISTER, // THE ONE THAT NEED TO BE SURROUNDED BU 8 TILES
    FIELD,    // ABBAYE
    SHIELD,   // BLASON
    VILLAGE
    
};
typedef enum Landscape_t Landscape;

struct Border_land_t
{
    Borders border;
    Landscape landscape;
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


Tile *create_tile(char arr1[], char arr2[] ,char arr3[],char arr4[], char arr5[]);
Landscape compare(int count , int stop ,  ...);
void print_tile(Tile *t);
void print_landscape(Tile *t, int l);
void check_null(void * n , char * msg); 
#endif