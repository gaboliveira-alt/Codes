#include <stdio.h>

#define TO_STR(x) #x

int main(void)
{
    printf("%s\n", TO_STR( 123\\12));

    return 0;
}