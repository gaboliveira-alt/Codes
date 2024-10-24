#include <stdio.h>

typedef struct
{
    int age;
    char name[40];
    int grade;
}
student;

int main(void)
{
    student s1;
    student s2;

    s1.age = 19;
    s1.grade = 9;
    sprintf(s1.name, "James Sunderland");

    s2.age = 18;
    s2.grade = 9;
    sprintf(s2.name, "Hunter Zolomon");

    printf("Student: %s, %i\n", s1.name, s1.age);
    printf("Student: %s, %i\n", s2.name, s2.age);

    return 0;
}