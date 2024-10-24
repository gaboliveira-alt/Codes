#include <stdio.h>

typedef struct
{
    int age;
    int grade;
    char name[40];
}
student;

int main(void)
{
    student s1 = {19, 9, "James Sunderland"};
    student s2;

    printf("Assigning, s2 = s1\n");
    s2 = s1;

    printf("Results, Name: %s, Age: %i, Grade: %i\n", s2.name, s2.age, s2.grade);

    return 0;
}