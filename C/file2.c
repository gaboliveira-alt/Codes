#include <stdio.h>

int main(void)
{
    FILE *fptr;
    char filename[50];
    char c;

    printf("Enter the filename of the file to create: ");
    gets(filename);
    fptr = fopen(filename, "w");

    fprintf(fptr, "Inventory\n");
    fprintf(fptr, "%i %s %f\n", 100, "Widget", 0.29);
    fputs("End of List", fptr);

    fclose(fptr);

    fptr = fopen(filename, "r");
    while ((c = fgetc(fptr)) != EOF)
        printf("%c", c);
    fclose(fptr);
    return 0;
}