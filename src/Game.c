#include "./../include/Game.h"
#include "./../include/Grid.h"
#include "./../include/Player.h"
#include "./../include/Result.h"
#include "./../include/Stack.h"
#include "./../include/Valid_squares.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Game *game_init(Player *players_arr[MAX_PLAYERS], Grid *g, Stack *s,
                __u_int num_players) {
  Game *game = (Game *)malloc(sizeof(Game));
  check_null((void *)game, "could not allocate memory for Game struct");
  game->game_state = UNFINISHED;
  game->grid = g;
  game->stack = s;
  game->num_players = num_players;
  // game->players = &(players_arr[0]); //does not work
  if (num_players > (int)MAX_PLAYERS) {
    printf("number of players in the game should be less than %d\n",
           MAX_PLAYERS);
    exit(EXIT_FAILURE);
  }
  // game_get_players(game->players , num_players);
  for (int i = 0; i < (int)num_players; i++) {
    game->players[i] = players_arr[i];
  }
  // when number of players < MAX_players
  for (int i = (int)num_players; i < MAX_PLAYERS; i++) {
    game->players[i] = NULL;
  }

  // make the first player true to true;

  game->players[0]->turn_to_play = true;

  return game;
}

// suggest open_sqaures with mathing Tiles
Coordinate game_suggest_valid_squares(Valid_squares *vs) {
  int choice;
  Coordinate pos;
  printf("choose where you want to put your Tile\n");
  for (int i = 0; i < vs->size; i++) {
    printf("type %d for  { %d , %d }\t", i, vs->arr[i].coor.x,
           vs->arr[i].coor.y);
    printf("\n");
  }
  scanf("%d", &choice);

  pos.x = vs->arr[choice].coor.x;
  pos.y = vs->arr[choice].coor.y;
  return pos;
}

/*
 * return how many times the user want a tile to be rotated;
 * in case there is so many possible_fits
 * if there is only one possible way we return 0;
 * */
int game_suggest_tile_rotation(Valid_squares *vs, int x, int y) {
  int i = 0;
  int choice = 0;
  for (i = 0; i < vs->size; i++) {
    if (vs->arr[i].coor.x == x && vs->arr[i].coor.y == y)
      break;
  }

  if (vs->arr[i].possible_fits > 1) {
    printf("choose  how many times to rotate the tile \n");
    if (vs->arr[i].orientation[0] == 1) {
      printf("type 0 to keep the tile as it is\n");
    }
    if (vs->arr[i].orientation[1] == 1) {

      printf("type 1 to rotate the tile ONE time\n");
    }
    if (vs->arr[i].orientation[2] == 1) {
      printf("type 2 to rotate the tile TWO times\n");
    }

    if (vs->arr[i].orientation[3] == 1) {
      printf("type 3 to rotate the tile THREE times\n");
    }
    scanf("%d", &choice);
    return choice;
  } else {
    printf("there is only one valid way to put the tile \n");
    for (int j = 0; j < 4; j++) {
      if (vs->arr[i].orientation[j] == 1) {
        return j;
      }
    }
  }
  // we can never reach this far but just to keep the compiler silent
  return 0;
}

int game_suggest_meeple() {
  char c;
  int choice = -1;
  printf("=> Do you want to put a meeple: n for NO y for yes?:  ");
  scanf("\n%c" , &c);

  if (c == 'y') {
    printf("to put the Meeple on LEFT   type 0\n");
    printf("to put the Meeple on TOP    type 1\n");
    printf("to put the Meeple on RIGHT  type 2\n");
    printf("to put the Meeple on BOTTOM type 3\n");
    printf("to put the Meeple on CENTER type 4\n");
    scanf("%d", &choice);
    return choice;
  }
  return -1;
}

void print_error(Result result) {
  switch (result) {
  case OK:
    printf("OK.\n");
    break;
  case EMPTY_STACK:
    printf("The stack is empty.\n");
    break;
  case INVALID_TURN:
    printf("Invalid turn.\n");
    break;
  case VALID_GRID_POSTION:
    printf("The position is valid on the grid.\n");
    break;
  case INVALID_GRID_POSTION:
    printf("The position is invalid on the grid.\n");
    break;
  case MATCHING_BORDERS:
    printf("The borders match.\n");
    break;
  case UNMATCHING_BORDERS:
    printf("The borders do not match.\n");
    break;
  case CONQUERED_ROAD:
    printf("can not put meeple on that square the raod alreay conquered");
    break;
  case UPDATED_ROADS:
    printf("Updated roads");
    break;
  default:
  case NOT_UPDATED_ROADS:
    printf("no need to update roads\n");
    break;
    printf("Unknown error.\n");
    break;
  }
}

int get_rand_number(int max) {
    srand(time(NULL)); // Seed the random number generator with the current time
    return rand() % (max + 1); // Generate a random number between 0 and max
}


int get_rand_number_for_rotation(Valid_squares *vs, int x, int y) {
  int i = 0;
  int choice = 0;
  int arr[4] = {-1, -1, -1, -1};


  for (i = 0; i < vs->size; i++) {
    if (vs->arr[i].coor.x == x && vs->arr[i].coor.y == y)
      break;
  }

  if (vs->arr[i].possible_fits > 1) {
    int j = 0;
    for (j = 0; j < 4; j++) {
      if (vs->arr[i].orientation[j] == 1) {
        return j;
      }
    }
  } else {
    printf("there is only one valid way to put the tile \n");
    for (int j = 0; j < 4; j++) {
      if (vs->arr[i].orientation[j] == 1) {
        return j;
      }
    }
  }
}

