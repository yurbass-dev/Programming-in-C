#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double a = 3.45;
    double b = 2.93;
    printf("The lower is %f.\n", min(a, b));

    return 0;
}

double min(double x, double y)
{
    double min;
    if (x > y)
        min = y;
    else
        min = x;

    return min;
}