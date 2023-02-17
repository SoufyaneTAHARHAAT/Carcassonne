#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "Meeple.h"
#include "Tile.h"

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
};
typedef struct Player_t Player;

// create an instance of Player struct
Player * player_create(Color player_color  , char *name , short age , Player_category player_cat);

// print function  
void player_show(Player *p);


#endif
