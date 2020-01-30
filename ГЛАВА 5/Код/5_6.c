#include <stdio.h>
int main(void)
{
	int count, sum, day, sql_count;

	count = 0;
	sum = 0;

	printf("Введите количество дней, для подсчета суммы.\n");
	printf("Для отмены введите 0.\n");
	scanf("%d", &day);

	while (count++ < day)
	{
		sql_count = count * count;
		sum = sum + sql_count;
	}
	printf("За %d дней Вы получите $%d.\n", day, sum);

	return 0;
}