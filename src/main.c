#include <stdio.h>
#include <stdlib.h>
#include "./../include/Stack.h"
#include "./../include/Grid.h"

int main() {
  char *filename = "docs/list_tiles.csv";
  Stack *s = stack_create();
  Grid *g = grid_create();
  read_tiles_file(filename, s);
  // stack_show(s);
  stack_summary(s);
  printf("\n");
  stack_mix(s);
  stack_summary(s);

  grid_put_tile(g , s->head->t ,  0 , 0);

  printf("\n");
  //  grid_show(g);

  tile_print(s->head->t);   
  

  return 0;
}
