#include <stdio.h>

int main(void)
{
    int x[] = {1, 2, 3, 4};

    printf("%i", *(x + 3));

    return 0;
}