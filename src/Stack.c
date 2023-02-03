#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../include/Stack.h"
#include "./../include/Tile.h"

void read_tiles_file(char *filename, Stack *s){
    FILE *file = fopen(filename , "r");
    char content1[10] , content2[10] , content3[10] , content4[10] , content5[10];
    if (file == NULL)
    {
        printf("could not read tile file\n");
        exit(EXIT_FAILURE);
        return;
    }
    
    while (
        fscanf(file , "%10[^,],%10[^,],%10[^,],%10[^,],%s\n" , content1 , content2 , content3, content4 , content5) != EOF
        )
    {   
       create_tile(content1 , content2, content3 ,content4 , content5);
        break;
    }
    
    fclose(file);
}

Stack * create_stack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("clould not allocate enough memory for satck structure\n");
        exit(EXIT_FAILURE);
    }
    s->tiles_number = 0;
    s->list_tiles = NULL;
    return s;
}