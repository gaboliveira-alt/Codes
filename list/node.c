#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *phrase;
    struct node *next;    
}
node;


int main()
{
    node *list = NULL;

    node *element = (node *)malloc(sizeof(node));

    element->phrase = "Hi";
    element->next = NULL;

    list = element;

    element = (node *)malloc(sizeof(node));
    element->phrase = "Hey";
    element->next = list;

    list = element;

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->phrase);
        ptr = ptr->next;
    }

    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
