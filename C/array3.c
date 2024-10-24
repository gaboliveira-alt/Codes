#include <stdio.h>

int main(void)
{
    int ages[] = {31, 22, 45, 56, 89};

    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += ages[i];
    }
    printf("Sum: %i\n", total);

    return 0;
}