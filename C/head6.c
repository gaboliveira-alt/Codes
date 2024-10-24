#include <stdio.h>

#define VAR(name, num) name##num

int main(void)
{
    int x1 = 125;
    int x2 = 250;
    int x3 = 500;

    printf("%i\n", VAR(x, 3));

    return 0;
}