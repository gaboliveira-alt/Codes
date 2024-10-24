#include <stdio.h>

const int N = 2;
int add_two_ints(int a, int b[]);

int main(void)
{
    int questions[N];
    for (int i = 0; i < N; i++)
    {
        questions[N];
        printf("Give a integer: ");
        scanf("%i", &questions[i]);
    }

    printf("Result is: %i\n", add_two_ints(N, questions));
}

int add_two_ints(int a, int b[])
{
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        sum += b[i];
    }
    return sum;
}