#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 50

typedef struct 
{
    int items[MAX_ELEMENTS];
    int size;
    int end;
}
static_queue;


int main()
{
    return 0;
}


void create_queue(static_queue *queue)
{
    queue->size = 0;
}


void empty_queue(static_queue *queue)
{
    if (queue->size == 0)
    {
        printf("Fila vazia!\n")
        return;
    }
}


void full_queue(static_queue *queue)
{
    if (queue->size < MAX_ELEMENTS - 1)
    {
        printf("Fila cheia!\n");
        return;
    }
}


void print_queue(static_queue *queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        printf("Fila: %d ", i);
    }
    printf("\n");
}