#ifndef ROAD_CONSTRUCTION_H
#define ROAD_CONSTRUCTION_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/Grid.h"
#include "./../include/Tile.h"
#include "./../include/Player.h"
#include "./../include/Open_squares.h"
#include "./../include/Result.h"
#include "./../include/coordinate.h"

struct r_node_t {
   Borders border;
   Coordinate pos;
  struct r_node_t *next;
  struct r_node_t *prev;
};
typedef struct r_node_t r_node;

struct Double_linked_list_info_t
{
  r_node *origine;
  r_node * head;
  r_node * tail;
};
typedef struct Double_linked_list_info_t Double_linked_list_info;

struct Road_t
{
    Double_linked_list_info *dll; // pointer to road node the doubly linked list  
    bool conquered; // true means road is taken can not put a meeple
    Player *owners[5]; // array of players
    int num_meeples[5]; // array for num_meeples for every player
};
typedef struct Road_t Road;

// whynot to make this like kind of static
// if I can know the number of Roads I can compose in carcassone game 
// it will much more better because I want have to deal with malloc and memory every time
struct Roads_construction_t {
    Road ** arr;
    int size;
};
typedef struct Roads_construction_t Roads_construction;

Roads_construction * roads_construction_init();
Result roads_construction_update(Roads_construction *rd, Grid *g, Tile *t, int x, int y);
Road *roads_construction_add_road(Roads_construction *R, Borders b, int x, int y);
void Roads_construction_print(Roads_construction *roads_construction);
/*Road * roads_construction_add_road(Borders b, int x, int y);*/


Double_linked_list_info * double_linked_list_info_create(); 

Road * roads_construction_search_road(Roads_construction *rd, int x, int y); 

void double_linked_list_append_in_beg(r_node** head , Borders B , int x, int y);
void double_linked_list_append_in_end(r_node** tail, Borders B , int x, int y);
void double_linked_list_append_in_origin(Double_linked_list_info *dll, Borders B, int x, int y);

// function to return the number of road in a tile;
int get_tile_number_of_roads(Tile *t);
void check_neighbors(Grid *g, int x, int y, Borders tab[4]);
bool is_center_road(Tile *t);


#endif
