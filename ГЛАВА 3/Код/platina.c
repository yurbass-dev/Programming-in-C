#include <stdio.h>

int main (void)
{
	float weight;
	float value;

	printf("Введите Ваш вес: ");
	scanf("%f", &weight);
	value = 1700.0 * weight * 14.5833;
	printf("Ваш вес в платиновом эквиваленте составляет: $%.2f.\n", value);

	return 0;
}