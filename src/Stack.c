#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./../include/Stack.h"
#include "./../include/Tile.h"




void read_tiles_file(char *filename, Stack *s)
{
    FILE *file = fopen(filename, "r");
    char content1[10], content2[10], content3[10], content4[10], content5[10];
    check_null((void *)file, "could read the file");
    while (
        fscanf(file, "%10[^,],%10[^,],%10[^,],%10[^,],%s\n", content1, content2, content3, content4, content5) != EOF)
    {
        Tile *t = tile_create(content1, content2, content3, content4, content5);
        // show_tile(*t);
        stack_push(s , t);;
    }

    fclose(file);
}

Stack *stack_create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    check_null((void *)s, "could not allocate memory for Stack");
    s->tiles_number = 0;
    s->head = NULL;
    return s;
}

void stack_push(Stack *s, Tile *t)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    check_null((void *)new_node, "could not allocate memory for Node");
    if (s->head == NULL)
    {
        s->head = new_node;
        new_node->t = t;
        new_node->next = NULL;
        s->tiles_number++;
    }
    else
    {
        new_node->t = t;
        new_node->next = s->head;
        s->head = new_node;
        s->tiles_number++;
    }
}

Tile * stack_pop(Stack*s) {
    check_null((void *)s->head , "No pop operation allowed, stack is empty");

    // if there is only one tile left in the stack
    if (s->head->next == NULL) {
        free(s->head);
        s->head = NULL;
        s->tiles_number = 0;
        return NULL;
    }
    else {
        Node * temp = s->head;
        s->head = s->head->next;
        free(temp);
        s->tiles_number--;
        return temp->t;
    }
}

void stack_show(Stack *s) {
    Node *temp = s->head;
    while (temp != NULL)
    {
        // printf("id tile = %d ->" , temp->t->id_tile);
        tile_print(temp->t);
        temp  = temp->next;
    }
    printf("\n");
}



void stack_mix(Stack *s) {
    srand( time( NULL ) );
    for (int i = 0; i < (int)s->tiles_number; i++)
    {
        int r1 = rand();
        int rand_one = (r1++ % s->tiles_number); // 5
        Node * n1 = stack_nth_node(  s->head, rand_one);
        int r2 = rand();
        int rand_two = (r2++ % s->tiles_number); // 10
        Node * n2 = stack_nth_node(s->head  , rand_two); 
        stack_swap_nodes(n1 , n2);
    }
}


Node *stack_nth_node( Node *head, __u_int n){
    Node * temp = head;
    int counter = 0;
    while (counter < (int)n) {
        temp = temp->next;
        counter++;
    }
    return temp;
}


void stack_swap_nodes(Node * n1 , Node *n2) {
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->t = n1->t;
    temp->next = n1->next;

    // n1 = n2;
    n1->t = n2->t;
     // n2 = temp
    n2->t = temp->t;

    free(temp);
}

void stack_summary(Stack *s) {
    Node *temp = s->head;

    while (temp !=NULL)
    {
        printf(" %d " , temp->t->id_tile);
        temp = temp->next;
    }
    
}

void check_null(void *n, char *msg)
{
    if (n == NULL)
    {
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}