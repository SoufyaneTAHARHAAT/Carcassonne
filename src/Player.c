#include <stdio.h>
#include <stdlib.h>
#include "./../include/Player.h"
#include "./../include/Meeple.h"
// verstile
int id_player_indicator = 0;

Player *player_create(Color player_color, char *name, short age, Player_category player_cat)
{
    Player *p = (Player *)malloc(sizeof(Player));
    check_null((void *)p, "could not allocate memory for struct player !!!");
    p->id_player = ++id_player_indicator;
    p->player_color = player_color;
    p->name = name;
    p->age = age;
    p->turn_to_play = false; // consider the case where the first player must have "turn_to_play" as true
    p->score = 0;
    switch (player_cat)
    {
        case HUMAN:
            p->player_cat = HUMAN;
            break;
        case AI:
            p->player_cat = AI;
        default:
            break;
    }
    p->tiles_history = NULL;
    // because one Meeple will be used to indicate score
    for (int i = 0; i < MEEPLES_NUM; i++)
    {
        p->meeples_arr_out_grid[i] = meeple_create(player_color);
    }
    
    // in the  start all meeples are out of the grid
    for (int i = 0; i < MEEPLES_NUM; i++)
    {
        p->meeples_arr_in_grid[i] = NULL;
    }
    return p;
}

void player_show(Player *p)
{
    printf("id : %d \n", p->id_player);
    printf("name : %s\n", p->name);
    switch (p->player_cat)
    {
    case HUMAN:
        printf("player category: HUMAN\n");
        break;
    case AI:
        printf("player category: AI\n");
        break;
    default:
        break;
    }
    printf("score : %d\n", p->score);
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

    for (int i = 0; i < MEEPLES_NUM; i++)
    {
        if (p->meeples_arr_out_grid[i] != NULL) {
        printf("Meeple n:%d, position:{%d , %d} " , i+1 , p->meeples_arr_out_grid[i]->position.x , p->meeples_arr_out_grid[i]->position.y);
        printf("OUT_GRID \n");
      }
    }
    
  
    for (int i = 0; i < MEEPLES_NUM; i++)
    {
        if (p->meeples_arr_in_grid[i] != NULL) {
        printf("Meeple n:%d, position:{%d , %d} " , i+1 , p->meeples_arr_in_grid[i]->position.x , p->meeples_arr_in_grid[i]->position.y);
        printf("IN_GRID \n");
      }
    }

    if (p->turn_to_play) printf("turn to play: true\n");
    else printf("turn to play: false\n");
}
