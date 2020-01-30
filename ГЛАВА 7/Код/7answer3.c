#include <stdio.h>
int main(void)
{
	int weight, height;

	printf("Введите ваш вес в фунтах и рост в дюймах: ");
	scanf("%d %d", &weight, &height);
	if (weight < 100 && height > 64)
		if (height >= 72)
			printf("Ваш вес мал для вашего роста.\n");
		else
		printf("Ваш вес слишком мал для вашего роста.\n");
	else if (weight > 300 && height < 48)
		printf("Ваш рост мал для вашего веса.\n");
	else
		printf("У вас идеальный вес.\n");

	return 0;
}