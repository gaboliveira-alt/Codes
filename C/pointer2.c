#include <stdio.h>

int main(void)
{
    int age = 24;
    int* p = &age;

    printf("%i", *p);

    return 0;
}