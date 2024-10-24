#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[20];
}
item;

int main(void)
{
    FILE *fptr;
    item first, second, secondf;

    first.id = 10276;
    strcpy(first.name, "Widget");
    second.id = 11876;
    strcpy(second.name, "Gadget");
    
    fptr = fopen("info.dat", "wb");
    fwrite(&first, 1, sizeof(first), fptr);
    fwrite(&second, 1, sizeof(second), fptr);
    fclose(fptr);

    fptr = fopen("info.dat", "rb");

    fseek(fptr, 1*sizeof(item), SEEK_SET);
    fread(&secondf, 1, sizeof(item), fptr);
    printf("%i %s\n", secondf.id, secondf.name);
    fclose(fptr);
    return 0;
}