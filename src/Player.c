#include <stdio.h>
#include "./../include/Player.h"

int id_player_indicator = 0;

Player * player_init(Color player_color  , char *name , short age) {
    Player *p = (Player *)malloc(sizeof(Player));
    check_null((void *)p  , "could not allocate memory for struct player !!!");
    p->id_player = id_player_indicator;
    p->player_color = player_color;
    p->name = name;
    p->age = age;
    p->turn_to_play = false;
    p->score = 0;
    p->tiles_history = NULL;
    return p;
}



