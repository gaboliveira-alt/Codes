#include <stdio.h>

int main(void)
{
    char name[50];
    fgets(name, 50, stdin);

    printf("Hi %s", name);

    return 0;
}