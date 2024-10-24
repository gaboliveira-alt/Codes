#include <stdio.h>

void greeting(char name[], int age)
{
    printf("Hello, %s!", name);
    printf(" You are %i years old! \n", age);
}

int main(void)
{
    greeting("James", 29);
    greeting("Mary", 29);

    return 0;
}