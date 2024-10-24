#include <stdio.h>

int main(void)
{
    int position = 3;

    if (position == 1)
    {
        printf("Gold");
    }
    else if (position == 2)
    {
        printf("Silver");
    }
    else if (position == 3)
    {
        printf("Bronze");
    }
    else
    {
        printf("Something Else");
    }
}