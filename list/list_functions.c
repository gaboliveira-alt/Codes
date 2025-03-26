#include <stdio.h>
#include <stdbool.h>

#ifndef MAX_ELEMENTS
    #define MAX_ELMENTS 100
#endif


typedef struct 
{
    int items[MAX_ELMENTS];
    int size;    
}
static_list;

void create_list(static_list *list);
void print_list(static_list *list);
void insert_item(static_list *list, int item);
void remove_item(static_list *list, int value);
int binary_search(static_list *list, int target);
void sequencial_search(static_list *list, int value);


int main()
{   
   static_list list;
   create_list(&list);
   
   for (int items = 0; items < 20; items++)
   {
        insert_item(&list, items);
   }

   print_list(&list);
   binary_search(&list, 4);
   sequencial_search(&list, 32);
}


void create_list(static_list *list)
{
    list->size = 0;
}

int void_list(static_list *list)
{
    if (list->size == -1)
    {
        printf("Lista vazia!\n");
        return 1;
    }

    return 0;
}

int full_list(static_list *list)
{
    if (list->size <= MAX_ELMENTS - 1)
    {
        return 1;
    }

    return 0;
}

void print_list(static_list *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}


void insert_item(static_list *list, int item)
{
    list->items[list->size] = item;
    list->size++;
    printf("O valor %d foi inserido\n", item);
}

void remove_item(static_list *list, int value)
{
    int position = binary_search(list, value);

    if (position == -1)
    {
        printf("O valor %d não está na lista\n", value);
    }
    else
    {
        int i = position;
        while (i < list->size - 1)
        {
            list->items[i] = list->items[i + 1];
            i++;
        }
        list->size--;
        printf("O valor %d foi removido\n", value);
    }
}


void insert_position(static_list *list, int position, int value)
{
    if (!full_list(list) && position <= list->size - 1)
    {
        for (int i = list->size; i >= 0; i--)
        {
            list->items[i] = list->items[i + 1];
        }

        list->items[position] = value;
        list->size++;
    }
}


void remove_position(static_list *list, int position, int value)
{
    if (!full_list(list) && position <= list->size - 1)
    {
        for (int i = list->size; i >= 0; i--)
        {
            list->items[i] = list->items[i + 1];
        }


        list->items[position] = value;
        list->size--;
    }
}


bool ordered_list(static_list *list)
{
    if (list->size <= 1)
    {
        return true;
    }

    bool ascending = false;
    for (int i = 0; i <= list->size - 1; i++)
    {
        if (list->items[i] > list->items[i + 1])
        {
            ascending = true;
            break;
        }
    }

    if (ascending)
    {
        printf("Lista ordenada\n");
        return true;
    }


    bool descending = false;
    for (int i = 0; i <= list->size - 1; i++)
    {
        if (list->items[i] < list->items[i - 1])
        {
            descending = true;
            break;
        }
    }

    if (descending)
    {
        printf("Lista desordenada\n");
        return true;
    }

    return descending;
    return ascending;
}


static_list copy_list(static_list *list1)
{
    static_list list2;
    create_list(&list2);

    for (int i = 0; i <= list1->size - 1; i++)
    {
        insert_item(&list2, list1->items[i]);
    }
    return list2;
}


static_list copy_list_and_remove_duplicate(static_list *list1)
{
    static_list list2;
    create_list(&list2);

    for (int i = 0; i <= list1->size - 1; i++)
    {
        int auxs = list1->items[i];
        bool is_existed = false;

        if (list2.items[i] == auxs)
        {
            is_existed = true;
            break;
        }

        if (!is_existed)
        {
            insert_item(&list2, auxs);
        }
    }

    return list2;
}


void invert_listOrigin(static_list *list)
{
    for (int i = 0; i < list->size / 2; i++)
    {
        int auxs = list->items[i];
        list->items[i] = list->items[list->size - 1 - i];
        list->items[list->size - 1 - i] = auxs;
    }
}

static_list invert_list1_to_list2(static_list *list1)
{
    static_list list2;
    create_list(&list2);
    
    for (int i = list1->size - 1; i >= 0; i--)
    {
        insert_item(&list2, list1->items[i]);
    }

    return list2;
}


static_list join_ordered_lists(static_list *list1, static_list *list2)
{
    static_list list3;
    create_list(&list3);

    int i = 0, j = 0;

    while (i <= list1->size - 1 && j <= list2->size - 1)
    {
        if (list1->items[i] < list2->items[j])
        {
            insert_item(&list3, list1->items[j]);
            i++;
        }
        else
        {
            insert_item(&list3, list2->items[i]);
            j++;
        }
    }


    while (i <= list1->size - 1)
    {
        insert_item(&list3, list1->items[i]);
        i++;
    }


    while (j <= list2->size - 1)
    {
        insert_item(&list3, list2->items[j]);
        j++;
    }


    return list3;
}


void remove_repeats(static_list *list, int value)
{
    for (int i = 0; i <= list->size - 1; i++)
    {
        if (list->items[i] == value)
        {
            for (int j = i; j <= list->size - 1; j++)
            {
                list->items[j] = list->items[j + 1];
            }
        }

        list->size--;
        i--;
    }
}


int binary_search(static_list *list, int target)
{
    int left = 0;
    int right = list->size + 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (target == list->items[middle])
        {
            printf("The middle: %d\n", list->items[middle]);
            return middle;
        }
        else if (target < list->items[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }

        middle = (left + right) / 2;
    }

    return -1;
}


void sequencial_search(static_list *list, int value)
{
    for (int i = 0; i < list->size; i++)
    {
        if (value == list->items[i])
        {
            printf("Value find: %d\n", list->items[i]);
            break;
        }
    }
    
    printf("Value not find\n");

}