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
    if (empty_queue(queue))
    {
        return -1;
    }

    printf("Fila: [ ");
    int position = queue->init;
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d", queue->items[position]);

        if (i < queue->size - 1)
        {
            printf(", ");
        }

        position = (position + 1) % MAX_ELEMENTS;
    }
    printf(" ]");
}


int front(static_queue *queue)
{
    if (empty_queue(queue))
    {
        return -1;
    }

    return queue->items[queue->init];
}


void queue_size(static_queue *queue)
{
    return queue->size;
}


bool enqueue(static_queue *queue, int value)
{
    if (full_queue(queue))
    {
        return false;
    }

    queue->items[queue->end] = value;
    queue->end = (queue->end + 1) % MAX_ELEMENTS;
    queue->size++
    return true;
}


int dequeue(static_queue *queue)
{
    if (empty_queue(queue))
    {
        return false;
    }

    int removed_value = queue->items[queue->init];
    queue->init = (queue->init + 1) % MAX_ELEMENTS;
    queue->size--;
    return removed_value;
}