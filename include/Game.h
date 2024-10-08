#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Grid.h"
#include "Stack.h"
#include "coordinate.h"
#include "Valid_squares.h"

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
    __u_int num_players;

};typedef struct Game_t Game;
 

Game * game_init(Player * players_arr[MAX_PLAYERS]  , Grid * g , Stack *s , __u_int num_players);
Coordinate game_suggest_valid_squares(Valid_squares *vs);
int game_suggest_tile_rotation(Valid_squares *vs, int x, int y); 
int game_suggest_meeple();
void game_get_players(Player * players_arr[MAX_PLAYERS]); 
void print_error(Result result); 
int get_rand_number(int max);
int get_rand_number_for_rotation(Valid_squares *vs, int x, int y) ;

#endif
