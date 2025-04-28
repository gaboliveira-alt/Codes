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


void insert_soldiers(linked_list *list)
{
    int quantity_soliders, validation, ch;

    printf("Insira a quantidade de soldados que voce deseja: ");
    validation = scanf("%d", &quantity_soliders);

    while (validation == 0)
    {
        fprintf(stderr, "Insira um valor valido acima de 0\n");
        printf("Insira a quantidade de soldados que voce deseja: ");

        do
        {
            ch = getchar();
        } 
        while ((ch != EOF) && (ch != "\n"));

        validation = scanf("%d", &quantity_soliders);
        printf("\n");        
    }

    if (quantity_soliders != 0)
    {
        insert_list(list, quantity_soliders);
    }
    else
    {
        printf("Vacilou\n");
    }
}


void insert_list(linked_list *list, int total_soldiers)
{
    for (int i = 0; i < total_soldiers + 1; i++)
    {
        node *soldier = (node *)malloc(sizeof(node));

        if (list->size == 0)
        {
            soldier->next = list->sentinel;
            soldier->prev = list->sentinel;
            soldier->soldier_number = i;
            list->sentinel->next = soldier;
            list->sentinel->prev = soldier;
            list->end = soldier;
            list->size++;
        }
        else
        {
            soldier->next = list->sentinel;
            soldier->prev = list->sentinel->prev;
            soldier->soldier_number = i;
            list->sentinel->prev->next = soldier;
            list->sentinel->prev = soldier;
            list->end = soldier;
            list->size++;
        }
    }

    view_soldiers(list);
}


int insert_jump()
{
    int quantity_jumps, validation, ch;

    printf("Insira a quantidade de pulos que voce deseja: ");
    scanf("%d", &quantity_jumps);

    while (validation == 0)
    {
        fprintf(stderr, "Insira uma quantidade valida de pulos!\n");
        printf("Insira a quantidade de pulos que voce deseja: ");

        do
        {
            ch = getchar();
        } 
        while ((ch != EOF) && (ch != "\n"));

        scanf("%d", &quantity_jumps);
        printf("\n");
    }
    
    if (quantity_jumps == 0)
    {
        printf("Nao existe pulos de 0\n");
    }
    else
    {
        return quantity_jumps;
    }
}


void remove_soldier(linked_list *list, int num_soldier)
{
    node *soldier = list->sentinel->next;
    int counter = 0;

    while (counter < num_soldier)
    {
        if (num_soldier == soldier->soldier_number)
        {
            soldier->prev->next = soldier->next;
            soldier->next->prev = soldier->prev;

            if (list->size == 1)
            {
                list->sentinel->next = list->sentinel;
                list->sentinel->prev = list->sentinel;
                list->end = NULL;
            }

            if (soldier == list->end)
            {
                if (soldier->prev == list->sentinel)
                {
                    list->end = NULL;
                }
                else
                {
                    list->end = soldier->prev;
                }
            }

            free(soldier);
            list->size--;
            view_soldiers(list);
            break;
        }

        soldier = soldier->next;
        counter++;
    }
}


void view_soldiers(linked_list *list)
{
    node *soldier = list->sentinel->next;

    for (int c = 0; c < list->size; c++)
    {
        printf("Soldado: %d", soldier->soldier_number);
        soldier = soldier->next;
    }
    printf("\n");
}


void josefo(linked_list *list, int jump)
{
    node *aux;
    
    if (jump > 0)
    {
        node *soldier = list->sentinel->next;
        int counter = 1;

        
        while (1)
        {
            if (soldier->soldier_number != 0)
            {
                if (list->size == 1)
                {
                    printf("O ultimo soldado: %d", soldier->soldier_number);
                    break;
                }

                if (counter == jump)
                {
                    aux = soldier->next;
                    remove_soldier(list, soldier->soldier_number);
                    counter = 1;
                    soldier = aux;
                    jump = insert_jump();
                }
                else
                {
                    soldier = soldier->next;
                    counter++;
                }
        }
        else
        {
            soldier = soldier->next;
        }
    }
}