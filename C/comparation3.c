#include <stdio.h>

int main(void)
{
    int balance = 200;
    int level = 8;
    char type = 'V';

    if (balance > 1000 || (level > 2 && type == 'V'))
    {
        printf("Welcome\n");
    }

    return 0;
}