#include <stdio.h>
#include <stdlib.h>
#include "./../include/Game.h"
#include "./../include/Grid.h"
#include "./../include/Grid_Validator.h"
#include "./../include/Open_squares.h"
#include "./../include/Player.h"
#include "./../include/Stack.h"
#include "./../include/Valid_squares.h"

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
  Game *gm = game_init(players_arr, g, s, 5);
  for (int i = 0; i < (int)gm->num_players; i++) {
    // player_show(gm->players[i]);
  }
  int player_index_turn = 0;
  Open_squares *os = open_squares_init();
  Valid_squares *vs = valid_squares_init();
    // grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);
  open_squares_print(os);
  while (true) {
    Tile *t = stack_pop(s);
    tile_print(t);
    valid_squares_update(vs, os, t);
    valid_squares_print(vs);
    Coordinate pos = game_suggest_valid_squares(vs);
    int x = pos.x, y = pos.y;
    int num_rotation = game_suggest_tile_rotation(vs, x, y);
    tile_rotate(t, num_rotation);
    tile_print(t);
    // int put_meeple = game_suggest_meeple(players_arr[player_index_turn]);
  //  break;
    grid_put_tile(s, g, t, p1, x, y, os);
    open_squares_update(g, os, x, y);
    grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);
  }
  return (0);
}
