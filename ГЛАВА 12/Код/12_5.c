#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define RANGE 10

int main(void)
{
	int array[SIZE];
	int temp;
	int seed;

	printf("Введите целое число для генерации случайных чисел: ");
	scanf("%d", &seed);
	srand(seed);
	
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % RANGE + 1;
	}
	printf("Исходный список числе:\n");
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 10 == 0)
			putchar('\n');
		printf("%4d", array[i]);
	}
	putchar('\n');
	putchar('\n');

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (array[i] < array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}

	printf("Отсортированный список числе:\n");
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 10 == 0)
			putchar('\n');
		printf("%4d", array[i]);
	}
	putchar('\n');
	putchar('\n');

	puts("Программа завершена!");


	return 0;
}