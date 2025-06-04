#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_ELEMENTS 100


typedef struct 
{
    int items[MAX_ELEMENTS];
    int front;
    int rear;
    int size;
}
static_deque;


int main()
{
    return 0;
}


void createDeque(static_deque *deque)
{
    deque->size = 0;
    deque->front = 0;
    deque->rear = 0;
}


bool isEmpty(static_deque *deque)
{
    if (deque->size == 0)
    {
        printf("Deque vazio!\n");
        return true;
    }
}


bool isFull(static_deque *deque)
{
    return (deque->size >= MAX_ELEMENTS);
}


bool insertRear(static_deque *deque, int value)
{
    if (isFull(deque))
    {
        return false;
    }


    deque->items[deque->rear] = value;
    deque->rear = (deque->rear + 1) % MAX_ELEMENTS;
    deque->size++;
    return true;
}


bool insertFront(static_deque *deque, int value)
{
    if (isFull(deque))
    {
        return false;
    }


    deque->front = (deque->front - 1 + MAX_ELEMENTS) % MAX_ELEMENTS;
    deque->items[deque->front] = value;
    deque->size++;
    return true;
}


int deleteFront(static_deque *deque)
{
    if (isEmpty(deque))
    {
        return false;
    }


    int removedItem = deque->items[deque->front];
    deque->front = (deque->front + 1) % MAX_ELEMENTS;
    deque->size--;
    return removedItem;
}


int deleteRear(static_deque *deque)
{
    if(isEmpty(deque))
    {
        return false;
    }


    deque->rear = (deque->rear - 1 % MAX_ELEMENTS) % MAX_ELEMENTS;
    int removedItem = deque->items[deque->rear];
    deque->size--;
    return removedItem;
}


int getFront(static_deque *deque)
{
    if (isEmpty(deque))
    {
        return false;
    }

    return deque->items[deque->front];
}


int getRear(static_deque *deque)
{
    if (isEmpty(deque))
    {
        return false;
    }


    int rear = (deque->rear - 1 % MAX_ELEMENTS) % MAX_ELEMENTS;
    return deque->items[rear];
}


void printDeque(static_deque *deque)
{
    if (isEmpty(deque))
    {
        return false;
    }


    printf("Deque: [");
    int i = deque->front;

    for (int count = 0; count < deque->size; count++)
    {
        printf("%d", deque->items[i]);

        if (count < deque->size - 1)
        {
            printf(", ");
        }

        i = (i + 1) & MAX_ELEMENTS;
    }
    printf(" ]\n");
}