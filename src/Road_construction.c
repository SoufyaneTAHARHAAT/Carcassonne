#include <stdio.h>
#include <stdlib.h>
#include "./../include/Player.h"
#include "./../include/Meeple.h"
#include "./../include/Tile.h"
#include "./../include/Road_construction.h"



// x and y for the last put Tile
Result roads_construction_update(Roads_construction *rd, Grid *g, Tile *t, int x, int y)
{
  
  int num_road = get_tile_number_of_roads(t);
  bool center_is_road = is_center_road(t);
  if (num_road == 0) return NOT_UPDATED_ROADS;

  // 0 means that  the first neighbor is an open square 
  // 1 means that right border fo the first neighbor contains a road 
  Borders are_neighbors_roads[4] = {0 , 0 , 0, 0}; 
  
  bool temp = false;
  check_neighbors(g, t, x, y, are_neighbors_roads);
  Borders b = LEFT;
  switch (num_road) {
    // if there is a road we add it an exsting one 
    // otherwise create a new Road;
    case 1:
    // we look through the neighbor
    // becuase we are in case: 1 am sure there is only one road

      for(int i = 0; i < 4; i++)
      {
        if (are_neighbors_roads[i] == 1)
          {
            b = i;
            break;
          }
         if (i == 3) temp = true;
      }
      
      // we add the current road to an existing Roads_construction;
      // we must find the to wich part we add the current Road;
      if (!temp)
      {
          Road * road = roads_construction_search_road(rd, x, y);
          if (road->dll->head->pos.x == x && road->dll->tail->pos.y)
           double_linked_list_append_in_beg(&road->dll->head, b, x, y); 
          else double_linked_list_append_in_end(&road->dll->tail, b, x, y);
      }
      // we create a new Road;
      else {
        roads_construction_add_road(b, x, y);
      }
    
    break;
    case 2:


    break;
    case 3:
    
    break;
    case 4:
    break;
  }  
}


Roads_construction * roads_construction_init()
{
  Roads_construction * road_cons = (Roads_construction *)malloc(sizeof(Roads_construction));
  check_null((void *)road_cons, "could not allocate memory for Roads_construction struct");
  // becuase the specail tile already contains a special tile we can crate a Road
  road_cons->arr = malloc(sizeof(Road *)); 
  road_cons->arr[0] = roads_construction_add_road(CENTER, SPECIAL_TILE_X_POS, SPECIAL_TILE_Y_POS);
  road_cons->size = 1;
  return road_cons;
}

// must to forget to add the pointers to every plyer 
Road * roads_construction_add_road(Borders b, int x, int y)
{
  Road * rd = (Road *)malloc(sizeof(Road));
  check_null((void *)rd, "could not allocate memory for Road struct");
  // create the double linked list
  rd->dll = double_linked_list_info_create();

  r_node * node = (r_node*)malloc(sizeof(r_node));

  node->border = b;
  node->pos.x = x;
  node->pos.y = y;
  node->next = node->prev = NULL;
  
  rd->dll->origine = node;
  rd->dll->head = node;
  rd->dll->tail = node;
  rd->conquered = false;

  return rd;
}


// search in all Roads and return a road that goes through x and y coordinates
// of course we need to check only the head and th tail
Road * roads_construction_search_road(Roads_construction *rd, int x, int y)
{

 Road **ptr_roads = rd->arr; 

  for(int i = 0; i < rd->size; i++) {

    if ((ptr_roads[i]->dll->head->pos.x == x && ptr_roads[i]->dll->head->pos.y == y) ||
        (ptr_roads[i]->dll->tail->pos.y == x && ptr_roads[i]->dll->tail->pos.y == y) )
      {
          return ptr_roads[i];
      }
  }

  return NULL; 

}



Double_linked_list_info * double_linked_list_info_create() {
  Double_linked_list_info *dll = (Double_linked_list_info *)malloc(sizeof(Double_linked_list_info));
  dll->origine = NULL;
  dll->head = NULL;
  dll->tail = NULL;
  return dll;
}

void double_linked_list_append_in_beg(r_node** head , Borders B , int x, int y)
{
  r_node* new_node = (r_node*)malloc(sizeof(r_node));
  check_null((void *)new_node, "could not allocate memory for new_node in double_linked_list_append_in_beg");

  new_node->border = B;
  new_node->pos.x = x;
  new_node->pos.y = y;
  new_node->prev = NULL;

  if (*head == NULL) {  // If the list is empty
    new_node->next = NULL;
    *head = new_node;
    return;
  }

  // If the list is not empty
  new_node->next = *head;
  (*head)->prev = new_node;
  *head = new_node;
}

void double_linked_list_append_in_end(r_node** tail , Borders B , int x, int y)
{
  r_node* new_node = (r_node*)malloc(sizeof(r_node));
  check_null((void *)new_node, "could not allocate memory for new_node in double_linked_list_append_in_beg");

  new_node->border = B;
  new_node->pos.x = x;
  new_node->pos.y = y;
  new_node->next = NULL;

  if (*tail == NULL) {  // If the list is empty
    new_node->next = NULL;
    *tail = new_node;
    return;
  }

  // If the list is not empty
  new_node->prev = *tail;
  (*tail)->next = new_node;
  *tail = new_node;
}
void double_linked_list_append_in_origin(Double_linked_list_info* dll , Borders B , int x, int y)
{
  r_node* new_node = (r_node*)malloc(sizeof(r_node));
  check_null((void *)new_node, "could not allocate memory for new_node in double_linked_list_append_in_origin");

  new_node->border = B;
  new_node->pos.x = x;
  new_node->pos.y = y;
  new_node->next = dll->origine;
  new_node->prev = NULL;

  if (dll->origine != NULL) {  // If the list is not empty
    dll->origine->prev = new_node;
  } else {  // If the list is empty
    dll->tail = new_node;
  }

  dll->origine = new_node;
}


int get_tile_number_of_roads(Tile *t) {

  int count = 0;
  for (int i = 0; i < 4; i++)
      if (t->borders[i].landscape == ROAD) count++;

  return count;
}

bool is_center_road(Tile *t) {
  
  return t->borders[4].landscape == ROAD;
}

 
void check_neighbors(Grid *g,Tile *t,  int x, int y, Borders tab[4])
{
  // check the left 
  if (g->tab[x][y - 1].square_state != EMPTY) tab[0] = 1; // there is  road   

  // check the top
  if (g->tab[x - 1][y].square_state != EMPTY) tab[1] = 1;

  // check the right
  
  if (g->tab[x][y + 1].square_state != EMPTY) tab[2] = 1;   

  // check the bottom
  if (g->tab[x + 1][y].square_state != EMPTY) tab[3] = 1;   
}

void double_linked_list_append_in_origin(Double_linked_list_info* dll , Borders B , int x, int y)
{
  r_node* new_node = (r_node*)malloc(sizeof(r_node));
  check_null((void *)new_node, "could not allocate memory for new_node in double_linked_list_append_in_origin");

  new_node->border = B;
  new_node->pos.x = x;
  new_node->pos.y = y;
  new_node->next = dll->origine;
  new_node->prev = NULL;

  if (dll->origine != NULL) {  // If the list is not empty
    dll->origine->prev = new_node;
  } else {  // If the list is empty
    dll->tail = new_node;
  }

  dll->origine = new_node;
}
