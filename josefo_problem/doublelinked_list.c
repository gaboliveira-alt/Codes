#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int soldier_number;
    struct node *prev;
    struct node *next;
}
node;


typedef struct
{
    int size;
    node *sentinel;
    node *end;
}
linked_list;


int main()
{
    return 0;
}


void create_list(linked_list *list)
{
    list->size = 0;
    list->sentinel = NULL;
    list->end = NULL;
}


void empty_list(linked_list *list)
{
    if (list->sentinel == NULL)
    {
        printf("Lista vazia\n");
        return;
    }


    node *ptr = list->sentinel;
    while (ptr != NULL)
    {
        node *node_to_free = ptr;
        ptr = ptr->next;
        free(node_to_free);
    }

    list->sentinel = NULL;
    list->end = NULL;
    list->size = 0;
}


void destroy_list(linked_list *list)
{
    empty_list(&list);
    free(list);
}


