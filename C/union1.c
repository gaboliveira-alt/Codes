#include <stdio.h>
#include <string.h>

union val
{
    int int_num;
    float fl_num;
    char str[20];
};

int main(void)
{
    union val test;

    test.int_num = 123;
    test.fl_num = 98.76;
    strcpy(test.str, "hello");

    printf("%i\n", test.int_num);
    printf("%f\n", test.fl_num);
    printf("%s\n", test.str);

    return 0;

}