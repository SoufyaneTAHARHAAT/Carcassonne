#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "Meeple.h"
#include "Tile.h"

struct Player_t {
    int id_player;
    Color player_color;
    char * name;
    short age;
    bool turn_to_play;
    unsigned short score;
    Tile* tiles_history; // to consider later nchllh
};
typedef struct Player_t Player;

// create an instance of Player struct
Player * player_create(Color player_color  , char *name , short age);

// print function  
void player_show(Player *p);


#endif
