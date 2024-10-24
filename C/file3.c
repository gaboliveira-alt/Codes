#include <stdio.h>

int main(void)
{
    FILE *fptr;
    int arr[10];
    int x[10];
    int k;

    for (k = 0; k < 10; k++)
        arr[k] = k;

    fptr = fopen("datafile.bin", "wb");
    fwrite(arr, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fptr);
    fclose(fptr);

    fptr = fopen("datafile.bin", "rb");
    fread(x, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fptr);
    fclose(fptr);

    for (k = 0; k < 10; k++)
        printf("%i", x[k]);
    return 0;
    


}