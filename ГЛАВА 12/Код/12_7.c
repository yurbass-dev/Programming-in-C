#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int count_rolls;
	int dice;
	int sides;

	srand((unsigned int) time(0));

	printf("Введите количество бросаний или q для завершения: ");
	while (scanf("%d", &count_rolls) == 1)
	{
		printf("Сколько граней и сколько костей? ");
		scanf("%d %d", &sides, &dice);
		printf("Имеем %d бросаний %d костей с %d гранями.\n", count_rolls, dice, sides);

		for (int i = 0; i < count_rolls; i++)
		{
			printf("%4d", rand() % (sides * dice) + 1);
			if ((i + 1) % 10 == 0)
				putchar('\n');
		}
		putchar('\n');
		printf("Введите количество бросаний или q для завершения: ");
	}
	puts("Программа завершена!");


	return 0;
}