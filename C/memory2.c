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
    printf("3rd element is equal to %i\n", *(ptr + 2));

    free(ptr);

    return 0;
}

