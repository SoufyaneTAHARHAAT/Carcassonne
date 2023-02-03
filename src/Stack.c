#include <stdio.h>
#include "./../include/Stack.h"

void read_tiles_file(char *filename, Stack *s){
    FILE *file = fopen(filename , "r");
    char content[1024];
    if (file == NULL)
    {
        printf("could not read tile file\n");
        return;
    }
    
    while (fscanf(file , "%s" , content) != EOF)
    {   
        printf("%s\n" , content);
    }
    
    fclose(file);
}