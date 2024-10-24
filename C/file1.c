#include <stdio.h>

int main(void)
{
    FILE *fptr;
    int stock;
    char buffer[200], item[10], c;
    float price;

    fptr = fopen("myfile.txt", "w"); 

    fprintf(fptr, "Inventory\n");
    fprintf(fptr, "%i %s %f\n", 100, "Widget", 0.29);
    fputs("End of List", fptr);
    fclose(fptr);

    fptr = fopen("myfile.txt", "r");
    fgets(buffer, 20, fptr);
    printf("%s\n", buffer);
    fscanf(fptr, "%i%s%f\n", &stock, item, &price);
    printf("%i %s %4.2f\n", stock, item, price);
    while ((c = fgetc(fptr)) != EOF)
        printf("%c", c);
    fclose(fptr);
    return 0;
}