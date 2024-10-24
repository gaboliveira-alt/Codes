#include <stdio.h>

int main(void)
{
    int num = 0;
    do
    {
        printf("%i\n", num);
        num+= 3;
    }
    while (num < 10);

    return 0;
}