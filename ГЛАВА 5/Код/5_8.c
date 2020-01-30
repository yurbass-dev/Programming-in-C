#include <stdio.h>

int main(void)
{
	int first, second, result;

	printf("Эта программа вычисляет результаты деления по модулю.\n");
	printf("Введите целое число, которое будет служить вторым операндом: ");
	scanf("%d", &second);

	printf("Теперь введите первый операнд: ");
	scanf("%d", &first);

	while (first > 0)
	{
		result = first % second;
		printf("\n%d %% %d = %d\n\n", first, second, result);
		printf("Введите следующее число для первого операнда (0 для выхода): ");
		scanf("%d", &first);
	}

	return 0;
}