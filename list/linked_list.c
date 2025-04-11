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
    if (list == NULL)
    {
        return;
    }

    node *ptr = list->head;
    node *next_node;

    while (ptr != NULL)
    {
        next_node = ptr->next;
        free(ptr);
        ptr = next_node;
    }


    list->head = NULL;
    list->end = NULL;
    list->size = 0;
}


void destroy_list(linked_list *list)
{
    empty_list(&list);
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

   list->size ++;
}


void insert_element_position(linked_list *list, int position, int item)
{
   if (position <= 0 && position > list->size)
   {
     printf("Erro ao colocar elemento na posição desejada\n");
     return;
   }


   node *new_element = (node *)malloc(sizeof(node));
   new_element->data = item;
   new_element->next = NULL;


   if (position == 0)
   {
    new_element->next = list->head;
    list->head = new_element;

    if (list->size == 0)
    {
        list->end = new_element;
    }
   }
   else if (position == list->size)
   {
    list->end->next = new_element;
    list->end = new_element;
   }
   else
   {
    node *prev = list->head;

    for (int i = 0; i < position - 1; i++)
    {
        prev = prev->next;
    }

    new_element->next = prev->next;
    prev->next = new_element;
   }

   list->size++;
}


void remove_element(linked_list *list)
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


int remove_element_position(linked_list *list, int position)
{
    if (position <= 0 && position > list->size)
    {
        printf("Erro ao remover item desejado\n");
        return;
    }


    if (void_list(&list))
    {
        printf("Lista Vazia, nada para remover\n");
        return;
    }

    node *to_remove = NULL;
    int item_removed;

    if (position == 0)
    {
        to_remove = list->head;
        list->head = list->head->next;
        item_removed = to_remove->data;
        free(to_remove);

        if (list->head == NULL)
        {
            list->end = NULL;
        }
    }
    else
    {
        node *prev = list->head;

        for (int i = 0; i < position - 1; i++)
        {
            prev = prev->next;
        }

        to_remove = prev->next;
        prev->next = to_remove->next;
        item_removed = to_remove->data;
        free(to_remove);
    }

    list->size--;
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
    linked_list list2;
    created_list(&list2);
    
    node *ptr = list1->head;
    while (ptr != NULL)
    {
        insert_element(&list2, ptr->data);
        ptr = ptr->next;
    }

    return list2;
}


linked_list copy_remove_duplicate(linked_list *list1)
{
    linked_list list2;
    created_list(&list2);

    node *ptr = list1->head;
    while (ptr != NULL)
    {
        bool is_existed = false;
        node *check_list2 = list2.head;

        while (check_list2 != NULL)
        {
            if (check_list2->data == ptr->data)
            {
                is_existed = true;
                break;
            }
            check_list2 = check_list2->next;
        }

        if (!is_existed)
        {
            insert_element(&list2, ptr->data);
        }

        ptr = ptr->next;
    }

    return list2;
}


void invert_listOrigin(linked_list *list)
{
    node *prev = NULL;
    node *currency = list->head;
    node *next = NULL;

    while (currency != NULL)
    {
        next = currency->next;
        currency->next = prev;
        prev = currency;
        currency = next;
    }

    list->head = prev;
}


linked_list invert_list1_to_list2(linked_list *list1)
{
    linked_list list2;
    created_list(&list2);

    node *prev = NULL;
    node *currency = list1->head;
    node *next = NULL;

    while (currency != NULL)
    {
        next = currency->next;
        currency->next = prev;
        prev = currency;
        currency = next;
    }

    list1->head = prev;

    node *currency_inverted = list1->head;

    while (currency_inverted != NULL)
    {
        insert_element(&list2, currency_inverted->data);
        currency_inverted = currency->next;
    }

    return list2;
}


linked_list join_ordered_lists(linked_list *list1, linked_list *list2)
{
    linked_list list3;
    created_list(&list3);

    node *currency_1 = list1->head;
    node *currency_2 = list2->head;

    while (currency_1 != NULL)
    {
        insert_element(&list3, currency_1->data);
        currency_1 = currency_1->next;
    }

    while (currency_2 != NULL)
    {
        insert_element(&list3, currency_2->data);
        currency_2 = currency_2->next;
    }
    
    return list3;
}


void remove_repeats(linked_list *list, int item)
{
    node *ptr = list->head;

    while (ptr != NULL)
    {
        bool is_existed = false;

        if (ptr->data == item)
        {
            is_existed = true;
            break;
        }

        ptr = ptr->next;
    }
}





