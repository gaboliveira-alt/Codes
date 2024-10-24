#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char title[40];
    float hours;
}
course;

int main(void)
{
    course cs1;
    course cs2;

    cs1.id = 123456;
    strcpy(cs1.title, "Javascript Basics");
    cs1.hours = 12.38;

    cs2.id = 341281;
    strcpy(cs2.title, "Advanced C++");
    cs2.hours = 14.28;

    printf("%i\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);
    printf("%i\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);

    return 0;
}
