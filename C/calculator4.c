#include <stdio.h>

int main(void)
{
    int items = 100;
    int per_box = 8;

    int left_over = items % per_box;
    printf("%i", left_over);
}