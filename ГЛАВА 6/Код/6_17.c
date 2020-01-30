#include <stdio.h>
#define JECKPOT 1000000.0
#define STAVKA 0.08
#define MINUS 100000.0
int main(void)
{
    int year = 0;
    double sum_1 = JECKPOT;
    double sum;

    sum -= MINUS;

    while( sum_1 >= 0)
    {
        sum_1 += STAVKA * sum_1 - MINUS;
        year++;
    }

    printf("Через %d лет, на счету у Чаки не останиться денег.\n", year);

    return 0;

}