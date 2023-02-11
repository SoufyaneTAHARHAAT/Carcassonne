#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        Tile *t = create_tile(content1, content2, content3, content4, content5);
        // show_tile(*t);
        push_to_stack(s , t);;
    }

    fclose(file);
}

Stack *create_stack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    check_null((void *)s, "could not allocate memory for Stack");
    s->tiles_number = 0;
    s->head_list = NULL;
    return s;
}

void push_to_stack(Stack *s, Tile *t)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    check_null((void *)new_node, "could not allocate memory for Node");
    if (s->head_list == NULL)
    {
        s->head_list = new_node;
        new_node->t = t;
        new_node->next = NULL;
    }
    else
    {
        new_node->t = t;
        new_node->next = s->head_list;
        s->head_list = new_node;
    }
}


void show_stack(Stack *s) {
    Node *temp = s->head_list;
    while (temp != NULL)
    {
        // printf("id tile = %d ->" , temp->t->id_tile);
        print_tile(temp->t);
        temp  = temp->next;
    }
    printf("\n");
}

void check_null(void *n, char *msg)
{
    if (n == NULL)
    {
        printf("%s\n", msg);
        exit(EXIT_FAILURE);
    }
}