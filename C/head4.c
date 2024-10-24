#include <stdio.h>

#define LEVEL 4

int main(void)
{
    #if LEVEL > 6
        printf("%i\n", LEVEL);
    #elif LEVEL > 5
        printf("%i\n", LEVEL);
    #elif LEVEL > 4
        printf("%i\n", LEVEL);
    #else 
        printf("No Level found\n");
    #endif

    return 0;
}