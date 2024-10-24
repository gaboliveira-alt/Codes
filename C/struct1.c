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
    student s1 = {19,"James Sunderland", 9};
    student s2 = {20, "Hunter Zolomon", 10};

    printf("Student: %s, %i\n", s1.name, s1.age);
    printf("Student: %s, %i\n", s2.name, s2.age);

    return 0;
}