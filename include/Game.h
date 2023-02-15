#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Grid.h"
#include "Stack.h"

#define MAX_PLAYERS 5

enum State_g{
    UNFINISHED,
    FINISHED
};
typedef enum State_g Game_state;

struct Game_t{
    // int * id_players; // pointer to an array contains id players
    Player* players[MAX_PLAYERS];
    Grid * grid; // pointer to the grid
    Stack * stack; // pointer to the stack of tiles
    Game_state game_state;

};typedef struct Game_t Game;
 

Game * game_init(Grid * g , Stack *s , __u_int num_players);

void game_get_players(Player * plyayers_arr[MAX_PLAYERS]); 

#endif