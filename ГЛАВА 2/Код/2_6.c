#include <stdio.h>

int main(void)
{
	int toes;
	int double_toes;
	int sqrt_toes;

	toes = 10;
	double_toes = toes * 2;
	sqrt_toes = toes * toes;

	printf("Количество пальцев: %d.\n", toes);
	printf("Удвоенное количество пальцев: %d.\n", double_toes);
	printf("Количество пальцев в квадрате: %d.\n", sqrt_toes);

	return 0;
}