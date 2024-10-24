#include <stdio.h>

typedef struct
{
    int x;
    int y;
}
point;

typedef struct 
{
    float radius;
    point center;
}
circle;

int main(void)
{
    point p;
    p.x = 3;
    p.y = 4;

    circle c;
    c.radius = 3.14;
    c.center = p;

    printf("Circle radius is %.2f, center is at(%i, %i)", c.radius, c.center.x, c.center.y);

    return 0;
}