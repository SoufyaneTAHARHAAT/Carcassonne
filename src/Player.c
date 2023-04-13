#include <stdio.h>
#include <stdlib.h>
#include "./../include/Player.h"
#include "./../include/Meeple.h"
#include "./../include/Grid.h"
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
    Coordinate pos = {-1 , -1};
    for (int i = 0; i < MEEPLES_NUM; i++)
    {
        p->meeples_arr[i] = pos;
    }
    p->num_meeples_in_grid = 0;
    p->num_meeples_out_grid = 7;
    return p;
}

void player_move_meeple_to_grid(Grid *g, Player *p, int x, int y, Borders border){
    if (g->tab[x][y].square_state == EMPTY){
        printf("this is not supposed to happen\n");
        exit(EXIT_FAILURE);
    }

    switch (border)
    {
    case LEFT:
        g->tab[x][y].t->borders[0].meepled = true;
        break;
    case TOP:
        g->tab[x][y].t->borders[1].meepled = true;
        break;
    case RIGHT:
        g->tab[x][y].t->borders[2].meepled = true;
        break;
    case BOTTOM:
        g->tab[x][y].t->borders[3].meepled = true;
        break;
    case CENTER:
        g->tab[x][y].t->borders[4].meepled = true;
        break;
    default:
        break;
    }

    p->meeples_arr[p->num_meeples_in_grid].x = x;
    p->meeples_arr[p->num_meeples_in_grid].y = y;
    p->num_meeples_in_grid++;
    p->num_meeples_out_grid--;
}

void player_move_meeple_out_grid(Player *p)
{
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
        printf("Meeple n:%d, position:{%d , %d} ", i + 1, p->meeples_arr[i].x, p->meeples_arr[i].y);
    }
    printf("\n");
    if (p->turn_to_play)
        printf("turn to play: true\n");
    else
        printf("turn to play: false\n");
}
