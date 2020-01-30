#include <stdio.h>

double Fibonacci(int);

int main(void)
{
	int n;

	printf("Введите число для вычисления числа Фибоначчи:\n");

	while (scanf("%d", &n) == 1)
	{
		if (n < 0)
		{
			printf("Введите положительное число.\n");
			continue;
		}
		printf("Число %d = %g числу Фибоначчи.\n", n, Fibonacci(n));
		printf("Введите следующее число (q для завершения).\n");
	}

	return 0;
}

double Fibonacci(int n)
{
	int num = 1;
	int first = 1;
	int second = 1;

	if (n < 2)
		num = 1;
	for (int i = 2; i < n; i++)
	{
		num = first + second;
		first = second;
		second = num;
	}

	return num;
}