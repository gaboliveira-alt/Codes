#include <stdio.h>

int main()
{
    int x = 3;
    int y = 5;

    printf("Conteudo de x: %d\n", x);
    printf("Conteudo de y: %d\n", y);

    int *px, *py;

    px = &x;
    py = &y;

    printf("Conteudo apontado de px: %d\n", *px);
    printf("Conteudo apontado de py: %d\n", *py);

    *px = 4;
    *py = 10;

    printf("Conteudo apontado de px: %d\n", *px);
    printf("Conteudo apontado de py: %d\n", *py);

    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);

    return 0;
}