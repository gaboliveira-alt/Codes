#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 10;
    int y = 0;

    if (y != 0)
    {
        printf("x/y= %i\n", x/y);
    }
    else
    {
        printf("Divisor is 0. Program exiting.");
        exit(EXIT_FAILURE);
    }

    return 0;
}