#include <stdio.h>
#include <stdlib.h>
#include "./../include/Stack.h"


int main() {
    char * filename = "docs/list_tiles.csv";
    Stack *s = (Stack *)malloc(sizeof(Stack));
    read_tiles_file(filename , s);
    return 0;
}

