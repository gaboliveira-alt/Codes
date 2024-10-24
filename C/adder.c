#include <stdio.h>

int add_two_ints(int a, int b);

int main(void)
{
    int x, y;
    printf("Add two ints: ");
    scanf("%i %i", &x, &y);
    
    int z = add_two_ints(x, y);

    printf("The sum is: %i\n", z);
    
}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}