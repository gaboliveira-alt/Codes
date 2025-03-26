#include <stdio.h>

int main(void)
{
    int x[] = {1, 2, 3, 4};
    int *p = x;

    for (int i = 0; i < 4; i++)
    {
        printf("%i \n", *p);
        p++;
    }

    return 0;
}