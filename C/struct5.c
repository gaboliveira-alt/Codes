#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int number;
    int age;
}
student;

void showStudentData(student *st)
{
    printf("\nStudent\n");
    printf("Name: %s\n", st->name);
    printf("Age: %i\n", st->age);
    printf("Number: %i\n", st->number);
}

int main(void)
{
    student st1;
    student st2;

    strcpy(st1.name, "Marcao");
    st1.age = 19;
    st1.number = 5;

    strcpy(st2.name, "Nelson");
    st2.age = 17;
    st2.number = 6;

    showStudentData(&st1);

    showStudentData(&st2);

    return 0; 
}
