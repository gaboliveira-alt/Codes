#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr;
    ptr = malloc(10*sizeof(*ptr));

    if (ptr != NULL)
    {
        *(ptr + 2) = 50;
    }

    ptr = realloc(ptr, 100 *sizeof(*ptr));
    *(ptr + 30) = 75;
    printf("%i %i", *(ptr + 2), *(ptr + 30));

    return 0;
}