#include <stdio.h>
#include <stdlib.h>
#include "./../include/Stack.h"
#include "./../include/Grid.h"
#include "./../include/Game.h"
#include "./../include/Player.h"

int main(void)
{
char *filename = "docs/list_tiles.csv";
Stack *s = stack_create();
Grid *g = grid_create();
read_tiles_file(filename, s);
//tile_print(s->head->t);
// stack_shuffle(s);
stack_summary(s);
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
for (int i = 0; i < (int)gm->num_players; i++)
//player_show(gm->players[i]);

return (0);
}
