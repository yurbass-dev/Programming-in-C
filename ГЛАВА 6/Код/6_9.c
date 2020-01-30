#include <stdio.h>

double result(double n, double m);

int main(void)
{
	double first_num, second_num;

	printf("Введите два числа с плавающей запятой для вычисления"
		   " их разности, деленной на их произведение: ");

	for( ;(scanf("%lf", &first_num), scanf("%lf", &second_num)) != 0; )
	{	
		printf("\n(%.2f - %.2f) / (%.2f * %.2f) = %.5f\n", first_num, second_num, first_num, second_num, result(first_num, second_num));
		printf("Введите следующую пару чисел или q для выхода: ");
	}	

		return 0;
}

double result(double n, double m)
{
	return (n - m) / (n * m);
}