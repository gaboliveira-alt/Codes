#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}
node;

typedef struct linked_list
{
    int size;
    node *head;
    node *end;
}
linked_list;




int main()
{
    return 0;
}


void created_list(linked_list *list)
{
    list->size = 0;
    list->head= NULL;
    list->end = NULL;
}


bool void_list(linked_list *list)
{
    return (list->head == NULL);
}


void empty_list(linked_list *list)
{
    if (full_list(&list))
    {
        list->head = NULL;
    }

    free(list);
}


void insert_element(linked_list *list, int item)
{
   node *new_element = (node *)malloc(sizeof(node));
   new_element->data = item;
   new_element->next = NULL;

   if (void_list(&list)) 
   {
      list->head = new_element;
      list->end = new_element;
   }
   else
   {
     list->end->next = new_element;
     list->end = new_element;
   }

   list->size++;
}


bool remove_element(linked_list *list)
{
    if (void_list(&list))
    {
        printf("Lista vazia, nada para remover\n");
        return true;
    }

    if (list->head == list->end)
    {
        free(list->head);
        list->head = NULL;
        list->end = NULL;
    }
    else
    {
        node *buffer = list->head;

        while (buffer->next != list->end)
        {
            buffer = buffer->next;
        }

        free(list->end);
        buffer->next = NULL;
        list->end = buffer;
    }

    list->size--;
    return true;
}


bool full_list(linked_list *list)
{
    return (list->head != NULL);
}   


void print_list(linked_list *list)
{
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("Elements: %d ->", ptr->data);
        ptr = ptr->next;
    }
}


void count_elements(linked_list *list)
{
    printf("Number of elements: %d", list->size); 
}


bool ordered_list(linked_list *list)
{
    if (list->size <= 1)
    {
        return true;
    }


    
    node *ptr = list->head;
    while (ptr->next != NULL && ptr->data == ptr->next->data)
    {
        ptr = ptr->next;
    }


    if (ptr->next == NULL)
    {
        return true;
    }


    bool asceding = (ptr->data > ptr->next->data);
    bool desceding = (ptr->data < ptr->next->data);
    while (ptr->next != NULL)
    {
        if (asceding)
        {
            return true;
        }
        else if (desceding)
        {
            return true;
        }
        ptr = ptr->next;
    }

    return true;
}


linked_list copy_list(linked_list *list1)
{
    linked_list *list2;
    created_list(&list2);
    
    
    
}