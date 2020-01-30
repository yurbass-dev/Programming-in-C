#include <stdio.h>

void kub(double n);

int main(void)
{
	double number;

	printf("Введите число, которое Вы хотите возвести в куб:\n");
	scanf("%lf", &number);
	kub(number);

	return 0;
}

void kub(double n)
{
	printf("Число %e в кубе %e.\n", n, n * n * n);
}