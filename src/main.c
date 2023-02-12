#include "./../include/Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename = "docs/list_tiles.csv";
  Stack *s = stack_create();
  read_tiles_file(filename, s);
  // stack_show(s);
  stack_summary(s);
  printf("\n");
  stack_mix(s);
  stack_summary(s);

  return 0;
}
