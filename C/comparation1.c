#include <stdio.h>

int main(void)
{
    int balance = 500;
    int level = 5;

    if (balance > 1000 || level > 3)
    {
        printf("Gold Tier");
    }

    return 0;
}