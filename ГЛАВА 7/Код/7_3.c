#include <stdio.h>
#define STOP 0

int main(void)
{
	int num;
	int all_chet_num = 0;
	float mid_count_chet_num = 0.0;
	int all_nechet_num = 0;
	float mid_count_nechet_num = 0.0;
	int i, j;

	printf("Введите целые числа (для завершения 0):\n");

	for ( ; scanf("%d", &num), num != 0; )
	{
		if (num % 2 == 0)
			all_chet_num++;
		else 
			all_nechet_num++;

		if (num % 2 == 0)
			mid_count_chet_num += num;

		else
			mid_count_nechet_num += num;

	}

	printf("Общее количество четных чисел (кроме 0) = %d.\n", all_chet_num);
	if (all_chet_num > 0)
		printf("Среднее значение четных чисел = %g.\n", mid_count_chet_num / all_chet_num);
	printf("Общее количество нечетных чисел = %d.\n", all_nechet_num);
	if (all_nechet_num > 0)
		printf("Среднее значение нечетных чисел = %g.\n", mid_count_nechet_num / all_nechet_num);

	return 0;
}