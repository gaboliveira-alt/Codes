#include <stdio.h>

void divide(int* x, int* y, int by)
    {
        *x /= by;
        *y /= by;
    }

int main(void)
{
    int x = 420;
    int y = 600;

    divide(&x, &y, 10);

    printf("%i %i", x, y);

    return 0;
}