#include <stdio.h>
#include <stdlib.h>
#include "./../include/Grid.h"
#include "./../include/Open_squares.h"
#include "./../include/Game.h"
#include "./../include/Grid_Validator.h"
#include "./../include/Player.h"
#include "./../include/Stack.h"

int main(void) {
  char *filename = "docs/list_tiles.csv";
  Stack *s = stack_create();
  Grid *g = grid_create();
  read_tiles_file(filename, s);
  // tile_print(s->head->t);
  //  stack_shuffle(s);
  //  stack_summary(s);
  // stack_summary(s);
  // stack_show(s);
  Player *p1 = player_create(RED, "zineddine", 26, HUMAN);
  Player *p2 = player_create(GREEN, "soufyane", 26, AI);
  Player *p3 = player_create(BLACK, "manel", 26, HUMAN);
  Player *p4 = player_create(BLUE, "khireddine", 26, AI);
  Player *p5 = player_create(YELLOW, "Jedda", 26, AI);

  Player *players_arr[5] = {p1, p2, p3, p4, p5};
  /*
   * player_show(p1);
   * player_show(p2);
   */
  Game *gm = game_init(players_arr, g, s, 5);
  for (int i = 0; i < (int)gm->num_players; i++) {
  
    // player_show(gm->players[i]);
  }
  Open_squares *os = open_squares_init();
  // grid_cut_show(g, 71, 71, 5);
  // open_squares_print(os);
  
  Tile *t = stack_pop(s);
  Tile *t2 = stack_pop(s);
  tile_print(t);
  tile_print(t2);

  Coordinate pos = {71 , 72};
  grid_put_tile(s, g, t, p1, pos, os);
  open_squares_update(g, os, 71, 72);
  // open_squares_print(os);
  // grid_cut_show(g, 71, 71, 5);

  Coordinate pos1 = {71 , 73};
  grid_put_tile(s, g, t2, p1, pos1, os);
  open_squares_update(g, os, 71, 73);
  open_squares_print(os);
  grid_cut_show(g, 71, 71, 5);
  return (0);
}
