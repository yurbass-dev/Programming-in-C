#include <stdio.h>

void to_base_n(unsigned long n, int p);

int main(void)
{
	unsigned long n;
	int p;

	printf("Введите число и основание системы  (2 - 10) для перевода числа:\n");

	while (scanf("%lu %d", &n, &p) == 2)
	{	
		if (p < 2 || p > 10)
		{
			printf("Основание системы счисления должно быть от 2 до 10.\n");
			continue;
		}
		printf("Число %lu в системе счисления %d = ", n, p);
		to_base_n(n, p);
		putchar('.');
		putchar('\n');
		printf("Введите следующие 2 цифры или q для завершения.\n");
	}
	

	return 0;
}

void to_base_n(unsigned long n, int p)
{
	int r;

	r = n % p;
	if (n >= p)
		to_base_n(n / p, p);

	if (r == 0)
		printf("0");
	else
		printf("%d", r);

	return;
}