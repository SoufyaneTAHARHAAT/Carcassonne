#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "Meeple.h"
#include "Tile.h"
#include "Grid.h"

#define MEEPLES_NUM 7 // it was 8 changed to 7

enum Player_category{
    HUMAN,
    AI
};
typedef enum  Player_category Player_category;

struct Player_t {
    int id_player;
    Color player_color;
    char * name;
    short age;
    bool turn_to_play;
    unsigned short score;
    Tile* tiles_history; // to consider later nchllh
    Player_category player_cat;
    Meeple *meeples_arr_out_grid[MEEPLES_NUM]; //arr of meeples that are out of the grid
    Meeple *meeples_arr_in_grid[MEEPLES_NUM]; //arr of meeples that are in the grid
    int num_meeples_out_grid; // 7
    int num_meeples_in_grid; // 0
};
typedef struct Player_t Player;

typedef struct Grid_t Grid;// for forwared declaration
// create an instance of Player struct
Player * player_create(Color player_color  , char *name , short age , Player_category player_cat);

void player_move_meeple_to_grid(Grid *g, Player *p, int x, int y, Borders border);
void player_move_meeple_out_grid(Player *p);

// print function  
void player_show(Player *p);


#endif
