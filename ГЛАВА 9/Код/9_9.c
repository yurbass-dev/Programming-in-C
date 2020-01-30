#include <stdio.h>

double power(double, int);

int main(void)
{
	double num;
	int pow;

	printf("Введите число и целую степень, в которую число будет возведено.\n"
		   "Для завершения программы введите q.\n");

	while (scanf("%lf %d", &num, &pow) == 2)
	{
		printf("%.3g в степени %d равно %.5g\n", num, pow, power(num, pow));
		printf("Введите следующую пару чисел или q для завершения.\n");
	}

	return 0;
}

double power(double num, int p)
{
	double poweer = 1;
	int i;

	if (num == 0 && p == 0)
	{
		printf("Результат возведения 0 в степень 0 не определен."
			   "\nИспользуется значение 1.\n");
		poweer = 1;
	}
	else if (num == 0 && p != 0)
		poweer = 0;
	else if (num != 0 && p == 0)
		poweer = 1;
	else if (p > 0)
	{
		poweer = num * power(num, p - 1);
		printf("%g\n", poweer);
	}
	else
	{
		p *= -1;
		poweer = 1 / (num * power(num, p - 1));
	}

	return poweer;
}