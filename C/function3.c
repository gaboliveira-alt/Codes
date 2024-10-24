#include <stdio.h>

int sum(int x, int y)
    {
    return (x + y);
    }

int main(void)
{
    int res = sum(12, 35);
    printf("%i", res);

    return 0;
}