#include <stdio.h>
#include <stdlib.h>
#include "./../include/Player.h"
// verstile
int id_player_indicator = 0;

Player * player_create(Color player_color  , char *name , short age) {
    Player *p = (Player *)malloc(sizeof(Player));
    check_null((void *)p  , "could not allocate memory for struct player !!!");
    p->id_player = id_player_indicator;
    p->player_color = player_color;
    p->name = name;
    p->age = age;
    p->turn_to_play = false;
    p->score = 0;
    p->tiles_history = NULL;
    return p;
}


void player_show(Player *p) {
    printf("name : %s\n" , p->name);
    printf("score : %d\n" , p->score);
    switch (p->player_color)
    {
    case RED:
            printf("color : RED\n");
        break;
    case GREEN:
            printf("color : GREEN\n");
        break;
    case YELLOW:
            printf("color : YELLOW\n");
        break;
    case BLUE:
            printf("color : BLUE\n");
        break;
    case BLACK:
            printf("color : BLACK\n");
        break;
    default:
        break;
    }
    
    printf("turn to play %d\n" , p->turn_to_play);
}



