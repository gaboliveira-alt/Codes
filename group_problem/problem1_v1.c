#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 50


typedef struct 
{
    int group_elements[MAX_ELEMENTS];
    int size;
    int group_number;
}
group;

void create_group(group *group_created, int quantity);
void print_group(group *group_created);
void insert_members(group *group_created, int member);


int main()
{
    group new_group;

    int quantity_group;
    printf("Informe a quantidade de grupos: ");
    scanf("%d", &quantity_group);

    create_group(&new_group, quantity_group);
    
        
    int quantity_members;
    char confirmation[20];
    do
    {
        printf("Informe a quantidade de membros para cada grupo: ");
        while (scanf("%d", &quantity_members) != 1 || quantity_members <= 0)
        {
            printf("Apenas numeros positivos\n");
            break;
        }
        

        printf("Voce deseja adicionar mais membros? ");
        scanf("%s", confirmation);
    } 
    while (strcmp(confirmation, "nao") != 0);

    
    for (int i = 0; i < quantity_members; i++)
    {
        insert_members(&new_group, i);
    }

    print_group(&new_group);
}


void create_group(group *group_created, int quantity)
{
    group_created->size = 0;

    int count = 1;
    while (count <= quantity)
    {
        group_created->group_number = quantity;
        count++;
    }
}


void insert_members(group *group_created, int member)
{
    group_created->group_elements[group_created->size] = member;
    group_created->size++;
}


void print_group(group *group_created)
{
    for (int i = 1; i < group_created->group_number + 1; i++)
    {
        printf("Grupo(%d):\n", i);

        for (int j = 1; j < group_created->size + 1; j++)
        {
            printf("Pessoas: %d\n", group_created->group_elements[j]);
        }
    }
}