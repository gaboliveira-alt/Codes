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
    union val info;
    union val *ptr = NULL;
    ptr = &info;
    ptr->int_num = 10;

    printf("info.int_num is %i\n", info.int_num);

    return 0;

}