#include <stdio.h>
#include <stdbool.h>

#define MAX_ELEMENTS 50

typedef struct 
{
    int items[MAX_ELEMENTS];
    int init;
    int end;
    int size;
}
static_queue;


int main()
{
    return 0;
}


void create_queue(static_queue *queue)
{
    queue->init = 0;
    queue->end = 0;
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


int full_queue(static_queue *queue)
{
    return ((queue->end + 1) % MAX_ELEMENTS == queue->init); 
}


void print_queue(static_queue *queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        printf("Fila: %d ", i);
    }
    printf("\n");
}


bool enqueue(static_queue *queue, int value)
{
    if (full_queue)
    {
        return false;
    }

    queue->end[queue->size] = value;
    queue->size++;
    return true;
}