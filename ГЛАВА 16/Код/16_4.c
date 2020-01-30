#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void doit_before_time_over(double time_to_finish, int t);

int main(void)
{
	int takts;
	double time_to_finish;

	printf("Введите число в секундах: ");
	while (scanf("%lf", &time_to_finish) == 1)
	{
		takts = clock();
		if (takts == -1)
		{
			puts("Не удалось получить количество выполненных тактов процессора.");
			exit(EXIT_FAILURE);
		}
		printf("Main: %f.\n", (double) takts / CLOCKS_PER_SEC);
		doit_before_time_over(time_to_finish, takts);
		printf("\nВведите число в секундах: ");
	}

	return 0;
}

void doit_before_time_over(double time_to_finish, int t)
{
	int takt;
	double time_sec;
	unsigned long count = 0;
	double num = 0.01;

	do
	{
		takt = clock();
		if (takt == -1)
		{
			puts("Не удалось получить количество выполненных тактов процессора.");
			exit(EXIT_FAILURE);
		}
		time_sec = ((double) takt - (double) t) / CLOCKS_PER_SEC;
		num += 0.0025;
		count++;

	}
	while (time_sec < time_to_finish);

	printf("Получилось число %f за %lu циклов и за %f секунд.\n", num, count, time_sec);
}