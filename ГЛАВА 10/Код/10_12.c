#include <stdio.h>
#define YEARS 5
#define MONTHS 12

void count_of_rainfall(const float rain[][MONTHS], int years);            //выводит количество осадков за каждый год
void average_count_of_rainfall(const float rain[][MONTHS], int years);    //выводит среднегодовое количество осадков
void average_of_month_rainfall(const float rain[][MONTHS], int years);    //выводит среднемесячное количество осадков

int main(void)
{
    const float rain[YEARS][MONTHS] =
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    
    count_of_rainfall(rain, YEARS);
    average_count_of_rainfall(rain, YEARS);
    average_of_month_rainfall(rain, YEARS);
    
    return 0;
}

void count_of_rainfall(const float rain[][MONTHS], int years)
{
    int start_year = 2010;
    
    
    printf(" ГОД    КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
    
    for (int year = 0; year < years; year++)
    {
        float total = 0.0;
        for (int month = 0; month < MONTHS; month++)
        {
            total += rain[year][month];
            
        }
        printf("%5d %14.1f\n", start_year + year,  total);
    }
    putchar('\n');
}

void average_count_of_rainfall(const float rain[][MONTHS], int years)
{
    float total = 0.0;
    float subtotal = 0.0;
    for (int year = 0; year < years; year++)
    {
        for (int month = 0; month < MONTHS; month++)
        {
            subtotal += rain[year][month];
        }
        total += subtotal;
        subtotal = 0.0;
    }
    total /= years;
    
    printf(" Среднегодовое количество осадков составляет  %.1f дюймов.\n", total);
    putchar('\n');
}

void average_of_month_rainfall(const float rain[][MONTHS], int years)
{
    float average_of_month = 0.0;

    printf(" СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf(" Янв  Фев  Мар  Апр  Май  Июн  Июл  Авг  Сен  Окт  Ноя  Дек\n");
    
    for (int month = 0; month < MONTHS; month++)
    {
        for (int year = 0; year < years; year++)
        {
            average_of_month += rain[year][month];
        }
        printf("%4.1f ", average_of_month / years);
        average_of_month = 0.0;
    }
    putchar('\n');
}

