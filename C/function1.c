#include <stdio.h>

void greeting(char name[])
{
    printf("Hi %s!\n", name);
}

int main(void)
{
    greeting("James");

    return 0;
}