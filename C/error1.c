#include <stdio.h>
#include <stdlib.h>

extern int errno;

int main(void)
{
    FILE *fptr;

    errno = 0;
    fptr = fopen("c:\\nonexistfile.txt", "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Error opening File. Error code: %i\n", errno);
        exit(EXIT_FAILURE);
    }

    fclose(fptr);
    return 0;
}