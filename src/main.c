#include <stdio.h>
#include <stdlib.h>
#include "./../include/Stack.h"


int main() {
    char * filename = "docs/list_tiles.csv";
    Stack *s = create_stack();
    read_tiles_file(filename , s);
    show_stack(s);
    return 0;
}

