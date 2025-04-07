#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *info;
    struct node *next;
}
node;


int main()
{
    node *list = NULL;

    node *elements = (node *)malloc(sizeof(node));
    elements->info = "Denis";
    elements->next = NULL;
    list = elements;

    elements = (node *)malloc(sizeof(node));
    elements->info = "Fabricio";
    elements->next = list;
    list = elements;

    elements = (node *)malloc(sizeof(node));
    elements->info = "Ruan";
    elements->next = list;
    list = elements;

    elements = (node *)malloc(sizeof(node));
    elements->info = "Fco Neto";
    elements->next = list;
    list = elements;

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->info);
        ptr = ptr->next;
    }
    
    return 0;
}
