#include <stdio.h>
#include <string.h>


#define MAX_ELEMENTS 50
#define MAX_GROUP 10


typedef struct 
{
    int group_elements[MAX_ELEMENTS];
    int size;
}
group;


void create_groups(group new_groups[], int quantity_groups);
void insert_members(group *new_group, int people);
void print_groups(group new_groups[], int quantity_groups);


int main()
{
    group new_groups[MAX_GROUP];


    int quantity_groups;
    printf("Maximo de Grupos possiveis: %d\n", MAX_GROUP);
    printf("Informe a quantidade de grupos que voce deseja: ");
    scanf("%d", &quantity_groups);
    while (quantity_groups <= 0)
    {
        printf("Voce precisa criar pelo menos 1 grupo");
        break;
    }

    create_groups(new_groups, quantity_groups);

    
    int quantity_people;
    char confirmation[20];
    do
    {
        for (int i = 0; i < quantity_groups; i++)
        {
        printf("Grupo(%d) - Informe a quantidade de membros para cada grupo: ", i + 1);
        while (scanf("%d", & quantity_people) != 1 && quantity_people <= 0 && quantity_people > MAX_ELEMENTS)
        {
            printf("Cada grupo deve ter no minimo 2 pessoas!\n");
        }

        for (int j = 0; j < quantity_people; j++)
        {
            insert_members(&new_groups[i], j + 1);
        }
        }

        printf("\nVoce deseja adicionar mais membros? (sim/nao): ");
        scanf("%s", confirmation);
    }
    while (strcmp(confirmation, "nao") != 0);

    print_groups(new_groups, quantity_groups);

    return 0;
}


void create_groups(group new_groups[], int quantity_groups)
{

    for (int i = 0; i < quantity_groups; i++)
    {
        new_groups[i].size = 0;
    }
}


void insert_members(group *new_group, int people)
{
    if (new_group->size < MAX_ELEMENTS)
    {
        new_group->group_elements[new_group->size] = people;
        new_group->size++;
    }
}


void print_groups(group new_groups[], int quantity_groups)
{
    for (int i = 0; i < quantity_groups; i++)
    {
        printf("Grupos(%d)\n", i+1);

        for (int j = 0; j < new_groups[i].size; j++)
        {
            printf("Pessoas: %d\n", new_groups->group_elements[j]);
        }
    }
}


void search_person(group new_groups[], int quantity_groups, int target)
{
    for (int i = 0; i < quantity_groups; i++)
    {
        for (int j = 0; j < new_groups[i].size; j++)
        {
            // encontrar o valor ....                        
        }
    }
}
