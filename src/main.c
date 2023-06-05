#include <stdio.h>
#include <stdlib.h>
#include "./../include/Game.h"
#include "./../include/Grid.h"
#include "./../include/Grid_Validator.h"
#include "./../include/Open_squares.h"
#include "./../include/Player.h"
#include "./../include/Stack.h"
#include "./../include/Valid_squares.h"
#include "./../include/Road_construction.h"

int main(void)
{
  char *filename = "docs/list_tiles.csv";
  Stack *s = stack_create();
  Grid *g = grid_create();

  grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);
  grid_cut_show_v3(g, SPECIAL_TILE_X_POS - 4, SPECIAL_TILE_X_POS - 4, 8);
  // exit(0);

  read_tiles_file(filename, s);
  // tile_print(s->head->t);
  //  stack_shuffle(s);
  //  stack_summary(s);
  // stack_summary(s);
  // stack_show(s);
  Player *p1 = player_create(RED, "zineddine", 26, AI);
  Player *p2 = player_create(GREEN, "soufyane", 26, AI);
  // Player *p3 = player_create(BLACK, "manel", 26, HUMAN);
  // Player *p4 = player_create(BLUE, "khireddine", 26, AI);
  // Player *p5 = player_create(YELLOW, "Jedda", 26, AI);

  Player *players_arr[5] = {p1, p2, NULL, NULL, NULL};
  Game *gm = game_init(players_arr, g, s, 2);
  for (int i = 0; i < (int)gm->num_players; i++)
  {
    player_show(gm->players[i]);
  }
  int player_index_turn = 0;
  Open_squares *os = open_squares_init();
  Valid_squares *vs = valid_squares_init();
  Roads_construction *rd = roads_construction_init();
  // Roads_construction_print(rd);
  printf("--------------------------------------------------\n");
  // grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);
  // open_squares_print(os);

  int nunber_of_executions = 0;
  while (true)
  {
    nunber_of_executions++;
    printf("nunber_of_executions = %d\n", nunber_of_executions);
    /* SHOW  INFO ABOUT THE GAME */
    // player_show(players_arr[player_index_turn]);
    /*------- START POP STACK FROM THE TILE ----------*/
    open_squares_print(os);

    Tile *t = stack_pop(s);
    // stack_show(s);
    printf("\n\tTILE POPPED FROM STACK\n");
    tile_print(t);
    /*------- END POP STACK FROM THE TILE ----------*/

    /*------- START SUGGEST VALID SQUARES ----------*/
    valid_squares_update(vs, os, t);
    valid_squares_print(vs);

    if (players_arr[player_index_turn]->player_cat == AI)
    {
      printf("AI is playing\n");
      int rand = get_rand_number(vs->size - 1);
      printf("rand = %d\n", rand);
      int x = vs->arr[rand].coor.x;
      int y = vs->arr[rand].coor.y;

      int rand_rotation = get_rand_number_for_rotation(vs, x, y);
      printf("rand_rotation = %d\n", rand_rotation);
      tile_rotate(t, rand_rotation);
      printf("\n\tTILE AFTER ROTATION\n");
      tile_print(t);
      grid_put_tile(s, g, t, players_arr[player_index_turn], x, y, os);
      Result rs = roads_construction_update(rd, g, t, x, y);
      print_error(rs);

      int rand_meeple = get_rand_number(1);
      printf("rand_meeple = %d\n", rand_meeple);
      // if (rand_meeple == 1)
      // {
      //   int radom_border = get_rand_number(4);
      //   roads_construction_conquere_road(rd, players_arr[player_index_turn], player_index_turn, x, y);
      //   player_move_meeple_to_grid(g, players_arr[player_index_turn], x, y, (Borders)radom_border);
      //   printf("radom_border = %d\n", radom_border);
      // }

      Roads_construction_print(rd);
      valid_square_destory(vs);
      open_squares_update(g, os, x, y);
      grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);
      grid_cut_show_v3(g, SPECIAL_TILE_X_POS - 4, SPECIAL_TILE_X_POS - 4, 8);
      Roads_construction_finished_roads(rd, g);
      player_index_turn++;
      if (player_index_turn == gm->num_players)
        player_index_turn = 0;
    }

    else
    {
      Coordinate pos = game_suggest_valid_squares(vs);
      int x = pos.x, y = pos.y;
      /*------- END SUGGEST VALID SQUARES ----------*/

      /*------- START SUGGEST TILE ROTATION ----------*/
      int num_rotation = game_suggest_tile_rotation(vs, x, y);
      tile_rotate(t, num_rotation);
      printf("\n\tTILE AFTER ROTATION\n");
      tile_print(t);
      /*------- END SUGGEST TILE ROTATION ----------*/

      grid_put_tile(s, g, t, players_arr[player_index_turn], x, y, os);
      /*------- START SUGGEST TO PUT MEEPLE ----------*/
      Result rs = roads_construction_update(rd, g, t, x, y);
      print_error(rs);

      int put_meeple_on = game_suggest_meeple();
      if (put_meeple_on != -1)
      {
        roads_construction_conquere_road(rd, players_arr[player_index_turn], player_index_turn, x, y);
        player_move_meeple_to_grid(g, players_arr[player_index_turn], x, y, (Borders)put_meeple_on);
      }

      Roads_construction_print(rd);
      /*------- END SUGGEST TO PUT MEEPLE ----------*/

      valid_square_destory(vs);
      open_squares_update(g, os, x, y);
      grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);
      grid_cut_show_v3(g, SPECIAL_TILE_X_POS - 4, SPECIAL_TILE_X_POS - 4, 8);

      Roads_construction_finished_roads(rd, g);
      player_index_turn++;
      if (player_index_turn == gm->num_players)
        player_index_turn = 0;
    }
  }
  return (0);
}
